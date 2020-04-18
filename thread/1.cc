
#include <bits/stdc++.h>

using namespace std;

class Foo {
private:
    mutex m;
    condition_variable_any cv1;
    condition_variable_any cv2;
public:
    Foo() {
    
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        lock_guard<mutex> lg(m);
        printFirst();
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        lock_guard<mutex> lg(m);
        cv1.wait(lg);
        printSecond();
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        lock_guard<mutex> lg(m);
        cv2.wait(lg);
        printThird();
    }
};

int main()
{
    Foo f;
    f.first([](){cout << "a" << endl;});
}