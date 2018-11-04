#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "NSNumber+NumberType.h"
#import "SDLAddCommand.h"
#import "SDLAddCommandResponse.h"
#import "SDLAddSubMenu.h"
#import "SDLAddSubMenuResponse.h"
#import "SDLAirbagStatus.h"
#import "SDLAlert.h"
#import "SDLAlertManeuver.h"
#import "SDLAlertManeuverResponse.h"
#import "SDLAlertResponse.h"
#import "SDLButtonPressResponse.h"
#import "SDLAmbientLightStatus.h"
#import "SDLAppHMIType.h"
#import "SDLAppInfo.h"
#import "SDLAppInterfaceUnregisteredReason.h"
#import "SDLArtwork.h"
#import "SDLAudioPassThruCapabilities.h"
#import "SDLAudioStreamingState.h"
#import "SDLAudioStreamManager.h"
#import "SDLAudioStreamManagerDelegate.h"
#import "SDLStreamingAudioManagerType.h"
#import "SDLAudioType.h"
#import "SDLBeltStatus.h"
#import "SDLBitsPerSample.h"
#import "SDLBodyInformation.h"
#import "SDLButtonCapabilities.h"
#import "SDLButtonEventMode.h"
#import "SDLButtonName.h"
#import "SDLButtonPress.h"
#import "SDLButtonPressMode.h"
#import "SDLCarModeStatus.h"
#import "SDLCarWindowViewController.h"
#import "SDLChangeRegistration.h"
#import "SDLChangeRegistrationResponse.h"
#import "SDLCharacterSet.h"
#import "SDLChoice.h"
#import "SDLClimateControlCapabilities.h"
#import "SDLClimateControlData.h"
#import "SDLClusterModeStatus.h"
#import "SDLCompassDirection.h"
#import "SDLComponentVolumeStatus.h"
#import "SDLConfiguration.h"
#import "SDLCreateInteractionChoiceSet.h"
#import "SDLCreateInteractionChoiceSetResponse.h"
#import "SDLDateTime.h"
#import "SDLDefrostZone.h"
#import "SDLDeleteCommand.h"
#import "SDLDeleteCommandResponse.h"
#import "SDLDeleteFile.h"
#import "SDLDeleteFileResponse.h"
#import "SDLDeleteInteractionChoiceSet.h"
#import "SDLDeleteInteractionChoiceSetResponse.h"
#import "SDLDeleteSubMenu.h"
#import "SDLDeleteSubMenuResponse.h"
#import "SDLDeliveryMode.h"
#import "SDLDeviceInfo.h"
#import "SDLDeviceLevelStatus.h"
#import "SDLDeviceStatus.h"
#import "SDLDiagnosticMessage.h"
#import "SDLDiagnosticMessageResponse.h"
#import "SDLDialNumber.h"
#import "SDLDialNumberResponse.h"
#import "SDLDIDResult.h"
#import "SDLDimension.h"
#import "SDLDisplayCapabilities.h"
#import "SDLDisplayType.h"
#import "SDLDriverDistractionState.h"
#import "SDLECallConfirmationStatus.h"
#import "SDLECallInfo.h"
#import "SDLEmergencyEvent.h"
#import "SDLEmergencyEventType.h"
#import "SDLEncodedSyncPData.h"
#import "SDLEncodedSyncPDataResponse.h"
#import "SDLEndAudioPassThru.h"
#import "SDLEndAudioPassThruResponse.h"
#import "SDLEnum.h"
#import "SDLErrorConstants.h"
#import "SDLFile.h"
#import "SDLFileManager.h"
#import "SDLFileManagerConstants.h"
#import "SDLFileType.h"
#import "SDLFuelCutoffStatus.h"
#import "SDLGenericResponse.h"
#import "SDLGetDTCs.h"
#import "SDLGetInteriorVehicleData.h"
#import "SDLGetDTCsResponse.h"
#import "SDLGetInteriorVehicleDataResponse.h"
#import "SDLGetSystemCapability.h"
#import "SDLGetSystemCapabilityResponse.h"
#import "SDLGetVehicleData.h"
#import "SDLGetVehicleDataResponse.h"
#import "SDLGetWayPoints.h"
#import "SDLGetWayPointsResponse.h"
#import "SDLGlobalProperty.h"
#import "SDLGPSData.h"
#import "SDLHapticRect.h"
#import "SDLHeadLampStatus.h"
#import "SDLHMICapabilities.h"
#import "SDLHMILevel.h"
#import "SDLHMIPermissions.h"
#import "SDLHMIZoneCapabilities.h"
#import "SDLIgnitionStableStatus.h"
#import "SDLIgnitionStatus.h"
#import "SDLImage.h"
#import "SDLImageField.h"
#import "SDLImageFieldName.h"
#import "SDLImageResolution.h"
#import "SDLImageType.h"
#import "SDLInteractionMode.h"
#import "SDLKeyboardEvent.h"
#import "SDLKeyboardLayout.h"
#import "SDLKeyboardProperties.h"
#import "SDLKeypressMode.h"
#import "SDLLanguage.h"
#import "SDLLayoutMode.h"
#import "SDLLifecycleConfiguration.h"
#import "SDLLifecycleConfigurationUpdate.h"
#import "SDLListFiles.h"
#import "SDLListFilesResponse.h"
#import "SDLLocationCoordinate.h"
#import "SDLLocationDetails.h"
#import "SDLLockScreenConfiguration.h"
#import "SDLLockScreenStatus.h"
#import "SDLLockScreenViewController.h"
#import "SDLLogConfiguration.h"
#import "SDLLogConstants.h"
#import "SDLLogFileModule.h"
#import "SDLLogFilter.h"
#import "SDLLogMacros.h"
#import "SDLLogManager.h"
#import "SDLLogTarget.h"
#import "SDLLogTargetAppleSystemLog.h"
#import "SDLLogTargetFile.h"
#import "SDLLogTargetOSLog.h"
#import "SDLMacros.h"
#import "SDLMaintenanceModeStatus.h"
#import "SDLManager.h"
#import "SDLManagerDelegate.h"
#import "SDLMediaClockFormat.h"
#import "SDLMenuCell.h"
#import "SDLMenuParams.h"
#import "SDLMetadataTags.h"
#import "SDLMetadataType.h"
#import "SDLModuleData.h"
#import "SDLModuleType.h"
#import "SDLMyKey.h"
#import "SDLNavigationCapability.h"
#import "SDLNotificationConstants.h"
#import "SDLOasisAddress.h"
#import "SDLOnAppInterfaceUnregistered.h"
#import "SDLOnAudioPassThru.h"
#import "SDLOnButtonEvent.h"
#import "SDLOnButtonPress.h"
#import "SDLOnCommand.h"
#import "SDLOnDriverDistraction.h"
#import "SDLOnEncodedSyncPData.h"
#import "SDLOnHashChange.h"
#import "SDLOnInteriorVehicleData.h"
#import "SDLOnHMIStatus.h"
#import "SDLOnKeyboardInput.h"
#import "SDLOnLanguageChange.h"
#import "SDLOnLockScreenStatus.h"
#import "SDLOnPermissionsChange.h"
#import "SDLOnSyncPData.h"
#import "SDLOnSystemRequest.h"
#import "SDLOnTBTClientState.h"
#import "SDLOnTouchEvent.h"
#import "SDLOnVehicleData.h"
#import "SDLOnWayPointChange.h"
#import "SDLParameterPermissions.h"
#import "SDLPerformAudioPassThru.h"
#import "SDLPerformAudioPassThruResponse.h"
#import "SDLPerformInteraction.h"
#import "SDLPerformInteractionResponse.h"
#import "SDLPermissionConstants.h"
#import "SDLPermissionItem.h"
#import "SDLPermissionManager.h"
#import "SDLPermissionStatus.h"
#import "SDLPhoneCapability.h"
#import "SDLPinchGesture.h"
#import "SDLPowerModeQualificationStatus.h"
#import "SDLPowerModeStatus.h"
#import "SDLPredefinedLayout.h"
#import "SDLPrerecordedSpeech.h"
#import "SDLPresetBankCapabilities.h"
#import "SDLPrimaryAudioSource.h"
#import "SDLPRNDL.h"
#import "SDLPutFile.h"
#import "SDLPutFileResponse.h"
#import "SDLRadioBand.h"
#import "SDLRadioControlCapabilities.h"
#import "SDLRadioControlData.h"
#import "SDLRadioState.h"
#import "SDLReadDID.h"
#import "SDLRectangle.h"
#import "SDLReadDIDResponse.h"
#import "SDLRegisterAppInterface.h"
#import "SDLRegisterAppInterfaceResponse.h"
#import "SDLRemoteControlCapabilities.h"
#import "SDLRequestType.h"
#import "SDLResetGlobalProperties.h"
#import "SDLResetGlobalPropertiesResponse.h"
#import "SDLResult.h"
#import "SDLRDSData.h"
#import "SDLRPCMessage.h"
#import "SDLRPCMessageType.h"
#import "SDLRPCNotification.h"
#import "SDLRPCNotificationNotification.h"
#import "SDLRPCRequest.h"
#import "SDLRPCResponse.h"
#import "SDLRPCResponseNotification.h"
#import "SDLRPCStruct.h"
#import "SDLSamplingRate.h"
#import "SDLScreenParams.h"
#import "SDLScreenManager.h"
#import "SDLScrollableMessage.h"
#import "SDLScrollableMessageResponse.h"
#import "SDLSecurityType.h"
#import "SDLSendHapticData.h"
#import "SDLSendHapticDataResponse.h"
#import "SDLSendLocation.h"
#import "SDLSendLocationResponse.h"
#import "SDLSetAppIcon.h"
#import "SDLSetAppIconResponse.h"
#import "SDLSetDisplayLayout.h"
#import "SDLSetDisplayLayoutResponse.h"
#import "SDLSetGlobalProperties.h"
#import "SDLSetInteriorVehicleData.h"
#import "SDLSetGlobalPropertiesResponse.h"
#import "SDLSetInteriorVehicleDataResponse.h"
#import "SDLSetMediaClockTimer.h"
#import "SDLSetMediaClockTimerResponse.h"
#import "SDLShow.h"
#import "SDLShowConstantTBT.h"
#import "SDLShowConstantTBTResponse.h"
#import "SDLShowResponse.h"
#import "SDLSingleTireStatus.h"
#import "SDLSlider.h"
#import "SDLSliderResponse.h"
#import "SDLSoftButton.h"
#import "SDLSoftButtonCapabilities.h"
#import "SDLSoftButtonObject.h"
#import "SDLSoftButtonState.h"
#import "SDLSoftButtonType.h"
#import "SDLSpeak.h"
#import "SDLSpeakResponse.h"
#import "SDLSpeechCapabilities.h"
#import "SDLStartTime.h"
#import "SDLStreamingMediaConfiguration.h"
#import "SDLStreamingMediaManager.h"
#import "SDLStreamingMediaManagerConstants.h"
#import "SDLStreamingMediaManagerDataSource.h"
#import "SDLSubscribeButton.h"
#import "SDLSubscribeButtonResponse.h"
#import "SDLSubscribeVehicleData.h"
#import "SDLSubscribeVehicleDataResponse.h"
#import "SDLSubscribeWayPoints.h"
#import "SDLSubscribeWayPointsResponse.h"
#import "SDLSyncMsgVersion.h"
#import "SDLSyncPData.h"
#import "SDLSyncPDataResponse.h"
#import "SDLSystemAction.h"
#import "SDLSystemCapability.h"
#import "SDLSystemCapabilityManager.h"
#import "SDLSystemCapabilityType.h"
#import "SDLSystemContext.h"
#import "SDLTBTState.h"
#import "SDLTemperature.h"
#import "SDLTemperatureUnit.h"
#import "SDLTextAlignment.h"
#import "SDLTextField.h"
#import "SDLTextFieldName.h"
#import "SDLTimerMode.h"
#import "SDLTireStatus.h"
#import "SDLTouch.h"
#import "SDLTouchCoord.h"
#import "SDLTouchEvent.h"
#import "SDLTouchEventCapabilities.h"
#import "SDLTouchManager.h"
#import "SDLTouchManagerDelegate.h"
#import "SDLTouchType.h"
#import "SDLTriggerSource.h"
#import "SDLTTSChunk.h"
#import "SDLTurn.h"
#import "SDLUnregisterAppInterface.h"
#import "SDLUnregisterAppInterfaceResponse.h"
#import "SDLUnsubscribeButton.h"
#import "SDLUnsubscribeButtonResponse.h"
#import "SDLUnsubscribeVehicleData.h"
#import "SDLUnsubscribeVehicleDataResponse.h"
#import "SDLUnsubscribeWayPoints.h"
#import "SDLUnsubscribeWayPointsResponse.h"
#import "SDLUpdateMode.h"
#import "SDLUpdateTurnList.h"
#import "SDLUpdateTurnListResponse.h"
#import "SDLVehicleDataActiveStatus.h"
#import "SDLVehicleDataEventStatus.h"
#import "SDLVehicleDataNotificationStatus.h"
#import "SDLVehicleDataResult.h"
#import "SDLVehicleDataResultCode.h"
#import "SDLVehicleDataStatus.h"
#import "SDLVehicleDataType.h"
#import "SDLVentilationMode.h"
#import "SDLVehicleType.h"
#import "SDLVideoStreamingCapability.h"
#import "SDLVideoStreamingCodec.h"
#import "SDLVideoStreamingFormat.h"
#import "SDLVideoStreamingProtocol.h"
#import "SDLVoiceCommand.h"
#import "SDLVrCapabilities.h"
#import "SDLVrHelpItem.h"
#import "SDLWarningLightStatus.h"
#import "SDLWayPointType.h"
#import "SDLWiperStatus.h"
#import "SmartDeviceLink.h"

FOUNDATION_EXPORT double SmartDeviceLinkVersionNumber;
FOUNDATION_EXPORT const unsigned char SmartDeviceLinkVersionString[];

