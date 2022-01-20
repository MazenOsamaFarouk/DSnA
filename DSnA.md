# TODO

 - [x] Topics in DS and Algo
 - [x] Presentation power points
 - [x] source code demos 
 - [x] excersies 

## Topics in DS and Algo
0. Review on Arrays, Relationship between DS and Algorithms
    - 1-D array
- insertion: @ beginning and middle:
```c
int array[MAX] = {2, 3, 4, 5};
int N = 4; // number of elements in array int i = 0; // loop variable
int value = 1; // new data element to be stored in array
// print array before insertion
printf(“Printing array before insertion −\n”); 
for(i = 0; i < N; i++) {
printf(“array[%d] = %d \n”, i, array[i]); }
// now shift rest of the elements downwards 
for(i = N; i >= 0; i--) {
array[i+1] = array[i];
}
//add new element at first position 
array[0] = value;
// increase N to reflect number of elements N++;
// print to confirm
printf(“Printing array after insertion −\n”);
for(i = 0; i < N; i++) {
printf(“array[%d] = %d\n”, i, array[i]);
}}
```
- deletion: @ beginning and middle:

```c
```

    - multi-dimensional arrays
    - applications of multi-dimensional arrays (matrices)
      ~ matrix operations
      ~ data bases
1. Time and Space complexity analysis (Big-O Notation)
   a. how to calculate time and space complexity for an algorithm (with graphs)
    - loops
    - recursion  
    note: user input , error checking and interrupts are not in the scope of calc. time complexity
2. Algorithms
   a. Search:
    * search terminology:
      - record: it's an element of the data structure you are searching 
      - index : place of the found element or record.
      - key: the search term you are looking for.
      - found : flag to determine if you have actually found the record in the array or not.   
    * **Linear Search**
 
        * **Idea** :  it's a sequential searching algorithm, meaning it has to go by all the elements of the array one by one and check if the element is the key matches any record in the array.
        * **pseudocode**:
         
```python
1. begin searching at the start of the array (index = 0)
2. if record @ current index == the search key
    2.a. The search completes with a status found = true and index value at the record that has the match.
3. if record @ current index != the search key
    3.a. increment the index to point to the next element in the array
    3.b. repeat step 2
4. if all records are searched and no match
    4.a the search completes with the status found=false, meaning the key does not exist in the array.
```


   * **implementation**:
```c
int search(int arr[], int size, int key)
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
```

   * analysis: 
   - [ ] TODO: analyse the linear search algorithm using big-o notation
   - [ ] TODO: advantages and disadvantages (corner cases)

* Binary Search

 * **Idea** : the idea is to rely on the prerequisite that the array is sorted. that means we have a interval of numbers that is either ascending or descending. using that interval we can then continously compare the key to the middle record to determine which half of the array the key can be found. if we repeat this again in half the array to dteremine which quarter of the array the key can be found, we will eventually find the record.
 * pseudocode: 

```python
1. start by initializing the search indices.
    1.a. start index -> 0 to be the very start of the array
    1.b. end index -> array size-1 to be at the last element of the array.
2. calculate the index of the middle record:
    middle = (start + end)/2
3. if the record@middle == record@key:
    3.a. The search completes with a status found = true and index value at the record that has the match whcih also happens to be the middle at this point.
4. if the record@middle < record@key:
    4.a. move the start index towards the middle to cut the array in half. (start = middle +1 )
    4.b repeat step 2
5. if the record@middle > record@key:
    5.a move the end index towards the middle to cut the array in half. (end = middle - 1)
    5.b repeat step 2

```  

* **implementation** :

~ iterative: 

```c
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
```
~ recursive:

```c
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return -1;
}
```

* **analysis**:
  - [ ] TODO: big-o analysis of binary search
  - [ ] adv. and disadv. of binary (corner cases)
  - [ ] comparison between linear and binary

   b. Sort:
    * bubble

        * **implementation** :
 
```c
void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n-1 ; ++i)
	{
		for (int j = 0; j < n-1-i; ++j)
		{
			if ( arr[j] > arr[j+1] )
			{
                swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
``` 

    * Selection
      * **implementation** :

```c
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}
```

    * Merge
      * **implementation** :

```c
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
```

    * insertion
      * **implementation** :

```c
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
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
```

    * binary sort
      * **implementation** :

```c
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
```

    * quick sort
      * **implementation** :

```c
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
```

1. Data Structures:
   * Review on c struct , pointers, dynamic-memory allocation
   * Abstract data type and libraries
   * basic operations on any data structure
    - creation
    - deletion
    - insertion
      ~ @beginning
      ~ @end (Append)
      ~ @middle
    - search
    - sort
    - access: Read/write
    - print
   a.LinkedLists 
    - single linked list
    - double linked list
    - circular linked list (single and double)
   b.Stack (LIFO)
    - stack concept
    - array based implementation
    - linked-list based implpementation
   c.Queue (FIFO)
    - queue concept
    - array-based implementation
    - linked-list based implementation
   d.Hash Table, Associative array and Look-Up Tables
    - Look-up tables and their applications in embedded systems
    - associative arrays
    - Hash table 
   e. Tree
    - Tree concept
    - node implementation
    - Tree operations
      ~ search
      ~ insertion
      ~ applications:
        * Abstract syntax tree  
   f. Heap (priority queue)
    - Heap concept (Max Min)
    - implementation
    - heap operations:
      ~ insertion
      ~ deletion
      ~ applications: operating systems


