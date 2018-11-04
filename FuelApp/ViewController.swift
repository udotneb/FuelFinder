import UIKit
import MapKit

protocol HandleMapSearch: class {
    func dropPinZoomIn(_ placemark:MKPlacemark)
}

class ViewController: UIViewController, CLLocationManagerDelegate, HandleMapSearch, MKMapViewDelegate{
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
        self.mapView.showsUserLocation = true
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
                print("in")
                if (unwrappedResponse.routes.count > 0) {
                    self.mapView.add(unwrappedResponse.routes[0].polyline)
                    self.mapView.setVisibleMapRect(unwrappedResponse.routes[0].polyline.boundingMapRect, animated: true)
                }
            }
            previous = i.coordinate
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        print(currentLocation?.coordinate.longitude)
        print(currentLocation?.coordinate.latitude)
        if currentLocation == nil {
            // Zoom to user location
            if let userLocation = locations.last {
                let viewRegion = MKCoordinateRegionMakeWithDistance(userLocation.coordinate, 2000, 2000)
                mapView.setRegion(viewRegion, animated: false)
            }
        }
        currentLocation = locations[locations.count - 1]
    }
    
    func dropPinZoomIn(_ placemark: MKPlacemark){
        // clear existing pins
        //mapView.removeAnnotations(mapView.annotations)
        var placemarkLat = placemark.coordinate.latitude
        var placemarkLon = placemark.coordinate.longitude
        showRouteOnMap(destinations: [CLLocation(latitude: placemarkLat, longitude: placemarkLon)])
    }
    
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        let renderer = MKPolylineRenderer(overlay: overlay)
        print("render")
        renderer.strokeColor = UIColor(red: 17.0/255.0, green: 147.0/255.0, blue: 255.0/255.0, alpha: 1)
        renderer.lineWidth = 5.0
        return renderer
    }
}



