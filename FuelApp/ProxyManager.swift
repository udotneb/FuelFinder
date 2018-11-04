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
    
    
    var lifecycleConfig: SDLLifecycleConfiguration!
    var streamingConfig: SDLStreamingMediaConfiguration!
    
    var configuration: SDLConfiguration!
    fileprivate var sdlManager: SDLManager!
    
    private override init() {
        super.init()
        
        lifecycleConfig = SDLLifecycleConfiguration(appName: "FuelFinder", appId: "12345", ipAddress: "10.142.80.48", port: 12345)
        //lifecycleConfig = SDLLifecycleConfiguration(appName: "FuelFinder", appId: "12345", ipAddress: "10.105.224.102", port: 12345)
        
        lifecycleConfig.appType = .navigation
        streamingConfig = SDLStreamingMediaConfiguration.autostreamingInsecureConfiguration(withInitialViewController: ViewController())
        
        configuration = SDLConfiguration(lifecycle: lifecycleConfig, lockScreen: .enabled(), logging: .default(), streamingMedia: streamingConfig)
        sdlManager = SDLManager(configuration: configuration, delegate: self)
    }
    
    func connect() {
        // Start watching for a connection with a SDL Core
        print("start")
        sdlManager.start { (success, error) in
            if success {
                //ViewController.flag = false
                print("in")
            }
            print(error)
        }
    }
}
