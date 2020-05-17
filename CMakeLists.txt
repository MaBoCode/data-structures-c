cmake_minimum_required(VERSION 3.15)
project(hash_table C)

set(CMAKE_C_STANDARD 99)

#Linking and compiling hashmap
add_executable(hashmap
        hashmap/hashmap.h
        hashmap/hashmap.c
        test_hashmap.c)

#Linking and compiling hashtable
add_executable(hashtable
        hashtable/hashtable.h
        hashtable/hashtable.c
        test_hashtable.c)