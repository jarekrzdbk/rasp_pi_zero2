#include "peripherals/uart.h"
#include "peripherals/gpio.h"
#include "uart.h"
#include <utils.h>

void uart_send(char c) {
    while (get32(UART_FR) & UARTFR_TXFF) {}
    put32(UART_DR, (unsigned)c);
}

char uart_recv(void) {
    while (get32(UART_FR) & UARTFR_RXFE) {}
    return (char)(get32(UART_DR) & 0xFF);
}

void uart_send_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        uart_send((char)str[i]);
    }
}

void uart_init(void) {
    unsigned int selector;
    selector = get32(GPFSEL1);

    // Set alt
    selector &= ~(7<<12);
    selector |= 4<<12;
    selector &= ~(7<<15);
    selector |= 4<<15;
    put32(GPFSEL1, selector);

    put32(GPPUD, 0);
    delay(150);
    put32(GPPUDCLK0, (1<<14) | (1<<15));
    delay(150);
    put32(GPPUDCLK0, 0);

    // Disable UART
    unsigned int control;
    unsigned int lcrh;
    unsigned int ibrd;
    double fbrd;
    double buaddiv;
    control = get32(UART_CR);
    control &= ~(UARTCR_UARTEN | UARTCR_RXE | UARTCR_TXE);
    put32(UART_CR, control);

    while (get32(UART_FR) & UARTFR_BUSY) {}

    lcrh = get32(UART_LCRH);
    lcrh &= ~UARTLCRH_FEN;
    put32(UART_LCRH, lcrh);


    buaddiv =  (double)FUARTCLK / (16 * (double)BAUD_RATE);
    ibrd = (int)buaddiv;
    put32(UART_IBRD, ibrd);

    long long f = (long long)buaddiv;
    fbrd = buaddiv - (double)f;
    unsigned int f_brd = (int)(fbrd * 64 + 0.5);
    put32(UART_FBRD, f_brd);

    lcrh = get32(UART_LCRH);
    lcrh &= ~(3u << 5);
    lcrh |= UARTLCRH_WLEN8;
    put32(UART_LCRH, lcrh);

    // Enable UART
    control = get32(UART_CR);
    control |= (UARTCR_UARTEN | UARTCR_TXE | UARTCR_RXE);
    put32(UART_CR, control);
}
