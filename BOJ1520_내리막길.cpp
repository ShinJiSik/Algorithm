//
//  main.cpp
//  BOJ1520_내리막길
//
//  Created by 신지식 on 14/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;
int w, h;
int map[501][501];
bool check[501][501];
int ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    if(x == h - 1 && y == w - 1){
        ans++;
        return;
    }
    //printf("%d %d\n", x, y);
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        
        if(map[x][y] > map[nx][ny] && check[nx][ny] == false){
            check[nx][ny] = true;
            dfs(nx, ny);
            check[nx][ny] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> map[i][j];
    ans = 0;
    dfs(0, 0);
    
    cout << ans << "\n";
}
