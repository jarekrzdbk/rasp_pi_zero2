#ifndef _UART_H
#define _UART_H

#define UARTCR_UARTEN (1u << 0)
#define UARTCR_TXE (1u << 8)
#define UARTCR_RXE (1u << 9)

#define UARTFR_BUSY (1u << 3)
#define UARTLCRH_FEN (1u << 4)

#define UARTLCRH_WLEN8 (3u << 5)

#define UARTFR_TXFF (1u << 5)
#define UARTFR_RXFE (1u << 4)

#define FUARTCLK 48000000

void uart_init( void );
char uart_recv( void );
void uart_send( char c );
void uart_send_string( char* str);

#endif // _UART_H
