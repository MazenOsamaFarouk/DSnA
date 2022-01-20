/**
 * @file array.h
 * @author mazen (mazen.osama@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct cvect_struct* cvect ;

#define CVECT_CAPACITY_PERCENT   10  
#define cvect_create(data_type, size)    cvect_fcreate(size, sizeof(data_type) )

cvect cvect_fcreate(unsigned int init_size, unsigned int element_size );
void  cvect_destroy(cvect);
void* cvect_get(cvect me,unsigned int index);
void  cvect_set(cvect me,unsigned int index, void* data);
void  cvect_insert(cvect me,unsigned int index, void* data);
void  cvect_append(cvect me,void* data);
unsigned int  cvect_getSize(cvect me);
void  cvect_resize(cvect me,unsigned int new_size);
void  cvect_delete(cvect me,unsigned int index);


#define array_sz(a)  (sizeof(a)/sizeof(a[0]))
int** matrix_create(int r, int c);
// void matrix_mul(int a[][3],int b[][3],int mul[][3], int r, int c);
void matrix_mul(int (*a)[3],int (*b)[3],int (*mul)[3], int r, int c);
// void matrix_print(int m[][3]);
void matrix_print(int** m);

void array_insert(int arr[], int size, int num, int idx);
void array_insert_end(int *arr, int curr_size,int num);
void array_delete(int arr[], int size, int idx);
void array_print(int* arr, int size);



#endif