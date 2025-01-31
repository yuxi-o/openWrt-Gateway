#include <stdio.h>

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "thread_led.h"
#include "debug.h"

static pthread_t led_thread;

void *led_thread_f()
{
	DEBUG_LOG ("led thread: I'm led thread\n");
	pthread_detach(pthread_self());
	while(1)
	{
		DEBUG_LOG("led thread is run\n");
		sleep(5);
	}
	pthread_exit(0);
}

void led_thread_create(void)
{
	int temp;
	memset(&led_thread, 0, sizeof(led_thread)); 
	/*创建线程*/
	if((temp = pthread_create(&led_thread, NULL, led_thread_f, NULL)) != 0)     
		DEBUG_LOG("led thread 1 is err!\n");
	else
		DEBUG_LOG("led thread 1 is ok\n");

}

void led_thread_wait(void)
{
	/*等待线程结束*/
	if(led_thread !=0)
	{ 
		pthread_join(led_thread,NULL);
		DEBUG_LOG("led thread is over/n");
	}
}



