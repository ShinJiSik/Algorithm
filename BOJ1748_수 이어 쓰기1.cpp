//
//  main.cpp
//  BOJ1748_수 이어 쓰기1
//
//  Created by 신지식 on 2018. 10. 6..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string n;
    cin >> n;
    
    long long tmp = stoll(n), tmp2 = 1, ans = 0;
    int len = n.length();

    if(len == 1){
        ans = stoll(n);
    }
    else{
        for(int i = 1; i < len; i++){
            ans += tmp2 * 9 * i;
            tmp2 *= 10;
        }
        tmp = tmp - tmp2 + 1;
        tmp *= len;
        ans += tmp;
    }
        
    printf("%lld\n", ans);
}
