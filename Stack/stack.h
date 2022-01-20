/**
 * @file stack.h
 * @author mazen osama 
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _STACK_H
#define _STACK_H

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


typedef struct stack_t* Stack;


void stack_create(Stack me, void* arr, int mem_size, int size);
void stack_destroy(Stack me);
void stack_push(Stack me, void* data);
void stack_pop(Stack me, void* destination);
void stack_peek(Stack me, void* destination);
int  stack_getCount(Stack me);
void stack_clear(Stack me);
BufStatus stack_isEmpty(Stack me);
BufStatus stack_isFull(Stack me);
void stack_print(Stack  me, void (*print_member)(void* member) );

#endif //_STACK_H