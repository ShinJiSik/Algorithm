//
//  main.cpp
//  Samsung_Find_Prison Break
//
//  Created by 신지식 on 2018. 9. 21..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int p[51][51];
int check[51][51];
int t, n, m, r, c, l;

int du[4] = {1, 2, 4, 7};
int dd[4] = {1, 2, 5, 6};
int dr[4] = {1, 3, 4, 5};
int dl[4] = {1, 3, 6, 7};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
stack<pair<int, int>> s;

void dfs(int x, int y){
    check[x][y] = true;
    printf("-- %d\n", p[x][y]);
    for(int i = 0; i < l; i++){
        int x2 = p[x][y];
        for(int a = x; a < n; a++){
            for(int b = y; b < m; b++){
                for(int c = 0; c < 4; c++){
                    if(x2 == 1 && check[a][b] == false)
                        dfs(x+dx[c], y+dy[c]);
                    else if(x2 == 2){
                        if(c != 0 && c != 1 && check[a][b] == false)
                            dfs(x+dx[c], y+dy[c]);
                    }
                    else if(x2 == 3){
                        if(c != 2 && c!= 3 && check[a][b] == false)
                            dfs(x+dx[c], y+dy[c]);
                    }
                    else if(x2 == 4){
                        if((c == 2 || c == 0) && check[a][b] == false)
                            dfs(x+dx[c], y+dy[c]);

                    }
                    else if(x2 == 5){
                        if((c == 3 || c == 0) && check[a][b] == false)
                            dfs(x+dx[c], y+dy[c]);
                    }
                    else if(x2 == 6){
                        if((c == 3 || c == 1) && check[a][b] == false)
                            dfs(x+dx[c], y+dy[c]);
                    }
                    else if(x2 == 7){
                        if((c == 1 || c == 2) && check[a][b] == false)
                            dfs(x+dx[c], y+dy[c]);
                    }
                }
            }
        }
        
    }
}

int main(){
    cin >> t;
    
    for(int a = 1; a <= t; a++){
        cin >> n >> m >> r >> c >> l;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> p[i][j];
                    check[i][j] = false;
            }
        }
        dfs(r, c);
        int count = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(check[i][j] == true)
                    count++;
            }
        }
        
        printf("%d\n", count);
    }
    
    
}

/*
#include <queue>


using namespace std;

struct Node{
    int x,y,depth;
};
queue<Node> q;
int map[50][50];
int check[50][50];


int direction[4][2]= {{0,-1},{1,0},{0,1},{-1,0}};
int terminal[8][4]={{0,0,0,0},{1,1,1,1},{1,0,1,0},{0,1,0,1},{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}};
//dirction 0123
int n,m,r,c,l;  //n,m: map 세로, 가로  r,c: 맨홀 뚜껑 위치장소 세로,가로  l: 소요된 시간



int cal_num_cases(){
    Node node={c,r,1};
    q.push(node);
    Node p;
    int result = 1;
    
    while(!q.empty()){
        p.x=q.front().x;
        p.y=q.front().y;
        p.depth=q.front().depth;
        q.pop();
        if(p.depth>=l) continue;
        check[p.y][p.x] = 1;
        for(int i=0; i<4; i++){
            if(terminal[map[p.y][p.x]][i]==1){
                int nx = p.x+direction[i][0];
                int ny = p.y+direction[i][1];
                
                if(nx>=0&&nx<m&&ny<n&&ny>=0&&terminal[map[ny][nx]][(i+2)%4]==1&&check[ny][nx]!=1){
                    //printf("%d %d\n",nx,ny);
                    check[ny][nx]=1;
                    Node node={nx,ny,p.depth+1};
                    q.push(node);
                    result++;
                }
            }
        }
        
        
        
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int testcase=0;
    scanf("%d",&testcase);
    for(int i=0; i<testcase; i++){
        scanf("%d %d %d %d %d",&n,&m,&r,&c,&l);
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                scanf("%d",&map[j][k]);
                
            }
        }
        
        printf("#%d %d\n",i+1,cal_num_cases());
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                check[j][k]=0;
            }
        }
    }
    
}
*/
/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, m, r, c, l, T, ans;
int map[51][51];
bool visited[51][51];
int dx[4] = { 0,0,1,-1 }, dy[4] = { -1,1,0,0 };

void bfs(){
    queue<pair<int, int>> q;
    visited[r][c] = true, ans++;
    q.push(make_pair(r,c));
    
    while (--l){
        int size = q.size();
        while (size--){
            int x = q.front().first, y = q.front().second; //r,c
            q.pop();
            for (int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                bool f = false;
                int here = map[x][y], next = map[nx][ny];
                if (here == 1) {
                    if (i == 0 && (next == 1 || next == 3 || next == 4 || next == 5))
                        f = true;
                    else if (i == 1 && (next == 1 || next == 3 || next == 6 || next == 7))
                        f = true;
                    else if (i == 2 && (next == 1 || next == 2 || next == 4 || next == 7))
                        f = true;
                    else if (i == 3 && (next == 1 || next == 2 || next == 5 || next == 6))
                        f = true;
                }
                else if (here == 2) {
                    if (i == 2 && (next == 1 || next == 2 || next == 4 || next == 7))
                        f = true;
                    else if (i == 3 && (next == 1 || next == 2 || next == 5 || next == 6))
                        f = true;
                }
                else if (here == 3) {
                    if (i == 0 && (next == 1 || next == 3 || next == 4 || next == 5))
                        f = true;
                    else if (i == 1 && (next == 1 || next == 3 || next == 6 || next == 7))
                        f = true;
                }
                else if (here == 4) {
                    if (i == 1 && (next == 1 || next == 3 || next == 6 || next == 7))
                        f = true;
                    else if (i == 3 && (next == 1 || next == 2 || next == 5 || next == 6))
                        f = true;
                }
                else if (here == 5) {
                    if (i == 1 && (next == 1 || next == 3 || next == 6 || next == 7))
                        f = true;
                    else if (i == 2 && (next == 1 || next == 2 || next == 4 || next == 7))
                        f = true;
                }
                else if (here == 6) {
                    if (i == 0 && (next == 1 || next == 3 || next == 4 || next == 5))
                        f = true;
                    else if (i == 2 && (next == 1 || next == 2 || next == 4 || next == 7))
                        f = true;
                }
                else if (here == 7) {
                    if (i == 0 && (next == 1 || next == 3 || next == 4 || next == 5))
                        f = true;
                    else if (i == 3 && (next == 1 || next == 2 || next == 5 || next == 6))
                        f = true;
                }
                if (f == true)
                    visited[nx][ny] = true, ans++, q.push(make_pair(nx, ny));
                
            }
        }
    }
}

int main() {
    cin >> T;
    for (int k = 0; k < T; k++) {
        cin >> n >> m >> r >> c >> l;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
        
        bfs();
        
        cout << "#" << k + 1 << " " << ans << "\n";
        
        ans = 0;
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
*/

/*
#include <cstdio>
#include <vector>
using namespace std;

int board[51][51];
int check[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m,r,c,l;
vector<int> v[8];
bool isPossible(int state,int newType){
    
    if( (state==0)  && (newType ==1 || newType ==2 || newType==5 || newType ==6)) return true;
    else if( (state==1) && (newType ==1 || newType==2 || newType==4 || newType==7)) return true;
    else if( (state==2) && (newType==1 || newType==3 || newType==4||newType==5)) return true;
    else if( (state>=3) && (newType==1 || newType==3 || newType==6 ||newType==7)) return true;
    return false;
}
void dfs(int nowx,int nowy,int time){
    check[nowx][nowy]=time;
    if(time == l-1) return;
    int type = board[nowx][nowy];
    for(int i=1;i<=7;i++){
        if(type==i){
            for(int j=0;j<(int)v[i].size();j++){
                int k = v[i][j];
                int nx = nowx + dx[k];
                int ny = nowy + dy[k];
                if(0<=nx && nx < n && 0<=ny && ny<m) if(isPossible(k, board[nx][ny]))
                    if(time+1 < check[nx][ny] ) dfs(nx,ny,time+1);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int T;
    
    scanf("%d",&T);
    
    for(int k=0;k<4;k++) v[1].push_back(k);
    v[2].push_back(0); v[2].push_back(1);
    v[3].push_back(2); v[3].push_back(3);
    v[4].push_back(0); v[4].push_back(3);
    v[5].push_back(1); v[5].push_back(3);
    v[6].push_back(1); v[6].push_back(2);
    v[7].push_back(0); v[7].push_back(2);
    
    for(int ii=1;ii<=T;ii++){
        
        scanf("%d %d %d %d %d",&n,&m,&r,&c,&l);
        
        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){
                scanf("%d",&board[i][j]);
                check[i][j]=31;
            }
        }
        
        dfs(r,c,0);
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(check[i][j]!=31)
                    ans++;
 
        if(l==1) ans = 1;
        printf("#%d %d\n",ii,ans);
    }
    
    return 0;
}*/
