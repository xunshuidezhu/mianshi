#include <bits/stdc++.h>
#include <signal.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <unistd.h>

using namespace std;

int fd;

void call(int sig)
{
    if (sig == SIGALRM) {
        long long val = 1;
        write(fd, &val, sizeof(val));
    }
}

int main()
{
    signal(SIGALRM, call);
    fd = eventfd(0, 0);
    alarm(1);
    long long val;
    read(fd, &val, sizeof(val));
    cout << val << endl;
}