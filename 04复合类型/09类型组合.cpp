#include <iostream>

using namespace std;

struct phone {
    int product_year;
};

void test() {
    phone s1, s2, s3;
    s1.product_year = 1998;

    phone *p2 = &s2;
    p2->product_year = 1999;

    phone phones[3];
    phones[0].product_year = 2003;

    //结构数组默认是第一个元素的地址
    cout << phones->product_year << endl;

    //定义指针数组，三个指针分别指向
    const phone *pas[3] = {&s1, &s2, &s3};

    cout << "pas[1].product_year: " << pas[1]->product_year << endl;

    const phone ** ppas = pas;
    auto ppbs = pas; // auto 会自动进行指针类型的判断

    cout << (*(ppas+1))->product_year << endl;
    cout << (*(ppbs+1))->product_year << endl;
};