//
//  main.cpp
//  BOJ14500_Tetromino
//
//  Created by 신지식 on 2018. 9. 24..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int check[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0 ,1, -1};
int ans = 0;
int n, m;
void go(int x, int y, int sum, int cnt){
    if(cnt == 4){
        ans = max(ans, sum);
        return;
    }
    
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(check[x][y] == true) return;
    check[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        go(x+dx[i], y+dy[i], sum + arr[x][y], cnt + 1);
    }
    check[x][y] = false;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            go(i, j, 0, 0);
            if(j + 2 < m){
                int tmp = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                if(i - 1 >= 0){
                    int tmp2 = tmp + arr[i-1][j+1];
                    if(tmp2 > ans)
                        ans = tmp2;
                }
                if(i + 1 < n){
                    int tmp2 = tmp + arr[i+1][j+1];
                    if(tmp2 > ans)
                        ans = tmp2;
                }
            }
            if(i + 2 < n){
                int tmp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
                if(j + 1 < m){
                    int tmp2 = tmp + arr[i+1][j+1];
                    if(tmp2 > ans)
                        ans = tmp2;
                }
                if(j - 1 >= 0){
                    int tmp2 = tmp + arr[i+1][j-1];
                    if(tmp2 > ans)
                        ans = tmp2;
                }
            }
        }
    }
    printf("%d\n", ans);
}
