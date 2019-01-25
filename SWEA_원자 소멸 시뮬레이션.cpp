//
//  main.cpp
//  SWEA_원자 소멸 시뮬레이션
//
//  Created by 신지식 on 2018. 10. 18..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, x, y, d, e, ans;
int arr[4002][4002];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct atom{
    int x;
    int y;
    int dir;
    int energy;
};

atom q[1000];
int front;
int rear;
int qsize;
bool empty(){
    if(front == rear)
        return true;
    else
        return false;
}

bool full(){
    if((rear + 1) % 1000 == front)
        return true;
    else
        return false;
}

void push(atom tmp){
    if (full())
        return;
    
    qsize++;
    q[rear] = tmp;
    rear = (rear + 1) % 1000;
    
}

atom pop(){
    atom ret = {0, 0, 0, 0};
    
    if(empty())
        return ret;
    
    qsize--;
    ret = q[front];
    front = (front + 1) % 1000;
    return ret;
}


int main(int argc, const char * argv[]) {
    int test_case;
    
    cin >> test_case;
    
    for(int t = 1; t <= test_case; t++){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> x >> y >> d >> e;
            arr[2*(x+1000)][2*(y+1000)] = e;
            push({2*(x+1000),2*(y+1000), d, e});
        }
        
        ans = 0;
        while(!empty()){
            for(int i = 0; i < qsize; i++){
                atom tmp = pop();
                int nx = tmp.x;
                int ny = tmp.y;
                int nd = tmp.dir;
                int ne = tmp.energy;
                int gx = nx + dx[nd];
                int gy = ny + dy[nd];

                if(arr[nx][ny] > ne){
                    ans += arr[nx][ny];
                    arr[nx][ny] = 0;
                    continue;
                }
                if(gx >= 0 && gx < 4002 && gy >= 0 && gy < 4002){
                    if(arr[gx][gy] != 0){
                        arr[gx][gy] += ne;
                    }
                    else{
                        arr[gx][gy] = ne;
                        push({gx, gy, nd, ne});
                    }
                }
                arr[nx][ny] = 0;
            }
        }
        
        printf("#%d %d\n", t, ans);
    }
}

/*
#include <cstdio>
using namespace std;
struct node{
    int x,y,k,dir;
    bool use;
}oneja[1001];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int m[4001][4001];
int main(int argc, const char * argv[]) {
    
    int T,n,a,b,c,d;
    
    scanf("%d",&T);
    
    for(int ii=1;ii<=T;ii++){
        
        scanf("%d",&n);
        
        for(int i=0;i<n;i++){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            oneja[i] = {(a+1000)*2,(b+1000)*2,d,c,true};
        }
        //1씩이동
        int ans = 0;
        
        for(int t=0;t<4010;t++){
            for(int i=0;i<n;i++){
                if(oneja[i].use == true){
                    if(m[oneja[i].x][oneja[i].y]>1){
                        m[oneja[i].x][oneja[i].y]=0;
                        ans+=oneja[i].k;
                        oneja[i].use = false;
                        continue;
                    }
                    int nx = oneja[i].x + dx[oneja[i].dir];
                    int ny = oneja[i].y + dy[oneja[i].dir];
                    if(0<=nx && nx<=4000 && 0<=ny && ny<=4000){
                        
                        if(m[nx][ny]==0){//존재하지않는다면
                            m[nx][ny] = 1;
                        }else{//이미 누군가 존재
                            m[nx][ny]++;
                            ans+= oneja[i].k;
                            oneja[i].use = false;
                        }
                        m[oneja[i].x][oneja[i].y] = 0;
                        oneja[i].x = nx; oneja[i].y = ny;
                    }else {
                        m[oneja[i].x][oneja[i].y] = 0;
                        oneja[i].use = false;
                    }
                }
            }
        }
        printf("#%d %d\n",ii,ans);
    }
    return 0;
}
*/
