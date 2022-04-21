#include <iostream>

using namespace std;

void countdown(int n);

void test(){
    countdown(4);
}

void countdown(int n) {
    cout << "counting down ..." << n << endl;
    if (n > 0) {
        countdown(n - 1);
    }
    cout << "result: " << n << endl;
}