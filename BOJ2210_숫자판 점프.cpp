//
//  main.cpp
//  BOJ2210_숫자판 점프
//
//  Created by 신지식 on 2018. 10. 17..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;
int arr[6][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
set<int> s;

void check(int x, int y, int make, int cnt){
    if(cnt == 6){
        s.insert(make);
        return;
    }
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        check(nx, ny, (make*10) + arr[nx][ny], cnt+1);
    }
}

int main(int argc, const char * argv[]) {

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> arr[i][j];
    

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            check(i, j, arr[i][j], 1);
        }
    }
    
    printf("%d\n", (int)s.size());
}
