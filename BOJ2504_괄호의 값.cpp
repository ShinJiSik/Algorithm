//
//  main.cpp
//  BOJ2504_괄호의 값
//
//  Created by 신지식 on 09/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string b;
    cin >> b;
    stack<char> s;
    int cur = 1;
    int sum = 0;
    bool check = false;
    for(int i = 0; i < b.size(); i++){
        switch(b[i]){
            case '(': s.push('('); cur *= 2; break;
            case '[': s.push('['); cur *= 3; break;
            case ')':
                if(i != 0){
                    if(s.empty() || s.top() != '(') check = true;
                    if(b[i-1] == '(') sum += cur;
                    s.pop();
                    cur /= 2;
                }
                break;
            case ']':
                if(i != 0){
                    if(s.empty() || s.top() != '[') check = true;
                    if(b[i-1] == '[') sum += cur;
                    s.pop();
                    cur /= 3;
                }
                break;
        }
    }
    
    if(!s.empty() || check == true)
        cout << "0\n";
    else
        cout << sum << "\n";
}
