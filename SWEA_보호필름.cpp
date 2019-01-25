//
//  main.cpp
//  SWEA_보호필름
//
//  Created by 신지식 on 2018. 10. 11..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
int origin[25][25];
int d, w, k;
int ans;
int pos[20];
int flag = 0;

void col_check(){
    int count = 1;
    flag = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < d-1; j++){
            printf("%d -> %d %d %d\n", i, origin[j][i], origin[j+1][i], count );
            if(origin[i][j] == origin[i][j+1])
                count++;
            if(count >= k-1){
                printf("--%d %d\n", i, count);
                flag++;
                break;
            }
        }
        count = 1;
    }
    if(flag == w)
        ans = 0;
    else
        printf("flag : %d\n", flag);
    printf("%d\n", flag);
}

void dfs(int x, int cnt){
    if(x == cnt){
        for(int i = 0; i < k; i++)
            printf("%d ", pos[i]);
        printf("\n");
       // col_check();
        return;
    }
    
    for(int i = 0; i < k; i++){
        pos[x] = i;
        dfs(x+1, cnt+1);
    }
}


int main(){
    int tt;
    cin >> tt;
    
    for(int t = 1; t <= tt; t++){
        cin >> d >> w >> k;
        
        for(int i = 0; i < d; i++){
            for(int j = 0; j < w; j++){
                cin >> origin[i][j];
            }
        }
        
        ans = 987654321;
        
      //  dfs(0, 0);
        col_check();
        printf("#%d %d\n", tt, ans);
    }
}
