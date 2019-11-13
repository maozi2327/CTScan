//////////////////////////////////////////////////////////////////////////////
//
//  Title     : niimaq.h
//  Project   : NI-IMAQ
//  Created   : 1/18/2002 @ 15:16:23
//  Platforms : All
//  Copyright : National Instruments 2011.  All Rights Reserved.
//  Access    : Public
//  Purpose   : Public header file for NI-IMAQ.
//
//////////////////////////////////////////////////////////////////////////////


//============================================================================
//  Preamble
//============================================================================
#if !defined(niimaq_h)
#define niimaq_h


//============================================================================
//  Pragmas
//============================================================================
#ifdef _CVI_
    #pragma  EnableLibraryRuntimeChecking
#endif


//============================================================================
//  Typedefs
//============================================================================
#if !defined(niimaq_types)
#define niimaq_types

#ifndef _NI_uInt8_DEFINED_
    #define _NI_uInt8_DEFINED_
    typedef unsigned char       uInt8;
#endif

#ifndef _NI_uInt16_DEFINED_
    #define _NI_uInt16_DEFINED_
    typedef unsigned short int  uInt16;
#endif

#ifndef _NI_uInt32_DEFINED_
    #define _NI_uInt32_DEFINED_
    #if defined(_MSC_VER)
        typedef unsigned long       uInt32;
    #else
        #if __x86_64__
            typedef unsigned int    uInt32;
        #else
            typedef unsigned long   uInt32;
        #endif
    #endif
#endif

#ifndef _NI_uInt64_DEFINED_
    #define _NI_uInt64_DEFINED_
    #if defined(_MSC_VER)
        typedef unsigned __int64   uInt64;
    #else
        typedef unsigned long long uInt64;
    #endif
#endif

#ifndef _NI_Int8_DEFINED_
    #define _NI_Int8_DEFINED_
    typedef char                Int8;
#endif

#ifndef _NI_Int16_DEFINED_
    #define _NI_Int16_DEFINED_
    typedef short int           Int16;
#endif

#ifndef _NI_Int32_DEFINED_
    #define _NI_Int32_DEFINED_
    #if defined(_MSC_VER)
        typedef long            Int32;
    #else
        #if __x86_64__
            typedef int         Int32;
        #else
            typedef long        Int32;
        #endif
    #endif
#endif

#ifndef _NI_Int64_DEFINED_
    #define _NI_Int64_DEFINED_
    #if defined(_MSC_VER)
        typedef __int64         Int64;
    #else
        typedef long long       Int64;
    #endif
#endif

#ifndef TRUE
    #define TRUE                1
#endif

#ifndef FALSE
    #define FALSE               0
#endif

typedef char*           Ptr;

typedef  uInt32   INTERFACE_ID;
typedef  uInt32   SESSION_ID;
typedef  uInt32   EVENT_ID;
typedef  uInt32   PULSE_ID;
typedef  uInt32   BUFLIST_ID;
typedef  Int32    IMG_ERR;
typedef  uInt16   IMG_SYNC;
typedef  uInt32   GUIHNDL;

#endif


//============================================================================
//  Includes
//============================================================================
#include <stddef.h>


//============================================================================
//  Defines
//============================================================================
#if (defined(__cplusplus) || defined(__cplusplus__))
    #define USER_EXTERN_C extern "C"
#else
    #define USER_EXTERN_C
#endif

#if defined(_MSC_VER)
    #ifndef NI_DLL_IMPORT
        #define NI_DLL_IMPORT __declspec(dllimport)
    #endif
    #ifndef NI_DLL_EXPORT
        #define NI_DLL_EXPORT __declspec(dllexport)
    #endif
    #ifndef NI_STDCALL
        #define NI_STDCALL    __stdcall
    #endif
    #ifndef NI_CDECL
        #define NI_CDECL      __cdecl
    #endif
#elif (defined(_CVI_) || defined(_CVI))
    #ifndef NI_DLL_IMPORT
        #define NI_DLL_IMPORT
    #endif
    #ifndef NI_DLL_EXPORT
        #define NI_DLL_EXPORT __declspec(dllexport)
    #endif
    #ifndef NI_STDCALL
        #define NI_STDCALL    __stdcall
    #endif
    #ifndef NI_CDECL
        #define NI_CDECL      __cdecl
    #endif
#elif defined(__GNUC__)
    #ifndef NI_DLL_IMPORT
        #define NI_DLL_IMPORT
    #endif
    #ifndef NI_DLL_EXPORT
        #define NI_DLL_EXPORT __attribute__ ((section (".export")))
    #endif
    #ifndef NI_STDCALL
        #define NI_STDCALL
    #endif
    #ifndef NI_CDECL
        #define NI_CDECL
    #endif
#endif

#if !defined(USER_MODE_BUILD)
    #define USER_FUNC USER_EXTERN_C NI_DLL_IMPORT Int32 NI_STDCALL
    #define USER_FUNCC USER_EXTERN_C NI_DLL_IMPORT Int32 NI_CDECL
#else
    #define USER_FUNC USER_EXTERN_C NI_DLL_EXPORT Int32 NI_STDCALL
    #define USER_FUNCC USER_EXTERN_C NI_DLL_EXPORT Int32 NI_CDECL
#endif

#define _IMG_BASE 0x3FF60000


//----------------------------------------------------------------------------
//  Attribute Keys
//----------------------------------------------------------------------------
#define  IMG_ATTR_INTERFACE_TYPE                (_IMG_BASE + 0x0001) // id of board - see constants below
#define  IMG_ATTR_PIXDEPTH                      (_IMG_BASE + 0x0002) // pixel depth in bits
#define  IMG_ATTR_COLOR                         (_IMG_BASE + 0x0003) // true = supports color
#define  IMG_ATTR_HASRAM                        (_IMG_BASE + 0x0004) // true = has on-board SRAM
#define  IMG_ATTR_RAMSIZE                       (_IMG_BASE + 0x0005) // SRAM size
#define  IMG_ATTR_CHANNEL                       (_IMG_BASE + 0x0006)
#define  IMG_ATTR_FRAME_FIELD                   (_IMG_BASE + 0x0007) // supports frame and field
#define  IMG_ATTR_HORZ_RESOLUTION               (_IMG_BASE + 0x0009)
#define  IMG_ATTR_VERT_RESOLUTION               (_IMG_BASE + 0x000A)
#define  IMG_ATTR_LUT                           (_IMG_BASE + 0x000B)
#define  IMG_ATTR_LINESCAN                      (_IMG_BASE + 0x000C)
#define  IMG_ATTR_GAIN                          (_IMG_BASE + 0x000D)
#define  IMG_ATTR_CHROMA_FILTER                 (_IMG_BASE + 0x000E)
#define  IMG_ATTR_WHITE_REF                     (_IMG_BASE + 0x000F)
#define  IMG_ATTR_BLACK_REF                     (_IMG_BASE + 0x0010)
#define  IMG_ATTR_DATALINES                     (_IMG_BASE + 0x0011) // pass in uInt32 array of size up to 16 elements to swap incoming data lines (0,1,2...15) - must be 16 x uInt32 array
#define  IMG_ATTR_NUM_EXT_LINES                 (_IMG_BASE + 0x0012)
#define  IMG_ATTR_NUM_RTSI_LINES                (_IMG_BASE + 0x0013)
#define  IMG_ATTR_NUM_RTSI_IN_USE               (_IMG_BASE + 0x0014)
#define  IMG_ATTR_MEM_LOCKED                    (_IMG_BASE + 0x0065)
#define  IMG_ATTR_BITSPERPIXEL                  (_IMG_BASE + 0x0066)
#define  IMG_ATTR_BYTESPERPIXEL                 (_IMG_BASE + 0x0067)
#define  IMG_ATTR_ACQWINDOW_LEFT                (_IMG_BASE + 0x0068)
#define  IMG_ATTR_ACQWINDOW_TOP                 (_IMG_BASE + 0x0069)
#define  IMG_ATTR_ACQWINDOW_WIDTH               (_IMG_BASE + 0x006A)
#define  IMG_ATTR_ACQWINDOW_HEIGHT              (_IMG_BASE + 0x006B)
#define  IMG_ATTR_LINE_COUNT                    (_IMG_BASE + 0x0070)
#define  IMG_ATTR_FREE_BUFFERS                  (_IMG_BASE + 0x0071)
#define  IMG_ATTR_HSCALE                        (_IMG_BASE + 0x0072)
#define  IMG_ATTR_VSCALE                        (_IMG_BASE + 0x0073)
#define  IMG_ATTR_ACQ_IN_PROGRESS               (_IMG_BASE + 0x0074)
#define  IMG_ATTR_START_FIELD                   (_IMG_BASE + 0x0075)
#define  IMG_ATTR_FRAME_COUNT                   (_IMG_BASE + 0x0076)
#define  IMG_ATTR_LAST_VALID_BUFFER             (_IMG_BASE + 0x0077)
#define  IMG_ATTR_ROWBYTES                      (_IMG_BASE + 0x0078)
#define  IMG_ATTR_CALLBACK                      (_IMG_BASE + 0x007B)
#define  IMG_ATTR_CURRENT_BUFLIST               (_IMG_BASE + 0x007C)
#define  IMG_ATTR_FRAMEWAIT_MSEC                (_IMG_BASE + 0x007D)
#define  IMG_ATTR_TRIGGER_MODE                  (_IMG_BASE + 0x007E)
#define  IMG_ATTR_INVERT                        (_IMG_BASE + 0x0082)
#define  IMG_ATTR_XOFF_BUFFER                   (_IMG_BASE + 0x0083)
#define  IMG_ATTR_YOFF_BUFFER                   (_IMG_BASE + 0x0084)
#define  IMG_ATTR_NUM_BUFFERS                   (_IMG_BASE + 0x0085)
#define  IMG_ATTR_LOST_FRAMES                   (_IMG_BASE + 0x0088)
#define  IMG_ATTR_COLOR_WHITE_REF               (_IMG_BASE + 0x008F) // Color white reference
#define  IMG_ATTR_COLOR_BLACK_REF               (_IMG_BASE + 0x0090) // Color black reference
#define  IMG_ATTR_COLOR_CLAMP_START             (_IMG_BASE + 0x0091) // Color clamp start
#define  IMG_ATTR_COLOR_CLAMP_STOP              (_IMG_BASE + 0x0092) // Color clamp stop
#define  IMG_ATTR_COLOR_ZERO_START              (_IMG_BASE + 0x0093) // Color zero start
#define  IMG_ATTR_COLOR_ZERO_STOP               (_IMG_BASE + 0x0094) // Color zero stop
#define  IMG_ATTR_COLOR_AVG_COUNT               (_IMG_BASE + 0x0095) // Color averaging count
#define  IMG_ATTR_COLOR_SW_CHROMA_FILTER        (_IMG_BASE + 0x0096) // Color SW chroma filter
#define  IMG_ATTR_COLOR_NTSC_SETUP_ENABLE       (_IMG_BASE + 0x0097) // Color NTSC Setup enable
#define  IMG_ATTR_COLOR_NTSC_SETUP_VALUE        (_IMG_BASE + 0x0098) // Color NTSC Setup value
#define  IMG_ATTR_COLOR_BRIGHTNESS              (_IMG_BASE + 0x0099) // Color brightness
#define  IMG_ATTR_COLOR_CONTRAST                (_IMG_BASE + 0x009A) // Color contrast
#define  IMG_ATTR_COLOR_SATURATION              (_IMG_BASE + 0x009B) // Color saturation
#define  IMG_ATTR_COLOR_TINT                    (_IMG_BASE + 0x009C) // Color tint (chroma phase)
#define  IMG_ATTR_COLOR_SW_POST_GAIN            (_IMG_BASE + 0x009D) // Color SW post-gain
#define  IMG_ATTR_COLOR_BURST_START             (_IMG_BASE + 0x009E) // Color burst start
#define  IMG_ATTR_COLOR_BURST_STOP              (_IMG_BASE + 0x009F) // Color burst stop
#define  IMG_ATTR_COLOR_BLANK_START             (_IMG_BASE + 0x00A0) // Color blank start
#define  IMG_ATTR_COLOR_BLANK_STOP              (_IMG_BASE + 0x00A1) // Color blank stop
#define  IMG_ATTR_COLOR_IMAGE_X_SHIFT           (_IMG_BASE + 0x00A2) // Color acquisition left shift
#define  IMG_ATTR_COLOR_GAIN                    (_IMG_BASE + 0x00A3) // Color HW pre-gain
#define  IMG_ATTR_COLOR_CLAMP_START_REF         (_IMG_BASE + 0x00A5) // Color clamp start reference
#define  IMG_ATTR_COLOR_CLAMP_STOP_REF          (_IMG_BASE + 0x00A6) // Color clamp stop reference
#define  IMG_ATTR_COLOR_ZERO_START_REF          (_IMG_BASE + 0x00A7) // Color zero start reference
#define  IMG_ATTR_COLOR_ZERO_STOP_REF           (_IMG_BASE + 0x00A8) // Color zero stop reference
#define  IMG_ATTR_COLOR_BURST_START_REF         (_IMG_BASE + 0x00A9) // Color burst start reference
#define  IMG_ATTR_COLOR_BURST_STOP_REF          (_IMG_BASE + 0x00AA) // Color burst stop reference
#define  IMG_ATTR_COLOR_BLANK_START_REF         (_IMG_BASE + 0x00AB) // Color blank start reference
#define  IMG_ATTR_COLOR_BLANK_STOP_REF          (_IMG_BASE + 0x00AC) // Color blank stop reference
#define  IMG_ATTR_COLOR_MODE                    (_IMG_BASE + 0x00AD) // Color acquisition mode
#define  IMG_ATTR_COLOR_IMAGE_REP               (_IMG_BASE + 0x00AE) // Color Image representation
#define  IMG_ATTR_GENLOCK_SWITCH_CHAN           (_IMG_BASE + 0x00AF) // switch channel fast
#define  IMG_ATTR_CLAMP_START                   (_IMG_BASE + 0x00B0) // clamp start
#define  IMG_ATTR_CLAMP_STOP                    (_IMG_BASE + 0x00B1) // clamp stop
#define  IMG_ATTR_ZERO_START                    (_IMG_BASE + 0x00B2) // zero start
#define  IMG_ATTR_ZERO_STOP                     (_IMG_BASE + 0x00B3) // zero stop
#define  IMG_ATTR_COLOR_HUE_OFFS_ANGLE          (_IMG_BASE + 0x00B5) // Color hue offset angle
#define  IMG_ATTR_COLOR_IMAGE_X_SHIFT_REF       (_IMG_BASE + 0x00B6) // Color acquisition left shift reference
#define  IMG_ATTR_LAST_VALID_FRAME              (_IMG_BASE + 0x00BA) // returns the cummulative buffer index (frame#)
#define  IMG_ATTR_CLOCK_FREQ                    (_IMG_BASE + 0x00BB) // returns the max clock freq of the board
#define  IMG_ATTR_BLACK_REF_VOLT                (_IMG_BASE + 0x00BC) // defines the black reference in volts
#define  IMG_ATTR_WHITE_REF_VOLT                (_IMG_BASE + 0x00BD) // defines the white reference in volts
#define  IMG_ATTR_COLOR_LOW_REF_VOLT            (_IMG_BASE + 0x00BE) // defines the color low reference in volts
#define  IMG_ATTR_COLOR_HIGH_REF_VOLT           (_IMG_BASE + 0x00BF)
#define  IMG_ATTR_GETSERIAL                     (_IMG_BASE + 0x00C0) // get the serial number of the board
#define  IMG_ATTR_ROWPIXELS                     (_IMG_BASE + 0x00C1)
#define  IMG_ATTR_ACQUIRE_FIELD                 (_IMG_BASE + 0x00C2)
#define  IMG_ATTR_PCLK_DETECT                   (_IMG_BASE + 0x00C3)
#define  IMG_ATTR_VHA_MODE                      (_IMG_BASE + 0x00C4) // Variable Height Acquisition mode
#define  IMG_ATTR_BIN_THRESHOLD_LOW             (_IMG_BASE + 0x00C5) // Binary threshold low
#define  IMG_ATTR_BIN_THRESHOLD_HIGH            (_IMG_BASE + 0x00C6) // Binary threshold hi
#define  IMG_ATTR_COLOR_LUMA_BANDWIDTH          (_IMG_BASE + 0x00C7) // selects different bandwidths for the luminance signal
#define  IMG_ATTR_COLOR_CHROMA_TRAP             (_IMG_BASE + 0x00C8) // enables and disables the chroma trap filter in the luma signal path
#define  IMG_ATTR_COLOR_LUMA_COMB               (_IMG_BASE + 0x00C9) // select the type of comb filter used in the luma path
#define  IMG_ATTR_COLOR_PEAKING_ENABLE          (_IMG_BASE + 0x00CA) // enable the peaking filter in the luma path
#define  IMG_ATTR_COLOR_PEAKING_LEVEL           (_IMG_BASE + 0x00CB)
#define  IMG_ATTR_COLOR_CHROMA_PROCESS          (_IMG_BASE + 0x00CC) // specifies the processing applied to the chroma signal
#define  IMG_ATTR_COLOR_CHROMA_BANDWIDTH        (_IMG_BASE + 0x00CD) // bandwidth of the chroma information of the image
#define  IMG_ATTR_COLOR_CHROMA_COMB             (_IMG_BASE + 0x00CE) // select the type of comb filter used in the chroma path
#define  IMG_ATTR_COLOR_CHROMA_PHASE            (_IMG_BASE + 0x00CF) // sets value of correction angle applied to the chroma vector.  Active only for NTSC cameras
#define  IMG_ATTR_COLOR_RGB_CORING_LEVEL        (_IMG_BASE + 0x00D0) // select RGB coring level
#define  IMG_ATTR_COLOR_HSL_CORING_LEVEL        (_IMG_BASE + 0x00D1) // select HSL coring level
#define  IMG_ATTR_COLOR_HUE_REPLACE_VALUE       (_IMG_BASE + 0x00D2) // hue value to replace if saturation value is less than HSL coring level
#define  IMG_ATTR_COLOR_GAIN_RED                (_IMG_BASE + 0x00D3) // Red Gain
#define  IMG_ATTR_COLOR_GAIN_GREEN              (_IMG_BASE + 0x00D4) // Green Gian
#define  IMG_ATTR_COLOR_GAIN_BLUE               (_IMG_BASE + 0x00D5) // Blue Gain
#define  IMG_ATTR_CALIBRATION_DATE_LV           (_IMG_BASE + 0x00D6) // 0 if board is uncalibrated, else seconds since Jan 1 1904
#define  IMG_ATTR_CALIBRATION_DATE              (_IMG_BASE + 0x00D7) // 0 if board is uncalibrated, else seconds since Jan 1 1970
#define  IMG_ATTR_IMAGE_TYPE                    (_IMG_BASE + 0x00D8) // return the IMAQ Vision image type for LabVIEW
#define  IMG_ATTR_DYNAMIC_RANGE                 (_IMG_BASE + 0x00D9) // the effective bits per pixel of the user's white-black level
#define  IMG_ATTR_ACQUIRE_TO_SYSTEM_MEMORY      (_IMG_BASE + 0x011B)
#define  IMG_ATTR_ONBOARD_HOLDING_BUFFER_PTR    (_IMG_BASE + 0x011C) // invalid on 64-bit OS
#define  IMG_ATTR_SYNCHRONICITY                 (_IMG_BASE + 0x011D)
#define  IMG_ATTR_LAST_ACQUIRED_BUFFER_NUM      (_IMG_BASE + 0x011E)
#define  IMG_ATTR_LAST_ACQUIRED_BUFFER_INDEX    (_IMG_BASE + 0x011F)
#define  IMG_ATTR_LAST_TRANSFERRED_BUFFER_NUM   (_IMG_BASE + 0x0120)
#define  IMG_ATTR_LAST_TRANSFERRED_BUFFER_INDEX (_IMG_BASE + 0x0121)
#define  IMG_ATTR_SERIAL_NUM_BYTES_RECEIVED     (_IMG_BASE + 0x012C) // # bytes currently in the internal serial read buffer
#define  IMG_ATTR_EXPOSURE_TIME_INTERNAL        (_IMG_BASE + 0x013C) // exposure time for 1454 (internal value - specified in 40MHz clks)
#define  IMG_ATTR_SERIAL_TERM_STRING            (_IMG_BASE + 0x0150) // The serial termination string
#define  IMG_ATTR_DETECT_VIDEO                  (_IMG_BASE + 0x01A3) // Determines whether to detect a video signal prior to acquiring
#define  IMG_ATTR_ROI_LEFT                      (_IMG_BASE + 0x01A4)
#define  IMG_ATTR_ROI_TOP                       (_IMG_BASE + 0x01A5)
#define  IMG_ATTR_ROI_WIDTH                     (_IMG_BASE + 0x01A6)
#define  IMG_ATTR_ROI_HEIGHT                    (_IMG_BASE + 0x01A7)
#define  IMG_ATTR_NUM_ISO_IN_LINES              (_IMG_BASE + 0x01A8) // The number of iso in lines the device supports
#define  IMG_ATTR_NUM_ISO_OUT_LINES             (_IMG_BASE + 0x01A9) // The number of iso out lines the device supports
#define  IMG_ATTR_NUM_POST_TRIGGER_BUFFERS      (_IMG_BASE + 0x01AA) // The number of buffers that hardware should continue acquire after sensing a stop trigger before it finally does stop
#define  IMG_ATTR_EXT_TRIG_LINE_FILTER          (_IMG_BASE + 0x01AB) // Whether to use filtering on the TTL trigger lines
#define  IMG_ATTR_RTSI_LINE_FILTER              (_IMG_BASE + 0x01AC) // Whether to use filtering on the RTSI trigger lines
#define  IMG_ATTR_NUM_PORTS                     (_IMG_BASE + 0x01AD) // Returns the number of ports that this device supports.
#define  IMG_ATTR_CURRENT_PORT_NUM              (_IMG_BASE + 0x01AE) // Returns the port number that the given interface is using.
#define  IMG_ATTR_ENCODER_PHASE_A_POLARITY      (_IMG_BASE + 0x01AF) // The polarity of the phase A encoder input
#define  IMG_ATTR_ENCODER_PHASE_B_POLARITY      (_IMG_BASE + 0x01B0) // The polarity of the phase B encoder input
#define  IMG_ATTR_ENCODER_FILTER                (_IMG_BASE + 0x01B1) // Specifies whether to use filtering on the encoder input
#define  IMG_ATTR_ENCODER_DIVIDE_FACTOR         (_IMG_BASE + 0x01B2) // The divide factor for the encoder scaler
#define  IMG_ATTR_ENCODER_POSITION              (_IMG_BASE + 0x01B3) // Returns the current value of the absolute encoder position as a uInt64
#define  IMG_ATTR_TEMPERATURE                   (_IMG_BASE + 0x01B4) // The device's current temperature, in degrees C
#define  IMG_ATTR_LED_PASS                      (_IMG_BASE + 0x01B5) // The state of the Pass LED
#define  IMG_ATTR_LED_FAIL                      (_IMG_BASE + 0x01B6) // The state of the Fail LED
#define  IMG_ATTR_SENSOR_PARTIAL_SCAN           (_IMG_BASE + 0x01B7) // The sensor's partial scan mode
#define  IMG_ATTR_SENSOR_BINNING                (_IMG_BASE + 0x01B8) // The sensor's binning mode
#define  IMG_ATTR_SENSOR_GAIN                   (_IMG_BASE + 0x01B9) // The sensor's gain factor
#define  IMG_ATTR_LIGHTING_MODE                 (_IMG_BASE + 0x01BB) // The internal lighting mode to use
#define  IMG_ATTR_LIGHTING_CURRENT              (_IMG_BASE + 0x01BC) // The amount of current sourced by the internal lighting controller (mA)
#define  IMG_ATTR_LIGHTING_MAX_CURRENT          (_IMG_BASE + 0x01BD) // Returns the maximum current that can be souced by the internal lighting controller given the current configuration
#define  IMG_ATTR_LIGHTING_EXT_STROBE_5V_TTL    (_IMG_BASE + 0x01BE) // Whether to enable stobing on the external 5V lighting output
#define  IMG_ATTR_LIGHTING_EXT_STROBE_24V       (_IMG_BASE + 0x01BF) // Whether to enable stobing on the external 24V (VCC) lighting output
#define  IMG_ATTR_SENSOR_EXPOSURE               (_IMG_BASE + 0x01C0) // The sensor's exposure time in milliseconds.
#define  IMG_ATTR_FRAME_RATE                    (_IMG_BASE + 0x01C1) // The frame rate.
#define  IMG_ATTR_MAX_FRAME_RATE                (_IMG_BASE + 0x01C2) // The maximum frame rate.
#define  IMG_ATTR_SEND_SOFTWARE_TRIGGER         (_IMG_BASE + 0x01C3) // Set to issue a software trigger to the action that was configured to wait for a software trigger.
#define  IMG_ATTR_FIXED_FRAME_RATE_MODE         (_IMG_BASE + 0x01C4) // Controls whether the sensor operates in fixed-frame-rate mode (true) or free-run mode (off).  When in fixed-frame-rate mode the sensor will run at the frame rate specified by IMG_ATTR_FRAME_RATE.  When in free-run mode, the sensor will run at the maximum frame rate possible.
#define  IMG_ATTR_UNSIGNED_16BIT_IMAGE          (_IMG_BASE + 0x01C5) // Whether to interpret 16 bits of pixel data as signed or unsigned.
#define  IMG_ATTR_POCL_STATUS                   (_IMG_BASE + 0x01C6) // Returns the status of the PoCL circuitry.
#define  IMG_ATTR_ROWPIXELS_ALIGNMENT           (_IMG_BASE + 0x01C7) // Alignment constraint of row pixels
#define  IMG_ATTR_ROWPIXELS_SUGGESTED_ALIGNMENT (_IMG_BASE + 0x01C8) // Suggested alignment constraint of row pixels
#define  IMG_ATTR_SUPPORTS_PULSE_UPDATE         (_IMG_BASE + 0x01C9) // Whether pulse updates are supported.
#define  IMG_ATTR_BAYER_PATTERN                 (_IMG_BASE + 0x01CB) // The bayer pattern
#define  IMG_ATTR_BAYER_RED_GAIN                (_IMG_BASE + 0x01CC) // The Bayer red gain
#define  IMG_ATTR_BAYER_GREEN_GAIN              (_IMG_BASE + 0x01CD) // The Bayer green gain
#define  IMG_ATTR_BAYER_BLUE_GAIN               (_IMG_BASE + 0x01CE) // The Bayer blue gain
#define  IMG_ATTR_BAYER_ALGORITHM               (_IMG_BASE + 0x01CF) // The Bayer decode algorithm
#define  IMG_ATTR_BAYER_ONBOARD_DECODE_ENABLE   (_IMG_BASE + 0x01D0) // Whether to enable onboard Bayer decoding
#define  IMG_ATTR_BAYER_ONBOARD_DECODE_FORCE_RGB32 (_IMG_BASE + 0x01D1) // Whether to force the decoded RGB image to be 32 bits.  By default pixel depths greater than 8 return a 64-bit RGB image.
#define  IMG_ATTR_ENCODER_USE_IO_BOARD_INPUT    (_IMG_BASE + 0x01D2) // Whether to use the I/O board inputs (TRUE) or the front connector inputs (FALSE) for the scaled encoder.
#define  IMG_ATTR_POCL_STATUS_BASE              (_IMG_BASE + 0x01D3) // Returns the status of the PoCL circuitry for the Base connector
#define  IMG_ATTR_POCL_STATUS_MED_FULL          (_IMG_BASE + 0x01D4) // Returns the status of the PoCL circuitry for the Medium/Full connector
#define  IMG_ATTR_IO_BOARD_PRESENT              (_IMG_BASE + 0x01D5) // Returns true if there is an IO board attached to the device


//============================================================================
//  Attribute Defines
//============================================================================

//----------------------------------------------------------------------------
//  LUT
//----------------------------------------------------------------------------
#define  IMG_LUT_NORMAL                      0
#define  IMG_LUT_INVERSE                     1
#define  IMG_LUT_LOG                         2
#define  IMG_LUT_INVERSE_LOG                 3
#define  IMG_LUT_BINARY                      4
#define  IMG_LUT_INVERSE_BINARY              5
#define  IMG_LUT_USER                        6


#define  IMG_LUT_TYPE_DEFAULT       0x00000010
#define  IMG_LUT_TYPE_RED           0x00000020
#define  IMG_LUT_TYPE_GREEN         0x00000040
#define  IMG_LUT_TYPE_BLUE          0x00000080
#define  IMG_LUT_TYPE_TAP0          0x00000100
#define  IMG_LUT_TYPE_TAP1          0x00000200
#define  IMG_LUT_TYPE_TAP2          0x00000400
#define  IMG_LUT_TYPE_TAP3          0x00000800


//------------------------------------------------------------------------------
//  Frame or Field Mode
//------------------------------------------------------------------------------
#define  IMG_FIELD_MODE                      0
#define  IMG_FRAME_MODE                      1


//----------------------------------------------------------------------------
//  Chrominance Filters
//----------------------------------------------------------------------------
#define IMG_FILTER_NONE                      0
#define IMG_FILTER_NTSC                      1
#define IMG_FILTER_PAL                       2


//------------------------------------------------------------------------------
//  Possible start field values
//------------------------------------------------------------------------------
#define  IMG_FIELD_EVEN                      0
#define  IMG_FIELD_ODD                       1


//----------------------------------------------------------------------------
//  Scaling
//----------------------------------------------------------------------------
#define  IMG_SCALE_NONE                      1
#define  IMG_SCALE_DIV2                      2
#define  IMG_SCALE_DIV4                      4
#define  IMG_SCALE_DIV8                      8


//----------------------------------------------------------------------------
//  Triggering Mode
//----------------------------------------------------------------------------
#define  IMG_TRIGMODE_NONE                   0
#define  IMG_TRIGMODE_NOREPEAT               1
#define  IMG_TRIGMODE_REPEAT                 2


//----------------------------------------------------------------------------
//  Field Acquisition Selection
//----------------------------------------------------------------------------
#define  IMG_ACQUIRE_EVEN                    0
#define  IMG_ACQUIRE_ODD                     1
#define  IMG_ACQUIRE_ALL                     2
#define  IMG_ACQUIRE_ALTERNATING             3


//----------------------------------------------------------------------------
//  Luma bandwidth
//----------------------------------------------------------------------------
#define  IMG_COLOR_LUMA_BANDWIDTH_FULL       0  // All filters including decimation filter disabled. Default for CCIR or RS-170
#define  IMG_COLOR_LUMA_BANDWIDTH_HIGH       1  // Highest available bandwidth with decimation filter enabled. Default for PAL or NTSC
#define  IMG_COLOR_LUMA_BANDWIDTH_MEDIUM     2  // Decimation filtered enabled, medium bandwidth.
#define  IMG_COLOR_LUMA_BANDWIDTH_LOW        3  // Decimation filtered enabled, lowest bandwidth.


//----------------------------------------------------------------------------
//  Comb filters
//----------------------------------------------------------------------------
#define  IMG_COLOR_COMB_OFF                  0  // Comb filtered disabled (default in S-Video/Y/C mode)
#define  IMG_COLOR_COMB_1LINE                1  // Comb filtered using 1 delayed line
#define  IMG_COLOR_COMB_2LINES               2  // Comb filtered using 2 delayed lines


//----------------------------------------------------------------------------
//  Chroma processing
//----------------------------------------------------------------------------
#define  IMG_COLOR_CHROMA_PROCESS_ALWAYS_OFF 0  // should be used when a monochrome camera is used. Default for RS-170 or CCIR
#define  IMG_COLOR_CHROMA_PROCESS_ALWAYS_ON  1  // should be used when a color camera is used.  Default for NTSC or PAL
#define  IMG_COLOR_CHROMA_PROCESS_AUTODETECT 2  // can be used if the camera type is unknown.


//----------------------------------------------------------------------------
//  Chroma bandwidth
//----------------------------------------------------------------------------
#define  IMG_COLOR_CHROMA_BANDWIDTH_HIGH     0  // Highest bandwidth (default)
#define  IMG_COLOR_CHROMA_BANDWIDTH_LOW      1  // Lowest bandwidth


//----------------------------------------------------------------------------
//  RGB Coring
//----------------------------------------------------------------------------
#define  IMG_COLOR_RGB_CORING_LEVEL_NOCORING 0  // The coring function is disabled
#define  IMG_COLOR_RGB_CORING_LEVEL_C1       1  // Coring activated for saturation equal or below 1 lsb
#define  IMG_COLOR_RGB_CORING_LEVEL_C3       2  // Coring activated for saturation equal or below 3 lsb
#define  IMG_COLOR_RGB_CORING_LEVEL_C7       3  // Coring activated for saturation equal or below 7 lsb


//----------------------------------------------------------------------------
//  Video Signal Types
//----------------------------------------------------------------------------
#define  IMG_VIDEO_NTSC                      0
#define  IMG_VIDEO_PAL                       1


//----------------------------------------------------------------------------
//  imgSessionExamineBuffer constants
//----------------------------------------------------------------------------
#define  IMG_LAST_BUFFER                     0xFFFFFFFE
#define  IMG_OLDEST_BUFFER                   0xFFFFFFFD
#define  IMG_CURRENT_BUFFER                  0xFFFFFFFC


//----------------------------------------------------------------------------
//  Buffer Element Specifiers
//----------------------------------------------------------------------------
#define  IMG_BUFF_ADDRESS                    (_IMG_BASE + 0x007E)   //  void*
#define  IMG_BUFF_COMMAND                    (_IMG_BASE + 0x007F)   //  uInt32
#define  IMG_BUFF_SKIPCOUNT                  (_IMG_BASE + 0x0080)   //  uInt32
#define  IMG_BUFF_SIZE                       (_IMG_BASE + 0x0082)   //  uInt32
#define  IMG_BUFF_TRIGGER                    (_IMG_BASE + 0x0083)   //  uInt32
#define  IMG_BUFF_NUMBUFS                    (_IMG_BASE + 0x00B0)   //  uInt32
#define  IMG_BUFF_CHANNEL                    (_IMG_BASE + 0x00Bc)   //  uInt32
#define  IMG_BUFF_ACTUALHEIGHT               (_IMG_BASE + 0x0400)   //  uInt32


//----------------------------------------------------------------------------
//  Possible Buffer Command Values
//----------------------------------------------------------------------------
#define  IMG_CMD_NEXT                        0x01  // Proceed to next list entry
#define  IMG_CMD_LOOP                        0x02  // Loop back to start of buffer list and continue processing - RING ACQUISITION
#define  IMG_CMD_PASS                        0x04  // Do nothing here
#define  IMG_CMD_STOP                        0x08  // Stop
#define  IMG_CMD_INVALID                     0x10  // Reserved for internal use


//----------------------------------------------------------------------------
//  Possible Triggered Acquisition Actions
//----------------------------------------------------------------------------
#define  IMG_TRIG_ACTION_NONE                0 // no trigger action
#define  IMG_TRIG_ACTION_CAPTURE             1 // one trigger required to start the acquisition once
#define  IMG_TRIG_ACTION_BUFLIST             2 // one trigger required to start the buflist each time
#define  IMG_TRIG_ACTION_BUFFER              3 // one trigger required for each buffer
#define  IMG_TRIG_ACTION_STOP                4 // one trigger is used to stop the acquisition


//----------------------------------------------------------------------------
// Old RTSI mapping constants (imgSessionSetRTSImap)
//----------------------------------------------------------------------------
#define  IMG_TRIG_MAP_RTSI0_DISABLED         0x0000000f
#define  IMG_TRIG_MAP_RTSI0_EXT0             0x00000001
#define  IMG_TRIG_MAP_RTSI0_EXT1             0x00000002
#define  IMG_TRIG_MAP_RTSI0_EXT2             0x00000003
#define  IMG_TRIG_MAP_RTSI0_EXT3             0x00000004
#define  IMG_TRIG_MAP_RTSI0_EXT4             0x00000005
#define  IMG_TRIG_MAP_RTSI0_EXT5             0x00000006
#define  IMG_TRIG_MAP_RTSI0_EXT6             0x00000007

#define  IMG_TRIG_MAP_RTSI1_DISABLED         0x000000f0
#define  IMG_TRIG_MAP_RTSI1_EXT0             0x00000010
#define  IMG_TRIG_MAP_RTSI1_EXT1             0x00000020
#define  IMG_TRIG_MAP_RTSI1_EXT2             0x00000030
#define  IMG_TRIG_MAP_RTSI1_EXT3             0x00000040
#define  IMG_TRIG_MAP_RTSI1_EXT4             0x00000050
#define  IMG_TRIG_MAP_RTSI1_EXT5             0x00000060
#define  IMG_TRIG_MAP_RTSI1_EXT6             0x00000070

#define  IMG_TRIG_MAP_RTSI2_DISABLED         0x00000f00
#define  IMG_TRIG_MAP_RTSI2_EXT0             0x00000100
#define  IMG_TRIG_MAP_RTSI2_EXT1             0x00000200
#define  IMG_TRIG_MAP_RTSI2_EXT2             0x00000300
#define  IMG_TRIG_MAP_RTSI2_EXT3             0x00000400
#define  IMG_TRIG_MAP_RTSI2_EXT4             0x00000500
#define  IMG_TRIG_MAP_RTSI2_EXT5             0x00000600
#define  IMG_TRIG_MAP_RTSI2_EXT6             0x00000700

#define  IMG_TRIG_MAP_RTSI3_DISABLED         0x0000f000
#define  IMG_TRIG_MAP_RTSI3_EXT0             0x00001000
#define  IMG_TRIG_MAP_RTSI3_EXT1             0x00002000
#define  IMG_TRIG_MAP_RTSI3_EXT2             0x00003000
#define  IMG_TRIG_MAP_RTSI3_EXT3             0x00004000
#define  IMG_TRIG_MAP_RTSI3_EXT4             0x00005000
#define  IMG_TRIG_MAP_RTSI3_EXT5             0x00006000
#define  IMG_TRIG_MAP_RTSI3_EXT6             0x00007000


//----------------------------------------------------------------------------
//  Frame timeout values
//----------------------------------------------------------------------------
#define  IMG_FRAMETIME_STANDARD              100      //    100 milliseconds
#define  IMG_FRAMETIME_1SECOND               1000     //   1000 milliseconds -  1 second
#define  IMG_FRAMETIME_2SECONDS              2000     //   2000 milliseconds -  2 seconds
#define  IMG_FRAMETIME_5SECONDS              5000     //   5000 milliseconds -  5 seconds
#define  IMG_FRAMETIME_10SECONDS             10000    //  10000 milliseconds - 10 seconds
#define  IMG_FRAMETIME_1MINUTE               60000    //  60000 milliseconds -  1 minute
#define  IMG_FRAMETIME_2MINUTES              120000   // 120000 milliseconds -  2 minutes
#define  IMG_FRAMETIME_5MINUTES              300000   // 300000 milliseconds -  5 minutes
#define  IMG_FRAMETIME_10MINUTES             600000   // 600000 milliseconds - 10 minutes


//----------------------------------------------------------------------------
//  Timeout values
//----------------------------------------------------------------------------
#define  IMG_TIMEOUT_INFINITE                0xFFFFFFFF


//----------------------------------------------------------------------------
//  Gain values
//----------------------------------------------------------------------------
#define  IMG_GAIN_0DB                        0
#define  IMG_GAIN_3DB                        1
#define  IMG_GAIN_6DB                        2


//----------------------------------------------------------------------------
//  Gain values for the 1409
//----------------------------------------------------------------------------
#define  IMG_GAIN_2_00                       0
#define  IMG_GAIN_1_75                       1
#define  IMG_GAIN_1_50                       2
#define  IMG_GAIN_1_00                       3


//----------------------------------------------------------------------------
//  Analog bandwidth
//----------------------------------------------------------------------------
#define  IMG_BANDWIDTH_FULL                  0
#define  IMG_BANDWIDTH_9MHZ                  1


//----------------------------------------------------------------------------
//  White and black reference ranges
//----------------------------------------------------------------------------
#define  IMG_WHITE_REFERENCE_MIN             0
#define  IMG_WHITE_REFERENCE_MAX             63
#define  IMG_BLACK_REFERENCE_MIN             0
#define  IMG_BLACK_REFERENCE_MAX             63


//----------------------------------------------------------------------------
//  Possible Trigger Polarities
//----------------------------------------------------------------------------
#define  IMG_TRIG_POLAR_ACTIVEH              0
#define  IMG_TRIG_POLAR_ACTIVEL              1


//----------------------------------------------------------------------------
//  The Trigger Lines
//  Important!!!  If you change the number of lines or add a different
//  kind of line, be sure to update IsExtTrigLine(), IsRTSILine(), or add
//  a new IsXXXLine() function, as appropriate.
//----------------------------------------------------------------------------
#define  IMG_EXT_TRIG0                       0
#define  IMG_EXT_TRIG1                       1
#define  IMG_EXT_TRIG2                       2
#define  IMG_EXT_TRIG3                       3
#define  IMG_EXT_RTSI0                       4
#define  IMG_EXT_RTSI1                       5
#define  IMG_EXT_RTSI2                       6
#define  IMG_EXT_RTSI3                       7
#define  IMG_EXT_RTSI4                       12
#define  IMG_EXT_RTSI5                       13
#define  IMG_EXT_RTSI6                       14
#define  IMG_TRIG_ROUTE_DISABLED             0xFFFFFFFF


//----------------------------------------------------------------------------
//  Internal Signals
//  These are the signals that you can wait on or use to trigger the start
//  of pulse generation.
//----------------------------------------------------------------------------
#define  IMG_AQ_DONE                         8     // wait for the entire acquisition to complete
#define  IMG_FRAME_START                     9     // wait for the frame to start
#define  IMG_FRAME_DONE                      10    // wait for the frame to complete
#define  IMG_BUF_COMPLETE                    11    // wait for the buffer to complete
#define  IMG_AQ_IN_PROGRESS                  15
#define  IMG_IMMEDIATE                       16
#define  IMG_FIXED_FREQUENCY                 17    // used in imgSessionLineTrigSrouce (linescan)
#define  IMG_LINE_VALID                      18    // wait for line valid signal (HSYNC)
#define  IMG_FRAME_VALID                     19    // wait for frame valid signal (VSYNC)


//----------------------------------------------------------------------------
//  IMAQ Vision Compatible Image Types.
//----------------------------------------------------------------------------
#define  IMG_IMAGE_U8                        0  // Unsigned 8-bit image
#define  IMG_IMAGE_I16                       1  // Signed 16-bit image
#define  IMG_IMAGE_RGB32                     4  // 32-bit RGB image
#define  IMG_IMAGE_HSL32                     5  // 32-bit HSL image
#define  IMG_IMAGE_RGB64                     6  // 64-bit RGB image
#define  IMG_IMAGE_U16                       7  // Unsigned 16-bit image


//----------------------------------------------------------------------------
//  Color representations
//----------------------------------------------------------------------------
#define  IMG_COLOR_REP_RGB32                 0  // 32 bits RGB
#define  IMG_COLOR_REP_RED8                  1  // 8 bits Red
#define  IMG_COLOR_REP_GREEN8                2  // 8 bits Green
#define  IMG_COLOR_REP_BLUE8                 3  // 8 bits Blue
#define  IMG_COLOR_REP_LUM8                  4  // 8 bits Light
#define  IMG_COLOR_REP_HUE8                  5  // 8 bits Hue
#define  IMG_COLOR_REP_SAT8                  6  // 8 bits Saturation
#define  IMG_COLOR_REP_INT8                  7  // 8 bits Intensity
#define  IMG_COLOR_REP_LUM16                 8  // 16 bits Light
#define  IMG_COLOR_REP_HUE16                 9  // 16 bits Hue
#define  IMG_COLOR_REP_SAT16                 10 // 16 bits Saturation
#define  IMG_COLOR_REP_INT16                 11 // 16 bits Intensity
#define  IMG_COLOR_REP_RGB48                 12 // 48 bits RGB
#define  IMG_COLOR_REP_RGB24                 13 // 24 bits RGB
#define  IMG_COLOR_REP_RGB16                 14 // 16 bits RGB (x555)
#define  IMG_COLOR_REP_HSL32                 15 // 32 bits HSL
#define  IMG_COLOR_REP_HSI32                 16 // 32 bits HSI
#define  IMG_COLOR_REP_NONE                  17 // No color information. Use bit-depth
#define  IMG_COLOR_REP_MONO10                18 // 10 bit Monochrome


//----------------------------------------------------------------------------
//  Specifies the size of each array element in the interface names array
//----------------------------------------------------------------------------
#define  INTERFACE_NAME_SIZE              256


//----------------------------------------------------------------------------
//  Pulse timebases
//----------------------------------------------------------------------------
#define  PULSE_TIMEBASE_PIXELCLK             0x00000001
#define  PULSE_TIMEBASE_50MHZ                0x00000002
#define  PULSE_TIMEBASE_100KHZ               0x00000003
#define  PULSE_TIMEBASE_SCALED_ENCODER       0x00000004


//----------------------------------------------------------------------------
//  Pulse mode
//----------------------------------------------------------------------------
#define  PULSE_MODE_TRAIN                    0x00000001
#define  PULSE_MODE_SINGLE                   0x00000002
#define  PULSE_MODE_SINGLE_REARM             0x00000003


//----------------------------------------------------------------------------
//  Pulse polarities
//----------------------------------------------------------------------------
#define  IMG_PULSE_POLAR_ACTIVEH             0
#define  IMG_PULSE_POLAR_ACTIVEL             1


//----------------------------------------------------------------------------
//  Power Over CameraLink states
//----------------------------------------------------------------------------
#define  IMG_POCL_UNKNOWN                    0xFFFFFFFF // The PoCL circuitry is in an unknown state
#define  IMG_POCL_NOT_SUPPORTED              0          // The PoCL circuitry does not exist on the device
#define  IMG_POCL_NO_AUX_POWER               1          // The PoCL circuitry has no power supply and thus cannot provide power
#define  IMG_POCL_BAD_FUSE                   2          // The PoCL circuitry has a blown fuse and thus cannot provide power
#define  IMG_POCL_DISABLED                   3          // The PoCL circuitry is disabled
#define  IMG_POCL_FAULT                      4          // The PoCL circuitry has detected a fault
#define  IMG_POCL_INITIALIZING               5          // The PoCL circuitry is initializing
#define  IMG_POCL_INACTIVE                   6          // The PoCL circuitry is enabled but not providing power
#define  IMG_POCL_ACTIVE                     7          // The PoCL circuitry is enabled and providing power


//----------------------------------------------------------------------------
//  Trigger drive
//----------------------------------------------------------------------------
#define  IMG_TRIG_DRIVE_DISABLED             0
#define  IMG_TRIG_DRIVE_AQ_IN_PROGRESS       1
#define  IMG_TRIG_DRIVE_AQ_DONE              2
#define  IMG_TRIG_DRIVE_PIXEL_CLK            3
#define  IMG_TRIG_DRIVE_UNASSERTED           4
#define  IMG_TRIG_DRIVE_ASSERTED             5
#define  IMG_TRIG_DRIVE_HSYNC                6
#define  IMG_TRIG_DRIVE_VSYNC                7
#define  IMG_TRIG_DRIVE_FRAME_START          8
#define  IMG_TRIG_DRIVE_FRAME_DONE           9
#define  IMG_TRIG_DRIVE_SCALED_ENCODER       10


//----------------------------------------------------------------------------
//  imgPlot Flags
//----------------------------------------------------------------------------
#define  IMGPLOT_MONO_8                      0x00000000
#define  IMGPLOT_INVERT                      0x00000001
#define  IMGPLOT_COLOR_RGB24                 0x00000002
#define  IMGPLOT_COLOR_RGB32                 0x00000004
#define  IMGPLOT_MONO_10                     0x00000008
#define  IMGPLOT_MONO_12                     0x00000010
#define  IMGPLOT_MONO_14                     0x00000020
#define  IMGPLOT_MONO_16                     0x00000040
#define  IMGPLOT_MONO_32                     0x00000080
#define  IMGPLOT_AUTO                        0x00000100


//----------------------------------------------------------------------------
//  Stillcolor modes.  OBSOLETE.
//----------------------------------------------------------------------------
#define  IMG_COLOR_MODE_DISABLED             0        // Color mode disabled
#define  IMG_COLOR_MODE_RGB                  1        // Color mode RGB StillColor
#define  IMG_COLOR_MODE_COMPOSITE_STLC       2        // Color mode Composite StillColor


//----------------------------------------------------------------------------
//  Signal states
//----------------------------------------------------------------------------
typedef enum {
   IMG_SIGNAL_STATE_RISING  = 0,
   IMG_SIGNAL_STATE_FALLING = 1,
   IMG_SIGNAL_STATE_HIGH    = 2,
   IMG_SIGNAL_STATE_LOW     = 3,
   IMG_SIGNAL_STATE_HI_Z    = 4
} IMG_SIGNAL_STATE;


//----------------------------------------------------------------------------
//  ROI Fit Modes
//----------------------------------------------------------------------------
typedef enum {
    IMG_ROI_FIT_LARGER,
    IMG_ROI_FIT_SMALLER
} IMG_ROI_FIT_MODE;


//----------------------------------------------------------------------------
//  Signal Types
//----------------------------------------------------------------------------
typedef enum {
    IMG_SIGNAL_NONE                 = 0xFFFFFFFF,
    IMG_SIGNAL_EXTERNAL             = 0,
    IMG_SIGNAL_RTSI                 = 1,
    IMG_SIGNAL_ISO_IN               = 2,
    IMG_SIGNAL_ISO_OUT              = 3,
    IMG_SIGNAL_STATUS               = 4,
    IMG_SIGNAL_SCALED_ENCODER       = 5,
    IMG_SIGNAL_SOFTWARE_TRIGGER     = 6
} IMG_SIGNAL_TYPE;


//----------------------------------------------------------------------------
//  Overwrite Modes
//----------------------------------------------------------------------------
typedef enum {
    IMG_OVERWRITE_GET_OLDEST         = 0,
    IMG_OVERWRITE_GET_NEXT_ITERATION = 1,
    IMG_OVERWRITE_FAIL               = 2,
    IMG_OVERWRITE_GET_NEWEST         = 3
} IMG_OVERWRITE_MODE;


//----------------------------------------------------------------------------
//  Sensor Scan Modes
//----------------------------------------------------------------------------
typedef enum {
    IMG_SENSOR_PARTIAL_SCAN_OFF     = 0,
    IMG_SENSOR_PARTIAL_SCAN_HALF    = 1,
    IMG_SENSOR_PARTIAL_SCAN_QUARTER = 2
} IMG_SENSOR_PARTIAL_SCAN;


//----------------------------------------------------------------------------
//  Sensor Binning Modes
//----------------------------------------------------------------------------
typedef enum {
    IMG_SENSOR_BINNING_OFF = 0,
    IMG_SENSOR_BINNING_1x2 = 1,
} IMG_SENSOR_BINNING;


//----------------------------------------------------------------------------
//  LED States
//----------------------------------------------------------------------------
typedef enum {
    IMG_LED_OFF = 0,
    IMG_LED_ON  = 1
} IMG_LED_STATE;


//----------------------------------------------------------------------------
//  Timebases
//----------------------------------------------------------------------------
typedef enum {
    IMG_TIMEBASE_PIXELCLK       = 1,
    IMG_TIMEBASE_50MHZ          = 2,
    IMG_TIMEBASE_100KHZ         = 3,
    IMG_TIMEBASE_SCALED_ENCODER = 4,
    IMG_TIMEBASE_MILLISECONDS   = 5
} IMG_TIMEBASE;


//----------------------------------------------------------------------------
//  Buffer location specifier.
//----------------------------------------------------------------------------
#define IMG_HOST_FRAME                    0
#define IMG_DEVICE_FRAME                  1


//----------------------------------------------------------------------------
//  Bayer decoding pattern.
//----------------------------------------------------------------------------
#define  IMG_BAYER_PATTERN_NONE           0xFFFFFFFF
#define  IMG_BAYER_PATTERN_GBGB_RGRG      0
#define  IMG_BAYER_PATTERN_GRGR_BGBG      1
#define  IMG_BAYER_PATTERN_BGBG_GRGR      2
#define  IMG_BAYER_PATTERN_RGRG_GBGB      3


//----------------------------------------------------------------------------
//  Bayer decoding algorithm.
//----------------------------------------------------------------------------
#define  IMG_BAYER_ALGORITHM_BILINEAR 0
#define  IMG_BAYER_ALGORITHM_VNG      1


//----------------------------------------------------------------------------
//  Internal Lighting Modes
//----------------------------------------------------------------------------
typedef enum {
    IMG_LIGHTING_OFF = 0,
    IMG_LIGHTING_CONTINUOUS = 1,
    IMG_LIGHTING_STROBED = 2
} IMG_LIGHTING_MODE;


//----------------------------------------------------------------------------
//  External Lighting Modes
//----------------------------------------------------------------------------
typedef enum {
    IMG_LIGHTING_EXTERNAL_STROBE_OFF = 0,
    IMG_LIGHTING_EXTERNAL_STROBE_RISING = 1,
    IMG_LIGHTING_EXTERNAL_STROBE_FALLING = 2
} IMG_LIGHTING_EXTERNAL_STROBE_MODE;


//----------------------------------------------------------------------------
//  Callback pointer definition
//----------------------------------------------------------------------------
typedef  uInt32 (NI_CDECL * CALL_BACK_PTR)(SESSION_ID boardid, IMG_ERR err, uInt32 signal, void* data);
typedef  uInt32 (NI_CDECL * CALL_BACK_PTR2)(SESSION_ID boardid, IMG_ERR err, IMG_SIGNAL_TYPE signalType, uInt32 signalIdentifier, void* data);


//============================================================================
//  Error and Warning Codes
//============================================================================
#include "niimaq_errors_legacy.h"
#include "niimaq_errors.h"


//============================================================================
//  Functions
//============================================================================
USER_FUNC imgInterfaceOpen(const Int8* interface_name, INTERFACE_ID* ifid);
USER_FUNC imgSessionOpen(INTERFACE_ID ifid, SESSION_ID* sid);
USER_FUNC imgClose(uInt32 void_id, uInt32 freeResources);
USER_FUNC imgSnap(SESSION_ID sid, void **bufAddr);
USER_FUNC imgSnapArea(SESSION_ID sid, void **bufAddr,uInt32 top,uInt32 left, uInt32 height, uInt32 width,uInt32 rowBytes);
USER_FUNC imgGrabSetup(SESSION_ID sid, uInt32 startNow);
USER_FUNC imgGrab(SESSION_ID sid, void** bufPtr, uInt32 syncOnVB);
USER_FUNC imgGrabArea(SESSION_ID sid, void** bufPtr, uInt32 syncOnVB, uInt32 top, uInt32 left, uInt32 height, uInt32 width, uInt32 rowBytes);
USER_FUNC imgRingSetup(SESSION_ID sid,  uInt32 numberBuffer,void* bufferList[], uInt32 skipCount, uInt32 startnow);
USER_FUNC imgSequenceSetup(SESSION_ID sid,  uInt32 numberBuffer,void* bufferList[], uInt32 skipCount[], uInt32 startnow, uInt32 async);
USER_FUNC imgSessionStartAcquisition(SESSION_ID sid);
USER_FUNC imgSessionStopAcquisition(SESSION_ID sid);
USER_FUNC imgSessionStatus(SESSION_ID sid, uInt32* boardStatus, uInt32* bufIndex);
USER_FUNC imgSessionConfigureROI(SESSION_ID sid, uInt32 top, uInt32 left, uInt32 height, uInt32 width);
USER_FUNC imgSessionGetROI(SESSION_ID sid, uInt32* top, uInt32* left, uInt32* height, uInt32* width);
USER_FUNC imgSessionGetBufferSize(SESSION_ID sid, uInt32* sizeNeeded);
USER_FUNC imgGetAttribute(uInt32 void_id, uInt32 attribute, void* value);
USER_FUNC imgCreateBuffer(SESSION_ID sid, uInt32 where, uInt32 bufferSize, void** bufAddr);
USER_FUNC imgDisposeBuffer(void* bufferPtr);
USER_FUNC imgCreateBufList(uInt32 numElements, BUFLIST_ID* bufListId);
USER_FUNC imgDisposeBufList(BUFLIST_ID bid, uInt32 freeResources);
USER_FUNC imgGetBufferElement(BUFLIST_ID bid, uInt32 element, uInt32 itemType, void *itemValue);
USER_FUNC imgSessionConfigure(SESSION_ID sid, BUFLIST_ID buflist);
USER_FUNC imgSessionAcquire(SESSION_ID sid, uInt32 async, CALL_BACK_PTR callback);
USER_FUNC imgSessionAbort(SESSION_ID sid, uInt32* bufNum);
USER_FUNC imgSessionReleaseBuffer(SESSION_ID sid);
USER_FUNC imgSessionClearBuffer(SESSION_ID sid, uInt32 buf_num, uInt8 pixel_value);
USER_FUNC imgSessionGetLostFramesList(SESSION_ID sid, uInt32* framelist, uInt32 numEntries);
USER_FUNC imgSessionSetUserLUT8bit(SESSION_ID sid, uInt32 lutType, uInt8 *lut);
USER_FUNC imgSessionSetUserLUT16bit(SESSION_ID sid, uInt32 lutType, uInt16 *lut);
USER_FUNC imgGetCameraAttributeNumeric(SESSION_ID sid, const Int8* attributeString,double *currentValueNumeric);
USER_FUNC imgSetCameraAttributeNumeric(SESSION_ID sid, const Int8* attributeString,double newValueNumeric);
USER_FUNC imgGetCameraAttributeString(SESSION_ID sid, const Int8* attributeString,Int8* currentValueString,uInt32 sizeofCurrentValueString);
USER_FUNC imgSetCameraAttributeString(SESSION_ID sid, const Int8* attributeString,Int8* newValueString);
USER_FUNC imgSessionSerialWrite(SESSION_ID sid, Int8 *buffer, uInt32 *bufSize, uInt32 timeout);
USER_FUNC imgSessionSerialRead(SESSION_ID sid, Int8 *buffer, uInt32 *bufSize, uInt32 timeout);
USER_FUNC imgSessionSerialReadBytes(SESSION_ID sid, char* buffer, uInt32 *bufferSize, uInt32 timeout);
USER_FUNC imgSessionSerialFlush(SESSION_ID sid);
USER_FUNC imgPulseCreate2(uInt32 timeBase, uInt32 delay, uInt32 width, IMG_SIGNAL_TYPE signalType, uInt32 signalIdentifier, uInt32 signalPolarity, IMG_SIGNAL_TYPE outputType, uInt32 outputNumber, uInt32 outputPolarity, uInt32 pulseMode, PULSE_ID* plsID);
USER_FUNC imgPulseDispose(PULSE_ID plsID);
USER_FUNC imgPulseRate(double delaytime, double widthtime, uInt32* delay, uInt32* width, uInt32* timebase);
USER_FUNC imgPulseStart(PULSE_ID pid,SESSION_ID sid);
USER_FUNC imgPulseUpdate(PULSE_ID pid, SESSION_ID sid, uInt32 delay, uInt32 width);
USER_FUNC imgPulseStop(PULSE_ID pid);
USER_FUNC imgSessionWaitSignal2(SESSION_ID sid, IMG_SIGNAL_TYPE signalType, uInt32 signalIdentifier, uInt32 signalPolarity, uInt32 timeout);
USER_FUNC imgSessionTriggerDrive2(SESSION_ID sid, IMG_SIGNAL_TYPE trigType, uInt32 trigNum, uInt32 polarity, uInt32 signal);
USER_FUNC imgSessionTriggerRead2(SESSION_ID sid, IMG_SIGNAL_TYPE trigType, uInt32 trigNum, uInt32 polarity, uInt32* status);
USER_FUNC imgSessionTriggerRoute2(SESSION_ID sid, IMG_SIGNAL_TYPE srcTriggerType, uInt32 srcTriggerNumber, IMG_SIGNAL_TYPE dstTriggerType, uInt32 dstTriggerNumber);
USER_FUNC imgSessionTriggerClear(SESSION_ID sid);
USER_FUNC imgSessionTriggerConfigure2(SESSION_ID sid, IMG_SIGNAL_TYPE trigType, uInt32 trigNum, uInt32 polarity, uInt32 timeout, uInt32 action);
USER_FUNC imgSessionSaveBufferEx(SESSION_ID sid, void *buffer,Int8* file_name);
USER_FUNC imgShowError(IMG_ERR error, Int8* text);
USER_FUNC imgInterfaceReset(INTERFACE_ID ifid);
USER_FUNC imgInterfaceQueryNames(uInt32 index, Int8* queryName);
USER_FUNC imgCalculateBayerColorLUT(double redGain, double greenGain, double blueGain, uInt32* redLUT, uInt32* greenLUT, uInt32* blueLUT, uInt32 bitDepth);
USER_FUNC imgBayerColorDecode(void* dst, const void* src, uInt32 rows, uInt32 cols, uInt32 dstRowPixels, uInt32 srcRowPixels, const uInt32* redLUT, const uInt32* greenLUT, const uInt32* blueLUT, uInt8 bayerPattern, uInt32 bitDepth, uInt32 reserved);
USER_FUNC imgSessionLineTrigSource2(SESSION_ID sid, IMG_SIGNAL_TYPE trigType, uInt32 trigNum, uInt32 polarity, uInt32 skip);
USER_FUNC imgSessionFitROI(SESSION_ID sid, IMG_ROI_FIT_MODE fitMode, uInt32 top, uInt32 left, uInt32 height, uInt32 width, uInt32* fittedTop, uInt32* fittedLeft, uInt32* fittedHeight, uInt32* fittedWidth);
USER_FUNC imgEncoderResetPosition(SESSION_ID sid);
USER_FUNC imgSessionCopyBufferByNumber(SESSION_ID sid, uInt32 bufNumber, void* userBuffer, IMG_OVERWRITE_MODE overwriteMode, uInt32* copiedNumber, uInt32* copiedIndex);
USER_FUNC imgSessionCopyAreaByNumber(SESSION_ID sid, uInt32 bufNumber, uInt32 top, uInt32 left, uInt32 height, uInt32 width, void* userBuffer, uInt32 rowPixels, IMG_OVERWRITE_MODE overwriteMode, uInt32* copiedNumber, uInt32* copiedIndex);
USER_FUNCC imgSetAttribute2(uInt32 void_id, uInt32 attribute, ...);
USER_FUNCC imgSetBufferElement2(BUFLIST_ID bid, uInt32 element, uInt32 itemType, ...);
USER_FUNC imgSessionExamineBuffer2(SESSION_ID sid, uInt32 whichBuffer, uInt32 *bufferNumber, void** bufferAddr);
USER_FUNC imgPlot2(void* hwnd, void* buffer, uInt32 leftBufOffset, uInt32 topBufOffset, uInt32 xsize, uInt32 ysize, uInt32 xpos, uInt32 ypos, uInt32 flags);
USER_FUNC imgPlotDC2(void* hdc, void* buffer, uInt32 xbuffoff, uInt32 ybuffoff, uInt32 xsize, uInt32 ysize, uInt32 xscreen, uInt32 yscreen, uInt32 flags);
USER_FUNC imgSetAttributeFromVoidPtr(uInt32 void_id, uInt32 attribute, const void* valuePtr);
USER_FUNC imgSetBufferElementFromVoidPtr(BUFLIST_ID bid, uInt32 element, uInt32 itemType, const void* valuePtr);
USER_FUNC imgSessionWaitSignalAsync3(SESSION_ID sid, IMG_SIGNAL_TYPE signalType, uInt32 signalIdentifier, uInt32 signalPolarity, uInt32 timeout, CALL_BACK_PTR2 funcptr, void* callbackData);


//============================================================================
//  Obsolete Functions
//============================================================================
USER_FUNC imgPulseCreate(uInt32 timeBase,uInt32 delay,uInt32 width,uInt32 signal_source,uInt32 signal_polar,uInt32 output,uInt32 output_polarity,uInt32 pulse_mode,PULSE_ID* plsID);
USER_FUNC imgSessionWaitSignal(SESSION_ID sid,uInt32 signal,uInt32 signal_pol, uInt32 timeout);
USER_FUNC imgSessionWaitSignalAsync(SESSION_ID sid,uInt32 signal,uInt32 signal_pol,CALL_BACK_PTR funcptr, void* callback_data);
USER_FUNC imgSessionTriggerDrive(SESSION_ID sid,uInt32 trig_num,uInt32 trig_polarity,uInt32 trig_drive);
USER_FUNC imgSessionTriggerRead(SESSION_ID sid, uInt32 trig_num, uInt32 polarity, uInt32* status);
USER_FUNC imgSessionTriggerRoute(SESSION_ID sid, uInt32 srcTrig, uInt32 dstTrig);
USER_FUNC imgSessionTriggerConfigure(SESSION_ID sid,uInt32 trig_num,uInt32 trig_polarity,uInt32 time_out,uInt32 trig_action);
USER_FUNC imgSessionLineTrigSource(SESSION_ID boardid, uInt32 trigNum, uInt32 polarity, uInt32 skip);
USER_FUNC imgSessionWait(SESSION_ID sid);
USER_FUNC imgSessionWaitAqdone(SESSION_ID sid);
USER_FUNC imgSessionWaitVblank(SESSION_ID sid);
USER_FUNC imgWaitBuffComplete(SESSION_ID sid);
USER_FUNC imgWaitFrameDone(SESSION_ID sid);
USER_FUNC imgWaitFrameStart(SESSION_ID sid);
USER_FUNC imgMemLock(BUFLIST_ID bid);
USER_FUNC imgMemUnlock(BUFLIST_ID bid);
USER_FUNC imgSessionCopyArea(SESSION_ID boardid, uInt32 bufIndex, uInt32 top, uInt32 left, uInt32 height, uInt32 width, Ptr userBuffer, uInt32 rowPixels, uInt32 waitForBufferDone);
USER_FUNC imgSessionCopyBuffer(SESSION_ID boardid, uInt32 bufIndex, uInt8* userBuffer, uInt32 waitForBufferDone);
USER_FUNC imgSetAttribute(uInt32 void_id, uInt32 type, uInt32 value);
USER_FUNC imgSetBufferElement(BUFLIST_ID bid, uInt32 element, uInt32 itemType, uInt32 itemValue);
USER_FUNC imgSessionExamineBuffer(SESSION_ID sid, uInt32 whichBuffer,uInt32 *bufferNumber,uInt32* bufferAddr);
USER_FUNC imgPlot(GUIHNDL window,void* buffer,uInt32 leftBufOffset,uInt32 topBufOffset,uInt32 xsize,uInt32 ysize,uInt32 xpos,uInt32 ypos,uInt32 flags);
USER_FUNC imgPlotDC(GUIHNDL DeviceContext,void* buffer,uInt32 xbuffoff,uInt32 ybuffoff,uInt32 xsize,uInt32 ysize,uInt32 xscreen,uInt32 yscreen,uInt32 flags);
USER_FUNC imgSessionWaitSignalAsync2(SESSION_ID sid, IMG_SIGNAL_TYPE signalType, uInt32 signalIdentifier, uInt32 signalPolarity, CALL_BACK_PTR2 funcptr, void* callbackData);


//============================================================================
//  Deprecated Functions - These will generate a MSVC warning if used
//============================================================================
#if (defined(_MSC_VER) && (_MSC_VER >= 1300))//msvc70 or above
    #pragma deprecated(imgSetAttribute, imgSetBufferElement, imgSessionExamineBuffer, imgPlot, imgPlotDC)
#endif


//============================================================================
//  imgSessionSetROI is obsolete.  Use imgSessionConfigureROI instead.
//============================================================================
#define imgSessionSetROI imgSessionConfigureROI


//============================================================================
//  Old 1408 revision numbers
//============================================================================
#define  PCIIMAQ1408_REVA                    0x00000000
#define  PCIIMAQ1408_REVB                    0x00000001
#define  PCIIMAQ1408_REVC                    0x00000002
#define  PCIIMAQ1408_REVF                    0x00000003
#define  PCIIMAQ1408_REVX                    0x00000004


//============================================================================
//  PCI device IDs
//============================================================================
#define  IMAQ_PCI_1405                       0x70CA1093
#define  IMAQ_PXI_1405                       0x70CE1093
#define  IMAQ_PCI_1407                       0xB0411093
#define  IMAQ_PXI_1407                       0xB0511093
#define  IMAQ_PCI_1408                       0xB0011093
#define  IMAQ_PXI_1408                       0xB0111093
#define  IMAQ_PCI_1409                       0xB0B11093
#define  IMAQ_PXI_1409                       0xB0C11093
#define  IMAQ_PCI_1410                       0x71871093
#define  IMAQ_PCI_1411                       0xB0611093
#define  IMAQ_PXI_1411                       0xB0911093
#define  IMAQ_PCI_1413                       0xB0311093
#define  IMAQ_PXI_1413                       0xB0321093
#define  IMAQ_PCI_1422                       0xB0711093
#define  IMAQ_PXI_1422                       0xB0811093
#define  IMAQ_PCI_1423                       0x70281093
#define  IMAQ_PXI_1423                       0x70291093
#define  IMAQ_PCI_1424                       0xB0211093
#define  IMAQ_PXI_1424                       0xB0221093
#define  IMAQ_PCI_1426                       0x715D1093
#define  IMAQ_PCIe_1427                      0x71BF1093
#define  IMAQ_PCI_1428                       0xB0E11093
#define  IMAQ_PXI_1428                       0x707C1093
#define  IMAQ_PCIX_1429                      0x71041093
#define  IMAQ_PCIe_1429                      0x71051093
#define  IMAQ_PCIe_1430                      0x71AE1093
#define  IMAQ_PCIe_1433                      0x74B61093
#define  IMAQ_PXIe_1435                      0x753C1093
#define  IMAQ_PXIe_1436                      0x756E1093
#define  IMAQ_PCIe_1437                      0x793B1093
#define  IMAQ_17xx                           0x71EC1093


//============================================================================
//  The end(if)
//============================================================================
#endif

