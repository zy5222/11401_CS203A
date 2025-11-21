/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/21: Implemented Division and Rolling Hash functions

   Developer: 王芷芸 <s1131547@mail.yzu.edu.tw>
 */
#include <stdio.h>
#include <string.h>

int myHashInt(int key, int m) {
    if(m <= 0){
        return 0;
    }
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    if(m <= 0 || str == NULL || *str == '\0'){
        return 0;
    }

    while (*str != '\0'){
        hash = hash * 31 + (unsigned char)(*str);
        str++;
    }
    return (int)(hash % m); // basic division method
}
