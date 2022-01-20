/**
 * @file stack.c
 * @author mazen osama
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

struct stack_t
{
    int size;
    int mem_size;
    int count;
    int top;
    void *arr;
};

void stack_create(Stack me, void* arr, int mem_size, int size)
{
    if (me != NULL)
	{
		me->size = size;
		me->top = 0;
        me->mem_size = mem_size;
		me->count =0 ;
		if (arr != NULL)
		{
			me->arr=arr ;
		}
	}	
}

void stack_destroy(Stack me)
{
    /* if you are using a dynamically allocated stack 
       you should free it from memeory using free();
       but if the impmentation is using a statically
       allocated stack, there is no need to free() it.
    */
}

void stack_push(Stack me, void* data)
{
    /* check if valid */
	if (me != NULL)
	{
		/* check if full */
		if (stack_isFull(me) != FULL)
		{
			/* move data in array */
			// me->arr[me->top] = num; // <-- simple implementation
            memcpy(((char*)me->arr)+(me->mem_size*me->top) , data , me->mem_size );
			/* increment top */
			me->top = (me->top+1)%(me->size);
			me->count++ ;
		}
	}
}

void  stack_pop(Stack me, void* destination)
{
    // int top;
    /* check if valid */
	if (me != NULL)
	{
		/* check if empty */
		if (stack_isEmpty(me) != EMPTY )
		{
			/* return top element in destination if user wants (i.e. destination is not null)*/
			// top = me->arr[me->top]; // <--  simple implementation
			if (destination != NULL)
			{
			memcpy( destination, ((char*)me->arr)+(me->mem_size*me->top) , me->mem_size);
			}
            /* decrement top */
			me->top = me->top>0 ? (me->top-1):(me->top) ;
			me->count-- ;
		}
	}	
    // return top;
}

void  stack_peek(Stack me, void* destination)
{
    // int top;
    /* check if valid */
	if (me != NULL)
	{
		/* check if empty */
		if (stack_isEmpty(me) != EMPTY )
		{
			/* return top element in destination if user wants (i.e. destination is not null)*/
			// top = me->arr[me->top]; // <--  simple implementation
			if (destination != NULL)
			{
			memcpy( destination, ((char*)me->arr)+(me->mem_size*me->top) , me->mem_size);
			}
			/* DO NOT decrement top -> This is the difference between
               peek and pop  */
			// me->top = me->top>0 ? (me->top-1):(me->top) ;
			// me->count-- ;
		}
	}	
    // return top;
}

int  stack_getCount(Stack me)
{
    int count=-1;
    if(me != NULL)
    {
        count = me->count;
    }
    return count;
}

void stack_clear(Stack me)
{
    if (me != NULL)
	{
		me->top = me->count = 0 ;
	}
}

BufStatus stack_isEmpty(Stack me)
{
    BufStatus status;
    /* check if valid */
	if (me != NULL)
	{
		status = (me->top==0 ? EMPTY:NOT_FULL) ;	
	}
	else
	{
		status = NOT_INIT;	
    }
    return status;
}

BufStatus stack_isFull(Stack me)
{
    BufStatus status;
    if (me != NULL)
	{
		status = (me->top==(me->size-1) ? FULL:NOT_FULL ) ;
	}
	else
	{
		status = NOT_INIT;
	}
    return status;
}

void stack_print(Stack  me, void (*print_member)(void* member) )
{
	if (me != NULL)
	{
		printf("top -> ------\n");
		for (int i = me->top-1; i>=0 ; --i)
		{
			printf("\t");
			print_member(((char*)me->arr)+(me->mem_size*i));
		}
	}
}