/*
* author	: lism2013@hotmail.com
* file		: leetcode_array.h
* cdatetime : 2017-02-04 18:18
*/

#ifndef LEETCODE_ARRAY_H
#define LEETCODE_ARRAY_H


// 2.1.1 remove duplicates from array
int removeDuplicatesFromArray(int A[], int n){
    if (n == 0){
        return -1;
    }

    int index = 0;
    for (int i = 1; i < n; i++){
        if (A[i -1] != A[i]){
            A[index++] = A[i];
        }
    }

    return index;
}

// test leetcode array
void testLeetcodeArray(){
    // remove duplicates
    int A[] = {0, 1, 1, 2, 3, 3, 4};
    int duplicateLength = removeDuplicatesFromArray(A, sizeof(A) / sizeof(*A));
    printArrayN(A, duplicateLength);
    printf("duplicate length:%d\n", duplicateLength);
}


#endif /* !LEETCODE_ARRAY_H */
