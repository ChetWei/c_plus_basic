//
//created by chetwei on 2022/5/4 
//
#include "worker.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Waiter waiter("bob",314L,5);
    Singer singer("tony",456L,3);

    Worker *w1 = &waiter;
    Worker *w2 = &singer;

    w1->Set();
    w1->Show();

    w2->Set();
    w2->Show();

    SingerWaiter sg("jack",123L,78.6);
    // 第一代 Worker
    // 第二代 Singer->Worker   Waiter->Worker
    // 第三代 SingerWaiter
    //由于第三代 SingerWaiter 继承了两个第二代，因此将它向上转行有歧义,y要指定对象
    //要解决这个情况，可以使用虚基类
//    Worker *pw = (Singer *) &sg;
//
    Worker *pw = &sg;

    return 0;
}