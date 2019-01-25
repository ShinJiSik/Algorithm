//
//  main.cpp
//  BOJ1012_유기농배추
//
//  Created by 신지식 on 14/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int test_case, w, h, k;
int farm[51][51];
bool check[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init(){
    for(int i = 0; i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            farm[i][j] = 0;
            check[i][j] = false;
        }
    }
}

void bfs(int a, int b){
    queue<pair<int, int>> q;
    
    q.push({a, b});
    check[a][b] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            
            if(farm[nx][ny] == 1 && check[nx][ny] == false){
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test_case;
    
    while(test_case--){
        cin >> w >> h >> k;
        
        init();
        
        int x, y;
        for(int i = 0; i < k; i++){
            cin >> y >> x;
            farm[x][y] = 1;
        }
        int ans = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(farm[i][j] == 1 && check[i][j] == false){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        
        cout << ans << "\n";
    }
}
