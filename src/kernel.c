#include "mini_uart.h"

void kernel_main(void) {
    uart_init();
    uart_send_string("Hello, world!\r\n");

    while (1) {
        char c = uart_recv();
        if (c == '\r' || c == '\n') {
            uart_send('\r');
            uart_send('\n');
        } else {
            uart_send(c);
        }
    }
}
