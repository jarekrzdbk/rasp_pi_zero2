#ifndef _P_UART_H
#define _P_UART_H

#include "peripherals/base.h"

#define UART_BASE (PBASE + 0x00201000)

// UART data register
#define UART_DR (UART_BASE + 0x00000000)

// UART flag register
#define UART_FR (UART_BASE + 0x00000018)

// UART Integer Baud rate divisor
#define UART_IBRD (UART_BASE + 0x00000024)

// UART Fractional Baud rate divisor
#define UART_FBRD (UART_BASE + 0x00000028)

// UART line control register
#define UART_LCRH (UART_BASE + 0x0000002c)

// UART control register
#define UART_CR (UART_BASE + 0x00000030)

#endif // _P_UART_H
