#ifndef _EMB1_H
#define _EMB1_H

#define UART_BASE_ADDRESS 0xFC000000

// Data structure containing UART parameters including base address and other settings.
typedef struct UART_HANDLE {
    uint32_t base_address;
} UART_HANDLE;

#define CNR_OFFSET 0x0
#define BRR_OFFSET 0x4
#define STA_OFFSET 0x8
#define TDR_OFFSET 0xC
#define RDR_OFFSET 0x10

#define CNR_ENABLE_TX_RX 0x1
#define CNR_ENABLE_INTERRUPT 0x2

#define BRR_BAUD_RATE_4800  0x0
#define BRR_BAUD_RATE_9600  0x1
#define BRR_BAUD_RATE_14400 0x2
#define BRR_BAUD_RATE_19200 0x3
#define BRR_BAUD_RATE_38400 0x4
#define BRR_BAUD_RATE_57600 0x5
#define BRR_BAUD_RATE_115200 0x6
#define BRR_BAUD_RATE_128000 0x7
#define BRR_BAUD_RATE_256000 0x8

#define BRR_PARITY_OFFSET 4
#define BRR_PARITY_EVEN 0x0
#define BRR_PARITY_ODD 0x1
#define BRR_PARITY_NONE 0x2

#define BRR_HW_FLOW_CONTROL_OFFSET 8

#define BRR_STOP_BIT_OFFSET  12

 #endif