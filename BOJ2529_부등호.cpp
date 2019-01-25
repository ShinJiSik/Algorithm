//
//  main.cpp
//  BOJ2529_부등호
//
//  Created by 신지식 on 2018. 10. 6..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> num;
vector<char> sign;

bool check(){
    for(int i = 0; i < n; i++){
        if(sign[i] == '<' && num[i] > num[i+1])
            return false;
        if(sign[i] == '>' && num[i] < num[i+1])
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        sign.push_back(ch);
    }
    
    for(int i = 9; i > 9 - (n + 1); i--)
        num.push_back(i);
    
    while(!check()){
        prev_permutation(num.begin(), num.end());
    }
    for(int i = 0; i <= n; i++)
        printf("%d", num[i]);
    printf("\n");
    
    num.clear();

    for(int i = 0; i <= n; i++)
        num.push_back(i);
    
    while(!check()){
        next_permutation(num.begin(), num.end());
    }
    for(int i = 0; i <= n; i++)
        printf("%d", num[i]);
    printf("\n");
}
