//
//  main.cpp
//  BOJ14499_주사위굴리기
//
//  Created by 신지식 on 2018. 10. 15..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[21][21];
int n, m, x, y, k;
int dice[7];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main(int argc, const char * argv[]) {
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    
    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        t--;
        int nx = x + dx[t];
        int ny = y + dy[t];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        
        if(t == 0){//동
            int tmp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = tmp;
        }
        else if(t == 1){//서
            int tmp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = tmp;
        }
        else if(t == 2){//북
            int tmp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = tmp;
        }
        else if(t == 3){//남
            int tmp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = tmp;
        }
        
        x = nx, y = ny;
        if(arr[x][y] == 0){
            arr[x][y] = dice[6];
        }
        else{
            dice[6] = arr[x][y];
            arr[x][y] = 0;
        }
        
        printf("%d\n", dice[1]);
    }
    
}
