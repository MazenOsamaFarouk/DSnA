/**
 * @file queue.h
 * @author mazen osama
 * @brief header file of queue data structure implementation
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QUEUE_H
#define _QUEUE_H

#ifndef BUF_STATUS
#define BUF_STATUS
typedef enum 
{
	EMPTY=0,
	FULL=!EMPTY,
	NOT_FULL,
	NOT_EMPTY,
	NOT_INIT /*error in case buffer is not initialized */
}BufStatus;
#endif

typedef struct queue_t* Queue;

void queue_create( Queue me, unsigned int buffer_size, void* cast_data, unsigned int member_size);

void queue_push( Queue me, void* cast_data);
void queue_pop( Queue me, void* destination);
void queue_peekFront( Queue me, void* destination);
void queue_peekBack( Queue me, void* destination);
void queue_clear(Queue me);
unsigned int queue_getCount(Queue me);
BufStatus queue_isEmpty( Queue me);
BufStatus queue_isFull( Queue me);
void queue_print( Queue me, void (*print_member)(void* member) );



#endif //_QUEUE_H