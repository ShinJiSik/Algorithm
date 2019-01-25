//
//  main.cpp
//  BOJ9663_N-Queens
//
//  Created by 신지식 on 2018. 10. 9..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//
/*
#include <iostream>
using namespace std;
bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
bool check(int row, int col) {
    // |
    if (check_col[col]) {
        return false;
    }
    // / 대각선
    if (check_dig[row+col]) {
        return false;
    }
    // \
    if (check_dig2[row-col+n]) {
        return false;
    }
    return true;
}
int calc(int row) {
    if (row == n) {
        // ans += 1;
        return 1;
    }
    int cnt = 0;
    for(int col = 0; col < n; col++){
        if(check(row, col)){
            check_dig[row+col] = true;
            check_dig2[row-col+n] = true;
            check_col[col] = true;
            a[row][col] = true;
            cnt += calc(row+1);
            check_dig[row+col] = false;
            check_dig2[row-col+n] = false;
            check_col[col] = false;
            a[row][col] = false;
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    cout << calc(0) << '\n';
    return 0;
}
 */

#include <iostream>
using namespace std;
bool a[15][15];
int n;
int ans = 0;
bool check(int row, int col) {
    // |
    for (int i=0; i<n; i++) {
        if (i == row) continue;
        if (a[i][col]) {
            return false;
        }
    }
    // 왼쪽 위 대각선
    int x = row-1;
    int y = col-1;
    while (x >=0 && y >=0) {
        if (a[x][y] == true) {
            return false;
        }
        x -= 1;
        y -= 1;
    }
    // /
    x = row-1;
    y = col+1;
    while (x >=0 && y < n) {
        if (a[x][y] == true) {
            return false;
        }
        x -=1;
        y += 1;
    }
    return true;
}
void calc(int row) {
    if (row == n) {
        ans += 1;
    }
    for (int col=0; col<n; col++) {
        a[row][col] = true;
        if (check(row, col)) {
            calc(row+1);
        }
        a[row][col] = false;
    }
}
int main() {
    cin >> n;
    calc(0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d%d ", i, j);
        printf("\n");
    }
    cout << ans << '\n';
    return 0;
}
