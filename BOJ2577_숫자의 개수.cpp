//
//  main.cpp
//  BOJ2577_숫자의 개수
//
//  Created by 신지식 on 09/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    long long a, b, c, re;
    cin >> a >> b >> c;
    
    int ans[10] = { 0, };
        re = a * b * c;
    
    string str = to_string(re);
    for(int i = 0; i < str.size(); i++)
        ans[str[i] - '0']++;
    
    for(int i = 0; i < 10; i++)
        cout << ans[i] << "\n";
}
