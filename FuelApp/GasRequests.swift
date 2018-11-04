//
//  GasRequests.swift
//  FuelApp
//
//  Created by Benjamin Ulrich on 11/3/18.
//  Copyright © 2018 Benjamin Ulrich. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON


public class GasRequests {
    static func test() {
        let domain = "http://api.mygasfeed.com/"
        let apiKey = "3h7oza1zx1"
        let Latitude = "37.8716"
        let Longitude = "-122.2727"
        let distance = "1"
        let fuelType = "reg"
        let sortBy = "Price"
        Alamofire.request("\(domain)/stations/radius/\(Latitude)/\(Longitude)/\(distance)/\(fuelType)/\(sortBy)/\(apiKey).json?callback=?").responseString { response in
            switch response.result {
            case .success(var data):
                data = data.replacingOccurrences(of: "(", with: "")
                data = data.replacingOccurrences(of: ")", with: "")
                data = data.replacingOccurrences(of: "?", with: "")
                data = data.replacingOccurrences(of: " ", with: "")
                let d = JSON(data)
                print(d.type)
                print(d)
            case .failure(let error):
                print("\(error)")
            }
        }
    }
}

