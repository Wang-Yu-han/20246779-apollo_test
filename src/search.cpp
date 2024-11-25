#include"search.h"
#include<iostream>
using namespace std;
#include<vector>
void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
    // 如果越界或者不是'O'，直接返回
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
        return;
    }
    
    // 标记当前的'O'为安全区域
    board[i][j] = 'S';  // S for Safe
    
    // 继续访问相邻的四个方向
    dfs(board, i + 1, j, m, n);
    dfs(board, i - 1, j, m, n);
    dfs(board, i, j + 1, m, n);
    dfs(board, i, j - 1, m, n);
}

// 主函数，解决问题
void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;

    int m = board.size();  // 行数
    int n = board[0].size();  // 列数

    // 从边界开始进行DFS，标记所有与边缘相连的'O'为安全区域
    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0, m, n);  // 左边界
        }
        if (board[i][n - 1] == 'O') {
            dfs(board, i, n - 1, m, n);  // 右边界
        }
    }

    for (int j = 0; j < n; ++j) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j, m, n);  // 上边界
        }
        if (board[m - 1][j] == 'O') {
            dfs(board, m - 1, j, m, n);  // 下边界
        }
    }

    // 现在将所有被围绕的'O'变成'X'，同时将安全的'O'恢复为'O'
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';  // 被围绕的'O'变成'X'
            } else if (board[i][j] == 'S') {
                board[i][j] = 'O';  // 安全的'O'恢复原状
            }
        }
    }
}

// 辅助函数，打印矩阵
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}