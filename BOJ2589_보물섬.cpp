//
//  main.cpp
//  BOJ2589_보물섬
//
//  Created by 신지식 on 14/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;
int w, h, ans = 0;
char map[51][51];
bool check[51][51];
int dist[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    dist[a][b] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(check[nx][ny] == false && map[nx][ny] != 'W'){
                check[nx][ny] = true;
                if(dist[nx][ny] < dist[x][y] + 1)
                    dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(dist[i][j] > sum)
                sum = dist[i][j];
        }
    }
    if(sum > ans)
        ans = sum;
}

void init(){
    for(int i = 0; i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            check[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    string s;
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++){
            map[i][j] = s[j];
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(map[i][j] == 'L'){
                bfs(i, j);
                init();
            }
        }
    }
    
    cout << ans << "\n";
}
