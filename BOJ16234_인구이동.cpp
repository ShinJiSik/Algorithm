//
//  main.cpp
//  BOJ16234_인구이동
//
//  Created by 신지식 on 30/10/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
#include <memory.h>
#include <vector>
using namespace std;
int n, l, r;
int map[51][51];
bool check[51][51];
bool ending;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            check[i][j] = false;
        }
    }
}

void bfs(int i, int j){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    
    q.push({i, j});
    v.push_back({i, j});
    //check[i][j] = true;
    int sum = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if(check[nx][ny] == false){
                int dist = abs(map[x][y] - map[nx][ny]);
                if(dist >= l && dist <= r){
                    q.push({nx, ny});
                    check[nx][ny]= true;
                    sum += map[nx][ny];
                    v.push_back({nx, ny});
                }
            }
        }
    }
    int len = (int)v.size();
    //printf("------------%d %d\n",sum, len);
    if(len >= 2){
        sum /= (len-1);
        for(int i = 0; i < len; i++)
            map[v[i].first][v[i].second] = sum;
        ending = true;
    }
}

int main(){
    cin >> n >> l >> r;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    int ans = 0;
    while(1){
        ending = false;
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(check[i][j] == false){
                    bfs(i, j);
                }
            }
        }
        /*
        for(int i = 0; i<n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", check[i][j]);
            }
            printf("\n");
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        */
        if(ending == false)
            break;
        ans++;
    }
    cout << ans << "\n";
}
