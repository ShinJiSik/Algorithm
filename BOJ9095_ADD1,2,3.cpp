//
//  main.cpp
//  BOJ9095_ADD1,2,3
//
//  Created by 신지식 on 2018. 9. 24..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    
    int t, n;
    int dp[12];
    cin >> n;
    
    dp[1] = 1; dp[2] = 2; dp[3] =4;
    for(int i = 4; i < 12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    for(int i = 0; i < n; i++){
        cin >> t;
        printf("%d\n", dp[t]);
    }
}
