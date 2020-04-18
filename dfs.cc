#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int rows;
    int cols;
public:
    int numIslands(vector<vector<char>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        int num = 0;
        dfs(grid, 0, 0, num);
        return num;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int num)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
            return;
        } 
        num++;
        grid[row][col] = '0';
        dfs(grid, row + 1, col, num);
        dfs(grid, row - 1, col, num);
        dfs(grid, row, col + 1, num);
        dfs(grid, row, col - 1, num);
    }
};

int main()
{
    vector<vector<char>> grid = {{'0','0'}};
    Solution s;
    cout << s.numIslands(grid) << endl;

}