#include <bits/stdc++.h>

using namespace std;

class Singlenton {
private:
    Singlenton()
    {
    }

    Singlenton(const Singlenton&)
    {
    }

    Singlenton& operator=(const Singlenton&)
    {
    }

    mutex m;

public:
    static Singlenton* single;

    Singlenton* getSingenton()
    {
        if (single != nullptr) {
            m.lock();
            if (single != nullptr) {
                single = new Singlenton;
            }
            m.unlock();
        }
        return single;
    }
};

Singlenton* Singlenton::single;