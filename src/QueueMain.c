/*
 ============================================================================
 Name        : Queue.c
 Author      : f
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "Queue.h"

Queue_t UsartQueue={
		.Size=40,
};
PQueue  UQueue=&UsartQueue;
int main(void) {
	QueueDat_t buff[255];
	QueueDat_t by;
	char swap;
	long Gsiz=0;
	InitQueue(UQueue);
	for(int i=0;i<100;i++)
	{
		swap=i%255;
     by=*(QueueDat_t*)&swap;
	printf("AddQueue:%ld",AddDatQueue(UQueue,by));
    printf("QueueSiz:%ld\r\n",GetDatSizQueue(UQueue));
	}
	Gsiz=GetDatQueue(UQueue,buff);
	printf("QueueSiz:%ld\r\n",GetDatSizQueue(UQueue));
    printf("OutSiz:%ld\r\n",Gsiz);
    while(Gsiz--)
    {
    	printf("%d",buff[Gsiz].dat);
    }
    while(1)
    {
	for(int i=0;i<100;i++)
	{
		swap=i%255;
     by=*(QueueDat_t*)&swap;
	printf("AddQueue:%ld",AddDatQueue(UQueue,by));
    printf("QueueSiz:%ld\r\n",GetDatSizQueue(UQueue));
	}
    Gsiz=GetDatQueue(UQueue,buff);
	printf("QueueSiz:%ld\r\n",GetDatSizQueue(UQueue));
    printf("OutSiz:%ld\r\n",Gsiz);
    while(Gsiz--)
    {
    	printf("%d",buff[Gsiz].dat);
    }
    }
	puts("Hello World"); /* prints Hello World */
	return EXIT_SUCCESS;
}
