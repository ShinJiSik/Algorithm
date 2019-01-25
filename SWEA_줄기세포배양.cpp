//
//  main.cpp
//  SWEA_줄기세포배양
//
//  Created by 신지식 on 2018. 10. 11..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define center 200
int pan[400][400];
bool check[400][400];
int ans = 0;
int t, n, m, k; //세로 가로 시간
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
struct CELL{
    int x, y, life, time;
};

int main(int argc, const char * argv[]) {
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        cin >> n >> m >> k;
        memset(pan, 0, sizeof(pan));
        memset(check, false, sizeof(check));
        queue<CELL> q[11];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int num;
                cin >> num;
                pan[i+center][j+center] = num;
                if(pan[i+center][j+center] != 0){
                    q[num].push({i + center, j + center, pan[i+center][j+center], 2*pan[i+center][j+center]});
                    check[i+center][j+center] = true;
                }
            }
        }
        
        for(int i = 0; i < k; i++){ //시간
            for(int j = 10; j >= 1; j--){ //생존력 높은놈 먼저 확장
                int siz = (int)q[j].size();
                for(int a = 0; a < siz; a++){
                    int x = q[j].front().x;
                    int y = q[j].front().y;
                    int live = q[j].front().life;
                    int start = q[j].front().time;
                    q[j].pop();
                    check[x][y] = true;
                    start--;
                    if(live > start){ //눈을 떠라
                        for(int b = 0; b < 4; b++){
                            int nx = x + dx[b];
                            int ny = y + dy[b];
                            
                            if(check[nx][ny] == false){
                                check[nx][ny] = true;
                                q[j].push({nx, ny, live, 2*live});
                            }
                        }
                    }
                    if(start != 0)//안죽었으면
                        q[j].push({x, y, live, start});
                }
            }
        }
        ans = 0;
        for(int i = 1; i <= 10; i++)
            ans += q[i].size();
        printf("#%d %d\n", tt+1, ans);
    }
}

