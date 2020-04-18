#include <bits/stdc++.h>

using namespace std;

struct node {
    int id;
    string name;
    int time;
};

class UndergroundSystem {
private:
    map<string, int> m;
    typedef vector<node>::iterator vnite;
    map<int, vnite> m_vnite;
    vector<node> v;
    map<string, int> size;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        node n;
        n.id = id;
        n.name = stationName;
        n.time = t;
        v.push_back(n);
        v.push_back(n);
        m_vnite[id] = v.end() - 1;
        cout << m_vnite[1]->id << m_vnite[1]->name << endl;
    }

    void checkOut(int id, string stationName, int t)
    {
        auto ite = m_vnite[id];
        cout << ite->id << ite->name << endl;
        string n = ite->name;
        string name = n + stationName;
        int time = t - ite->time;
        m[name] += time;
        size[name]++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string name = startStation + endStation;
        int time = m[name];
        int num = size[name];
        return double((double)time / (double)num);
    }
};

int main()
{
    UndergroundSystem us;
    us.checkIn(1, "a", 2);
    us.checkIn(2, "a", 3);
    us.checkOut(1, "b", 8);
    us.checkOut(2, "b", 12);
    cout << us.getAverageTime("a", "b") << endl;
}
