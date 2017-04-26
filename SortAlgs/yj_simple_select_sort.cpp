//
// Created by Jing Yang on 2017/04/21Friday.
//

#include "yj_simple_select_sort.h"

/*
 *  @brief  简单选择排序，将数组分成有序部分和无序部分（左边有序右边无序）
 *          每次从无序部分选择出最小值交换到无序部分的第一个位置，有序部分增加一个，无序部分减少一个元素
 *
 *  @analysis  时间复杂度O(n^2)，空间复杂度O(1)
 *
 *             选择排序不稳定，举个例子，序列5 8 5 2 9，我们知道第一遍选择第1个元素5会和2交换，那么原序列中2个5的相对前后顺序就被破坏了
 */

void yj_simple_select_sort (int myArr[], int len) {
    int i,j, minPtr;

    for (i = 0;  i < len ; ++i) {
        minPtr = i; //i 是无序部分第一个元素
        for (j = i+1; j <= len - 1; j++) {//遍历无序部分, 找到最小值的下标
            if(myArr[minPtr] > myArr[j]){
                minPtr = j;
            }
        }

        int temp = myArr[i];
        myArr[i] = myArr[minPtr];
        myArr[minPtr] = temp;
    }
}