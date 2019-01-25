//
//  main.cpp
//  SWEA_디저트카페
//
//  Created by 신지식 on 2018. 10. 18..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int map[21][21];
bool check[21][21];
bool num[101];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};
int n, ans, init_x, init_y;

void rotate(int x, int y, int next, int cnt){
    int nx = x + dx[next];
    int ny = y + dy[next];
    
    if(next == 3 && nx == init_x && ny == init_y){
        if(cnt > ans)
            ans = cnt;
        return;
    }
    
    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
        if(check[nx][ny] == false && num[map[nx][ny]] == false){
            num[map[nx][ny]] = true;
            check[nx][ny] = true;
            rotate(nx, ny, next, cnt + 1);
            if(next < 3)
                rotate(nx, ny, next + 1, cnt + 1);
            check[nx][ny] = false;
            num[map[nx][ny]] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    int test_case;
    cin >> test_case;
    
    for(int t = 1; t <= test_case; t++){
        cin >> n;
        
        memset(num, false, sizeof(num));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> map[i][j];
        
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                init_x = i, init_y = j;
                num[map[i][j]] = true;
                check[i][j] = true;
                rotate(i, j, 0, 1);
                num[map[i][j]] = false;
                check[i][j] = false;
            }
        }
        if(ans < 3)
            printf("#%d -1\n", t);
        else
            printf("#%d %d\n", t, ans);
    }
}
