//
//  main.cpp
//  BOJ2468_안전영역
//
//  Created by 신지식 on 14/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, ans, area;
int map[101][101];
int temp[101][101];
bool check[101][101];

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = map[i][j];
            check[i][j] = false;
        }
    }
}

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if(temp[nx][ny] == 1 && check[nx][ny] == false){
                temp[nx][ny] = -1;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    if(ans < area)
        ans = area;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int to = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(to < map[i][j])
                to = map[i][j];
        }
    }
    
    ans = 0;
    for(int flood = 0; flood < to; flood++){
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(temp[i][j] <= flood){
                    temp[i][j] = -1;
                }
                else
                    temp[i][j] = 1;
            }
        }
        
        area = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(temp[i][j] == 1){
                    bfs(i, j);
                    area++;
                }
            }
        }
    }
    
    cout << ans << "\n";
}
