//
//  main.cpp
//  BOJ4963_섬의개수
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[51][51];
bool check[51][51];
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0 ,-1, 1, 0, 1, -1};
int w, h;

void bfs(int x, int y, int cnt){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h){
                if(arr[nx][ny] == 1 && check[nx][ny] == false){
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    while(1){
        cin >> h >> w;
        if(w == 0 && h == 0)
            break;

        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                cin >> arr[i][j];
                check[i][j] = false;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(arr[i][j] == 1 && check[i][j] == false){
                    bfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
    }
}
