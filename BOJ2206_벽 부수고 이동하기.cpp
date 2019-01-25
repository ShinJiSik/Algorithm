//
//  main.cpp
//  BOJ2206_벽 부수고 이동하기
//
//  Created by 신지식 on 2018. 10. 3..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
/*
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[1001][1001];
int dist[1001][1001];

void bfs(int x, int y, int z){
    queue<pair<pair<int, int>, int>> q;
    
    q.push(make_pair(make_pair(x, y), 0));
    dist[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(dist[nx][ny] == 0){
                    if(arr[nx][ny] == 0){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push(make_pair(make_pair(nx, ny), z));
                    }
                }
                else{
                    if(arr[nx][ny] == 0 && z == 1){
                        if(arr[nx][ny] == 0){
                            dist[nx][ny] = dist[x][y] + 1;
                            z = 1;
                            q.push(make_pair(make_pair(nx, ny), z));
                    }
                    else if(arr[nx][ny] == 1 && z == 0){
                        dist[nx][ny] = dist[x][y] + 1;
                        z = 1;
                        q.push(make_pair(make_pair(nx, ny), z));
                    }
                }
            }
        }
    }
    }
    
    if(dist[n-1][m-1] == 0)
        printf("-1\n");
    else
        printf("%d\n", dist[n-1][m-1]);
    
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
            //dist[i][j] = -1;
        }
    }
    
    bfs(0, 0, 0 );
    
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            printf("%d   ", dist[i][j]);
        }
        printf("\n");
    }
}
*/
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int N, M;
    char map[1001][1001] = { 0 };
    bool visit[1001][1001][2] = { 0 };
    queue<pair<pair<int, int>, bool>> q;
    int cnt = 0;
    int flag = 0;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++) {
            scanf("%c", &map[i][j]);
        }
    }
    
    q.push({ {0,0},0 });
    visit[0][0][0] = 1;
    
    while (!q.empty()) {
        int qs = q.size();
        for (int i = 0; i < qs; i++) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            bool chck = q.front().second;
            q.pop();
            
            if (x == N - 1 && y == M - 1) {
                flag = 1;
                break;
            }
            
            for (int d = 0; d < 4; d++) {
                int xx = x + dx[d];
                int yy = y + dy[d];
                
                if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
                if (visit[xx][yy][chck]) continue;
                
                if (chck) {
                    if (map[xx][yy] == '0') {
                        q.push({ {xx,yy},chck });
                        visit[xx][yy][chck] = 1;
                    }
                }
                else {
                    if (map[xx][yy] == '0') {
                        q.push({ {xx,yy},chck });
                        visit[xx][yy][chck] = 1;
                    }
                    else {
                        q.push({ {xx,yy},1 });
                        visit[xx][yy][1] = 1;
                    }
                }
            }
        }
        if (flag) break;
        
        cnt++;
    }
    
    if(flag)
        printf("%d\n", cnt + 1);
    else
        printf("-1\n");
}
