//
// Created by Jing Yang on 2017/04/20Thursday.
//

#include "yj_bubble_sort.h"

/*
 *   比较相邻的元素。如果第一个比第二个大，就交换他们两个。
 *   对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
 *   针对所有的元素重复以上的步骤，除了最后一个。
 *   持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
 *
 *  @brief  冒泡排序
 *          结束的标志是在一趟排序中没有发生元素的交换（可能早于循环结束条件的到来）
 *
 *  @analysis  时间复杂度：最坏O(n^2),逆序；
 *                       最好O(n),顺序。
 *                       平均O(n^2)
 *             空间复杂度：O(1)
 *
 *             冒泡排序是稳定的
 */

void yj_bubble_sort(int myArr[], int len) {
    int i, j, flag;

    for (i = len - 1;  i >= 1 ; --i) {
        flag = 0;
        for( j = 0; j < i; ++j) {
            if(myArr[j] > myArr[j+1]) {
                int temp = myArr[j];
                myArr[j] = myArr[j+1];
                myArr[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}

void yj_bubble_sort2(int myArr[], int len) {
    int i, j, flag;

    for (i = 0; i < len - 1;i++) {
        flag = 0;
        for( j = 0; j < len-1-i; ++j) {
            if(myArr[j] > myArr[j+1]) {
                int temp = myArr[j];
                myArr[j] = myArr[j+1];
                myArr[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}