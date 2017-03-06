// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

// ctrl
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x80 : Data signal of num_harmonics_V
//        bit 7~0 - num_harmonics_V[7:0] (Read/Write)
//        others  - reserved
// 0x84 : reserved
// 0x88 : Data signal of decimation_V
//        bit 7~0 - decimation_V[7:0] (Read/Write)
//        others  - reserved
// 0x8c : reserved
// 0x40 ~
// 0x7f : Memory 'fharmonics' (16 * 32b)
//        Word n : bit [31:0] - fharmonics[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XHLS_DFT_CTRL_ADDR_AP_CTRL              0x00
#define XHLS_DFT_CTRL_ADDR_GIE                  0x04
#define XHLS_DFT_CTRL_ADDR_IER                  0x08
#define XHLS_DFT_CTRL_ADDR_ISR                  0x0c
#define XHLS_DFT_CTRL_ADDR_NUM_HARMONICS_V_DATA 0x80
#define XHLS_DFT_CTRL_BITS_NUM_HARMONICS_V_DATA 8
#define XHLS_DFT_CTRL_ADDR_DECIMATION_V_DATA    0x88
#define XHLS_DFT_CTRL_BITS_DECIMATION_V_DATA    8
#define XHLS_DFT_CTRL_ADDR_FHARMONICS_BASE      0x40
#define XHLS_DFT_CTRL_ADDR_FHARMONICS_HIGH      0x7f
#define XHLS_DFT_CTRL_WIDTH_FHARMONICS          32
#define XHLS_DFT_CTRL_DEPTH_FHARMONICS          16

