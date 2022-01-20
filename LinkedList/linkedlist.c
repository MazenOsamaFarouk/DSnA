/**
 * @file linkedlist.c
 * @author mazen osama (mazne.osama@coretech-innovations.com)
 * @brief implementation of linkedlist functions
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "../Algorithms/Algorithms.h"
#include "linkedlist.h"

struct node
{
    int value;
    Node* next;
};

struct node2
{
    int value;
    Node2* next;
    Node2* prev;
};

struct ll_t
{
    Node* head;
    Node* tail;
    int size;
};


struct dll_t
{
    Node2* head;
    Node2* tail;
    int size;
};


linklist linklist_create(int init_val)
{
    linklist me = (linklist)malloc(sizeof(struct ll_t));
    if(me != NULL)
    {
        me->head = (Node*)malloc(sizeof(struct node));
        if(me->head != NULL)
        {
            me->head->value = init_val ;
            me->head->next = NULL ;
            me->tail = me->head;
            me->size = 1;
        }
        else
        {
            printf("linklist_create: malloc failed to allocate\n");
        }
    }
    else
    {
        printf("linklist_create: malloc failed to allocate\n");
    }

    return me ;
}

void     linklist_destroy(linklist me)
{
    /* traverse the linked list one node at a time and free the node */
    Node* list = me->head;
    while(me->head != NULL)
    {
        if(me->head == me->tail)
        {
            me->tail = me->tail->next ;
        }
        me->head = me->head->next ;
        free(list);
        list = me->head ;
    }
}

void     Node_set(Node* n, int val)
{
    n->value = val;
    // Node* list = me->head;
    // int i=0;
    // while(list != NULL)
    // {
    //     if(i == idx)
    //     {
    //         list->value = val ;
    //         break;
    //     }
    //     list = list->next;
    //     i++;
    // }
}

int     Node_getValue(Node* n)
{
    return n->value;
}

Node*   Node_getNext(Node* n)
{
    return n->next ;
    // Node* list = me->head;
    // int i=0;
    // while(list != NULL)
    // {
    //     if(i == idx)
    //     {
    //         *val = list->value ;
    //         break;
    //     }
    //     list = list->next;
    //     i++;
    // }
}
unsigned int     linklist_getSize(linklist me)
{
    return me->size ;
}



/**
 * @brief 
 * 
 * @param me 
 * @return Node* 
 */
Node*  linklist_getHead(linklist me)
{
    return me->head;
}


Node*  linklist_gettail(linklist me)
{
    return me->tail;
}


void     linklist_insertByVal(linklist me, int num)
{
    Node* list=me->head ;
    Node *cur, *prev ; 
	Node *new_node = malloc(sizeof(Node));

	if (new_node == NULL)
	{
		printf("Memory full, cannot add another item \n");
		return ;
	}
	new_node->value = num;

	for( cur=list, prev= NULL ;
		 cur != NULL && new_node->value > cur->value;
		 prev=cur, cur=cur->next )	;

	new_node->next = cur;

	if(prev == NULL ) {  me->head = new_node;       } 
	else              {  prev->next = new_node ; }
    if(cur == NULL ){me->tail = new_node;}
    me->size++;
}

/**
 * @brief 
 * 
 * @param me 
 * @param num 
 */
void     linklist_append(linklist me, int num)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode != NULL)
    {
        newnode->value = num;
        newnode->next = NULL;
        me->tail->next = newnode;
        me->tail = newnode ;
        me->size++;
    }
}

void     linklist_prepend(linklist me, int num)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode != NULL)
    {
        newnode->value = num;
        newnode->next = me->head ;
        me->head = newnode ;
        me->size++;
    }
}

// TODO: check all cases: insert at beginning, at end and in middle
void     linklist_deleteByVal(linklist me, int num)
{
    //using the trailing pointer technique
    Node * list = me->head ;
	Node *cur, *prev;

	for( cur=list, prev=NULL ; 
		 cur != NULL && cur->value != num ;
		 prev = cur, cur=cur->next )
		;

	if (cur == NULL)
	{
		return;
	}
	 
	else if (prev == NULL)
	{
		// list = (list)->next;
        me->head = cur->next;
	}
	else
	{
		prev->next = cur->next;
	}
    if(cur == me->tail){me->tail = prev;}
	free(cur);
    me->size--;
}

void     linklist_insertAfter(linklist me, Node* n , int val)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode != NULL && n != NULL)
    {
        if(n == me->tail)
        {
            linklist_append(me, val);
        }
        else
        {
            newnode->value = val;
            newnode->next = n->next;
            n->next = newnode ;
            me->size ++ ;
        }
    }
}


void linklist_deleteNext(linklist me,Node* n )
{
    Node* temp;
    if(n != NULL && n->next != NULL)
    {
        if(n->next == me->tail)
        {
            me->tail = n;
        }
        temp = n->next ;
        n->next = temp->next;
        free(temp);
        me->size--;
    }
}


void dlinklist_insertBefore(Node2* n)
{

}

// void     linklist_insertAfterIndex(linklist me, int idx, int num)
// {
//     Node* list = me->head;
//     int i=0;
//     while(list != NULL)
//     {
//         if(i == idx)
//         {
//             Node* newnode = (Node*)malloc(sizeof(Node));
//             if(newnode != NULL)
//             {
//                 newnode->value = num;
//                 newnode->next = list->next;
//                 list->next = newnode ;
//                 me->size++;                
//             }
//             break;
//         }
//         list = list->next;
//         i++;
//     }
// }

// void     linklist_deleteByIndex(linklist me, int idx)
// {
//     Node* list = me->head;

// 	Node *cur, *prev;
//     int i=0;
// 	for( cur=list, prev=NULL ; 
// 		 cur != NULL || i!= idx ;
// 		 prev = cur, cur=cur->next )
// 		{
//             i++;
//         }

// 	if (cur == NULL)
// 	{
// 		return;
// 	}
	 
// 	else if (prev == NULL)
// 	{
// 		list = (list)->next;
// 	}
// 	else
// 	{
// 		prev->next = cur->next;
// 	}

// 	free(cur);
//     me->size--;
// }


Node*    linklist_search(linklist me, int key)
{
    Node* list = me->head ;
    while( list != NULL && list->value != key)
	{
		list = list->next;
	}

	/* returns NULL if n does not exist
	otherwise,
	returns a pointer to the node containing the value of key */
	return list; 
}

void     linklist_sort(linklist me)
{
    Node* ni;
    Node* nj;

    for (ni = me->head; ni != me->tail; ni=ni->next)
    {
        for (nj = ni->next; nj != NULL; nj=nj->next)
        {
            if (nj->value < ni->value)
            {
                swap(&(nj->value), &(ni->value));
            }
        }
    }
}



