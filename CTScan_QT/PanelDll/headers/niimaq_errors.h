//////////////////////////////////////////////////////////////////////////////
//
//  Title     : niimaq_errors.h
//  Project   : NI-IMAQ
//  Platforms : All
//  Copyright : National Instruments.  All Rights Reserved.
//  Access    : Public
//  Purpose   : Error codes for NI-IMAQ.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef NIIMAQ_ERRORS_H
#define NIIMAQ_ERRORS_H

#ifndef IMG_ERR_GOOD
    #define IMG_ERR_GOOD 0 // No error
#endif

//----------------------------------------------------------------------------
//  New Error codes (3.0)
//----------------------------------------------------------------------------
#define IMG_ERR_FIRST_ERROR                                   0xBFF60001 // (-1074397183)
#define IMG_ERR_NOT_SUPPORTED                                 0xBFF60001 // (-1074397183) NI-IMAQ cannot perform the requested operation.
#define IMG_ERR_SYSTEM_MEMORY_FULL                            0xBFF60003 // (-1074397181) Not enough memory to perform the operation.
#define IMG_ERR_BUFFER_SIZE_TOO_SMALL                         0xBFF6000E // (-1074397170) Buffer size used is too small for minimum acquisition frame.
#define IMG_ERR_BUFFER_LIST_NOT_LOCKED                        0xBFF60013 // (-1074397165) Buffer list is not locked for this acquisition.
#define IMG_ERR_BAD_INTERFACE_FILE                            0xBFF60015 // (-1074397163) The passed in interface or session is invalid.
#define IMG_ERR_BAD_USER_RECT                                 0xBFF60017 // (-1074397161) Region of interest is larger than the acquisition area.
#define IMG_ERR_BAD_CAMERA_FILE                               0xBFF60018 // (-1074397160) Camera file is missing or corrupted.
#define IMG_ERR_NO_BUFFERS_CONFIGURED                         0xBFF6001A // (-1074397158) No buffers configured for session.
#define IMG_ERR_BAD_BUFFER_LIST_FINAL_COMMAND                 0xBFF6001B // (-1074397157) Buffer list does not contain a valid final command.
#define IMG_ERR_BAD_BUFFER_LIST_COMMAND                       0xBFF6001C // (-1074397156) Buffer list contains an invalid command.
#define IMG_ERR_BAD_BUFFER_POINTER                            0xBFF6001D // (-1074397155) One or more of the buffers in the buffer list is not configured.
#define IMG_ERR_BOARD_NOT_RUNNING                             0xBFF6001E // (-1074397154) No acquisition in progress.
#define IMG_ERR_VIDEO_LOCK                                    0xBFF6001F // (-1074397153) Cannot detect recognizable video source.
#define IMG_ERR_BOARD_RUNNING                                 0xBFF60021 // (-1074397151) Cannot perform request; acquisition currently in progress.
#define IMG_ERR_TIMEOUT                                       0xBFF60022 // (-1074397150) A timeout error occurred while waiting for the specified event. If waiting for an image, verify that all video data is acquired within the timeout period. If waiting for a signal, verify that the signal assertion occurs within the timeout period.
#define IMG_ERR_ZERO_BUFFER_SIZE                              0xBFF60024 // (-1074397148) The buffer has a size of zero.
#define IMG_ERR_NO_INTERFACE_FOUND                            0xBFF60027 // (-1074397145) No interface found.
#define IMG_ERR_FIFO_OVERFLOW                                 0xBFF6002C // (-1074397140) FIFO overflow caused acquisition to halt.
#define IMG_ERR_MEMORY_PAGE_LOCK_FAULT                        0xBFF6002D // (-1074397139) Operating system denied request to lock down memory.
#define IMG_ERR_BAD_CAMERA_TYPE                               0xBFF60034 // (-1074397132) This camera type is not supported by this hardware.
#define IMG_ERR_BAD_CLOCK_FREQUENCY                           0xBFF60038 // (-1074397128) Bad clock frequency.
#define IMG_ERR_HARDWARE_NOT_CAPABLE                          0xBFF6003A // (-1074397126) Hardware not capable of supporting this operation.
#define IMG_ERR_ATTRIBUTE_NOT_SETTABLE                        0xBFF60044 // (-1074397116) This attribute cannot be set.
#define IMG_ERR_ONBOARD_MEMORY_FULL                           0xBFF6004D // (-1074397107) Not enough onboard memory to perform the operation.
#define IMG_ERR_BUFFER_NOT_RELEASED                           0xBFF60051 // (-1074397103) This buffer is currently protected. Release it to allow new data to be written.
#define IMG_ERR_BAD_LUT_TYPE                                  0xBFF60052 // (-1074397102) The LUT type is invalid.
#define IMG_ERR_ATTRIBUTE_NOT_READABLE                        0xBFF60053 // (-1074397101) The selected attribute is not readable.
#define IMG_ERR_BOARD_NOT_SUPPORTED                           0xBFF60054 // (-1074397100) This version of NI-IMAQ does not support this device.
#define IMG_ERR_BAD_FRAME_FIELD                               0xBFF60055 // (-1074397099) The value of IMG_ATTR_FRAME_FIELD is invalid.
#define IMG_ERR_INVALID_ATTRIBUTE                             0xBFF60056 // (-1074397098) The requested attribute is invalid.
#define IMG_ERR_BAD_LINE_MAP                                  0xBFF60057 // (-1074397097) The physical data lines are incorrectly mapped to bit values.
#define IMG_ERR_BAD_CHANNEL                                   0xBFF60059 // (-1074397095) The requested channel is invalid for this device.
#define IMG_ERR_BAD_CHROMA_FILTER                             0xBFF6005A // (-1074397094) The value of IMG_ATTR_CHROMA_FILTER is invalid.
#define IMG_ERR_BAD_SCALE                                     0xBFF6005B // (-1074397093) The value of IMG_ATTR_HSCALE or IMG_ATTR_VSCALE is invalid.
#define IMG_ERR_BAD_TRIGGER_MODE                              0xBFF6005D // (-1074397091) The requested triggering mode is invalid.
#define IMG_ERR_BAD_CLAMP_START                               0xBFF6005E // (-1074397090) The clamp start value is invalid.
#define IMG_ERR_BAD_CLAMP_STOP                                0xBFF6005F // (-1074397089) The requested clamp stop value is invalid.
#define IMG_ERR_BAD_BRIGHTNESS                                0xBFF60060 // (-1074397088) The requested brightness level is out of range.
#define IMG_ERR_BAD_CONTRAST                                  0xBFF60061 // (-1074397087) The requested contrast level is out of range.
#define IMG_ERR_BAD_SATURATION                                0xBFF60062 // (-1074397086) The requested saturation level is out of range.
#define IMG_ERR_BAD_TINT                                      0xBFF60063 // (-1074397085) The requested tint level is out of range.
#define IMG_ERR_BAD_HUE_OFF_ANGLE                             0xBFF60064 // (-1074397084) The requested hue offset angle is out of range.
#define IMG_ERR_BAD_ACQUIRE_FIELD                             0xBFF60065 // (-1074397083) The field requested to be acquired is invalid.
#define IMG_ERR_BAD_LUMA_BANDWIDTH                            0xBFF60066 // (-1074397082) The requested luma bandwidth value is invalid.
#define IMG_ERR_BAD_LUMA_COMB                                 0xBFF60067 // (-1074397081) The requested luma comb setting is invalid.
#define IMG_ERR_BAD_CHROMA_PROCESS                            0xBFF60068 // (-1074397080) The requested chroma processing value is invalid.
#define IMG_ERR_BAD_CHROMA_BANDWIDTH                          0xBFF60069 // (-1074397079) The requested chroma bandwidth value is invalid.
#define IMG_ERR_BAD_CHROMA_COMB                               0xBFF6006A // (-1074397078) The requested chroma comb setting value is invalid.
#define IMG_ERR_BAD_RGB_CORING                                0xBFF6006B // (-1074397077) The requested minimum level of saturation (coring) for the RGB color space is invalid.
#define IMG_ERR_BAD_HUE_REPLACE_VALUE                         0xBFF6006C // (-1074397076) The requested HSL hue replacement value is out of range.
#define IMG_ERR_BAD_RED_GAIN                                  0xBFF6006D // (-1074397075) The requested red gain value is out of range.
#define IMG_ERR_BAD_GREEN_GAIN                                0xBFF6006E // (-1074397074) The requested green gain value is out of range.
#define IMG_ERR_BAD_BLUE_GAIN                                 0xBFF6006F // (-1074397073) The requested blue gain value is out of range.
#define IMG_ERR_BAD_START_FIELD                               0xBFF60070 // (-1074397072) The requested start field value is invalid.
#define IMG_ERR_BAD_TAP_DIRECTION                             0xBFF60071 // (-1074397071) The direction of the tap scan is invalid.
#define IMG_ERR_BAD_MAX_IMAGE_RECT                            0xBFF60072 // (-1074397070) The maximum image rectangle value is invalid.
#define IMG_ERR_BAD_TAP_TYPE                                  0xBFF60073 // (-1074397069) The tap configuration is invalid.
#define IMG_ERR_BAD_SYNC_RECT                                 0xBFF60074 // (-1074397068) The synchronization rectangle is invalid.
#define IMG_ERR_BAD_ACQWINDOW_RECT                            0xBFF60075 // (-1074397067) The requested acquisition window is invalid.
#define IMG_ERR_BAD_HSL_CORING                                0xBFF60076 // (-1074397066) The requested minimum level of saturation (coring) for the HSL color space is out of range.
#define IMG_ERR_BAD_TAP_0_VALID_RECT                          0xBFF60077 // (-1074397065) The rectangle defined for Tap 0 is invalid.
#define IMG_ERR_BAD_TAP_1_VALID_RECT                          0xBFF60078 // (-1074397064) The rectangle defined for Tap 1 is invalid.
#define IMG_ERR_BAD_TAP_2_VALID_RECT                          0xBFF60079 // (-1074397063) The rectangle defined for Tap 2 is invalid.
#define IMG_ERR_BAD_TAP_3_VALID_RECT                          0xBFF6007A // (-1074397062) The rectangle defined for Tap 3 is invalid.
#define IMG_ERR_BAD_TAP_RECT                                  0xBFF6007B // (-1074397061) The tap rectangle is invalid.
#define IMG_ERR_BAD_NUM_TAPS                                  0xBFF6007C // (-1074397060) The number of taps is invalid.
#define IMG_ERR_BAD_TAP_NUM                                   0xBFF6007D // (-1074397059) The tap number is invalid.
#define IMG_ERR_BAD_QUAD_NUM                                  0xBFF6007E // (-1074397058) The scarab quadrant number is invalid.
#define IMG_ERR_BAD_NUM_DATA_LINES                            0xBFF6007F // (-1074397057) The number of data lines requested is invalid for this image acquisition device.
#define IMG_ERR_BAD_BITS_PER_COMPONENT                        0xBFF60080 // (-1074397056) The bits-per-component value is invalid.
#define IMG_ERR_BAD_NUM_COMPONENTS                            0xBFF60081 // (-1074397055) The number of components value is invalid.
#define IMG_ERR_BAD_BIN_THRESHOLD_LOW                         0xBFF60082 // (-1074397054) The requested lower binary threshold value is out of range.
#define IMG_ERR_BAD_BIN_THRESHOLD_HIGH                        0xBFF60083 // (-1074397053) The requested upper binary threshold value is out of range.
#define IMG_ERR_BAD_BLACK_REF_VOLT                            0xBFF60084 // (-1074397052) The requested black reference voltage value is out of range.
#define IMG_ERR_BAD_WHITE_REF_VOLT                            0xBFF60085 // (-1074397051) The requested white reference voltage value is out of range.
#define IMG_ERR_BAD_FREQ_STD                                  0xBFF60086 // (-1074397050) The video standard frequency value selected for the 6431 chip is invalid.
#define IMG_ERR_BAD_HDELAY                                    0xBFF60087 // (-1074397049) The HDELAY value is out of range.
#define IMG_ERR_BAD_LOCK_SPEED                                0xBFF60088 // (-1074397048) The setting for lock speed is invalid.
#define IMG_ERR_BAD_BUFFER_LIST                               0xBFF60089 // (-1074397047) The buffer list is invalid.
#define IMG_ERR_BOARD_NOT_INITIALIZED                         0xBFF6008A // (-1074397046) The image aquisition device is not yet initialized.
#define IMG_ERR_BAD_PCLK_SOURCE                               0xBFF6008B // (-1074397045) The requested pixel clock source is invalid for this image acquisition device.
#define IMG_ERR_BAD_VIDEO_LOCK_CHANNEL                        0xBFF6008C // (-1074397044) The selected video timing signal source is invalid for this image acquisition device.
#define IMG_ERR_BAD_LOCK_SEL                                  0xBFF6008D // (-1074397043) The selected lock mode is invalid.
#define IMG_ERR_BAD_BAUD_RATE                                 0xBFF6008E // (-1074397042) The selected baud rate is invalid for this image acquisition device.
#define IMG_ERR_BAD_STOP_BITS                                 0xBFF6008F // (-1074397041) The requested serial stop bits setting is invalid for this image acquisition device.
#define IMG_ERR_BAD_DATA_BITS                                 0xBFF60090 // (-1074397040) The requested serial data bits setting is invalid for this image acquisition device.
#define IMG_ERR_BAD_PARITY                                    0xBFF60091 // (-1074397039) The requested serial parity setting is invalid for this image acquisition device.
#define IMG_ERR_TERM_STRING_NOT_FOUND                         0xBFF60092 // (-1074397038) The requested serial termination string was not found in the returned buffer.
#define IMG_ERR_SERIAL_READ_TIMEOUT                           0xBFF60093 // (-1074397037) The serial read did not complete within the specified timeout period.
#define IMG_ERR_SERIAL_WRITE_TIMEOUT                          0xBFF60094 // (-1074397036) The serial write operation could not execute within the specified timeout period.
#define IMG_ERR_BAD_SYNCHRONICITY                             0xBFF60095 // (-1074397035) The async setting in imgSessionAcquire is invalid.
#define IMG_ERR_BAD_INTERLACING_CONFIG                        0xBFF60096 // (-1074397034) This tap configuration cannot be interlaced.
#define IMG_ERR_BAD_CHIP_CODE                                 0xBFF60098 // (-1074397032) The requested chip code is invalid. Could not find a matching chip.
#define IMG_ERR_LUT_NOT_PRESENT                               0xBFF60099 // (-1074397031) The LUT chip does not exist on this image acquisition device.
#define IMG_ERR_DSPFILTER_NOT_PRESENT                         0xBFF6009A // (-1074397030) The DSP filter does not exist on this image acquisition device.
#define IMG_ERR_DEVICE_NOT_FOUND                              0xBFF6009B // (-1074397029) The image acquisition device was not found.
#define IMG_ERR_ONBOARD_MEM_CONFIG                            0xBFF6009C // (-1074397028) An error occurred during onboard memory configuration.
#define IMG_ERR_BAD_POINTER                                   0xBFF6009D // (-1074397027) The pointer provided is either NULL when it should not be, or is non-NULL when it should be NULL.
#define IMG_ERR_BAD_BUFFER_LIST_INDEX                         0xBFF6009E // (-1074397026) The requested buffer list index is invalid.
#define IMG_ERR_INVALID_BUFFER_ATTRIBUTE                      0xBFF6009F // (-1074397025) The requested buffer attribute is invalid.
#define IMG_ERR_INVALID_BUFFER_PTR                            0xBFF600A0 // (-1074397024) The requested buffer was not created by the NI-IMAQ driver software.
#define IMG_ERR_BUFFER_LIST_ALREADY_LOCKED                    0xBFF600A1 // (-1074397023) This image acquisition device already has a buffer list locked down in memory.
#define IMG_ERR_BAD_DEVICE_TYPE                               0xBFF600A2 // (-1074397022) The type of image acquisition device requested is invalid.
#define IMG_ERR_BAD_BAR_SIZE                                  0xBFF600A3 // (-1074397021) The size of one or more Base Address Register windows is incorrect.
#define IMG_ERR_NO_VALID_COUNTER_RECT                         0xBFF600A5 // (-1074397019) The selected region of interest is not valid for the camera tap configuration.
#define IMG_ERR_ACQ_STOPPED                                   0xBFF600A6 // (-1074397018) The wait terminated because the acquisition stopped.
#define IMG_ERR_BAD_TRIGGER_ACTION                            0xBFF600A7 // (-1074397017) The requested trigger action is invalid.
#define IMG_ERR_BAD_TRIGGER_POLARITY                          0xBFF600A8 // (-1074397016) The trigger polarity is invalid.
#define IMG_ERR_BAD_TRIGGER_NUMBER                            0xBFF600A9 // (-1074397015) The requested trigger line is invalid. Please verify that this trigger line exists and is properly connected to your device.
#define IMG_ERR_BUFFER_NOT_AVAILABLE                          0xBFF600AA // (-1074397014) The requested buffer has been overwritten and is no longer available.
#define IMG_ERR_BAD_PULSE_ID                                  0xBFF600AC // (-1074397012) The pulse ID is invalid.
#define IMG_ERR_BAD_PULSE_TIMEBASE                            0xBFF600AD // (-1074397011) The requested timebase for the pulse is invalid.
#define IMG_ERR_BAD_PULSE_GATE                                0xBFF600AE // (-1074397010) The gate signal for the pulse is invalid.
#define IMG_ERR_BAD_PULSE_GATE_POLARITY                       0xBFF600AF // (-1074397009) The polarity of the pulse gate signal is invalid.
#define IMG_ERR_BAD_PULSE_OUTPUT                              0xBFF600B0 // (-1074397008) The output signal for the pulse is invalid.
#define IMG_ERR_BAD_PULSE_OUTPUT_POLARITY                     0xBFF600B1 // (-1074397007) The requested polarity of the pulse output signal is invalid.
#define IMG_ERR_BAD_PULSE_MODE                                0xBFF600B2 // (-1074397006) The requested pulse mode is invalid.
#define IMG_ERR_NOT_ENOUGH_RESOURCES                          0xBFF600B3 // (-1074397005) There are not enough system resources to complete the requested option.
#define IMG_ERR_INVALID_RESOURCE                              0xBFF600B4 // (-1074397004) The requested resource is invalid.
#define IMG_ERR_BAD_FVAL_ENABLE                               0xBFF600B5 // (-1074397003) The selected FVAL enable mode is invalid.
#define IMG_ERR_BAD_WRITE_ENABLE_MODE                         0xBFF600B6 // (-1074397002) The specified combination of enable lines is invalid.
#define IMG_ERR_COMPONENT_MISMATCH                            0xBFF600B7 // (-1074397001) Internal Error: The installed components of the NI-IMAQ driver software are incompatible. Reinstall NI-IMAQ.
#define IMG_ERR_FPGA_PROGRAMMING_FAILED                       0xBFF600B8 // (-1074397000) Internal Error: The attempt to download the program to an FPGA was unsuccessful.
#define IMG_ERR_CONTROL_FPGA_FAILED                           0xBFF600B9 // (-1074396999) Internal Error: The control FPGA did not initialize properly.
#define IMG_ERR_CHIP_NOT_READABLE                             0xBFF600BA // (-1074396998) Internal Error: Attempted to read a write-only chip.
#define IMG_ERR_CHIP_NOT_WRITABLE                             0xBFF600BB // (-1074396997) Internal Error: Attempted to write to a read-only chip.
#define IMG_ERR_I2C_BUS_FAILED                                0xBFF600BC // (-1074396996) Internal Error: The I2C bus did not respond correctly.
#define IMG_ERR_DEVICE_IN_USE                                 0xBFF600BD // (-1074396995) The requested image acquisition device is already in use.
#define IMG_ERR_BAD_TAP_DATALANES                             0xBFF600BE // (-1074396994) The requested data lanes on a particular tap are invalid.
#define IMG_ERR_BAD_VIDEO_GAIN                                0xBFF600BF // (-1074396993) The requested video gain value is out of range.
#define IMG_ERR_VHA_MODE_NOT_ALLOWED                          0xBFF600C0 // (-1074396992) The current device configuration does not allow VHA mode.
#define IMG_ERR_BAD_TRACKING_SPEED                            0xBFF600C1 // (-1074396991) The color video tracking speed is invalid.
#define IMG_ERR_BAD_COLOR_INPUT_SELECT                        0xBFF600C2 // (-1074396990) The selected input connector is not valid.
#define IMG_ERR_BAD_HAV_OFFSET                                0xBFF600C3 // (-1074396989) The offset value for the Horizontal Active Video color decoder setting is invalid.
#define IMG_ERR_BAD_HS1_OFFSET                                0xBFF600C4 // (-1074396988) The Horizontal Sync 1offset value for the color decoder is invalid.
#define IMG_ERR_BAD_HS2_OFFSET                                0xBFF600C5 // (-1074396987) The Horizontal Sync 2 offset value for the color decoder is invalid.
#define IMG_ERR_BAD_IF_CHROMA                                 0xBFF600C6 // (-1074396986) The chroma IF compensation setting is invalid.
#define IMG_ERR_BAD_COLOR_OUTPUT_FORMAT                       0xBFF600C7 // (-1074396985) The color output format is invalid.
#define IMG_ERR_BAD_SAMSUNG_SCHCMP                            0xBFF600C8 // (-1074396984) The phase constant specified for the color decoder is invalid.
#define IMG_ERR_BAD_SAMSUNG_CDLY                              0xBFF600C9 // (-1074396983) The chroma path group delay setting is invalid.
#define IMG_ERR_BAD_SECAM_DETECT                              0xBFF600CA // (-1074396982) The SECAM detection method is invalid.
#define IMG_ERR_BAD_FSC_DETECT                                0xBFF600CB // (-1074396981) The FSC detection method is invalid.
#define IMG_ERR_BAD_SAMSUNG_CFTC                              0xBFF600CC // (-1074396980) The chroma frequency tracking time constant is invalid.
#define IMG_ERR_BAD_SAMSUNG_CGTC                              0xBFF600CD // (-1074396979) The chroma gain tracking time constant setting is invalid.
#define IMG_ERR_BAD_SAMSUNG_SAMPLE_RATE                       0xBFF600CE // (-1074396978) The pixel sampling rate is invalid.
#define IMG_ERR_BAD_SAMSUNG_VSYNC_EDGE                        0xBFF600CF // (-1074396977) The requested VSYNC edge to synchronize with is invalid.
#define IMG_ERR_SAMSUNG_LUMA_GAIN_CTRL                        0xBFF600D0 // (-1074396976) The method used to control the gain setting for luminance is invalid.
#define IMG_ERR_BAD_SET_COMB_COEF                             0xBFF600D1 // (-1074396975) The chrominance comb coefficients setting is invalid.
#define IMG_ERR_SAMSUNG_CHROMA_TRACK                          0xBFF600D2 // (-1074396974) The method used to track chrominance is invalid.
#define IMG_ERR_SAMSUNG_DROP_LINES                            0xBFF600D3 // (-1074396973) The algorithm for dropping video lines is invalid.
#define IMG_ERR_VHA_OPTIMIZATION_NOT_ALLOWED                  0xBFF600D4 // (-1074396972) VHA optimization is not applicable for the current configuration.
#define IMG_ERR_BAD_PG_TRANSITION                             0xBFF600D5 // (-1074396971) A pattern generation is invalid.
#define IMG_ERR_TOO_MANY_PG_TRANSITIONS                       0xBFF600D6 // (-1074396970) The number of pattern generation transitions exceeds the maximum allowed for the selected image acquisition device.
#define IMG_ERR_BAD_CL_DATA_CONFIG                            0xBFF600D7 // (-1074396969) The data configuration for the channel link chip is invalid.
#define IMG_ERR_BAD_OCCURRENCE                                0xBFF600D8 // (-1074396968) The requested occurrence is invalid.
#define IMG_ERR_BAD_PG_MODE                                   0xBFF600D9 // (-1074396967) The pattern generation mode is invalid.
#define IMG_ERR_BAD_PG_SOURCE                                 0xBFF600DA // (-1074396966) The pattern generation source signal is invalid.
#define IMG_ERR_BAD_PG_GATE                                   0xBFF600DB // (-1074396965) The pattern generation gate signal is invalid.
#define IMG_ERR_BAD_PG_GATE_POLARITY                          0xBFF600DC // (-1074396964) The pattern generation gate polarity is invalid.
#define IMG_ERR_BAD_PG_WAVEFORM_INITIAL_STATE                 0xBFF600DD // (-1074396963) The initial state for the pattern generation waveform is invalid.
#define IMG_ERR_INVALID_CAMERA_ATTRIBUTE                      0xBFF600DE // (-1074396962) The requested camera attribute is invalid.
#define IMG_ERR_BOARD_CLOSED                                  0xBFF600DF // (-1074396961) The request failed because the device is closed.
#define IMG_ERR_FILE_NOT_FOUND                                0xBFF600E0 // (-1074396960) The requested file could not be found.
#define IMG_ERR_BAD_1409_DSP_FILE                             0xBFF600E1 // (-1074396959) The dspfilter1409.bin file is corrupt or missing.
#define IMG_ERR_BAD_SCARABXCV200_32_FILE                      0xBFF600E2 // (-1074396958) The scarabXCV200.bin file is corrupt or missing.
#define IMG_ERR_BAD_SCARABXCV200_16_FILE                      0xBFF600E3 // (-1074396957) The scarab16bit.bin file is corrupt or missing.
#define IMG_ERR_BAD_CAMERA_LINK_FILE                          0xBFF600E4 // (-1074396956) The Camera Link FPGA bin file is corrupt or missing.
#define IMG_ERR_BAD_1411_CSC_FILE                             0xBFF600E5 // (-1074396955) The colorspace.bin file is corrupt or missing.
#define IMG_ERR_BAD_ERROR_CODE                                0xBFF600E6 // (-1074396954) The error code passed into imgShowError is unknown.
#define IMG_ERR_DRIVER_TOO_OLD                                0xBFF600E7 // (-1074396953) The image acquisition device requires a newer version of the NI-IMAQ driver software.
#define IMG_ERR_INSTALLATION_CORRUPT                          0xBFF600E8 // (-1074396952) The NI-IMAQ driver software installation is corrupt.
#define IMG_ERR_NO_ONBOARD_MEMORY                             0xBFF600E9 // (-1074396951) NI-IMAQ cannot perform an onboard acquisition because there is no onboard memory.
#define IMG_ERR_BAD_BAYER_PATTERN                             0xBFF600EA // (-1074396950) The Bayer pattern specified is invalid.
#define IMG_ERR_CANNOT_INITIALIZE_BOARD                       0xBFF600EB // (-1074396949) The image acquisition device is not operating correctly and cannot be initialized.
#define IMG_ERR_CALIBRATION_DATA_CORRUPT                      0xBFF600EC // (-1074396948) The stored calibration data has been corrupted.
#define IMG_ERR_DRIVER_FAULT                                  0xBFF600ED // (-1074396947) NI-IMAQ attempted to perform an illegal operation.
#define IMG_ERR_ADDRESS_OUT_OF_RANGE                          0xBFF600EE // (-1074396946) NI-IMAQ attempted to access a chip beyond the applicable addressable range.
#define IMG_ERR_ONBOARD_ACQUISITION                           0xBFF600EF // (-1074396945) The requested operation is not valid for onboard acquisitions.
#define IMG_ERR_NOT_AN_ONBOARD_ACQUISITION                    0xBFF600F0 // (-1074396944) The requested operation is valid only for onboard acquisitions.
#define IMG_ERR_BOARD_ALREADY_INITIALIZED                     0xBFF600F1 // (-1074396943) NI-IMAQ attempted to call an initialization function on an image acquisition device that was already initialized.
#define IMG_ERR_NO_SERIAL_PORT                                0xBFF600F2 // (-1074396942) The image acquisition device does not have a serial port. Serial functions are invalid.
#define IMG_ERR_BAD_VENABLE_GATING_MODE                       0xBFF600F3 // (-1074396941) The VENABLE gating mode selection is invalid.
#define IMG_ERR_BAD_1407_LUT_FILE                             0xBFF600F4 // (-1074396940) The lutfpga1407.bin file is corrupt or missing.
#define IMG_ERR_BAD_SYNC_DETECT_LEVEL                         0xBFF600F5 // (-1074396939) The synchronization signal detection level is out of range.
#define IMG_ERR_BAD_1405_GAIN_FILE                            0xBFF600F6 // (-1074396938) The gain1405.bin file is corrupt or missing.
#define IMG_ERR_CLAMP_DAC_NOT_PRESENT                         0xBFF600F7 // (-1074396937) The image acquisition device does not have a clamp DAC.
#define IMG_ERR_GAIN_DAC_NOT_PRESENT                          0xBFF600F8 // (-1074396936) The image acquisition device does not have a gain DAC.
#define IMG_ERR_REF_DAC_NOT_PRESENT                           0xBFF600F9 // (-1074396935) The image acquisition device does not have a reference DAC.
#define IMG_ERR_BAD_SCARABXC2S200_FILE                        0xBFF600FA // (-1074396934) The scarabXC2S200.bin file is corrupt or missing.
#define IMG_ERR_BAD_LUT_GAIN                                  0xBFF600FB // (-1074396933) The specified LUT gain is invalid.
#define IMG_ERR_BAD_MAX_BUF_LIST_ITER                         0xBFF600FC // (-1074396932) The requested number of buffer lists for an onboard acquisition is invalid.
#define IMG_ERR_BAD_PG_LINE_NUM                               0xBFF600FD // (-1074396931) The requested line number for pattern generation is invalid.
#define IMG_ERR_BAD_BITS_PER_PIXEL                            0xBFF600FE // (-1074396930) The requested number of bits per pixel is invalid.
#define IMG_ERR_TRIGGER_ALARM                                 0xBFF600FF // (-1074396929) Triggers are coming in too fast to handle them and maintain system responsiveness. Check for noise on your trigger line.
#define IMG_ERR_BAD_SCARABXC2S200_03052009_FILE               0xBFF60100 // (-1074396928) The scarabXC2S200_03052009.bin file is corrupt or missing.
#define IMG_ERR_LUT_CONFIG                                    0xBFF60101 // (-1074396927) Internal Error:  An error occurred while configuring the LUT.
#define IMG_ERR_CONTROL_FPGA_REQUIRES_NEWER_DRIVER            0xBFF60102 // (-1074396926) A firmware update has been applied to the device. The image acquisition device requires a newer version of the NI-IMAQ driver software to work with the update.
#define IMG_ERR_CONTROL_FPGA_PROGRAMMING_FAILED               0xBFF60103 // (-1074396925) An error occurred while updating the firmware on the device.
#define IMG_ERR_BAD_TRIGGER_SIGNAL_LEVEL                      0xBFF60104 // (-1074396924) The trigger line does not support the requested signaling level.
#define IMG_ERR_CAMERA_FILE_REQUIRES_NEWER_DRIVER             0xBFF60105 // (-1074396923) This camera file requires a newer version of NI-IMAQ.
#define IMG_ERR_DUPLICATED_BUFFER                             0xBFF60106 // (-1074396922) An image cannot be placed in the same buffer list more than once.
#define IMG_ERR_NO_ERROR                                      0xBFF60107 // (-1074396921) No error
#define IMG_ERR_INTERFACE_NOT_SUPPORTED                       0xBFF60108 // (-1074396920) The camera file does not support the current interface type.
#define IMG_ERR_BAD_PCLK_POLARITY                             0xBFF60109 // (-1074396919) The requested polarity for the pixel clock is invalid.
#define IMG_ERR_BAD_ENABLE_POLARITY                           0xBFF6010A // (-1074396918) The requested polarity for the enable line is invalid.
#define IMG_ERR_BAD_PCLK_SIGNAL_LEVEL                         0xBFF6010B // (-1074396917) The requested signaling level for the pixel clock is invalid.
#define IMG_ERR_BAD_ENABLE_SIGNAL_LEVEL                       0xBFF6010C // (-1074396916) The requested signaling level for the enable line is invalid.
#define IMG_ERR_BAD_DATA_SIGNAL_LEVEL                         0xBFF6010D // (-1074396915) The requested signaling level for the data lines is invalid.
#define IMG_ERR_BAD_CTRL_SIGNAL_LEVEL                         0xBFF6010E // (-1074396914) The requested signaling level for the control lines is invalid.
#define IMG_ERR_BAD_WINDOW_HANDLE                             0xBFF6010F // (-1074396913) The requested window handle is invalid.
#define IMG_ERR_CANNOT_WRITE_FILE                             0xBFF60110 // (-1074396912) Cannot open the requested file for writing.
#define IMG_ERR_CANNOT_READ_FILE                              0xBFF60111 // (-1074396911) Cannot open the requested file for reading.
#define IMG_ERR_BAD_SIGNAL_TYPE                               0xBFF60112 // (-1074396910) Cannot wait on the requested signal.
#define IMG_ERR_BAD_SAMPLES_PER_LINE                          0xBFF60113 // (-1074396909) The specified number of samples per line is invalid.
#define IMG_ERR_BAD_SAMPLES_PER_LINE_REF                      0xBFF60114 // (-1074396908) The specified reference value for samples per line is invalid.
#define IMG_ERR_USE_EXTERNAL_HSYNC                            0xBFF60115 // (-1074396907) The current video signal requires an external HSYNC to be used to lock the signal.
#define IMG_ERR_BUFFER_NOT_ALIGNED                            0xBFF60116 // (-1074396906) An image buffer is not properly aligned. All image buffers must be aligned to a 4-byte boundary.
#define IMG_ERR_ROWPIXELS_TOO_SMALL                           0xBFF60117 // (-1074396905) The number of pixels per row is less than the region of interest width.
#define IMG_ERR_ROWPIXELS_NOT_ALIGNED                         0xBFF60118 // (-1074396904) The number of pixels per row is not properly aligned. The total number of bytes per row must be aligned to a 4-byte boundary.
#define IMG_ERR_ROI_WIDTH_NOT_ALIGNED                         0xBFF60119 // (-1074396903) The ROI width is not properly aligned. The total number of bytes bounded by the ROI width must be aligned to a 4-byte boundary.
#define IMG_ERR_LINESCAN_NOT_ALLOWED                          0xBFF6011A // (-1074396902) Linescan mode is not valid for this tap configuration.
#define IMG_ERR_INTERFACE_FILE_REQUIRES_NEWER_DRIVER          0xBFF6011B // (-1074396901) This interface file requires a newer version of NI-IMAQ.
#define IMG_ERR_BAD_SKIP_COUNT                                0xBFF6011C // (-1074396900) The requested skip count value is out of range.
#define IMG_ERR_BAD_NUM_X_ZONES                               0xBFF6011D // (-1074396899) The number of X zones in the tap configuration of the camera is invalid.
#define IMG_ERR_BAD_NUM_Y_ZONES                               0xBFF6011E // (-1074396898) The number of Y zones in the tap configuration of the camera is invalid.
#define IMG_ERR_BAD_NUM_TAPS_PER_X_ZONE                       0xBFF6011F // (-1074396897) The number of taps per X zone in the tap configuration of the camera is invalid.
#define IMG_ERR_BAD_NUM_TAPS_PER_Y_ZONE                       0xBFF60120 // (-1074396896) The number of taps per Y zone in the tap configuration of the camera is invalid.
#define IMG_ERR_BAD_TEST_IMAGE_TYPE                           0xBFF60121 // (-1074396895) The requested test image type is invalid.
#define IMG_ERR_CANNOT_ACQUIRE_FROM_CAMERA                    0xBFF60122 // (-1074396894) This firmware is not capable of acquiring from a camera.
#define IMG_ERR_BAD_CTRL_LINE_SOURCE                          0xBFF60123 // (-1074396893) The source for the camera control line is invalid.
#define IMG_ERR_BAD_PIXEL_EXTRACTOR                           0xBFF60124 // (-1074396892) The requested pixel extractor is invalid.
#define IMG_ERR_BAD_NUM_TIME_SLOTS                            0xBFF60125 // (-1074396891) The requested number of time slots is invalid.
#define IMG_ERR_BAD_PLL_VCO_DIVIDER                           0xBFF60126 // (-1074396890) The requested VCO divide down number is invalid. The only valid values are 2, 4, 8 and 16.
#define IMG_ERR_CRITICAL_TEMP                                 0xBFF60127 // (-1074396889) The device temperature exceeded the critical temperature threshold.
#define IMG_ERR_BAD_DPA_OFFSET                                0xBFF60128 // (-1074396888) The requested dynamic phase aligner offset is invalid.
#define IMG_ERR_BAD_NUM_POST_TRIGGER_BUFFERS                  0xBFF60129 // (-1074396887) The requested number of post trigger buffers is invalid.
#define IMG_ERR_BAD_DVAL_MODE                                 0xBFF6012A // (-1074396886) The requested DVAL mode is invalid.
#define IMG_ERR_BAD_TRIG_GEN_REARM_SOURCE                     0xBFF6012B // (-1074396885) The requested trigger generator rearm source signal is invalid.
#define IMG_ERR_BAD_ASM_GATE_SOURCE                           0xBFF6012C // (-1074396884) The requested ASM gate signal is invalid.
#define IMG_ERR_TOO_MANY_BUFFERS                              0xBFF6012D // (-1074396883) The requested number of buffer list buffers is not supported by this image acquisition device.
#define IMG_ERR_BAD_TAP_4_VALID_RECT                          0xBFF6012E // (-1074396882) The rectangle defined for Tap 4 is invalid.
#define IMG_ERR_BAD_TAP_5_VALID_RECT                          0xBFF6012F // (-1074396881) The rectangle defined for Tap 5 is invalid.
#define IMG_ERR_BAD_TAP_6_VALID_RECT                          0xBFF60130 // (-1074396880) The rectangle defined for Tap 6 is invalid.
#define IMG_ERR_BAD_TAP_7_VALID_RECT                          0xBFF60131 // (-1074396879) The rectangle defined for Tap 7 is invalid.
#define IMG_ERR_FRONT_END_BANDWIDTH_EXCEEDED                  0xBFF60132 // (-1074396878) The camera is providing image data faster than the image acquisition device can receive it.
#define IMG_ERR_BAD_PORT_NUMBER                               0xBFF60133 // (-1074396877) The requested port number does not exist.
#define IMG_ERR_PORT_CONFIG_CONFLICT                          0xBFF60134 // (-1074396876) The requested port cannot be cannot be configured due to a conflict with another port that is currently opened.
#define IMG_ERR_BITSTREAM_INCOMPATIBLE                        0xBFF60135 // (-1074396875) The requested bitstream is not compatible with the image acquisition device.
#define IMG_ERR_SERIAL_PORT_IN_USE                            0xBFF60136 // (-1074396874) The requested serial port is currently in use and is not accessible.
#define IMG_ERR_BAD_ENCODER_DIVIDE_FACTOR                     0xBFF60137 // (-1074396873) The requested encoder divide factor is invalid.
#define IMG_ERR_ENCODER_NOT_SUPPORTED                         0xBFF60138 // (-1074396872) Encoder support is not present for this image acquisition device. Please verify that this device is capable of handling encoder signals and that phase A and B are connected.
#define IMG_ERR_BAD_ENCODER_POLARITY                          0xBFF60139 // (-1074396871) The requested encoder phase signal polarity is invalid.
#define IMG_ERR_BAD_ENCODER_FILTER                            0xBFF6013A // (-1074396870) The requested encoder filter setting is invalid.
#define IMG_ERR_ENCODER_POSITION_NOT_SUPPORTED                0xBFF6013B // (-1074396869) This image acquisition device does not support reading the absolute encoder position.
#define IMG_ERR_IMAGE_IN_USE                                  0xBFF6013C // (-1074396868) The image appears to be in use. Please name the images differently to avoid this situation.
#define IMG_ERR_BAD_SCARABXL4000_FILE                         0xBFF6013D // (-1074396867) The scarab.bin file is corrupt or missing.
#define IMG_ERR_BAD_CAMERA_ATTRIBUTE_VALUE                    0xBFF6013E // (-1074396866) The requested camera attribute value is invalid. For numeric camera attributes, please ensure that the value is properly aligned and within the allowable range.
#define IMG_ERR_BAD_PULSE_WIDTH                               0xBFF6013F // (-1074396865) The requested pulse width is invalid.
#define IMG_ERR_FPGA_FILE_NOT_FOUND                           0xBFF60140 // (-1074396864) The requested FPGA bitstream file could not be found.
#define IMG_ERR_FPGA_FILE_CORRUPT                             0xBFF60141 // (-1074396863) The requested FPGA bitstream file is corrupt.
#define IMG_ERR_BAD_PULSE_DELAY                               0xBFF60142 // (-1074396862) The requested pulse delay is invalid.
#define IMG_ERR_BAD_PG_IDLE_SIGNAL_LEVEL                      0xBFF60143 // (-1074396861) The pattern generation (PG) idle state is invalid. Camera control lines sourced from the PG unit must be all tristate or all non-tristate.
#define IMG_ERR_BAD_PG_WAVEFORM_IDLE_STATE                    0xBFF60144 // (-1074396860) The idle state for the pattern generation waveform is invalid.
#define IMG_ERR_64_BIT_MEMORY_NOT_SUPPORTED                   0xBFF60145 // (-1074396859) This device only supports acquiring into the 32-bit address space; however, portions of the image buffer list reside outside of 32-bit physical memory.
#define IMG_ERR_64_BIT_MEMORY_UPDATE_AVAILABLE                0xBFF60146 // (-1074396858) This 32-bit device is operating on a 64-bit OS with more than 3GB of physical memory. An update is available to allow acquisitions into 64-bit physical memory. Contact National Instruments for assistance.
#define IMG_ERR_32_BIT_MEMORY_LIMITATION                      0xBFF60147 // (-1074396857) This 32-bit device is operating on a 64-bit OS with more than 3GB of physical memory. This configuration could allocate 64-bit memory which is unsupported by the device. To solve this problem, use imgCreateBuffer to allocate image buffers, or reduce the amount of physical memory in the system.
#define IMG_ERR_KERNEL_NOT_LOADED                             0xBFF60148 // (-1074396856) The kernel component of the driver, niimaqk.sys, is not loaded. Verify that an IMAQ device is in your system or reinstall the driver.
#define IMG_ERR_BAD_SENSOR_SHUTTER_PERIOD                     0xBFF60149 // (-1074396855) The sensor shutter period is invalid. Check the horizontal and vertical shutter period values.
#define IMG_ERR_BAD_SENSOR_CCD_TYPE                           0xBFF6014A // (-1074396854) The sensor CCD type is invalid.
#define IMG_ERR_BAD_SENSOR_PARTIAL_SCAN                       0xBFF6014B // (-1074396853) The sensor partial scan mode is invalid.
#define IMG_ERR_BAD_SENSOR_BINNING                            0xBFF6014C // (-1074396852) The sensor binning mode is invalid.
#define IMG_ERR_BAD_SENSOR_GAIN                               0xBFF6014D // (-1074396851) The sensor gain value is invalid.
#define IMG_ERR_BAD_SENSOR_BRIGHTNESS                         0xBFF6014E // (-1074396850) The sensor brightness value is invalid.
#define IMG_ERR_BAD_LED_STATE                                 0xBFF6014F // (-1074396849) The LED state is invalid.
#define IMG_ERR_64_BIT_NOT_SUPPORTED                          0xBFF60150 // (-1074396848) The operation is not supported for 64-bit applications.
#define IMG_ERR_BAD_TRIGGER_DELAY                             0xBFF60151 // (-1074396847) The requested trigger delay value is not supported.
#define IMG_ERR_LIGHTING_CURRENT_EXCEEDS_LIMITS               0xBFF60152 // (-1074396846) The configured lighting current level exceeds the hardware or user's configured limits.
#define IMG_ERR_LIGHTING_INVALID_MODE                         0xBFF60153 // (-1074396845) The configured lighting mode is invalid.
#define IMG_ERR_LIGHTING_EXTERNAL_INVALID_MODE                0xBFF60154 // (-1074396844) The configured external lighting mode is invalid.
#define IMG_ERR_BAD_SENSOR_EXPOSURE                           0xBFF60155 // (-1074396843) The sensor exposure time is invalid.
#define IMG_ERR_BAD_FRAME_RATE                                0xBFF60156 // (-1074396842) The frame rate is invalid for the current configuration.
#define IMG_ERR_BAD_SENSOR_PARTIAL_SCAN_BINNING_COMBINATION   0xBFF60157 // (-1074396841) The partial scan mode / binning mode combination is invalid.
#define IMG_ERR_SOFTWARE_TRIGGER_NOT_CONFIGURED               0xBFF60158 // (-1074396840) The requested software trigger is not configured.
#define IMG_ERR_FREE_RUN_MODE_NOT_ALLOWED                     0xBFF60159 // (-1074396839) Free-run mode is not allowed in the current configuration. This is typically caused by simultaneously enabling free-run mode and a triggered acquisition.
#define IMG_ERR_BAD_LIGHTING_RAMPUP                           0xBFF6015A // (-1074396838) The lighting ramp-up delay is either less than the minimum value allowed or larger than the maximum time that the light is allowed to be on.
#define IMG_ERR_AFE_CONFIG_TIMEOUT                            0xBFF6015B // (-1074396837) Internal Error: A write to the AFEConfig register did not complete properly.
#define IMG_ERR_LIGHTING_ARM_TIMEOUT                          0xBFF6015C // (-1074396836) Internal Error: The arming of the lighting controller did not complete properly.
#define IMG_ERR_LIGHTING_SHORT_CIRCUIT                        0xBFF6015D // (-1074396835) The Direct Drive lighting controller has detected an abnormal load condition, such as a short circuit. Correct the abnormal load condition before restarting the acquisition.
#define IMG_ERR_BAD_BOARD_HEALTH                              0xBFF6015E // (-1074396834) The board health register has indicated an internal problem.
#define IMG_ERR_LIGHTING_BAD_CONTINUOUS_CURRENT_LIMIT         0xBFF6015F // (-1074396833) The requested continuous current limit for the lighting controller is less than the minimum allowed current level.
#define IMG_ERR_LIGHTING_BAD_STROBE_DUTY_CYCLE_LIMIT          0xBFF60160 // (-1074396832) The requested duty cycle limit for the lighting controller strobe mode is invalid.
#define IMG_ERR_LIGHTING_BAD_STROBE_DURATION_LIMIT            0xBFF60161 // (-1074396831) The requested duration limit for the lighting controller strobe mode is invalid.
#define IMG_ERR_BAD_LIGHTING_CURRENT_EXPOSURE_COMBINATION     0xBFF60162 // (-1074396830) The lighting current is invalid because the exposure time plus the lighting ramp-up time exceeds either the strobe duration limit or the strobe duty cycle limit.
#define IMG_ERR_LIGHTING_HEAD_CONFIG_NOT_FOUND                0xBFF60163 // (-1074396829) The configuration for the desired light head was not found.
#define IMG_ERR_LIGHTING_HEAD_DATA_CORRUPT                    0xBFF60164 // (-1074396828) The data for the desired light head configuration is invalid or corrupt.
#define IMG_ERR_LIGHTING_ABORT_TIMEOUT                        0xBFF60165 // (-1074396827) Internal Error: The abort of the lighting controller did not complete properly.
#define IMG_ERR_LIGHTING_BAD_STROBE_CURRENT_LIMIT             0xBFF60166 // (-1074396826) The requested strobe current limit for the lighting controller is less than the minimum allowed current.
#define IMG_ERR_DMA_ENGINE_UNRESPONSIVE                       0xBFF60167 // (-1074396825) Internal Error: The DMA engine is unresponsive. Reboot the target. If the problem persists contact National Instruments.
#define IMG_ERR_IMAGE_NOT_32BYTE_ALIGNED                      0xBFF60168 // (-1074396824) The image width is not a multiple of 32-bytes. The current configuration requires that the image width be a multiple of 32-bytes.
#define IMG_ERR_IMAGE_BORDER_NONZERO                          0xBFF60169 // (-1074396823) The image border is not zero. The current configuration requires that the image have no border.
#define IMG_ERR_UNKNOWN_CAMERA_FILE                           0xBFF6016A // (-1074396822) No valid camera file selected for this interface.
#define IMG_ERR_ONBOARD_DECODING_NOT_CHANGEABLE_DURING_ACQ    0xBFF6016B // (-1074396821) The Bayer pattern cannot be change to None or away from None while the acquisition is running and onboard Bayer decoding is enabled.
#define IMG_ERR_BAD_BAYER_GAIN_FOR_ONBOARD_DECODE             0xBFF6016C // (-1074396820) The specified Bayer gain is not supported when onboard Bayer decoding is enabled.
#define IMG_ERR_BAD_BAYER_PATTERN_FOR_ONBOARD_DECODE          0xBFF6016D // (-1074396819) The specified Bayer pattern is not supported when onboard Bayer decoding is enabled.
#define IMG_ERR_BAD_NUM_COMPONENTS_FOR_ONBOARD_DECODE         0xBFF6016E // (-1074396818) The number of components value in the camera file must be 1 when onboard Bayer decoding is enabled.
#define IMG_ERR_BAD_NUM_PHANTOM_COMPONENTS_FOR_ONBOARD_DECODE 0xBFF6016F // (-1074396817) The number of phantom components value in the camera file must be 0 when onboard Bayer decoding is enabled.
#define IMG_ERR_POCL_FAULT                                    0xBFF60170 // (-1074396816) The Power Over Camera Link (PoCL) circuitry has encountered an overcurrent condition. Please power down the computer to safely reset the PoCL circuitry.
#define IMG_ERR_POCL_VIDEO_LOCK                               0xBFF60171 // (-1074396815) The Power Over CameraLink circuitry is unable to provide power and the device cannot detect a recognizable video source.
#define IMG_ERR_POCL_BAD_FUSE                                 0xBFF60172 // (-1074396814) The Power Over CameraLink circuitry cannot provide power due to a blown fuse.
#define IMG_ERR_POCL_NO_AUX_POWER                             0xBFF60173 // (-1074396813) The Power Over CameraLink circuitry cannot provide power due to a missing auxilliary power connection
#define IMG_ERR_PULSE_UPDATE_NOT_SUPPORTED                    0xBFF60174 // (-1074396812) This image acquisition device does not support updating pulses.
#define IMG_ERR_BAD_BITS_PER_COMPONENT_FOR_ONBOARD_DECODE     0xBFF60175 // (-1074396811) The bits per component value in the camera file must be less than 16 when onboard Bayer decoding is enabled.
#define IMG_ERR_IO_BOARD_NOT_PRESENT                          0xBFF60176 // (-1074396810) The requested configuration requires the IO extension board, but the IO extension board is not connected.
#define IMG_ERR_LAST_ERROR                                    0xBFF60176 // (-1074396810)

#endif
