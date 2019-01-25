//
//  main.cpp
//  BOJ2583_영역구하기
//
//  Created by 신지식 on 2018. 10. 18..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n, k;
bool check[101][101];
int cnt = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    check[x][y] = true;
    cnt++;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n){
            if(check[nx][ny] == false){
                dfs(nx, ny);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> m >> n >> k;
    
    int x1, x2, y1, y2;
    
    for(int i = 0; i < k; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        y2 -= 1;
        x2 -= 1;
        for(int a = x1; a <= x2; a++){
            for(int b = y1; b <= y2; b++){
                check[a][b] = true;
            }
        }
    }
    
    vector<int> area;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j] == false){
                dfs(i, j);
                area.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(area.begin(), area.end());
    printf("%d\n", (int)area.size());
    for(int i = 0; i < (int)area.size(); i++)
        printf("%d ", area[i]);
    printf("\n");
}
