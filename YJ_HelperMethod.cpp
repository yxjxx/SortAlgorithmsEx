//
// Created by Jing Yang on 2017/04/20Thursday.
//

#include <iomanip>
#include "iostream"
#include "YJ_HelperMethod.h"
using namespace std;

//最大数字的位数
int largest_num_bits(int myArr[], int len){
    int current_largest_bits;
    if(len == 0) {
        return 0;
    } else {
        current_largest_bits = 1;
    }
    int measure = 10;//尺子
    for (int i = 0; i < len; ++i) {
        while (myArr[i] >= measure) {
            measure *= 10;
            ++current_largest_bits;
        }
    }
    return current_largest_bits;
}

void create_array_with_random_numbers(int myArr[], int len) {
    for (int i = 0; i < len; ++i) {
        sranddev();
        myArr[i] = rand() % NUM_RANGE;
    }
}

void print_array(int myArr[], int len) {
    int max_bit = largest_num_bits(myArr, len);
    for (int i = 0; i < len; ++i) {
        cout << right << setw(max_bit + 1) << myArr[i]; //打印时每个数字显示都占用 max_bit 位
    }
    cout << endl;
}