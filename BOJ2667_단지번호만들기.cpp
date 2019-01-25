//
//  main.cpp
//  BOJ2667_단지번호만들기
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int arr[26][26];
int group[26][26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans[26];
void bfs(int x, int y, int cnt){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    group[x][y] = cnt;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(arr[nx][ny] == 1 && group[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j]==1 && group[i][j] == 0)
                bfs(i, j, ++cnt);
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[group[i][j]]++;
        }
    }
    sort(ans+1, ans+1+cnt);
    for(int i = 1; i <= cnt; i++)
        printf("%d\n", ans[i]);
}

