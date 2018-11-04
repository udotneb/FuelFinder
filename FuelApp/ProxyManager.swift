//
//  ProxyManager.swift
//  FuelApp
//
//  Created by Benjamin Ulrich on 11/3/18.
//  Copyright © 2018 Benjamin Ulrich. All rights reserved.
//

import UIKit
import SmartDeviceLink
class ProxyManager: NSObject, SDLManagerDelegate {
    func managerDidDisconnect() {
        return
    }
    
    func hmiLevel(_ oldLevel: SDLHMILevel, didChangeToLevel newLevel: SDLHMILevel) {
        return
    }
    
    // Singleton
    static let sharedManager = ProxyManager()
    
    //let lifecycleConfiguration = SDLLifecycleConfiguration(appName:"FuelFinder", appId: "12345")
    
    var configuration = SDLConfiguration(lifecycle: SDLLifecycleConfiguration(appName: "FuelFinder", appId: "12345", ipAddress: "136.152.143.145", port: 12345), lockScreen: .enabled(), logging: .default(), streamingMedia: nil)
    fileprivate var sdlManager: SDLManager!
    
    private override init() {
        super.init()
        sdlManager = SDLManager(configuration: configuration, delegate: self)
    }
    
    func connect() {
        // Start watching for a connection with a SDL Core
        sdlManager.start { (success, error) in
            if success {
                //ViewController.flag = false
                print("in")
            }
        }
    }
}
