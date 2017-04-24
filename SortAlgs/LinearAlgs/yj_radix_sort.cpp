//
// Created by Jing Yang on 2017/04/24Monday.
//

#include "yj_radix_sort.h"
#include "../../YJ_HelperMethod.h"

/*
 *  @brief  基数排序，从最低位到最高位对数组中元素依次进行一次稳定的排序（本算法用的是计数排序）
 *
 *          有的书介绍基数排序的时候用到了放置到桶中（具有队列先进先出的特性的桶），然后再收集的方法，实质上就是一次稳定的排序过程
 *
 *  @analysis  时间复杂度O( d*(n+k) ),d为最大位数，n为数组中元素的个数，k为数组中元素使用的进制（本例为10）
 *             空间复杂度O(k)
 */
void yj_radix_sort(int myArr[], int len){
    int bit_num = largest_num_bits(myArr, len);
    int countArr[10];//用于计数排序的数组
    int tempArr[len];
    int weight;

    int radix = 1;
    for (int i = 1; i <= bit_num; ++i) {

        //对每一位上的数进行计数排序
        for (int j = 0; j < 10; ++j) {
            countArr[j] = 0;
        }
        for (int j = 0; j < len; ++j) {
            weight = (myArr[j] / radix) % 10;//每一位的数
            countArr[weight]++;
        }
        for (int j = 1; j < 10; ++j) {
            countArr[j] = countArr[j-1] + countArr[j];
        }
        for (int j = len - 1; j >= 0 ; --j) {
            weight = (myArr[j] / radix) % 10;
            int subIdx = countArr[weight] - 1;
            tempArr[subIdx] = myArr[j];
            countArr[weight]--;
        }//计数排序结束

        for (int j = 0; j < len; ++j) {
            myArr[j] = tempArr[j];
        }
        radix *= 10;
    }
}