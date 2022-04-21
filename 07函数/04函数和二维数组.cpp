
#include <iostream>

using namespace std;

//2个指向int的指针 组成的数组
int sum(int (*ar2)[2], int size);

//int sum(int ar2[][2], int size); //等同于上面的效果

void test() {
    int data[3][2] = {{1, 2},
                      {3, 4},
                      {5, 6}};
    int total = sum(data, 3);
    cout << total << endl;
}


int sum(int ar2[][2], int size) {
    int total = 0;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < 2; c++) { //固定2列
            total += ar2[r][c]; //ar2[r][c]  等价于 *( *(ar2+r) + c )
            // (ar2+r) 是 第几行的地址（长度为2的数组地址）;
            // *(ar2+r) 第几行（长度为2的数组），数组就是第一个元素的起始地址
            // *(ar2+r) + c  这一行的第几列 元素地址
            // *( *(ar2+r) + c )  这一行的第几列 元素的值
        }
    }
    return total;
}