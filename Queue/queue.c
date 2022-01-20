/**
 * @file queue.c
 * @author Mazen osama
 * @brief 
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "queue.h"


struct queue_t
{
	int front;
	int back;
	unsigned int buf_size;
	unsigned int mem_size;
	unsigned int count;
	void* data;
};

void queue_create( Queue me, unsigned int buffer_size, void* cast_data, unsigned int member_size)
{
	if (me != NULL)
	{
		me->buf_size = buffer_size;
		me->mem_size = member_size;
		me->front = 0;
		me->back = 0;
		me->count =0 ;
		if (cast_data != NULL)
		{
			me->data=cast_data ;
		}
	}	
}

void queue_push( Queue me, void* cast_data)
{
	/* check if valid */
	if (me != NULL)
	{
		 if (queue_isFull(me) != FULL	)
		{
				/* move data in array */
			memcpy(me->data+(me->mem_size*me->back) , cast_data , me->mem_size );	
			me->back=(me->back+1)%me->buf_size;
			me->count++;
		}
	}
}

void queue_pop( Queue me, void* destination)
{
	/* check if valid */
	if (me != NULL)
	{
		/* check if empty */
		if (queue_isEmpty(me) != EMPTY)
		{
			/* return front element in destination if user wants (i.e. destination is not null) */
			if(destination != NULL)
			{
				memcpy( destination, me->data+(me->mem_size*me->front) , me->mem_size);
			}
			/* increment front */
			me->front = (me->front+1)%(me->buf_size) ;
			me->count--;
		}
	}	
}

// void queue_peek( Queue me, void* destination)
// {
// 	/* check if valid */
// 	if (me != NULL)
// 	{
// 		/* check if empty */
// 		if (queue_isEmpty(me) != EMPTY)
// 		{
// 			/* return front element in destination */
// 			memcpy( destination, ((char*)me->data)+(me->mem_size*me->front) , me->mem_size);
// 		}
// 	}	
// }

void queue_peekFront( Queue me, void* destination)
{
	/* check if valid */
	if (me != NULL)
	{
		/* check if empty */
		if (queue_isEmpty(me) != EMPTY)
		{
			/* return front element in destination */
			memcpy( destination, me->data+(me->mem_size*me->front) , me->mem_size);
		}
	}
}

void queue_peekBack( Queue me, void* destination)
{
	int tmp = 0;
	/* check if valid */
	if (me != NULL)
	{
		/* check if empty */
		if (queue_isEmpty(me) != EMPTY)
		{
			/* return back element in destination */
			 tmp = (me->back==0?me->buf_size-1:me->back-1);
			memcpy( destination, (me->data)+(me->mem_size*(tmp)) , me->mem_size);
		}
	}	
}

void queue_clear(Queue me)
{
	/* check if valid */
	if (me != NULL)
	{
		me->front = me->back = me->count = 0 ;
	}
}

unsigned int queue_getCount(Queue me)
{
	return me->count ;
}



BufStatus queue_isEmpty( Queue me)
{
	/* check if valid */
	if (me != NULL)
	{
		return (me->count == 0)? EMPTY:NOT_EMPTY;
		//return (me->front==me->back ? EMPTY:NOT_EMPTY);
	}
	else
	{
		return NOT_INIT;
	}
}

BufStatus queue_isFull( Queue me)
{
/* check if valid */
	if (me != NULL)
	{
		return (me->count == me->buf_size)? FULL:NOT_FULL ;
		//return (me->back+1)==me->front ? FULL:NOT_FULL ;
	}
	else
	{
		return NOT_INIT;
	}
}

void queue_print( Queue me, void (*print_member)(void* member) )
{
	if (me != NULL)
	{
		printf("front-> ");
		for (int i = me->front; i < me->back;   )
		{	
			if(i!=me->front)
			{
				if (i== me->back-1)
				{
					printf("back -> ");	
				}
				else
				{
					printf("\t");	
				}
				
			}
			
			print_member(me->data+(me->mem_size*i));

			if (i == me->buf_size-1)
			{
				i=0;
			}
			else
			{
				i++;
			}
		}	
	}
}