#include <stdio.h>

#include <unistd.h>
#include <pthread.h>

#include <sys/time.h>
#include <string.h>
#include "thread_key.h"
#include "debug.h"

static pthread_t key_thread;

static void *key_thread_f()
{
	DEBUG_LOG("key thread: I'm key thread\n");
	pthread_detach(pthread_self());
	while(1)
	{
		printf("key thread is run\n");
		sleep(5);
	}
	pthread_exit(0);
}

void key_thread_create(void)
{
	int temp;
	memset(&key_thread, 0, sizeof(pthread_t)); 
	/*创建线程*/
	if((temp = pthread_create(&key_thread, NULL, key_thread_f, NULL)) != 0)     
		DEBUG_LOG("key thread is err!\n");
	else
		DEBUG_LOG("key thread is ok\n");

}

void key_thread_wait(void)
{
	/*等待线程结束*/
	if(key_thread !=0)
	{ 
		pthread_join(key_thread,NULL);
		DEBUG_LOG("key thread is over/n");
	}
}


