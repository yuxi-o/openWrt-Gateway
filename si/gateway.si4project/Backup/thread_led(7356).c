#include <stdio.h>

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "thread_led.h"
#include "debug.h"


void *led_thread_f(void *parameter)
{
	DEBUG_LOG ("led thread: I'm led thread\n");

	/* 线程自销毁，当线程销毁时，自动回收资源 */
	pthread_detach(pthread_self());	
	//struct tGatewayInfo *gatewayInfo = (struct tGatewayInfo *)parameter;
	while(1)
	{
		DEBUG_LOG("led thread is run\n");
		sleep(5);
	}
	pthread_exit(0);
}

int led_thread_init(struct tGatewayInfo *gatewayInfo)
{
	int temp;
	
	/*创建线程*/
	temp = pthread_create(&gatewayInfo->thread.led, NULL, led_thread_f, (void *)gatewayInfo);
	if(temp != 0)     
		DEBUG_LOG("led thread 1 is err!\n");
	else
		DEBUG_LOG("led thread 1 is ok\n");

	return temp;
}

void led_thread_wait(struct tGatewayInfo *gatewayInfo)
{
	/*等待线程结束*/
	if(gatewayInfo->thread.led !=0)
	{ 
		pthread_join(gatewayInfo->thread.led,NULL);
		DEBUG_LOG("led thread is over/n");
	}
}



