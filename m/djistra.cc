#include <bits/stdc++.h>

using namespace std;

//DisjKstra算法
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        queue<int> myQue; //该队列用于即将访问的节点
        vector<int> distToK(N + 1, INT_MAX); //distToK[index]表示点K到点index的最短距离
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1)); //邻接矩阵
        for (auto& time : times) { //构建邻接矩阵
            graph[time[0]][time[1]] = time[2];
        }
        myQue.push(K);
        distToK[K] = 0; //K到自己的最短距离为0
        //开始搜索各个点到k的最短距离
        while (!myQue.empty()) {
            int front = myQue.front();
            myQue.pop();
            //利用当前front节点，尝试稀疏点k到所有节点的最短距离
            for (int target = 1; target <= N; ++target) {
                if (graph[front][target] != -1 && distToK[front] + graph[front][target] < distToK[target]) {
                    //如果front到target有边，并且点k到front的距离distToK[front] + 点front到target距离graph[front][target]小于点k到target的距离distToK[target]
                    distToK[target] = distToK[front] + graph[front][target]; //则进行稀疏
                    myQue.push(target); //放入队列
                }
            }
        }
        //寻找点k到各个点的最短距离的最大值
        int maxRes = 0;
        for (int i = 1; i <= N; ++i) {
            maxRes = max(maxRes, distToK[i]);
        }
        return maxRes == INT_MAX ? -1 : maxRes;
    }
};

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
} node;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        while (root != NULL || !s.empty()) {
            while (root != NULL) {
                s.push(root);
                res.push_back(root->val);
                root = root->right;
            }
            if (!s.empty()) {
                auto node = s.top();
                if (node->left) {
                    root = node->left;
                }
                s.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
