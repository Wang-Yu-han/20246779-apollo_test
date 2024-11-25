#include"search.h"
#include<iostream>
#include<vector>
#include <locale>
using namespace std;

int main()
{
    int m, n;
    std::setlocale(LC_ALL, "Chs");
    std::setlocale(LC_ALL, "zh_CN.UTF-8");
    // 输入矩阵的行数和列数
    cout << "行数 (m): ";
    cin >> m;
    cout << "列数 (n): ";
    cin >> n;

    // 创建 board 矩阵
    vector<vector<char>> board(m, vector<char>(n));

    // 输入 board 的内容
    cout << "请输入元素 (每个元素都是字符'X'或者'O'):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];  // 逐个输入矩阵元素
        }
    }


    cout << "先前的矩阵:" << endl;
    printBoard(board);

    // 调用solve函数处理
    solve(board);

    cout << "调整后的矩阵:" << endl;
    printBoard(board);

    return 0;
}