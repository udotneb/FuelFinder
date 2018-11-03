//
//  ViewController.swift
//  FuelApp
//
//  Created by Benjamin Ulrich on 11/3/18.
//  Copyright © 2018 Benjamin Ulrich. All rights reserved.
//

import UIKit
import CoreLocation
import MapKit

class ViewController: UIViewController, CLLocationManagerDelegate, MKMapViewDelegate {

    @IBOutlet weak var mapView: MKMapView!
    private var locationManager: CLLocationManager!
    private var currentLocation: CLLocation?
    private var destinationLocation: [CLLocation]?
    private var routeRecently = false
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        mapView.delegate = self
        destinationLocation = [CLLocation(latitude: 37.774929, longitude: -122.419418), CLLocation(latitude: 38, longitude: -122.419418)]
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.requestAlwaysAuthorization()
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        currentLocation = nil
        self.mapView.showsUserLocation = true
        locationManager.startUpdatingLocation()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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
                    print(unwrappedResponse.routes.count)
                    self.mapView.add(unwrappedResponse.routes[0].polyline)
                    self.mapView.setVisibleMapRect(unwrappedResponse.routes[0].polyline.boundingMapRect, animated: true)
                }
            }
            previous = i.coordinate
        }
    }
    
    
    // MARK: DELEGATE METHODS
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        let renderer = MKPolylineRenderer(overlay: overlay)
        renderer.strokeColor = UIColor(red: 17.0/255.0, green: 147.0/255.0, blue: 255.0/255.0, alpha: 1)
        renderer.lineWidth = 5.0
        return renderer
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
        if !routeRecently {
            showRouteOnMap(destinations: destinationLocation!)
            routeRecently = true
        }
    }
}



