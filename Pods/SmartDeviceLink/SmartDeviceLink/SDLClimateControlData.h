//
//  SDLClimateControlData.h
//

#import "SDLRPCMessage.h"
#import "SDLDefrostZone.h"
#import "SDLVentilationMode.h"

NS_ASSUME_NONNULL_BEGIN

@class SDLTemperature;


/**
 The current information for the Climate Remote Control Module
 */
@interface SDLClimateControlData : SDLRPCStruct

- (instancetype)initWithFanSpeed:(nullable NSNumber<SDLInt> *)fanSpeed desiredTemperature:(nullable SDLTemperature *)desiredTemperature acEnable:(nullable NSNumber<SDLBool> *)acEnable circulateAirEnable:(nullable NSNumber<SDLBool> *)circulateAirEnable autoModeEnable:(nullable NSNumber<SDLBool> *)autoModeEnable defrostZone:(nullable SDLDefrostZone)defrostZone dualModeEnable:(nullable NSNumber<SDLBool> *)dualModeEnable acMaxEnable:(nullable NSNumber<SDLBool> *)acMaxEnable ventilationMode:(nullable SDLVentilationMode)ventilationMode;

/**
 * Speed of Fan in integer
 *
 * Optional, MinValue- 0 MaxValue= 100
 */
@property (nullable, strong, nonatomic) NSNumber<SDLInt> *fanSpeed;

/**
 * The Current Temperature in SDLTemperature
 *
 * @warning This property is readonly and cannot be set on the module.
 *
 * Optional
 */
@property (nullable, strong, nonatomic) SDLTemperature *currentTemperature;

/**
 * Desired Temperature in SDLTemperature
 *
 * Optional
 */
@property (nullable, strong, nonatomic) SDLTemperature *desiredTemperature;

/**
 * Represents if AC is enabled.
 *
 * Optional, Boolean
 */
@property (nullable, strong, nonatomic) NSNumber<SDLBool> *acEnable;

/**
 * Represents if circulation of air is enabled.
 *
 * Optional, Boolean
 */
@property (nullable, strong, nonatomic) NSNumber<SDLBool> *circulateAirEnable;

/**
 * Represents if auto mode is enabled.
 *
 * Optional, Boolean
 */
@property (nullable, strong, nonatomic) NSNumber<SDLBool> *autoModeEnable;

/**
 * Represents the kind of defrost zone
 *
 * Optional, SDLDefrostZone
 */
@property (nullable, strong, nonatomic) SDLDefrostZone defrostZone;

/**
 * Represents if dual mode is enabled.
 *
 * Optional, Boolean
 */
@property (nullable, strong, nonatomic) NSNumber<SDLBool> *dualModeEnable;

/**
 * Represents if ac max is enabled.
 *
 * Optional, Boolean
 */
@property (nullable, strong, nonatomic) NSNumber<SDLBool> *acMaxEnable;

/**
 * Represents the kind of Ventilation zone
 *
 * Optional, SDLVentilationMode
 */
@property (nullable, strong, nonatomic) SDLVentilationMode ventilationMode;

@end

NS_ASSUME_NONNULL_END
