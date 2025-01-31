#include <stdio.h>

#include <unistd.h>
#include <pthread.h>

#include <sys/time.h>
#include <string.h>
#include "usart.h"
#include "thread_usart_send.h"
#include "debug.h"
#include "gw_ipc.h"
#include "usart.h"

static pthread_t usart_send_thread;

void *usart_send_thread_f()
{
	char send_buff[USART_BUFF_LEN];
	mqd_t ret;
	unsigned prio;
	size_t size;
	struct mq_attr attr;
	
	DEBUG_LOG("usart send thread ok\n");
	pthread_detach(pthread_self());
	
	mq_getattr(g_mqid_usart_s, &attr);
	size = attr.mq_msgsize;
	//DEBUG_LOG("flag=%ld max #msg=%ld max #bytes/msg=%ld #currently on queue=%ld\n", attr.mq_flags ,attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
	while(1)
	{
		memset(send_buff, 0, USART_BUFF_LEN);
		ret = mq_receive(g_mqid_usart_s, (char*)&send_buff, size, &prio);
		
		if(ret > 0)
		{
			DEBUG_LOG("usart wait data ok mq receice data len = %d\n", ret);
			if(uart_send(serial_fd , send_buff, USART_BUFF_LEN)>0)
				DEBUG_LOG("usart send data ok \n");
			else
				DEBUG_LOG("usart send data error\n");
		}
	}
	pthread_exit(0);
}

void usart_send_thread_create(void)
{
	int temp;
	memset(&usart_send_thread, 0, sizeof(pthread_t)); 
	/*创建线程*/
	if((temp = pthread_create(&usart_send_thread, NULL, usart_send_thread_f, NULL)) != 0)     
		DEBUG_LOG("usart send thread is err!\n");
	else
		DEBUG_LOG("usart send thread is ok\n");
}

void usart_send_thread_wait(void)
{
	/*等待线程结束*/
	if(usart_send_thread !=0)
	{ 
		pthread_join(usart_send_thread,NULL);
		DEBUG_LOG("usart send thread is over/n");
	}
}




