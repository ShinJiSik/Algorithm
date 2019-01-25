//
//  main.cpp
//  BOJ2875_대회 or 인턴
//
//  Created by 신지식 on 30/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m, k;
    
    cin >> n >> m >> k;
    int ans = 0;
   
    while(n >= 2 && m >= 1 && n + m >= k + 3){
        ans++;
        n -= 2;
        m -= 1;
    }
    cout << ans << "\n";
}
