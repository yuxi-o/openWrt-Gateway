#ifndef _THREAD_USART_RCEV_H
#define _THREAD_USART_RCEV_H
#include <stdio.h>
#include "gw_config.h"

void *usart_rcev_thread_f(void *parameter);
void usart_rcev_thread_init(tGatewayInfo *gatewayInfo);
void usart_rcev_thread_wait(tGatewayInfo *gatewayInfo);

#endif /* _THREAD_USART_RCEV_H */



