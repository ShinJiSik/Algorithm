//
//  main.cpp
//  BOJ14503_로봇청소기
//
//  Created by 신지식 on 2018. 10. 15..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//
/*
 
 현재 위치를 청소한다.
 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
 
 */
#include <iostream>
#include <algorithm>
using namespace std;
int arr[55][55];
int n, m, r, c, dir;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    cin >> r >> c >> dir;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    while(1){
        if(arr[r][c] == 0)
            arr[r][c] = 2;
        
        if(arr[r+1][c] != 0 && arr[r-1][c] != 0 && arr[r][c+1] != 0 && arr[r][c-1] != 0){
            if(arr[r-dx[dir]][c-dy[dir]] == 1){
                break;
            }
            else{
                r -= dx[dir];
                c -= dy[dir];
            }
        }
        else{
            dir = (dir+3)%4;
            if(arr[r+dx[dir]][c+dy[dir]] == 0){
                r += dx[dir];
                c += dy[dir];
            }
        }
        /*
        printf("----------------\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
        */
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 2)
                ans++;
    }
    printf("%d\n", ans);
}
