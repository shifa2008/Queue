/*
 * Queue.c
 *
 *  Created on: 2017��8��11��
 *      Author: user
 */
#include "Queue.h"
void DelQueue(PQueue queue)
{
    free(queue->dat);
}
void InitQueue(PQueue queue)
{
	queue->dat=malloc(sizeof(QueueDat_t)*queue->Size);
    queue->QueueStart=0;
    queue->QueueStop=0;
    if(queue->dat==NULL)
    {
    	printf("��ʼ������ʧ�� �ڴ治�㣡��\r\n");
    }
}
char GetFlagQueue(PQueue queue)
{
	if(queue->QueueStart==queue->QueueStop)
	{
		return 0;
	}
	if(((queue->QueueStop+1)%queue->Size)==queue->QueueStart)
	{
	    return -1;
	}
	return 1;
}
long AddDatQueue(PQueue queue,QueueDat_t by)
{
     if(GetFlagQueue(queue)!=-1)
     {
    	 *(queue->dat+queue->QueueStop)=by;
          queue->QueueStop=(queue->QueueStop+1)%queue->Size;
          return 0;
     }
     return -1;
}
unsigned long GetDatSizQueue(PQueue queue)
{
	return (queue->QueueStop-queue->QueueStart+queue->Size)%queue->Size;
}
long  GetDatQueue(PQueue queue,PQueueDat dat)
{
	unsigned long siz=(queue->QueueStop-queue->QueueStart+queue->Size)%queue->Size;
	unsigned long i=0;
	if(GetFlagQueue(queue)!=0)
    {
	   for(i=0;i<siz;i++)
		{
	     *(dat+i)=*(queue->dat+queue->QueueStart);
	     queue->QueueStart=(queue->QueueStart+1)%queue->Size;
		}
	}
	return i;
}

