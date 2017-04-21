//
// Created by Jing Yang on 2017/04/20Thursday.
//

#include "yj_shell_sort.h"

/*
 *  @brief 一趟希尔排序，类似于直接插入排序。
 */
void one_ride_shell(int myArr[], int len, int step) {
   int j = 0, temp;
    for (int i = step; i < len; ++i) {
        temp = myArr[i];
        for (j = i-step; j >= 0 && myArr[j] > temp ; j -= step) {
            myArr[j+step] = myArr[j];
        }
        myArr[j+step] = temp;
    }
}

/*
 *  @brief 希尔排序，也叫缩小增量排序，将待排序的序列按step分成几个子序列，分别对这几个子序列进行直接插入排序
 *         最后一趟的步长应该要为1，保证一定能排好序的。
 *
 *  @param myArray[] 待排序数组
 *  @param stepArray[] 步长数组，步长的选择是希尔排序的关键，参看reference
 *
 *  @reference https://en.wikipedia.org/wiki/Shellsort
 *
 *  @analysis 时间复杂度与步长数组的选取有关，希尔排序的最优时间复杂度为O( n*(logn)^2 ),空间复杂度为O(1).
 *
 *            希尔排序是不稳定的，由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素的相对顺序，
 *            但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱，
 *            所以shell排序是不稳定的。
 */
void yj_shell_sort (int myArr[], int len, int stepArr[], int step_arr_len) {
    for (int i = 0; i<step_arr_len; ++i) {
        int step = stepArr[i];
        one_ride_shell(myArr, len, step);
    }
}