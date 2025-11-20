/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include <stdio.h>
#include <string.h>

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    if(m <= 0){
        return 0;
    }
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    if(m <= 0 || str == NULL || *str == '\0'){
        return 0;
    }

    while (*str != '\0'){
        hash = hash * 31 + (unsigned char)(*str);
        str++;
    }
    return (int)(hash % m); // basic division method
}
