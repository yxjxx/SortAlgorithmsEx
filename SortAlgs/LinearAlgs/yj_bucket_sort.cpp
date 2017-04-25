//
// Created by Jing Yang on 2017/04/25Tuesday.
//

#include <cstdlib>
#include "yj_bucket_sort.h"
#include "../../YJ_Structs.h"

/*
 *  @brief  桶排序，假设输入由一个随机过程产生，该过程产生将元素均匀而独立的分布到区间[0,1)上，桶排序的思想就是把区间[0,1)划分成n个相同大小的子区间（即桶）
 *                 将n个输入数分布到各个桶中去，因为输入均匀分布，一般不会有太多的元素分布到同一个桶中。
 *                 为了得到结果，先对各个桶中的元素进行排序，然后按次序输出各桶中的元素。
 *
 *                 本例中元素范围为0-99，使用10个桶，十位相同的数放在一个桶中.
 */
void yj_bucket_sort(int myArr[], int len) {
    int BUCKET_SIZE = 10;
    LNode *bucketArr = (LNode *)malloc(BUCKET_SIZE * sizeof(LNode));

    //init bucketArr
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        bucketArr[i].data = i;
        bucketArr[i].next = NULL;
    }

    //遍历 myArr 放到桶中
    for (int i = 0; i < len; ++i) {
        LNode *newNode, *ptr, *prePtr;
        int whichBucket = myArr[i] / BUCKET_SIZE;

        prePtr = &(bucketArr[whichBucket]);
        ptr = bucketArr[whichBucket].next;

        while (ptr != NULL && ptr->data <= myArr[i]) {
            prePtr = ptr;
            ptr = ptr->next;
        }
        newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = myArr[i];
        newNode->next = ptr;
        prePtr->next = newNode;
    }

    int subIdx = 0;
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        LNode *ptr = &(bucketArr[i]);
        while(ptr->next != NULL) {
            myArr[subIdx++] = ptr->next->data;
            ptr = ptr->next;
        }
    }
}