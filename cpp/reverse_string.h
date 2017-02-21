#include "stdio.h"
#include "string.h"
#include <assert.h>
#include <stdlib.h> 

// TODO: bad case, return new string
// str      : char string
// @return  : the reverse of char string 
char* reverseStringBad(const char* str){
    if (str == NULL){
        return NULL;
    }

    int len = strlen(str);

    //new?malloc?stack
    char* res = (char*)malloc(len + 1);
    //char res[len+1];

    for (int i = 0; i < len; i++){
        res[len - i - 1] = str[i];
    }

    strcat(res, "\0");
    return res;
}

// no need new/alloc new memory
char* reverseString(char* str){
    if (str == NULL){
        return NULL;
    }

    char *pS = str;

    // how to goto the end of str?
    char *pE = str;
    while (*pE){
        pE++;
    }
    pE--;

    // WHY: bus error: 10?
    // Mac OS
    char t;
    while (pE > pS){
        t = *pS;

        printf("t=%c, pe=%c\n", t, *pE);
        *pS++ = *pE;
        *pE-- = t;
    }

    return str;
}

void testReverseString(){
    const char *str = "hello world!";

    //!should free result, otherwise memory leak
    char* result = reverseStringBad(str);
    printf("result = %s\n", result);
    free(result);

    /**
    char *str2 = "hello world!";
    char* result2 = reverseString(str2);
    printf("result = %s\n", result2);
    */
}
