/*
* author	: lism2013@hotmail.com
* file		: util.h
* cdatetime : 2017-02-03 18:00
*/

#ifndef UTIL_H
#define UTIL_H

// swap
void swapInt(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

// print array
void printArray(int array[], int low, int high){
    for (int i = low; i <= high; i++){
        printf("i=%d ", array[i]);
    }
    printf("\n");
}

// another print array
void printArrayN(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("i=%d\n", A[i]);
    }
}

// print int* ptr
void printPtr(int* x, const char* str){
    printf("%s ptr : %x\n", str, x);
}

// print int** ptr
void printPtr(int** x, const char* str){
    printf("%s ptr : %x\n", str, x);
}

// print int
void print(int val){
    printf("%d\n", val);
}

// print next line
void printN(){
    printf("\n");
}

// print 
void printStr(const char* str){
    printf("%s\n", str);
}




#endif /* !UTIL_H */
