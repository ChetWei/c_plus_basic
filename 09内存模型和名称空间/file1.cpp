
#include "coordin.h"

//file1来调用 file2对coordin头文件的实现

int main(){
    rect rc = {1,5};
    changeRect(rc,20);
    showRect(rc);
    return 0;
}

//对文件进行编译  g++ file1.cpp file2.cpp
