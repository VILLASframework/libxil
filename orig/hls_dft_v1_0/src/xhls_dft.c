// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xhls_dft.h"

/************************** Function Implementation *************************/
int XHls_dft_CfgInitialize(XHls_dft *InstancePtr, XHls_dft_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}

void XHls_dft_Start(XHls_dft *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL) & 0x80;
    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XHls_dft_IsDone(XHls_dft *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XHls_dft_IsIdle(XHls_dft *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XHls_dft_IsReady(XHls_dft *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XHls_dft_EnableAutoRestart(XHls_dft *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL, 0x80);
}

void XHls_dft_DisableAutoRestart(XHls_dft *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_AP_CTRL, 0);
}

void XHls_dft_Set_num_harmonics_V(XHls_dft *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_NUM_HARMONICS_V_DATA, Data);
}

u32 XHls_dft_Get_num_harmonics_V(XHls_dft *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_NUM_HARMONICS_V_DATA);
    return Data;
}

void XHls_dft_Set_decimation_V(XHls_dft *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_DECIMATION_V_DATA, Data);
}

u32 XHls_dft_Get_decimation_V(XHls_dft *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_DECIMATION_V_DATA);
    return Data;
}

u32 XHls_dft_Get_fharmonics_BaseAddress(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Ctrl_BaseAddress + XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE);
}

u32 XHls_dft_Get_fharmonics_HighAddress(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Ctrl_BaseAddress + XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH);
}

u32 XHls_dft_Get_fharmonics_TotalBytes(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH - XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + 1);
}

u32 XHls_dft_Get_fharmonics_BitWidth(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHLS_DFT_CTRL_WIDTH_FHARMONICS;
}

u32 XHls_dft_Get_fharmonics_Depth(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHLS_DFT_CTRL_DEPTH_FHARMONICS;
}

u32 XHls_dft_Write_fharmonics_Words(XHls_dft *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH - XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Ctrl_BaseAddress + XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XHls_dft_Read_fharmonics_Words(XHls_dft *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH - XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Ctrl_BaseAddress + XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + (offset + i)*4);
    }
    return length;
}

u32 XHls_dft_Write_fharmonics_Bytes(XHls_dft *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH - XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Ctrl_BaseAddress + XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XHls_dft_Read_fharmonics_Bytes(XHls_dft *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH - XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Ctrl_BaseAddress + XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE + offset + i);
    }
    return length;
}

void XHls_dft_InterruptGlobalEnable(XHls_dft *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_GIE, 1);
}

void XHls_dft_InterruptGlobalDisable(XHls_dft *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_GIE, 0);
}

void XHls_dft_InterruptEnable(XHls_dft *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_IER);
    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_IER, Register | Mask);
}

void XHls_dft_InterruptDisable(XHls_dft *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_IER);
    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_IER, Register & (~Mask));
}

void XHls_dft_InterruptClear(XHls_dft *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_dft_WriteReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_ISR, Mask);
}

u32 XHls_dft_InterruptGetEnabled(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_IER);
}

u32 XHls_dft_InterruptGetStatus(XHls_dft *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHls_dft_ReadReg(InstancePtr->Ctrl_BaseAddress, XHLS_DFT_CTRL_ADDR_ISR);
}

