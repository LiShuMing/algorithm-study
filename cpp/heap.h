/*
* author	: lism2013@hotmail.com
* file		: heap.h
* cdatetime : 2017-02-05 10:46
*/

#ifndef HEAP_H
#define HEAP_H

// min-heap

// left of i
// i : 0, 1, 2....
int leftHeap(int array[], int n, int i){
    if (i >= n){
        return -1;
    }
    int left = 2 * i + 1;
    if (left >= n){
        return -1;
    }

    return  array[left];
}

// left index of i
int leftIndex(int array[], int n, int i){
    if (i >= n){
        return -1;
    }
    int left = 2 * i + 1;
    if (left >= n){
        return -1;
    }
    return left;
}

// version 2
int leftIndex(int array[], int low, int high, int i){
    if (i > high){
        return -1;
    }
    int left = 2 * (i - low) + 1 + low;
    if (left > high){
        return -1;
    }
    return left;
}

// right of i
int rightHeap(int array[], int n, int i){
    if (i >= n){
        return -1;
    }
    int right = 2 * (i + 1);
    if (right >= n){
        return -1;
    }

    return  array[right];
}

// right index of i
int rightIndex(int array[], int n, int i){
    if (i >= n){
        return -1;
    }
    int right = 2 * ( i + 1);
    if (right >= n){
        return -1;
    }
    return right;
}

// version2
int rightIndex(int array[], int low, int high, int i){
    if (i > high){
        return -1;
    }
    int right = 2 * ( i - low + 1) + low;
    if (right > high){
        return -1;
    }
    return right;
}

// exchange index i to modify min-heap
// array    : heap
// n        : heap array size
// i        : index i
void minHeapify(int array[], int n, int i){
    if (i >= n){
        return;
    }

    int left = leftIndex(array, n ,i);

    int small = i;
    if (left != -1){
        if (array[i] > array[left]){
            small = left;
        } 
    }

    int right = rightIndex(array, n ,i);
    if (right != -1){
        if (array[i] > array[right] && array[left] > array[right]){
            small = right;
        }
    }

    if (small != i){
        // swap i & small
        swapInt(&array[i], &array[small]);
        minHeapify(array, n, small);
    }
}

// version2 : support low/high
void minHeapify(int array[], int low, int high, int i){
    if (i > high){
        return;
    }

    int left = leftIndex(array, low, high ,i);

    int small = i;
    if (left != -1){
        if (array[i] > array[left]){
            small = left;
        } 
    }

    int right = rightIndex(array, low, high,i);
    if (right != -1){
        if (array[i] > array[right] && array[left] > array[right]){
            small = right;
        }
    }

    if (small != i){
        // swap i & small
        swapInt(&array[i], &array[small]);
        minHeapify(array, low, high, small);
    }
}



// build min-heap
void buildMinHeap(int array[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        minHeapify(array, n , i);
    }
}

// heap sort
void heapSort(int array[], int low, int high){
    int len = high - low + 1;
    // first build heap
    buildMinHeap(array, len);

    for (int i = low + 1; i < high; i++){
        minHeapify(array, i, high, i);
    }
}

// test heap
void testHeap(){
    int array[] = {6, 3, 2, 5, 1, 0, 4};
    printArray(array, 0, 6);

    printStr("build heap");
    buildMinHeap(array, 7);
    printArray(array, 0, 6);

    printStr("heap sort");
    heapSort(array, 0, 6);
    printArray(array, 0, 6);
}




#endif /* !HEAP_H */
