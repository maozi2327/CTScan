//////////////////////////////////////////////////////////////////////////////
//
//  Title     : niimaq_errors_legacy.h
//  Project   : NI-IMAQ
//  Platforms : All
//  Copyright : National Instruments 2017.  All Rights Reserved.
//  Access    : Public
//  Purpose   : Legacy error codes for NI-IMAQ.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef NIIMAQ_ERRORS_LEGACY_H
#define NIIMAQ_ERRORS_LEGACY_H

#ifndef IMG_ERR_GOOD
    #define IMG_ERR_GOOD 0 // no error
#endif

//----------------------------------------------------------------------------
//  Old errors (from 2.X)
//----------------------------------------------------------------------------
#define _IMG_ERR                                0xBFF60000
#define  IMG_ERR_NCAP                           (_IMG_ERR + 0x0001)  // function not implemented
#define  IMG_ERR_OVRN                           (_IMG_ERR + 0x0002)  // too many interfaces open
#define  IMG_ERR_EMEM                           (_IMG_ERR + 0x0003)  // could not allocate memory in user mode (calloc failed)
#define  IMG_ERR_OSER                           (_IMG_ERR + 0x0004)  // operating system error occurred
#define  IMG_ERR_PAR1                           (_IMG_ERR + 0x0005)  // Error with parameter 1
#define  IMG_ERR_PAR2                           (_IMG_ERR + 0x0006)  // Error with parameter 2
#define  IMG_ERR_PAR3                           (_IMG_ERR + 0x0007)  // Error with parameter 3
#define  IMG_ERR_PAR4                           (_IMG_ERR + 0x0008)  // Error with parameter 4
#define  IMG_ERR_PAR5                           (_IMG_ERR + 0x0009)  // Error with parameter 5
#define  IMG_ERR_PAR6                           (_IMG_ERR + 0x000A)  // Error with parameter 6
#define  IMG_ERR_PAR7                           (_IMG_ERR + 0x000B)  // Error with parameter 7
#define  IMG_ERR_MXBF                           (_IMG_ERR + 0x000C)  // too many buffers already allocated
#define  IMG_ERR_DLLE                           (_IMG_ERR + 0x000D)  // DLL internal error - bad logic state
#define  IMG_ERR_BSIZ                           (_IMG_ERR + 0x000E)  // buffer size used is too small for minimum acquisition frame
#define  IMG_ERR_MXBI                           (_IMG_ERR + 0x000F)  // exhausted buffer id's
#define  IMG_ERR_ELCK                           (_IMG_ERR + 0x0010)  // not enough physical memory - the system could not allocate page locked memory
#define  IMG_ERR_DISE                           (_IMG_ERR + 0x0011)  // error releasing the image buffer
#define  IMG_ERR_BBUF                           (_IMG_ERR + 0x0012)  // bad buffer pointer in list
#define  IMG_ERR_NLCK                           (_IMG_ERR + 0x0013)  // buffer list is not locked
#define  IMG_ERR_NCAM                           (_IMG_ERR + 0x0014)  // no camera defined for this channel
#define  IMG_ERR_BINT                           (_IMG_ERR + 0x0015)  // bad interface
#define  IMG_ERR_BROW                           (_IMG_ERR + 0x0016)  // rowbytes is less than region of interest
#define  IMG_ERR_BROI                           (_IMG_ERR + 0x0017)  // bad region of interest; check width, heigh, rowpixels, and scaling
#define  IMG_ERR_BCMF                           (_IMG_ERR + 0x0018)  // bad camera file (check syntax)
#define  IMG_ERR_NVBL                           (_IMG_ERR + 0x0019)  // not successful because of hardware limitations
#define  IMG_ERR_NCFG                           (_IMG_ERR + 0x001A)  // invalid action - no buffers configured for session
#define  IMG_ERR_BBLF                           (_IMG_ERR + 0x001B)  // buffer list does not contain a valid final command
#define  IMG_ERR_BBLE                           (_IMG_ERR + 0x001C)  // buffer list does contains an invalid command
#define  IMG_ERR_BBLB                           (_IMG_ERR + 0x001D)  // a buffer list buffer is null
#define  IMG_ERR_NAIP                           (_IMG_ERR + 0x001E)  // no acquisition in progress
#define  IMG_ERR_VLCK                           (_IMG_ERR + 0x001F)  // can't get video lock
#define  IMG_ERR_BDMA                           (_IMG_ERR + 0x0020)  // bad DMA transfer
#define  IMG_ERR_AIOP                           (_IMG_ERR + 0x0021)  // can't perform request - acquisition in progress
#define  IMG_ERR_TIMO                           (_IMG_ERR + 0x0022)  // wait timed out - acquisition not complete
#define  IMG_ERR_NBUF                           (_IMG_ERR + 0x0023)  // no buffers available - too early in acquisition
#define  IMG_ERR_ZBUF                           (_IMG_ERR + 0x0024)  // zero buffer size - no bytes filled
#define  IMG_ERR_HLPR                           (_IMG_ERR + 0x0025)  // bad parameter to low level - check attributes and high level arguments
#define  IMG_ERR_BTRG                           (_IMG_ERR + 0x0026)  // trigger loopback problem - can't drive trigger with action enabled
#define  IMG_ERR_NINF                           (_IMG_ERR + 0x0027)  // no interface found
#define  IMG_ERR_NDLL                           (_IMG_ERR + 0x0028)  // unable to load DLL
#define  IMG_ERR_NFNC                           (_IMG_ERR + 0x0029)  // unable to find API function in DLL
#define  IMG_ERR_NOSR                           (_IMG_ERR + 0x002A)  // unable to allocate system resources (CVI only)
#define  IMG_ERR_BTAC                           (_IMG_ERR + 0x002B)  // no trigger action - acquisition will time out
#define  IMG_ERR_FIFO                           (_IMG_ERR + 0x002C)  // fifo overflow caused acquisition to halt
#define  IMG_ERR_MLCK                           (_IMG_ERR + 0x002D)  // memory lock error - the system could not page lock the buffer(s)
#define  IMG_ERR_ILCK                           (_IMG_ERR + 0x002E)  // interface locked
#define  IMG_ERR_NEPK                           (_IMG_ERR + 0x002F)  // no external pixel clock
#define  IMG_ERR_SCLM                           (_IMG_ERR + 0x0030)  // field scaling mode not supported
#define  IMG_ERR_SCC1                           (_IMG_ERR + 0x0031)  // still color rgb, channel not set to 1
#define  IMG_ERR_SMALLALLOC                     (_IMG_ERR + 0x0032)  // Error during small buffer allocation
#define  IMG_ERR_ALLOC                          (_IMG_ERR + 0x0033)  // Error during large buffer allocation
#define  IMG_ERR_BADCAMTYPE                     (_IMG_ERR + 0x0034)  // Bad camera type - (Not a NTSC or PAL)
#define  IMG_ERR_BADPIXTYPE                     (_IMG_ERR + 0x0035)  // Camera not supported (not 8 bits)
#define  IMG_ERR_BADCAMPARAM                    (_IMG_ERR + 0x0036)  // Bad camera parameter from the configuration file
#define  IMG_ERR_PALKEYDTCT                     (_IMG_ERR + 0x0037)  // PAL key detection error
#define  IMG_ERR_BFRQ                           (_IMG_ERR + 0x0038)  // Bad frequency values
#define  IMG_ERR_BITP                           (_IMG_ERR + 0x0039)  // Bad interface type
#define  IMG_ERR_HWNC                           (_IMG_ERR + 0x003A)  // Hardware not capable of supporting this
#define  IMG_ERR_SERIAL                         (_IMG_ERR + 0x003B)  // serial port error
#define  IMG_ERR_MXPI                           (_IMG_ERR + 0x003C)  // exhausted pulse id's
#define  IMG_ERR_BPID                           (_IMG_ERR + 0x003D)  // bad pulse id
#define  IMG_ERR_NEVR                           (_IMG_ERR + 0x003E)  // should never get this error - bad code!
#define  IMG_ERR_SERIAL_TIMO                    (_IMG_ERR + 0x003F)  // serial transmit/receive timeout
#define  IMG_ERR_PG_TOO_MANY                    (_IMG_ERR + 0x0040)  // too many PG transitions defined
#define  IMG_ERR_PG_BAD_TRANS                   (_IMG_ERR + 0x0041)  // bad PG transition time
#define  IMG_ERR_PLNS                           (_IMG_ERR + 0x0042)  // pulse not started error
#define  IMG_ERR_BPMD                           (_IMG_ERR + 0x0043)  // bad pulse mode
#define  IMG_ERR_NSAT                           (_IMG_ERR + 0x0044)  // non settable attribute
#define  IMG_ERR_HYBRID                         (_IMG_ERR + 0x0045)  // can't mix onboard and system memory buffers
#define  IMG_ERR_BADFILFMT                      (_IMG_ERR + 0x0046)  // the pixel depth is not supported by this file format
#define  IMG_ERR_BADFILEXT                      (_IMG_ERR + 0x0047)  // This file extension is not supported
#define  IMG_ERR_NRTSI                          (_IMG_ERR + 0x0048)  // exhausted RTSI map registers
#define  IMG_ERR_MXTRG                          (_IMG_ERR + 0x0049)  // exhausted trigger resources
#define  IMG_ERR_MXRC                           (_IMG_ERR + 0x004A)  // exhausted resources (general)
#define  IMG_ERR_OOR                            (_IMG_ERR + 0x004B)  // parameter out of range
#define  IMG_ERR_NPROG                          (_IMG_ERR + 0x004C)  // FPGA not programmed
#define  IMG_ERR_NEOM                           (_IMG_ERR + 0x004D)  // not enough onboard memory to perform operation
#define  IMG_ERR_BDTYPE                         (_IMG_ERR + 0x004E)  // bad display type -- buffer cannot be displayed with imgPlot
#define  IMG_ERR_THRDACCDEN                     (_IMG_ERR + 0x004F)  // thread denied access to function
#define  IMG_ERR_BADFILWRT                      (_IMG_ERR + 0x0050)  // Could not write the file
#define  IMG_ERR_AEXM                           (_IMG_ERR + 0x0051)  // Already called ExamineBuffer once.  Call ReleaseBuffer.

#endif
