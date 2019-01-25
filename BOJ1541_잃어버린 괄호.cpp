//
//  main.cpp
//  BOJ1541_잃어버린 괄호
//
//  Created by 신지식 on 30/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    vector<int> num, sign;
    int cur = 0;
    sign.push_back(1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '+')
                sign.push_back(1);
            else if(s[i] == '-')
                sign.push_back(-1);
            
            num.push_back(cur);
            cur = 0;
        }
        else
            cur = cur * 10 + (s[i] - '0');
    }
    num.push_back(cur);
    
    bool minus = false;
    int ans = 0;
    for(int i = 0; i < num.size(); i++){
        if(sign[i] == -1){
            minus = true;
        }
        
        if(minus == true)
            ans -= num[i];
        else
            ans += num[i];
    }
    cout << ans << "\n";
}
