//
// Created by Jing Yang on 2017/04/20Thursday.
//
#include "yj_direct_insertion_sort.h"

/*
 * @brief direct insertion sort
 * @algorithm 将数组分成有序和暂时无序的两部分
 *            从剩余的待排序的元素中每次取出一个数与前面已经排好序的部分比较，插入到适当的位置（一般从后向前比较）
 *
 * @analysis 时间复杂度，最好 (n)，本身有序；
 *                     最坏 O(n^2),本身逆序。
 *                     平均 O(n^2)
 *           空间复杂度  O(1)　
 *
 *           稳定性：因为是逐位比较插入的，所以插入排序是稳定的。
 */

void yj_direct_insertion_sort(int myArray[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {//遍历数组
        temp = myArray[i];
        for (j = i-1; j>-1 ; j--) {//遍历左边有序部分，找到合适位置插入
            if (temp < myArray[j]) {
                myArray[j+1] = myArray[j];
            } else {
                break;
            }
        }
        myArray[j+1] = temp;
    }
}

//等价写法
void yj_direct_insertion_sort2(int myArray[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {//遍历数组
        temp = myArray[i];
        for (j = i-1; j>-1 && temp < myArray[j]; j--) {//遍历左边有序部分，找到合适为止插入
            myArray[j+1] = myArray[j];
        }
        myArray[j+1] = temp;
    }
}


