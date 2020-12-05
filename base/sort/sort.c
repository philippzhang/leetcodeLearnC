//
// Created by zhangyangshuo on 2020/12/4.
//

#include <stdio.h>
#include <stdlib.h>
//交换
void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//返回最小
int min(int x,int y){
    return x<y ? x : y;
}

//冒泡排序
void looperSort(int * arr,int len){
    int i,j;
    for (i = 0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

//选择排序/
void selectSort(int *arr,int len){
    int min ,i ,j;
    for(i=0;i<len-1;i++){
        min = i;
        for(j=i+1;j<len;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[min],&arr[i]);
        }
    }
}

//插入排序
void insertSort(int *arr,int len){
    int i,j,temp;
    for(i=1;i<len;i++){
        temp = arr[i];
        for (j=i;j>0&&arr[j-1]>temp;--j){
            arr[j] = arr[j-1];
        }
        arr[j]=temp;
    }
}

//希尔排序
void shelllSort(int *arr,int len){
    int gap,i,j,temp;
    for(gap = len>>1;gap>0;gap=gap>>=1){
        for(i=gap;i<len;i++){
            temp = arr[i];
            for(j=i-gap;j>=0&&arr[j]>temp;j-=gap){
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = temp;
        }
    }
}

//归并排序
void mergeSort(int *arr,int len){
    int *a = arr;
    int *b = (int*)malloc(len*sizeof(int));
    int seg, start;
    for(seg=1;seg<len;seg+=seg){
        for(start=0;start<len;start+=seg+seg){
            int low = start, mid = min(start+seg,len),high = min(start+seg+seg,len);
            int k = low;
            int start1=low ,end1=mid;
            int start2=mid ,end2=high;
            while(start1<end1&&start2<end2){
                b[k++] = a[start1]<a[start2]?a[start1++]:a[start2++];
            }
            while(start1<end1){
                b[k++] = a[start1++];
            }
            while(start2<end2){
                b[k++] = a[start2++];
            }
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if(a!=arr){
        int i;
        for(i=0;i<len;i++){
            b[i] = a[i];
        }
        b=a;
    }
    free(b);
}

void merge_sort_recursive(int arr[],int reg[] ,int start, int end){
    if(start>=end){
        return;
    }
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr,reg,start1,end1);
    merge_sort_recursive(arr,reg,start2,end2);
    int k = start;
    while(start1<=end1 && start2<=end2){
        reg[k++] = arr[start1]<arr[start2]?arr[start1++]:arr[start2++];
    }
    while(start1<=end1){
        reg[k++] = arr[start1++];
    }
    while(start2<=end2){
        reg[k++] = arr[start2++];
    }
    for(k=start;k<=end;k++){
        arr[k] = reg[k];
    }
}

//归并排序 递归
void mergeSort2(int *arr, int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

typedef struct _Range {
    int start, end;
} Range;

Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
//快速排序
void quickSort(int *arr, int len){
    if(len<=0){
        return;
    }
    //r为模式列表，p为数量，r[p++]为push,r[--p]为pop去的元素
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0,len-1);
    while(p){
        Range range = r[--p];
        if(range.start>=range.end){
            continue;
        }
        //中间值
        int mid = arr[(range.start+range.end)/2];
        int left = range.start,right = range.end;
        do{
            //检测左侧是否符合要求
            while (arr[left]<mid) ++left;
            //检测右侧是否符合要求
            while (arr[right]>mid) --right;
            if(left<=right){
                swap(&arr[left],&arr[right]);
                //移动指针
                left++;right--;
            }
        }while (left<=right);

        if(range.start<right) r[p++] = new_Range(range.start,right);
        if(range.end>left) r[p++] = new_Range(left,range.end);

    }
}
//快速排序递归
void quick_sort_recursive(int arr[],int start, int end){
    if(start>=end){
        return;
    }
    int mid = arr[end];
    int left = start,right =end-1;
    while(left<right){
        while(arr[left]<mid&&left<right){
            left++;
        }
        while(arr[right]>=mid&&left<right){
            right--;
        }
        swap(&arr[left],&arr[right]);
    }
    if(arr[left]>=arr[right]){
        swap(&arr[left],&arr[end]);
    }else{
        left++;
    }
    if(left){
        quick_sort_recursive(arr,start,left-1);
    }
    quick_sort_recursive(arr,left+1,end);
}

void quickSort2(int *arr,int len){
    quick_sort_recursive(arr,0,len-1);
}

int binarySearch(int *arr,int len,int key){
    int start=0;
    int end = len-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(key<arr[mid]){
            end = mid-1;
        }else if(key>arr[mid]){
            start = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

//二分检索
void print_array(int* arr,int len){
    int i;
    for( i = 0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("%c",'\n');
}

int main(){
    int arr[] = {1,5,2,3,6,7,8,4,9,0};
    int len=sizeof(arr)/sizeof(0);
    print_array(arr,len);
    printf("%s\n","冒泡排序:");
    looperSort(arr,len);
    print_array(arr,len);
    printf("%s\n","二分查找:");
    int m=binarySearch(arr,len,3);
    printf("%d\n",m);


    printf("%s\n","选择排序:");
    int arr2[] = {1,5,2,3,6,7,8,4,9,0};
    selectSort(arr2,len);
    print_array(arr2,len);


    printf("%s\n","插入排序:");
    int arr3[] = {1,5,2,3,6,7,8,4,9,0};
    insertSort(arr3,len);
    print_array(arr3,len);


    printf("%s\n","基尔排序:");
    int arr4[] = {1,5,2,3,6,7,8,4,9,0};
    shelllSort(arr4,len);
    print_array(arr4,len);

    printf("%s\n","归并排序:");
    int arr5[] = {1,5,2,3,6,7,8,4,9,0};
    mergeSort(arr5,len);
    print_array(arr5,len);

    printf("%s\n","归并排序递归:");
    int arr6[] = {1,5,2,3,6,7,8,4,9,0};
    mergeSort2(arr6,len);
    print_array(arr6,len);

    printf("%s\n","快速排序:");
    int arr7[] = {1,5,2,3,6,7,8,4,9,0};
    quickSort(arr7,len);
    print_array(arr7,len);

    printf("%s\n","快速排序递归:");
    int arr8[] = {1,5,2,3,6,7,8,4,9,0};
    quickSort2(arr8,len);
    print_array(arr8,len);


}