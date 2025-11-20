/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include <string>

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    if(m <= 0){
        return 0;
    }
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    if(m <= 0 || str.empty()){
        return 0;
    }
    for(char c : str){
        hash = hash * 31 + static_cast<unsigned char>(c);
    }
    return static_cast<int>(hash % m);  // basic division method
}
