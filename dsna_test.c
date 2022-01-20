/**
 * @file dsna_test.c
 * @author mazen osama (mazen.osama@coretech-innovations.com)
 * @brief this is a file for testing the implmentations of the Data structures and algorithms
 * @version 1.0
 * @date 2022-01-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "array/array.h"
#include "LinkedList/linkedlist.h"
#include "Algorithms/Algorithms.h"
#include "TestFramework/mof_test.h"
#include "Stack/stack.h"
#include "Queue/queue.h"

int arr[]={34,56,81,91,21,50,5,12,13};
int org[]={34,56,81,91,21,50,5,12,13};
int keyf = 12 ;
int keynf = 55;
int key_idx;


void print_vect(cvect vect)
{
    for (int i = 0; i < cvect_getSize(vect); i++)
    {
        printf("%d ", *((int*)cvect_get(vect, i)));
    }
    printf("\n");
}

void TEST_cvect(void)
{
int temp ;
    int * tempP = NULL;
    // printf("Hello World\n");
    cvect v=cvect_create(int,10);
    printf("%d\n", cvect_getSize(v));
    // print_vect(v);
    for (int i = 0; i < cvect_getSize(v); i++)
    {
        temp = (i+1)*10;
        // cvect_set(v,i,&temp);
        tempP = (int*)cvect_get(v,i);
        *tempP = temp;
        // printf("setting...\n");
    }
    print_vect(v);

    temp = 666;
    cvect_insert(v,5,&temp);

    print_vect(v);

    cvect_delete(v, 0);

    print_vect(v);

    temp= 10;
    cvect_append(v,&temp);   
    print_vect(v);

    cvect_resize(v , 15);
    print_vect(v);

    cvect_resize(v , 5);
    print_vect(v);

}


void shuffle(void)
{
    for(int i=0; i<array_sz(arr); i++)
    {
        arr[i] = org[i];
    }
}

// void TEST_linearsearch(void)

TEST(linear_search)
{
    key_idx = linear_search(arr,array_sz(arr),keynf);
    if(key_idx > 0)
    {
        printf("%d found @ %d \n", keyf,key_idx);
    }
    else{
        printf("linearSearch:%d was Not found\n", keynf);
    }
}

// void TEST_binarysearch(void)
TEST(binary_search)
{
    key_idx = binary_search(arr,array_sz(arr),keyf);
    if(key_idx > 0)
    {
        printf("%d found @ %d \n", keyf,key_idx);
    }
    else
    {
        printf("binarySearch:%d was Not found\n", keyf);
    }
}


// void TEST_bubblesort(void)
TEST(bubble_sort)
{
    bubble_sort(arr,array_sz(arr));
    array_print(arr, array_sz(arr));
    printf("\nSorted ? ");
    scanf("%d");
  
}

// void TEST_Selectionsort(void)
TEST(selectionSort)
{
    selectionSort(arr,array_sz(arr));
    array_print(arr, array_sz(arr));
    printf("\nSorted ? ");
    scanf("%d");
  
}

// void TEST_insertionsort(void)
TEST(insertion_sort)
{
    insertion_sort(arr, array_sz(arr));
    array_print(arr, array_sz(arr));
    printf("\nSorted ? ");
    scanf("%d");    
}


// void TEST_matrixmul(void)
// {
//     int a[3][3] = {
//         {0,0,2},
//         {0,2,0},
//         {2,0,0},
//     };
//     int b[3][3] = {
//         {2,2,2},
//         {3,3,3},
//         {4,4,4},
//     };

//     int m[3][3] = {0};
//     matrix_mul(a,b,m,3,3);
//     matrix_print(m);
// }


// void TEST_matrixcreate(void)
// {
//      int b[3][3] = {
//         {2,2,2},
//         {3,3,3},
//         {4,4,4},
//     };
//     int ** mat = matrix_create(3,3);
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             mat[i][j] = b[i][j];
//         }
        
//     }

//     matrix_print(mat);
    

// }

void linklist_print(linklist l)
{
    printf("------------\n");
    Node* it = linklist_getHead(l);
    printf("head-> %d\n", Node_getValue(it));
    Node* end = linklist_gettail(l);
    for(it=Node_getNext(it);it != end;it=Node_getNext(it))
    {
        printf("       ");
        printf("%d\n", Node_getValue(it));
    }
    printf("tail-> %d\n", Node_getValue(end));
    printf("------------\n");
}


int main(void)
{

    int * a[3];  // array of 3 pointers to int
    int (*b)[3]; // pointer to array of 3 ints;

#define QSZ 5
#define STACKSZ 5

    int q[QSZ];
    int stack[STACKSZ];

    Stack s;
    Queue Q;

    stack_create(s,(int*)stack,sizeof(int),STACKSZ);
    queue_create(Q,QSZ,(int*)q,sizeof(int));

    printf("size of a  = %d\n", sizeof(a)); // 24 = (8*3)
    printf("size of b  = %d\n", sizeof(b)); // 8 = 1 * sizeof(any pointer)

    printf("size of a step = %d\n", sizeof(*a)); // 8= 1 * sizeof(any pointer)
    printf("size of b step = %d\n", sizeof(*b)); // 12 = 3 * sizeof(int) = (3*4)

    void (*f)(void);
    printf("size of pointer to func = %d\n", sizeof(&f));

    linklist l=linklist_create(0);

    for(int i=1; i<5; i++)
    {
        linklist_append(l, i*5); //DONE
    }
     linklist_print(l);

    for(int i=1; i<5; i++)
    {
        linklist_prepend(l, i*7); //DONE
    }

     linklist_print(l);

    linklist_sort(l);

    //  linklist_print(l);
    linklist_insertByVal(l,19);

     linklist_print(l);

    linklist_deleteByVal(l , 15);

     linklist_print(l);

    linklist_deleteByVal(l , 28);

     linklist_print(l);

    linklist_insertAfter(l, linklist_getHead(l), 666);

     linklist_print(l);

    linklist_deleteNext(l , linklist_getHead(l));

    linklist_print(l);


    // TEST_linearsearch();
    // TEST_matrixmul();
    // TEST_matrixcreate();
    // TEST_bubblesort();
    // TEST_binarysearch();
    // TEST_Selectionsort();
    // shuffle();
    // array_print(arr, array_sz(arr));
    // TEST_insertionsort();

    
}