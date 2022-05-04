//Created by chetwei on 2022/5/4
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Worker {
private:
    std::string fullname;
    long id;

public:
    Worker() {
        fullname = "no one";
        id = 0l;
    }

    Worker(const string &s, long n) : fullname(s), id(n) {}

    //定义纯虚函数，同时表明该类不可实例化，同时继承该类的派生类必须实现该函数。
//    virtual ~Worker() = 0;
    virtual ~Worker(){};

    virtual void Set(){
        cout << "Enter worker's name: ";
        getline(cin,fullname);
        cout <<"Enter worker's ID: ";
        cin >> id;
        while (cin.get()!= '\n')
            continue;
    };

    virtual void Show() const{
        cout << "Name: " << fullname << "\n";
        cout << "Worker's ID: " << id << "\n";
    };
};

//虚基类 virtual public 两个关键字的顺序无关
//作用：使用虚基类的派生类，共享一个基类对象，而不是各自引用自己的基类对象副本
//在使用多态的时候不会有歧义
class Waiter : virtual public Worker {
private:
    int height;
public:

    //派生类只能在其初始化列表中调用基类的构造函数
    Waiter() : Worker() {
        height = 0;
    }

    Waiter(const string &s, long n, int p = 0) : Worker(s, n), height(p) {}

    Waiter(const Worker &wk, int p = 0) : Worker(wk), height(p) {}

    ~Waiter(){}

    void Set(){
        cout << "Enter Waiter's height : ";
        cin >> height;
        while (cin.get()!= '\n')
            continue;
    };

    void Show() const{
        cout << "Waiter" << endl;
        Worker::Show(); //基类的方法
        cout << "Waiter's height: " << height << "\n";
    };

};


class Singer : virtual public Worker {

private:

    int weight;

public:
    Singer() : Worker(), weight(0) {}

    Singer(const string &s, long n, int v = 0) : Worker(s, n), weight(v) {
    }

    Singer(const Worker &worker, int v = 0) : Worker(worker), weight(v) {}

    ~Singer(){};

    void Set(){
        cout << "Enter Singer's weight : ";
        cin >> weight;
        while (cin.get()!= '\n')
            continue;
    };

    void Show() const{
        cout << "Singer" << endl;
        Worker::Show(); //基类的方法
        cout << "Singer's weight: " << weight << "\n";
    };
};

///多继承
class SingerWaiter:public Singer,public Waiter{

private:
    double saraly;
public:
    //派生类只能在其初始化列表中调用基类的构造函数
    SingerWaiter() : Worker() {
        saraly = 0;
    }

    SingerWaiter(const string &s, long n, double p = 0) : Worker(s, n), saraly(p) {}

    SingerWaiter(const Worker &wk, int p = 0) : Worker(wk), saraly(p) {}

    ~SingerWaiter(){}

    void Set(){
        cout << "Enter SingerWaiter's saraly : ";
        cin >> saraly;
        while (cin.get()!= '\n')
            continue;
    };

    void Show() const{
        cout << "SingerWaiter" << endl;
        Worker::Show(); //基类的方法
        Singer::Show();
        Waiter::Show();
        cout << "SingerWaiter's saraly: " << saraly << "\n";
    };
};