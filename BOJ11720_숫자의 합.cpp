//
//  main.cpp
//  BOJ11720_숫자의 합
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += s[i]-'0';
    }
    cout << sum << "\n";
}
