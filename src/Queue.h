/*
 * Queue.h
 *
 *  Created on: 2017��8��11��
 *      Author: user
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct QueueDat{
	unsigned char dat;
}QueueDat_t,*PQueueDat;
typedef struct Queue{
	unsigned long QueueStart;
	unsigned long QueueStop;
	PQueueDat  dat;
	unsigned long Size;
}Queue_t,*PQueue;

#endif /* QUEUE_H_ */
