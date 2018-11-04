//
//  SDLModuleData.h
//

#import "SDLRPCMessage.h"
#import "SDLModuleType.h"

@class SDLRadioControlData;
@class SDLClimateControlData;

NS_ASSUME_NONNULL_BEGIN

/**
 Describes a remote control module's data
 */
@interface SDLModuleData : SDLRPCStruct

- (instancetype)initWithRadioControlData:(SDLRadioControlData *)radioControlData;
- (instancetype)initWithClimateControlData:(SDLClimateControlData *)climateControlData;

/**
 The moduleType indicates which type of data should be changed and identifies which data object exists in this struct.

 For example, if the moduleType is CLIMATE then a "climateControlData" should exist

 Required
 */
@property (strong, nonatomic) SDLModuleType moduleType;

/**
 The radio control data

 Optional
 */
@property (nullable, strong, nonatomic) SDLRadioControlData *radioControlData;

/**
 The climate control data

 Optional
 */
@property (nullable, strong, nonatomic) SDLClimateControlData *climateControlData;

@end

NS_ASSUME_NONNULL_END
