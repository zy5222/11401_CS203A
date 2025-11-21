/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/21: Implemented Division and Rolling Hash functions

   Developer: 王芷芸 <s1131547@mail.yzu.edu.tw>
 */
#include <string>

int myHashInt(int key, int m) {
    if(m <= 0){
        return 0;
    }
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    if(m <= 0 || str.empty()){
        return 0;
    }
    for(char c : str){
        hash = hash * 31 + static_cast<unsigned char>(c);
    }
    return static_cast<int>(hash % m);  // basic division method
}
