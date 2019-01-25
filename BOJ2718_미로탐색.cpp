//
//  main.cpp
//  BOJ2718_미로탐색
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101][101];
int cal[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(arr[nx][ny] == 1 && cal[nx][ny] == 1){
                    q.push(make_pair(nx, ny));
                    cal[nx][ny] = cal[x][y] + 1;
                }
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
            if(arr[i][j] == 1)
                cal[i][j] = 1;
        }
    }
    
    bfs(0, 0);

    printf("%d\n", cal[n-1][m-1]);
}
