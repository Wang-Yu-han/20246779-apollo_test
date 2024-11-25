#ifndef SEARCH_H
#define SEARCH_H
#include<vector>
using namespace std;
void dfs(vector<vector<char>>& board, int i, int j, int m, int n);
void solve(vector<vector<char>>& board);
void printBoard(const vector<vector<char>>& board);

#endif
