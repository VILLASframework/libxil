/******************************************************************************
*
* Copyright (C) 2015 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xaxis_switch.h
* @addtogroup axis_switch_v1_0
* @{
* @details
*
* This is the main header file for Xilinx AXI4-Stream Switch Control Router
* core. It is used for routing streams where masters in the system do not know
* final destination address.
*
* <b>Core Features </b>
*
* For a full description of AXI4-Stream Switch Control Router, please see the
* hardware specification.
*
* <b>Software Initialization & Configuration</b>
*
* The application needs to do following steps in order for preparing the
* AXI4-Stream Switch Control Router core to be ready.
*
* - Call XAxisScr_LookupConfig using a device ID to find the core
*   configuration.
* - Call XAxisScr_CfgInitialize to initialize the device and the driver
*   instance associated with it.
*
* <b>Interrupts </b>
*
* This driver does not have interrupt mechanism.
*
* <b> Virtual Memory </b>
*
* This driver supports Virtual Memory. The RTOS is responsible for calculating
* the correct device base address in Virtual Memory space.
*
* <b> Threads </b>
*
* This driver is not thread safe. Any needs for threads or thread mutual
* exclusion must be satisfied by the layer above this driver.
*
* <b> Asserts </b>
*
* Asserts are used within all Xilinx drivers to enforce constraints on argument
* values. Asserts can be turned off on a system-wide basis by defining at
* compile time, the NDEBUG identifier. By default, asserts are turned on and it
* is recommended that users leave asserts on during development.
*
* <b> Building the driver </b>
*
* The XAXI4-Stream Switch driver is composed of several source files. This
* allows the user to build and link only those parts of the driver that are
* necessary.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who Date     Changes
* ----- --- -------- --------------------------------------------------
* 1.00  sha 01/28/15 Initial release.
* </pre>
*
******************************************************************************/
#ifndef XAXIS_SWITCH_H_
#define XAXIS_SWITCH_H_		/**< Prevent circular inclusions
				  *  by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "xaxis_switch_hw.h"
#include "xil_assert.h"
#include "xstatus.h"

/************************** Constant Definitions *****************************/


/**************************** Type Definitions *******************************/

/**
* This typedef contains configuration information for the AXI4-Stream Switch
* core. Each AXI4-Stream Switch device should have a configuration structure
* associated.
*/
typedef struct {
	u16 DeviceId;		/**< DeviceId is the unique ID of the AXI4-
				  *  Stream Switch core */
	u64 BaseAddress;	/**< BaseAddress is the physical base address
						 *  of the core's registers */
	u8 MaxNumSI;		/**< Maximum number of Slave interfaces */
	u8 MaxNumMI;		/**< Maximum number of Master interfaces */
} XAxis_Switch_Config;

/**
* The AXI4-Stream Switch driver instance data. An instance must be allocated
* for each core in use.
*/
typedef struct {
	XAxis_Switch_Config Config;	/**< Hardware Configuration */
	u32 IsReady;			/**< Core and the driver instance are
					  *  initialized */
} XAxis_Switch;

/***************** Macros (Inline Functions) Definitions *********************/

/*****************************************************************************/
/**
*
* This macro enables register updates.
*
* @param	InstancePtr is a pointer to the XAxis_Switch core instance.
*
* @return	None.
*
* @note		C-style signature:
*		void XAxisScr_RegUpdateEnable(XAxis_Switch *InstancePtr)
*
******************************************************************************/
#define XAxisScr_RegUpdateEnable(InstancePtr) \
	XAxisScr_WriteReg((InstancePtr)->Config.BaseAddress, \
		XAXIS_SCR_CTRL_OFFSET, \
		XAxisScr_ReadReg((InstancePtr)->Config.BaseAddress, \
			XAXIS_SCR_CTRL_OFFSET) | \
				XAXIS_SCR_CTRL_REG_UPDATE_MASK)

/*****************************************************************************/
/**
*
* This macro disables register updates.
*
* @param	InstancePtr is a pointer to the XAxis_Switch core instance.
*
* @return	None.
*
* @note		C-style signature:
*		void XAxisScr_RegUpdateDisable(XAxis_Switch *InstancePtr)
*
******************************************************************************/
#define XAxisScr_RegUpdateDisable(InstancePtr) \
	XAxisScr_WriteReg((InstancePtr)->Config.BaseAddress, \
		XAXIS_SCR_CTRL_OFFSET, \
		XAxisScr_ReadReg((InstancePtr)->Config.BaseAddress, \
			XAXIS_SCR_CTRL_OFFSET) & \
				(~XAXIS_SCR_CTRL_REG_UPDATE_MASK))

/************************** Function Prototypes ******************************/

/* Initialization function in xaxis_switch_sinit.c */
XAxis_Switch_Config *XAxisScr_LookupConfig(u16 DeviceId);

/* Initialization and control functions in xaxis_switch.c */
s32 XAxisScr_CfgInitialize(XAxis_Switch *InstancePtr,
						   XAxis_Switch_Config *CfgPtr, u64 EffectiveAddr);

void XAxisScr_MiPortEnable(XAxis_Switch *InstancePtr, u8 MiIndex,
				u8 SiIndex);
void XAxisScr_MiPortDisable(XAxis_Switch *InstancePtr, u8 MiIndex);
s32 XAxisScr_IsMiPortEnabled(XAxis_Switch *InstancePtr, u8 MiIndex,
				u8 SiIndex);
s32 XAxisScr_IsMiPortDisabled(XAxis_Switch *InstancePtr, u8 MiIndex);
void XAxisScr_MiPortDisableAll(XAxis_Switch *InstancePtr);

/* Self test function in xaxis_switch_selftest.c */
s32 XAxisScr_SelfTest(XAxis_Switch *InstancePtr);

/************************** Variable Declarations ****************************/


#ifdef __cplusplus
}
#endif

#endif /* End of protection macro */
/** @} */
