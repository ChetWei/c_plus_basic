#include <iostream>
#include "coordin.h"

//定义一个static变量，只能在本文件访问
static int errors = 6;

rect changeRect(rect & xypos,int v){

    xypos.x *= v;
    xypos.y *= v;

    return xypos;
}

void showRect(rect xypos){
    using namespace std;
    cout << "x: " << xypos.x << endl;
    cout << "y: " << xypos.y << endl;
}
