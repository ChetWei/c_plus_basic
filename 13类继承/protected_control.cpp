//
//created by chetwei on 2022/5/2 
//
#include <iostream>

using namespace std;


class A {
    string phone; //成员默认是 私有的，派生类无法访问，只能通过基类的公共方法进行访问
protected:  //protected的作用在于，使得派生类可以直接访问基类的成员
    string username;
private:
    string password;

public:
    A() {};

    A(string username, string phone, string password) {
        this->username = username;
        this->phone = phone;
        this->password = password;
    }

    void showpwd() {
        cout << "passwod: " << this->password << endl;
    }
};

class B : public A {
public:
    B(string username, string phone, string password) : A(username, phone, password) {
    }

    void showname() { //访问基类中的 protected 成员
        cout << "username: " << username << endl;
    }
};

int main() {

    B b = B("Tom", "119", "123456");
    b.showname();
    b.showpwd();
}