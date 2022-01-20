/**
 * @file linkedlist.h
 * @author mazen osama (mazen.osama@coretech-innovations.com)
 * @brief linked list implementation (single, double, circular)
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


typedef struct node Node;
typedef struct node2 Node2;
typedef struct ll_t* linklist ;
typedef struct dll_t* dlinklist ; 

int     Node_getValue(Node* n);
Node*   Node_getNext(Node* n);

int     Node2_getValue(Node2* n);
Node2*   Node2_getNext(Node2* n);

linklist linklist_create(int init_val);
void     linklist_destroy(linklist me);

unsigned int     linklist_getSize(linklist me);
Node*  linklist_getHead(linklist me);
Node*  linklist_gettail(linklist me);

void     linklist_insertByVal(linklist me, int num);
void     linklist_insertAfter(linklist me, Node* n , int val);
void     linklist_append(linklist me, int num);
void     linklist_prepend(linklist me, int num);
void     linklist_deleteByVal(linklist me, int num);
// void     linklist_insertAfterIndex(linklist me, int idx, int num);
// void     linklist_insertBeforeIndex(linklist me, int idx, int num);
// void     linklist_deleteByIndex(linklist me, int idx);
void     linklist_deleteNext(linklist me,Node* n );

int      linklist_searchByIndex(linklist me, int key);
Node*    linklist_search(linklist me, int key);
void     linklist_sort(linklist me);

#endif