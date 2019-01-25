//
//  main.cpp
//  SWEA_요리사
//
//  Created by 신지식 on 2018. 10. 20..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
int cook[17][17];
int check[17];
int ans;

void dfs(int cnt, int idx){
    if(cnt == n){
        if(idx == n/2){
            int diff1 = 0;
            int diff2 = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j) continue;
                    if(check[i] == 1 && check[j] == 1)
                        diff1 += (cook[i][j]);
                    else if(check[i] == 0 && check[j] == 0)
                        diff2 += (cook[i][j]);
                }
            }
            
            ans = min(ans, abs(diff1 - diff2));
        }
        
        
        return;
    }
    
    check[cnt] = 1;
    dfs(cnt+1, idx+1);
    check[cnt] = 0;
    
    check[cnt] = 0;
    dfs(cnt+1, idx);
    check[cnt] = 1;
}


int main(int argc, const char * argv[]) {
    int test_case;

    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        cin >> n;
        memset(check, 0, sizeof(check));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> cook[i][j];
        
        ans = 987654321;
        dfs(0, 0);
        
        printf("#%d %d\n", t, ans);
    }
}
