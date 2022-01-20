#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"

typedef struct cvect_struct
{
    void* vect;
    unsigned int size;
    unsigned int capacity;
    unsigned int element_size;
}cvect_t;


static inline void cvect_checkCapacity(cvect me)
{
    
    if(me->size == me->capacity)
    {
        me->capacity = (me->size * (100UL+ CVECT_CAPACITY_PERCENT))/100UL ; // to avoid floats
        me->vect = realloc(me->vect,  me->capacity * me->element_size);
    }
}

cvect cvect_fcreate(unsigned int init_size, unsigned int element_size )
{
    
    void* temp;
    cvect_t *vect = malloc(sizeof(cvect_t));
    temp = malloc(init_size * element_size);

    if(temp != NULL)
    {
        vect->vect = temp;
        vect->element_size = element_size;
        vect->size = init_size ;
        vect->capacity = init_size ;
        printf("vector allocated @ %p\n , with %d bytes\n", vect->vect , init_size * element_size);
        return vect;
    }
    else{
        printf("malloc failed \n");
        return NULL;
    }
}

void  cvect_destroy(cvect me)
{
    free(me->vect);
    free(me);
}

void* cvect_get(cvect me,unsigned int index)
{
    if(index < me->size)
    {
        return (void*)((char*)me->vect + (index*me->element_size)) ;
    }

    return NULL;
}
void  cvect_set(cvect me,unsigned int index, void* data)
{
    if(index < me->size)
    {    
        void* record = cvect_get(me, index);
        memcpy(record, data,me->element_size);
    }
}

void  cvect_insert(cvect me,unsigned int index, void* data)
{
    if(index < me->size)
    {

        cvect_checkCapacity(me);
        // increment size to keep track
        me->size++;
        for (int i = me->size-2; i >= index; i--)
        {
            //do this-> arr[i+1] = arr[i];
            // but with the set and get methods because we cannot use the array notation because of void pointer
            cvect_set(me,i+1, cvect_get(me,i));
        }
        cvect_set(me, index, data);

    }
}

void  cvect_append(cvect me,void* data)
{
    cvect_checkCapacity(me);
    // increment size to keep track
    me->size++ ;
    cvect_set(me, me->size-1, data);
}
unsigned int  cvect_getSize(cvect me)
{
    return me->size;
}
void  cvect_resize(cvect me,unsigned int new_size)
{
    cvect_checkCapacity(me);
    me->size = new_size ;
}
void  cvect_delete(cvect me,unsigned int index)
{
    if(index < me->size)
    {
        for (int i = index; i < me->size-1; i++)
        {
            /* arr[i] = arr[i+1]; */
            cvect_set(me, i,cvect_get(me, i+1));
        }
        // decrement the size to keep track
        me->size-- ;
    }
}

int** matrix_create(int r, int c)
{
    int** mat = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {   
        mat[i] = (int*)malloc(c * sizeof(int));
    }
    return mat;
}

void matrix_print(int** m)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
           printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void matrix_mul(int (*a)[3],int (*b)[3],int (*mul)[3], int r, int c)
{
    for(int i=0;i<r;i++)    
    {    
        for(int j=0;j<c;j++)    
        {    
            mul[i][j]=0;    
            for(int k=0;k<c;k++)    
            {    
             mul[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }
    
}

void array_insert(int arr[], int size, int num, int idx)
{
    if(idx < size-1)
    {
        //shift array to the right
        for(int i=size-2 ; i >= idx  ; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[idx] = num ;
    }
    else
    {
        printf("insert error: outside array!\n");
    }
}

void array_delete(int arr[], int size, int idx)
{
    if(idx< size-1)
    {
       //shift array to the right
       int i ;
        for ( i = idx; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        arr[i] = 0;
    }
}

void array_insert_end(int *arr, int curr_size,int num)
{
    int *arr2 = (int*)realloc(arr,curr_size+1);
    
     arr=arr2;
     arr[curr_size] = num;
   
}


void array_print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


