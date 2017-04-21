//
// Created by Jing Yang on 2017/04/20Thursday.
//

#include "yj_bubble_sort.h"

/*
 *  @brief  冒泡排序
 *          结束的标志是在一趟排序中没有发生元素的交换（可能早于循环结束条件的到来）
 *
 *  @analysis  时间复杂度：最坏O(n^2),逆序；
 *                       最好O(n),顺序。
 *                       平均O(n^2)
 *             空间复杂度：O(1)
 *
 *             冒牌排序是稳定的
 */

void yj_bubble_sort(int myArr[], int len) {
    int i, j, flag;

    for (i = len;  i >= 1 ; --i) {
        flag = 0;
        for( j = 1; j < i; ++j) {
            if(myArr[j-1] > myArr[j]) {
                int temp = myArr[j];
                myArr[j] = myArr[j-1];
                myArr[j-1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}