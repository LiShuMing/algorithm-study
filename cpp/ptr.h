/*
* author	: lism2013@hotmail.com
* file		: ptr.h
* cdatetime : 2017-02-04 23:48
*/

#ifndef PTR_H
#define PTR_H

// pr
int c = 5;

void chgPtr(int* y){
    printPtr(&c, "c:");
    y = &c;
    printPtr(y, "x:");
}

void chgPtrPtr(int** x){
    printPtr(&c, "c:");
    *x = &c;
}

void testPtr(){
    int a = 3;
    printPtr(&a, "a");

    int* x = &a;
    printPtr(x, "x 1:");
    printPtr(&x, "xx 1:");

    int b = 4;
    x = &b;
    printPtr(&b, "b:");
    printPtr(x, "x 2:");
    printPtr(&x, "xx 2:");

    printPtr(&c, "c:");
    chgPtr(x);

    printPtr(x, "x 3:");
    printPtr(&x, "xx 3:");

    chgPtrPtr(&x);
    printPtr(x, "x 4:");
}
#endif /* !PTR_H */
