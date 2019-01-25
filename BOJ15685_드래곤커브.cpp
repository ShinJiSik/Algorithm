//
//  main.cpp
//  BOJ15685_드래곤커브
//
//  Created by 신지식 on 2018. 10. 16..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

/*
#include <iostream>
#include <vector>
using namespace std;

struct curve{
    int cx, cy;
};
int n, x, y, d, g;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool check[110][110];
vector<curve> v;

int main(int argc, const char * argv[]) {
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y >> d >> g;
        v.push_back({x, y});
        check[y][x] = true;
        
        for(int j = 0; j < 4; j++){
            if(d == j){
                int nx = x + dx[j];
                int ny = y + dy[j];
                check[ny][nx] = 1;
                v.push_back({nx, ny});
            }
        }
        
        for(int j = 0; j < g; j++){
            int siz = (int)v.size();
            int rot = 0;
            
            for(int k = siz-2; k >= 0; k--){
                int standX = v[k+1].cx;
                int standY = v[k+1].cy;
                int prevX = v[k].cx;
                int prevY = v[k].cy;
                
                for(int a = 0; a < 4; a++){
                    if(standX + dx[a] == prevX && standY + dy[a] == prevY){
                        rot = a - 1;
                        if(rot == -1)
                            rot = 3;
                        break;
                    }
                }
                
                int nx = v.back().cx + dx[rot];
                int ny = v.back().cy + dy[rot];
                v.push_back({nx, ny});
                check[ny][nx] = true;
            }
        }
        

        v.clear();
    }
    for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                printf("%d ", check[i][j]);
        }        printf("\n");

    }
       int ans = 0;
    for (int i=0; i<=99; i++) {
        for (int j=0; j<=99; j++) {
            if (check[i][j] && check[i][j+1] && check[i+1][j] && check[i+1][j+1]) {
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);
}
*/

#include <iostream>
#include <vector>
using namespace std;

int n, x, y, d, g, s, ans;
int map[105][105];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int change(int d)
{
    // 방향 전환
    if(d == 0 || d == 1)
        d += 2;
    else
        d -= 2;
    // 왼쪽으로 90도 회전
    if(d == 0)
        d = 3;
    else
        d--;
    
    return d;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d %d", &y, &x, &d, &g);
        vector<int> v;
        v.push_back(d);
        while(g--)
        {
            s = v.size();
            for(int i = s - 1; i >= 0; i--)
                v.push_back(change(v[i]));
        }
        map[x][y] = 1;
        s = v.size();
        for(int i = 0; i < s; i++)
        {
            x += dx[v[i]];
            y += dy[v[i]];
            map[x][y] = 1;
        }
    }
    
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
                ans++;
        }
    }
    printf("%d\n", ans);
}
