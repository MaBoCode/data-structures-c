//
// Created by matt on 5/18/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

unsigned int get_size(struct ListNode* node) {
    unsigned int count = 0;
    struct ListNode* temp = node;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int get_number(struct ListNode* node) {
    unsigned int capacity = get_size(node);
    st_stack *stack = st_create(capacity);
    struct ListNode* temp = node;

    while (temp != NULL) {
        st_push(stack, temp->val);
        temp = temp->next;
    }
    int nb = 0;
    for(int i = 0; i < stack->capacity; i++) {
        int value = stack->items[i];
        nb += value * (int) pow(10, i);
    }
    free(stack);
    return nb;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int n1 = get_number(l1);
    int n2 = get_number(l2);

    struct ListNode* node = malloc(sizeof(struct ListNode));


}

int main(void) {
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l2->val = 4;
    l3->val = 3;

    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;

    addTwoNumbers(l1, NULL);

    free(l1);
    free(l2);
    free(l3);
}