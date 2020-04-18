#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

bool flag = true;

class Producer {
public:
    static void* A(void* arg)
    {
        while (1) {
            while (!flag) {
                pthread_cond_wait(&cond, &mutex);
            }
            cout << "A" << endl;
            flag = false;
            sleep(1);
            pthread_cond_signal(&cond);
        }
    }

    static void* B(void* arg)
    {
        while (1) {
            while (flag) {
                pthread_cond_wait(&cond, &mutex);
            }
            cout << "B" << endl;
            flag = true;
            sleep(1);
            pthread_cond_signal(&cond);
        }
    }
    static pthread_mutex_t mutex;
    static pthread_cond_t cond;
};

pthread_mutex_t Producer::mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t Producer::cond = PTHREAD_COND_INITIALIZER;

struct D {
    int a;
    operator bool() {
        //return true;
    }
    operator void*() {
        
    }
};

int main()
{
    pthread_t tid[2];
    D d;
    if (d == nullptr) {
        cout << "d" << endl; 
    }
    pthread_create(&tid[0], NULL, Producer::A, NULL);
    pthread_create(&tid[1], NULL, Producer::B, NULL);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

}