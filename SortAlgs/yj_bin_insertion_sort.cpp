//
// Created by Jing Yang on 2017/04/20Thursday.
//

#include "yj_bin_insertion_sort.h"
#include "yj_bin_search.h"

/*
 *  @brief 折半插入排序，与直接插入排序类似，只是在将关键字插入到有序部分时使用折半查找来找到插入的位置，而不是从右至左逐次遍历
 *         相同的数字时是插入到右边了，即保持了这两个数字原来的相对位置，故算法是稳定的了。
 *
 *  @analysis 时间复杂度，最好(n)，本身有序；
 *                      最坏O(n^2),本身逆序；
 *                      平均情况O(n^2)
 *            空间复杂度  O(1)　
 */

void yj_bin_insertion_sort(int myArr[], int len) {
    int i, j, key, insert_position;
    for (i = 1; i < len; ++i) {
        key = myArr[i];
        insert_position = yj_bin_search_for_bin_insertion_sort(myArr, 0, i-1, key);
        for (j = i-1; j >= insert_position ; j--) {
            myArr[j+1] = myArr[j];
        }
        myArr[insert_position] = key;
    }
}