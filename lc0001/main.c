//
// Created by zhangyangshuo on 2020/11/9.
//
#include <stdio.h>
#include <stdlib.h>
struct object {
    int val;
    int index;
};
int compare(const void *a, const void *b){
    return ((struct object*)a)->val -  ((struct object*)b)->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    struct object *objs = malloc(numsSize* sizeof(*objs));
    for(i =0;i<numsSize;i++){
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs,numsSize,sizeof(*objs),compare);

    int *results = malloc(2*sizeof(int));
    i = 0;
    j = numsSize-1;
    while(i<j){
        int sum = objs[i].val+objs[j].val;
        if(sum<target){
            i++;
        }else if(sum>target){
            j--;
        }else{
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            *returnSize = 2;
            free(objs);
            return results;
        }
    }
    free(objs);
    return NULL;
}

int main(void){
    int nums[] ={3,2,3};
    int size = sizeof(nums) / sizeof(*nums);
    int target = 6;
    int count = 0;
    int *indexes = twoSum(nums,size ,target,&count);
    if(indexes!=NULL){
        printf("%d %d\n",indexes[0],indexes[1]);
    }else{
        printf("Not found\n");
    }
    return 0;
}
