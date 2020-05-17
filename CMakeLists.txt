cmake_minimum_required(VERSION 3.15)
project(data-structures-c C)

set(CMAKE_C_STANDARD 99)

#Linking and compiling SLL
add_executable(sll
        lists/singly_ll/singly_linked_list.h
        lists/singly_ll/singly_linked_list.c
        lists/singly_ll/test_sll.c)

#Linking and compiling DLL
add_executable(dll
        lists/doubly_ll/doubly_linked_list.h
        lists/doubly_ll/doubly_linked_list.c
        lists/doubly_ll/test_dll.c)

#Linking and compiling hashmap
add_executable(hashmap
        hashmap/hashmap.h
        hashmap/hashmap.c
        hashmap/test_hashmap.c)

#Linking and compiling hashtable
add_executable(hashtable
        hashtable/hashtable.h
        hashtable/hashtable.c
        hashtable/test_hashtable.c)

target_link_libraries(hashtable m)