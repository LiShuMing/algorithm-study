#include "stdio.h"
#include <assert.h>

// array    : sorted array
// low      : low index of array
// high     : high index of array
// target   : search target
// @return  : target index
int binarySearch(int array[], int low, int high, int target){
    if (low > high){
        return -1;
    }

    if (low == high){
        if (array[low] == target){
            return low;
        } 

        return -1;
    }

    int mid = (low + high) / 2;
    if (target < mid){
        return binarySearch(array, low, mid -1, target);
    } else if (target > mid){
        return binarySearch(array, mid + 1, high, target);
    }

    return mid;
}

// binarySearch witout recurse
int binarySearchWithoutRecurse(int array[], int low, int high, int target){
    if (low > high){
        return -1;
    }

    if (low == high){
        if (array[low] == target){
            return low;
        } 
        return -1;
    }

    while (low <= high){
        int mid = (low + high) / 2;
        if (target < array[mid]){
            high = mid - 1;
            continue;
        } else if (target > array[mid]){
            low = mid + 1;
            continue;
        } else {
            return mid;
        }
    }

    return -1;
}

// test binarySearch
void testBinarySearch(){
    int array[5] = {0,1,2,3,4};
    int result = -1;
    int resultWithoutRecurse = -1;

    for (int i = 0; i < 5; i++){
        result = binarySearch(array, 0, 4, i);
        resultWithoutRecurse = binarySearchWithoutRecurse(array, 0, 4, i);
        assert(result == resultWithoutRecurse);
        printf("result=%d\tresultWithoutRescurse=%d\n", result, resultWithoutRecurse);
    }
}
