#include <thread>
#include <iostream>

using namespace std;

void routine()
{
    this_thread::sleep_for(std::chrono::seconds(2));
    int* a = nullptr;
    *a = 1;
}

void routine1()
{
    while (1) {
        cout << "asd" << endl;;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}

int main()
{
    thread a(routine);
    thread b(routine1);

    a.detach();
    b.join();
}