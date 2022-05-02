//
//created by chetwei on 2022/5/2 
//


//抽象基类
//抽象类，不能用来创建对象；
// 由它的派生类来进行具体的实现，通过派生类来创建对象
class BaseEllipse {
private:
    double x;
    double y;
public:
    BaseEllipse(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}

    virtual ~BaseEllipse() {}

    void Move(int nx, int ny) { x = nx, y = ny; }

    virtual double Area() const=0; //=0 定义了一个虚函数，那么这个类就是一个抽象类
};
