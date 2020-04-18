#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
      if (deck.size() == 0) {
    	  return false;
      }
      unordered_map<int, int> um;
      for (auto i : deck) {
        um[i]++;
      }
      int num = um.begin()->second;
      cout << um.size() << endl;
      for (auto i : um) {
        if (i.second == num) {
            continue;
        } else {
          return false;
        }
      }
      return true;
  }

};

int main() {
  Solution s;
  vector<int> v = {1,1,2,2,3,3};
  cout << s.hasGroupsSizeX(v) << endl;
}
