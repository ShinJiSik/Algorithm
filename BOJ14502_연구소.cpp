//
//  main.cpp
//  BOJ14502_연구소
//
//  Created by 신지식 on 2018. 10. 17..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[10][10];
int co[10][10];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> virus;
vector<pair<int, int>> non;
vector<pair<int, int>> pick;
int ans = 0;

int safe(){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(co[i][j] == 0)
                count++;
        }
    }
    return count;
}

void copy(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            co[i][j] = map[i][j];
}

void warn(){
    for(int i = 0; i < virus.size(); i++){
        queue<pair<int, int>> q;
        q.push({virus[i].first, virus[i].second});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if(co[nx][ny] == 0){
                    co[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }

    }
    
}

void brute(int idx, int cnt){
    if(cnt == 3){
        //for(int i = 0; i < 3; i++)
        //    printf("%d %d | ", pick[i].first, pick[i].second);
        //printf("\n");
        
        copy();
       
        for(int i = 0; i < 3; i++){
            int x = pick[i].first;
            int y = pick[i].second;
            co[x][y] = 1;
        }
        
        /*
        printf("------\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%d ", co[i][j]);
            }
            printf("\n");
        }
        */
        
        warn();
        ans = max(ans,safe());
        return;
        
    }
    if(idx == non.size()) return;

    pick.push_back({non[idx].first, non[idx].second});
    brute(idx + 1, cnt + 1);
    pick.pop_back();
    
    brute(idx + 1, cnt);
}


int main(int argc, const char * argv[]) {
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0)
                non.push_back({i, j});
            if(map[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    brute(0, 0);
    printf("%d\n", ans);
}
