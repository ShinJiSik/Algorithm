//
//  main.cpp
//  BOJ16236_아기상어
//
//  Created by 신지식 on 05/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int sea[21][21];
int dist[21][21];
bool check[21][21];
int now_size = 2; //현재 상어 크기
int eating = 0; // 현재까지 먹은 개수
int now_x, now_y; //아기 상어 현재 위치
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool breaking = false;
int ans = 0;
vector<pair<int, int>> prior;

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = 0;
            check[i][j] = false;
        }
    }
}

void print(){
    printf("\n%d %d || %d %d || %d\n", now_x, now_y, now_size, eating, ans);
    printf("--- sea ---\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ",sea[i][j]);
        printf("\n");
    }
    
    printf("\n---dist---\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }
}

void find_prior(){
    if(prior.size() >= 1){
        int diff = dist[prior[0].first][prior[0].second];
        int x = prior[0].first;
        int y = prior[0].second;
        for(int i = 0; i < prior.size(); i++){
            if(dist[prior[i].first][prior[i].second] < diff){
                diff = dist[prior[i].first][prior[i].second];
                now_x = prior[i].first;
                now_y = prior[i].second;
            }
            else if(dist[prior[i].first][prior[i].second] == diff){
                if(prior[i].first < x){
                    x = prior[i].first;
                    y = prior[i].second;
                }
                else if(prior[i].first == x){
                    if(prior[i].second < y){
                        x = prior[i].first;
                        y = prior[i].second;
                    }
                }
            }
        }
        now_x = x;
        now_y = y;
         
        eating += 1;
        if(eating == now_size){
            now_size += 1;
            eating = 0;
        }
        
        ans += dist[now_x][now_y];
        
        prior.clear();
    }
    else{
        breaking = true;
    }
}

void eat(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    check[a][b] = true;
    sea[a][b] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if(check[nx][ny] == false && sea[nx][ny] <= now_size){
                check[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                if(sea[nx][ny] < now_size && sea[nx][ny] != 0)
                    prior.push_back({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    
    find_prior();
   // print();
    init();
}

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> sea[i][j];
            if(sea[i][j] == 9){
                now_x = i;
                now_y = j;
            }
        }
    }
    
    while(breaking != true){
        eat(now_x, now_y);
    }
    cout << ans << "\n";
}
