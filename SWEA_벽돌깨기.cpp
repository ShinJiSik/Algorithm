
//
//  main.cpp
//  SWEA_벽돌깨기
//
//  Created by 신지식 on 2018. 10. 9..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int origin[20][20];
int map[20][20];
int pos[6];
bool check[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, w, h;
int ans;

void copy(){
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            map[i][j] = origin[i][j];
}

void remake(){
    for(int i = 0; i < w; i++){
        for(int j = h-1; j >= 0; j--){
            if(map[j][i] == 0){
                for(int k = j-1; k >= 0; k--){
                    if(map[k][i] != 0){
                        map[j][i] = map[k][i];
                        map[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void breaking(){
    copy();
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++){
        int p = pos[i];
        for(int j = 0; j < h; j++){
            if(map[j][p] != 0){
                if(map[j][p] == 1){
                    map[j][p] = 0;
                    break;
                }
                else{
                    q.push(make_pair(j, p));
                    memset(check, false, sizeof(check));
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        int len = map[x][y];
                        check[x][y] = true;
                        map[x][y] = 0;
                        for(int a = 1; a <= len-1; a++){
                            for(int b = 0; b < 4; b++){
                                int nx = x + dx[b] * a;
                                int ny = y + dy[b] * a;
                                
                                if((nx >= 0  && nx < h) && (ny >= 0 && ny < w) && map[nx][ny] != 0 && check[nx][ny] == false){
                                    if(map[nx][ny] == 1)
                                        map[nx][ny] = 0;
                                    else{
                                        check[nx][ny] = true;
                                        q.push(make_pair(nx, ny));
                                    }
                                }
                                
                            }
                        }
                    }
                    break;
                }
            }
        }
        remake();
    }
    
    
    int count = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(map[i][j] != 0)
                count++;
        }
    }
    
    ans = min(ans, count);
    
    return;
}

void dfs(int x){
    if(x == n){
        breaking();
        /*
         printf("----------------\n");
         for(int i = 0; i < h; i++){
         for(int j = 0; j < w; j++)
         printf("%d ", map[i][j]);
         printf("\n");
         }
        */
        return;
    }
    
    for(int i = 0; i < w; i++){
        pos[x] = i;
        dfs(x + 1);
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    
    for(int tt = 0; tt < t; tt++){
        cin >> n >> w >> h;
        
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> origin[i][j];
        ans = 987654321;
        copy();
        dfs(0);
        
        printf("#%d %d\n", tt+1, ans);
    }
}
