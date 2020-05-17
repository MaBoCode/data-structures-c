#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashMap* map = createHashMap(numsSize);
    int* result = (int*) malloc(sizeof(int) * 2);

    for(int i = 0; i < numsSize; i++) {
        put(map, nums[i], i);
    }

    for(int i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        Entry* elem = get(map, diff);
        if(elem != NULL) {
            result[0] = i;
            result[1] = elem->value;
            return result;
        }
    }
    free(result);
    free(map);
    return NULL;
}

typedef struct Tests {
    int key;
    int value;
    struct Tests *next;
} Test ;

int main(void) {
    int nums[] = {2,7,11,15};
    int numSize = sizeof(nums) / sizeof(int);
    int target = 9;
    int returnSize[2];

    //int* result = twoSum(nums, 4, target, returnSize);

    //printf("i = %d, j = %d\n", result[0], result[1]);

    printf("sizeof(Tests) = %lu\n", sizeof(struct Tests));
    printf("sizeof(Test) = %lu\n", sizeof(Test));
}