#include <stdio.h>
#include <stdint.h>

#include "emb1.h"

/*
 * Story EMB-1
 * -----------
 *
 * Write an initialization routine for a UART device. The UART is a memory
 * mapped device at the address 0xFC000000 on an embedded platform.
 * This peripheral is controlled by the following 32 bit registers (offsets given)
 *
 *  CNR: control register Offset: 0x0
 *  - Bit 0: enable UART TX/RX
 *  - Bit 1: enable UART interrupt; interrupt will be caused by changes in STA register
 *
 * BRR: Baud rate register Offset: 0x4 
 * BRR[0:3] Selects the baud rate as follows
 *  - 0: 4800
 *  - 1: 9600
 *  - 2: 14400
 *  - 3: 19200
 *  - 4: 38400
 *  - 5: 57600
 *  - 6: 115200
 *  - 7: 128000
 *  - 8: 256000
 *
 *  BRR[4:5] Selects parity as follows
 *  - 0 Even Parity
 *  - 1 Odd Parity
 *  - 2 No Parity
 *
 *  - BRR[8] Turning this bit on enables hardware flow control
 *
 *  - BRR[12:15] Contains the number of stop bits
 *
 *  STA: status register Offset: 0x8
 *  - Bit 0: RX ready: if set a byte can be read from RDR, reading the byte will clear RX ready (READ-ONLY)
 *  - Bit 1: TX ready: if set a byte can be writter to TDR, writing will clear TX ready until next byte can be written (READ-ONLY)
 *
 * TDR: Transmit data register     Offset: 0xC
 *  - Contains data to be transmitted via UART
 *
 * RDR: Receive data register     Offset: 0x10  (READ-ONLY)
 *  - Contains data received via UART
 *
 * You need to write an initialization routine for this UART in C with the following configuration.
 *
 * Baud Rate: 115200, stop bits 1, parity none, flow control none
 * TX and RX are interrupt based operations, with data registers cleared at the start of operation.
 */


// write operation should write one byte to UART
void write_uart(char c)
{
    uint32_t volatile * uluart_base = (uint32_t volatile *) UART_BASE_ADDRESS;

    // Busy wait until there is a byte to write
    while (!(*uluart_base & (0x2 << STA_OFFSET))) {};

    *uluart_base |= c << TDR_OFFSET;    
}

// read one byte from UART
int read_uart()
{
    uint32_t volatile * uluart_base = (uint32_t volatile *) UART_BASE_ADDRESS;

    // Busy wait until there is a byte to read
    while (!(*uluart_base & (0x1 << STA_OFFSET))) {};

    return (*uluart_base >> RDR_OFFSET) & 0xFF;
}

// init UART
void init_uart(UART_HANDLE *h)
{
    h->base_address = UART_BASE_ADDRESS;
    uint32_t volatile * uluart_base = (uint32_t volatile *) UART_BASE_ADDRESS;

    *uluart_base |= BRR_BAUD_RATE_115200 << BRR_OFFSET;
    *uluart_base |= 0x1 << BRR_STOP_BIT_OFFSET;
    *uluart_base |= BRR_PARITY_NONE << (BRR_OFFSET+BRR_PARITY_OFFSET);
    *uluart_base &= ~(0x1 << BRR_HW_FLOW_CONTROL_OFFSET);

    *uluart_base |= CNR_ENABLE_TX_RX;
    *uluart_base |= CNR_ENABLE_INTERRUPT;
}

// Provide a sample utilizing the functions above 
// the produced code need not work (since it lacks the actual UART), but it needs
// to be "functional" in the sense that it does the right thing in code review
int main(int argc, char *argv[])
{
    UART_HANDLE* hnd;
    char c = 'a';
    int data;

    init_uart(hnd);
    write_uart(c);
    data = read_uart();
}
