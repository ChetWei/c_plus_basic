#ifndef COORDIN_H__
#define COORDIN_H__

//使用if 防止头文件多次声明
struct rect {
    double x;
    double y;
};

rect changeRect(rect & xypos,int v); //由cpp文件来实现

void showRect(rect xypos); //由cpp文件来实现

#endif