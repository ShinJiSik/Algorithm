//
//  main.cpp
//  BOJ2309_7Dwarf
//
//  Created by 신지식 on 2018. 9. 23..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int t[10];
int sum = 0;

void solve(){
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 9; j++){
            if(sum - (t[i] + t[j]) == 100){
                t[i] = -1; t[j] = -1;
                return;
            }
        }
    }
}
int main(){
    for(int i = 0; i < 9; i++){
        cin >> t[i];
        sum += t[i];
    }
    
    solve();
    sort(t, t+9);

    for(int i = 0; i < 9; i++){
        if(t[i] != -1) printf("%d\n", t[i]);
    }
}
