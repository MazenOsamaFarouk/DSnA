#include <stdio.h>
#include <stdlib.h>


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int linear_search(int arr[], int size, int key)
{
    int found_idx = -1;
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
        {
            found_idx=i;
            break;
        }
    return found_idx;
}

int binary_search(int a[], int size, int key)
{
    int start = 0 ;
    int end = size-1  ;
    int middle ;
    int found_idx=-1;
    while( (start <= end) )
    {	
        middle = (start + end)/2 ;
        if (a[middle] == key )
        {
            found_idx=middle;
            break ;
        } 
        else if (a[middle] < key)
        {
            start = middle + 1 ;
        }
        else
        {
            end = middle - 1; 
        }
       
    }
return found_idx;
}

void selectionSort(int arr[], int n)
{
   
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}


void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n-1 ; ++i) // no passes
	{ 
		for (int j = 0; j < n-1-i; ++j)  // no of iterations / pass
		{
			if ( arr[j] > arr[j+1] )
			{
                swap(&arr[j],&arr[j+1]);
			}
		}
	}
}


void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}
