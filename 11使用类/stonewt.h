
#ifndef C_PLUS_BASIC_STONEWT_H
#define C_PLUS_BASIC_STONEWT_H

class Stonewt {
private:
    enum {
        Lbs_per_stn = 14
    };
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt();

    Stonewt(double lbs);

    Stonewt(int stn, double lbs);

    ~Stonewt();

    void show_lbs() const;

    void show_stn() const;

    //转换函数 没有返回类型，没有参数，但必须返回转换后的值
    operator int() const;
    operator double() const;
//    operator long() const;


};

#endif //C_PLUS_BASIC_STONEWT_H
