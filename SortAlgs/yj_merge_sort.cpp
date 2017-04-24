//
// Created by Jing Yang on 2017/04/24Monday.
//

#include "yj_merge_sort.h"

void merge(int myArr[], int left, int mid, int right) {
    int leftPtr,rightPtr,sortedArrPtr;
    int len = right+1;
    int backupArr[len];
    for (int i = left; i <= right; ++i) {
        backupArr[i] = myArr[i];
    }

    for (leftPtr=left, rightPtr=mid+1, sortedArrPtr=left; leftPtr <= mid && rightPtr <= right ; sortedArrPtr++) {
        if (backupArr[leftPtr] <= backupArr[rightPtr]){
            myArr[sortedArrPtr] = backupArr[leftPtr++];
        } else {
            myArr[sortedArrPtr] = backupArr[rightPtr++];
        }
    }

    while(leftPtr <= mid) {
        myArr[sortedArrPtr++] = backupArr[leftPtr++];
    }
    while(rightPtr <= right) {
        myArr[sortedArrPtr++] = backupArr[rightPtr++];
    }
}

/*
 *  @brief  归并排序(2路归并排序）
 *
 *  analysis  时间复杂度：O(n*logn)，平均，最好，最坏都是
 *            空间复杂度：O(n), 需要数组长度的辅助空间
 *            尽管归并排序的最坏时间复杂度要好于快排，但是实际生产环境中多使用的是快排，因为快排很难取到最坏时间复杂度，而且快排的空间复杂度小于归并
 */
void yj_merge_sort(int myArr[], int left, int right){
    if (left < right) {
        int mid = (left + right) / 2;
        yj_merge_sort(myArr, left, mid);
        yj_merge_sort(myArr, mid+1, right);
        merge(myArr, left, mid, right);
    }
}