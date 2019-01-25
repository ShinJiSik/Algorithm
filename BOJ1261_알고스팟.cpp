//
//  main.cpp
//  BOJ1261_알고스팟
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int arr[101][101];
int dist[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp;
    q.push(make_pair(x, y));
    dist[x][y] = 0;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(dist[nx][ny] == -1){
                    if(arr[nx][ny] == 0){
                        dist[nx][ny] = dist[x][y];
                        q.push(make_pair(nx, ny));
                    }
                    else{
                        dist[nx][ny] = dist[x][y] + 1;
                        tmp.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if(q.empty()){
            while(!tmp.empty()){
                q.push(tmp.front());
                tmp.pop();
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> m >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
            dist[i][j] = -1;
        }
    }
    
    bfs(0, 0);
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n", dist[n-1][m-1]);
}

/*
#include <queue>
using namespace std;
int d[555][555];
int a[555][555];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    scanf("%d %d",&m,&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
            d[i][j] = -1;
        }
    }
    priority_queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0,make_pair(0,0)));
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == 0) {
                        d[nx][ny] = d[x][y];
                    } else {
                        d[nx][ny] = d[x][y]+1;
                    }
                    q.push(make_pair(-d[nx][ny],make_pair(nx,ny)));
                }
            }
        }
    }
    printf("%d\n",d[n-1][m-1]);
    return 0;
}
*/
