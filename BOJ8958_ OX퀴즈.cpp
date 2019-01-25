//
//  main.cpp
//  BOJ8958_ OX퀴즈
//
//  Created by 신지식 on 05/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n;
queue<string> q;
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        q.push(str);
    }
    
    while(!q.empty()){
        string t = q.front();
        q.pop();
        int count = 0, ans = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == 'O'){
                count += 1;
                ans += count;
            }
            else if(t[i] == 'X'){
                count = 0;
            }
        }
        
        cout << ans << "\n";
    }
    
}
