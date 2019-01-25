//
//  main.cpp
//  BOJ15684_사다리조작
//
//  Created by 신지식 on 2018. 10. 14..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, h;
int arr[100][100];

struct info{
    int x;
    int y;
};

int start(int c){// c는 해당 열
    int r = 1;
    while(r <= h){
        if(arr[r][c] == 1)
            c += 1;
        else if(arr[r][c] == 2)
            c -= 1;
        
        r += 1;
    }
    
    return c;
}

bool go(){
    for(int i = 1; i <= n; i++){
        int res = start(i);
        if(res != i) return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    cin >> n >> m >> h;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[a][b+1] = 2;
    }
    vector<info> v;
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= n-1; j++){
            if(arr[i][j] != 0) continue;
            if(arr[i][j+1] != 0) continue;
            v.push_back({i, j});
        }
    }
    int ans = -1;
    if(go()){
        printf("0\n");
        return 0;
    }
    int siz = (int)v.size();

    for(int i = 0; i < siz; i++){
        int nx = v[i].x;
        int ny = v[i].y;
        if(arr[nx][ny] != 0 || arr[nx][ny+1] != 0) continue;
        arr[nx][ny] = 1;
        arr[nx][ny+1] = 2;
        if(go()){
            if(ans == -1 || ans > 1)
                ans = 1;
        }
        for(int j = i+1; j < siz; j++){
            int nx1 = v[j].x;
            int ny1 = v[j].y;
            if(arr[nx1][ny1] != 0 || arr[nx1][ny1+1] != 0) continue;
            arr[nx1][ny1] = 1;
            arr[nx1][ny1+1] = 2;
            if(go()){
                if(ans == -1 || ans > 2)
                    ans = 2;
            }
            for(int k = j+1; k < siz; k++){
                int nx2 = v[k].x;
                int ny2 = v[k].y;
                if(arr[nx2][ny2] != 0 || arr[nx2][ny2+1] != 0) continue;
                arr[nx2][ny2] = 1;
                arr[nx2][ny2+1] = 2;
                if(go()){
                    if(ans == -1 || ans > 3)
                        ans = 3;
                }
                arr[nx2][ny2] = 0;
                arr[nx2][ny2+1] = 0;
            }
            arr[nx1][ny1] = 0;
            arr[nx1][ny1+1] = 0;
        }
        arr[nx][ny] = 0;
        arr[nx][ny+1] = 0;
    }
    
    printf("%d\n", ans);
    
}
