/*
* author	: lism2013@hotmail.com
* file		: sort.h
* cdatetime : 2017-02-03 17:57
*/

#include "util.h"

#ifndef SORT_H
#define SORT_H

// bubble sort : from little to big
void bubbleSort(int array[], int low, int high){
    for (int i = low; i < high - 1; i++){
        for (int j = low; j < high - i - 1; j++){
            if (array[j] > array[j + 1]){
                swapInt(&array[j], &array[j + 1]);
            }
        }
    }
}

// find the most least value of array
int findMostLeast(int array[], int low, int high){
    //int t = 2^31 - 1;
    int index = low;

    for (int i = low + 1; i < high - 1; i++){
        if (array[i] < array[index]){
            index = i;
        }
    }
    return index;
}

// select sort : select the least & swap
void selectSort(int array[], int low, int high){
    int index = 0;

    for (int i = low; i < high - 1; i++){
        index = findMostLeast(array, i, high);
        swapInt(&array[i], &array[index]);
    }
}

// insert sort : select the least & swap
void insertSort(int array[], int low, int high){
    int t = -1;
    for (int i = low + 1; i < high; i++){
        t = array[i];
        if (array[i - 1] > array[i]){
            int j = i - 1;
            while (array[j] > t && j >= low){
                array[j+1] = array[j];
                j--;
            }
            array[j + 1] = t;
        }
    }
}

// shell sort : select the least & swap
void shellSort(int array[], int low, int high){
    for (int gap = (high - low + 1) / 2; gap > 0; gap = gap / 2){
        for (int i = 0; i < gap; i++){
            for (int j = gap + i; j <= high; j = j + gap){
                int tmp = array[j];
                if (array[j - gap] > tmp) {
                    int k = j;

                    while (k >= i + gap && array[k - gap] > tmp){
                        array[k] = array[k - gap];
                        k = k - gap;
                    }

                    array[k] = tmp;
                }
            }
        }
    }
}

// TODO: 
void mergeTwoSortedArray(int array1[], int low1, int high1, 
        int array2[], int low2, int high2){
}

// TODO: recursely merge sort
void mergeSortRecursely(int array[], int low, int high){
}

// merge sort : no use recurse!
void mergeSort(int array[], int low, int high){
    int k, z, tmp;
    for (int gap = 1; gap < (high - low + 1); gap = gap * 2){
        for (int i = low; i < high; i = i + 2 * gap){
            k = i;
            for (int j = gap + i; j <= i + 2 * gap - 1 && j <= high; j++){
                tmp = array[j];

                while (k < j && array[k] <= tmp){
                    k++;
                }

                if (k < j){
                    z = j;
                    while (z > k){
                        array[z] = array[z - 1];
                        z--;
                    }

                    printf("gap=%d,i=%d,j=%d,k=%d,z=%d\n", gap,i,j,k,z);
                    array[z] = tmp;
                }
            }
        }
    }
}

// quick sort
void quickSort(int array[], int low, int high){
    if (low >= high || low < 0 || high < 0){
        return;
    }

    int p = low;
    int k, tmp;

    for (int i = low + 1; i <= high; i++){
        if (array[i] < array[p]){
            k = i;
            tmp = array[i];
            while (k > p){
                array[k] = array[k - 1];
                k--;
            }
            printf("p=%d,k=%d\n", p, k);
            array[k] = tmp;
            p = k + 1;
        }
    }

    quickSort(array, low , p -1);
    quickSort(array, p + 1, high);
}

// test func
void testFunc(void (*func)(int array[], int low, int high)){
    int array[] = {3, 2, 0, 1, 4, 5};
    func(array, 0, 5);

    printArray(array, 0, 5);

    for (int i = 1; i <= 5; i++){
        assert(array[i] > array[i -1]);
    }
}

// test
void testSort(){
    // bubble sort
    printf("bubble sorted!\n");
    testFunc(bubbleSort);

    // select sort
    printf("select sorted!\n");
    testFunc(selectSort);

    // insert sort
    printf("insert sorted!\n");
    testFunc(insertSort);

    // shell sort
    printf("shell sorted!\n");
    testFunc(shellSort);

    // merge sort
    printf("merge sorted!\n");
    testFunc(mergeSort);

    // quick sort
    printf("quick sorted!\n");
    testFunc(quickSort);
}



#endif /* !SORT_H */
