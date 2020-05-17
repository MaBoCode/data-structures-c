//
// Created by matt on 5/17/20.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node {
    int  data;
    struct Node* next;
};

void push(struct Node**, int);
void insert_after(struct Node*, int);
void append(struct Node**, int);

void delete(struct Node**, int);
void delete_at(struct Node**, int);
void remove_duplicates(struct Node*);

void erase(struct Node**);

int occurs(struct Node*, int);
int rec_occurs(struct Node*, int);

int length(struct Node**);
int rec_length(struct Node*);

int exist(struct Node*, int);
int rec_exist(struct Node*, int);

int get_at(struct Node*, int);
int rec_get_at(struct Node*, int);
int rec_get_at_helper(struct Node*, int , int);

void print_list(struct Node*);

#endif //SINGLY_LINKED_LIST_H
