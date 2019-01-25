//
//  main.cpp
//  BOJ3055_탈출
//
//  Created by 신지식 on 2018. 10. 4..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int r, c;
char arr[51][51];
int moving[51][51];
bool check[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> s;
queue<pair<int, int>> water;
int ax = 0, ay = 0;
int cnt = 0;
void bfs(int x, int y){
    printf("%d %d\n", ax, ay);
    s.push(make_pair(x, y));
    int nx = 0, ny = 0;
    int flag = 0;
    
    while(!s.empty()){
          int w_s = water.size();
        printf("-- %d--\n", w_s);
        while(w_s--){
            x = water.front().first;
            y = water.front().second;
            water.pop();
            
            for(int i = 0; i < 4; i++){
                nx = x + dx[i];
                ny = y + dy[i];
                
                if(nx < 0 && nx >= c && ny < 0 && ny >= r) continue;
                if(arr[nx][ny] == '.' || arr[nx][ny] == 'S'){
                    if(check[nx][ny] == false){
                        moving[nx][ny] = 0;
                        check[nx][ny] = true;
                        water.push(make_pair(nx, ny));
                    }
                }
            }
        }

        
        x = s.front().first;
        y = s.front().second;
        s.pop();
        int notcnt = 0;
        if(notcnt == 4){
            flag = 1;
            break;
        }
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 && nx >= c && ny < 0 && ny >= r){
                notcnt++;
                continue;
            }
            if(arr[nx][ny] == '.' && check[nx][ny] == false){
                moving[nx][ny] = moving[x][y] + 1;
                s.push(make_pair(nx, ny));
                cnt++;
            }
            if(moving[nx][ny] == 0){
                notcnt++;
            }
        }
        printf("->>>> %d %d %d\n", s.size(), x, y);

        printf("----------------\n");
        for(int i = 0; i < c; i++){
            for(int j = 0; j < r; j++){
                printf("%d ", moving[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        cnt++;
    }
    if(flag == 1)
        printf("%d\n", cnt-1);
    else
        printf("KAKTUS\n");
}

int main(int argc, const char * argv[]) {
    cin >> c >> r;
    int x = 0, y = 0;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'D'){
                moving[i][j] = 3;
                ax = i, ay = j;
            }
            else if(arr[i][j] == 'S'){
                moving[i][j] = 1;
                x = i, y = j;
            }
            else if(arr[i][j] == '*'){
                moving[i][j] = 0;
                water.push(make_pair(i, j));
            }
            else if(arr[i][j] == 'X'){
                moving[i][j] = 4;
                check[i][j] = true;
            }
            else
                moving[i][j] = -1;
        }
    }
    
    bfs(x, y);
    
}
