// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xhls_dft.h"

extern XHls_dft_Config XHls_dft_ConfigTable[];

XHls_dft_Config *XHls_dft_LookupConfig(u16 DeviceId) {
	XHls_dft_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XHLS_DFT_NUM_INSTANCES; Index++) {
		if (XHls_dft_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XHls_dft_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XHls_dft_Initialize(XHls_dft *InstancePtr, u16 DeviceId) {
	XHls_dft_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XHls_dft_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XHls_dft_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

