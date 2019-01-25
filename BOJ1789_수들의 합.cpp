//
//  main.cpp
//  BOJ1789_수들의 합
//
//  Created by 신지식 on 14/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    long long s, cnt = 1, ans = 0;
    cin >> s;
    while(1){
        ans += cnt;
        if(ans > s)  break;
        cnt++;
    }
    
    cout << cnt-1 << "\n";
}
