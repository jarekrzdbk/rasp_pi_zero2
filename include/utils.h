#ifndef _BOOT_H
#define _BOOT_H

#define BAUD_RATE 115200
#define UART_CLOCK_HZ 250000000u

extern void delay (unsigned long);
extern void put32 (unsigned long, unsigned int);
extern unsigned int get32 (unsigned long);

#endif // _BOOT_H
