
#ifndef __USART_
#define __USART_

#include <stdio.h> 
#include <stdint.h>
#include <strings.h>    
int open_usart(void);
int uart_recv(int fd, char *data, int datalen);
int uart_send(int fd, char *data, int datalen);

#endif	//__USART_