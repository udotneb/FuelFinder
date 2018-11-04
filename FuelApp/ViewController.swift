import UIKit
import MapKit

protocol HandleMapSearch: class {
    func dropPinZoomIn(_ placemark:MKPlacemark)
}

class ViewController: UIViewController, CLLocationManagerDelegate, HandleMapSearch{
    var selectedPin: MKPlacemark?
    var resultSearchController: UISearchController!
    
    let locationManager = CLLocationManager()
    private var currentLocation: CLLocation?
    
    @IBOutlet weak var mapView: MKMapView!
    
    @IBAction func button3(_ sender: AnyObject) {
        getDirections()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestAlwaysAuthorization()
        locationManager.startUpdatingLocation()
        currentLocation = nil
        let locationSearchTable = storyboard!.instantiateViewController(withIdentifier: "LocationSearchTable") as! LocationSearchTable
        resultSearchController = UISearchController(searchResultsController: locationSearchTable)
        resultSearchController.searchResultsUpdater = locationSearchTable
        let searchBar = resultSearchController!.searchBar
        searchBar.sizeToFit()
        searchBar.placeholder = "Search for places"
        navigationItem.titleView = resultSearchController?.searchBar
        resultSearchController.hidesNavigationBarDuringPresentation = false
        resultSearchController.dimsBackgroundDuringPresentation = true
        definesPresentationContext = true
        locationSearchTable.mapView = mapView
        locationSearchTable.handleMapSearchDelegate = self
    }
    
    func getDirections(){
        guard let selectedPin = selectedPin else { return }
        let mapItem = MKMapItem(placemark: selectedPin)
        let launchOptions = [MKLaunchOptionsDirectionsModeKey: MKLaunchOptionsDirectionsModeDriving]
        mapItem.openInMaps(launchOptions: launchOptions)
    }
    
    func showRouteOnMap(destinations: [CLLocation]) {
        // INPUT: List of locations to drive to
        var previous = currentLocation!.coordinate
        for i in destinations {
            let request = MKDirectionsRequest()
            request.source = MKMapItem(placemark: MKPlacemark(coordinate: previous, addressDictionary: nil))
            request.destination = MKMapItem(placemark: MKPlacemark(coordinate: i.coordinate, addressDictionary: nil))
            let annotation = MKPointAnnotation()
            annotation.coordinate = i.coordinate
            mapView.addAnnotation(annotation)
            request.requestsAlternateRoutes = true
            request.transportType = .automobile
            
            let directions = MKDirections(request: request)
            
            directions.calculate { [unowned self] response, error in
                guard let unwrappedResponse = response else { return }
                
                if (unwrappedResponse.routes.count > 0) {
                    self.mapView.add(unwrappedResponse.routes[0].polyline)
                    self.mapView.setVisibleMapRect(unwrappedResponse.routes[0].polyline.boundingMapRect, animated: true)
                }
            }
            previous = i.coordinate
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .authorizedWhenInUse {
            locationManager.requestLocation()
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print("error:: \(error)")
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.first else { return }
        let span = MKCoordinateSpanMake(0.05, 0.05)
        let region = MKCoordinateRegion(center: location.coordinate, span: span)
        mapView.setRegion(region, animated: true)
        currentLocation = locations[locations.count - 1]
    }
    
    func dropPinZoomIn(_ placemark: MKPlacemark){
        // cache the pin
        selectedPin = placemark
        // clear existing pins
        mapView.removeAnnotations(mapView.annotations)
        var placemarkLat = placemark.coordinate.latitude
        var placemarkLon = placemark.coordinate.longitude
        print("in")
        showRouteOnMap(destinations: [CLLocation(latitude: placemarkLat, longitude: placemarkLon)])
    }
}



extension ViewController : MKMapViewDelegate {
    /*
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView?{
        
        guard !(annotation is MKUserLocation) else { return nil }
        
        let reuseId = "pin"
        guard let pinView = mapView.dequeueReusableAnnotationView(withIdentifier: reuseId) as? MKPinAnnotationView else { return nil }
        
        pinView.pinTintColor = UIColor.orange
        pinView.canShowCallout = true
        let smallSquare = CGSize(width: 30, height: 30)
        var button: UIButton?
        button = UIButton(frame: CGRect(origin: CGPoint.zero, size: smallSquare))
        button?.setBackgroundImage(UIImage(named: "car"), for: UIControlState())
        button?.addTarget(self, action: #selector(ViewController.getDirections), for: .touchUpInside)
        pinView.leftCalloutAccessoryView = button
        
        return pinView
    } */
    
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        let renderer = MKPolylineRenderer(overlay: overlay)
        renderer.strokeColor = UIColor(red: 17.0/255.0, green: 147.0/255.0, blue: 255.0/255.0, alpha: 1)
        renderer.lineWidth = 5.0
        return renderer
    }
}






