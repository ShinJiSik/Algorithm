//
//  main.cpp
//  SWEA_홈 방범 서비스
//
//  Created by 신지식 on 2018. 10. 19..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[21][21];
int check[21][21];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;
queue<pair<int, int>> q;

void bfs(int x, int y){
    memset(check, 0, sizeof(check));
    check[x][y] = 1;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny] != 0) continue;
            
            if(check[nx][ny] < 2*n){
                check[nx][ny] = check[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    for(int k = 1; k <= n*2; k++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(check[i][j] <= k && map[i][j] == 1 && check[i][j] > 0)
                    cnt++;
            }
        }
        
        if((m * cnt) - ((k * k) + ((k - 1) * (k - 1))) >= 0){
            if(ans < cnt)
                ans = cnt;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int test_case;
    
    cin >> test_case;
    for(int t = 0; t < test_case; t++){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                bfs(i, j);
            }
        }
        
        printf("#%d %d\n", t+1, ans);
    }
}
