//
//  main.cpp
//  BOJ14888_AddOperator
//
//  Created by 신지식 on 2018. 9. 25..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int n;
vector<int> v;
int oper[4]; //+ - * /
int maximum = INT_MIN;
int minimum = INT_MAX;

void cal(int idx, int prev){
    if(idx == n - 1){
        maximum = max(maximum, prev);
        minimum = min(minimum, prev);
        
        return;
    }
    for(int i = 0; i < 4; i++){
        if(oper[i] != 0){
            oper[i]--;
            if(i == 0) cal(idx + 1, prev + v[idx+1]);
            if(i == 1) cal(idx + 1, prev - v[idx+1]);
            if(i == 2) cal(idx + 1, prev * v[idx+1]);
            if(i == 3) cal(idx + 1, prev / v[idx+1]);
            oper[i]++;
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i = 0; i < 4; i++)
        cin >> oper[i];
    
    cal(0, v[0]);
    printf("%d\n%d\n", maximum, minimum);
}

/* SWEA
int n;
int t;
vector<int> v;
int oper[4]; //+ - * /
int maximum;
int minimum;

void cal(int idx, int prev){
    if(idx == n - 1){
        maximum = max(maximum, prev);
        minimum = min(minimum, prev);
        
        return;
    }
    for(int i = 0; i < 4; i++){
        if(oper[i] != 0){
            oper[i]--;
            if(i == 0) cal(idx + 1, prev + v[idx+1]);
            if(i == 1) cal(idx + 1, prev - v[idx+1]);
            if(i == 2) cal(idx + 1, prev * v[idx+1]);
            if(i == 3) cal(idx + 1, prev / v[idx+1]);
            oper[i]++;
        }
    }
}

int main(){
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cin >> n;
        
        minimum = INT_MAX;
        maximum = INT_MIN;
        v.clear();
        
        for(int i = 0; i < 4; i++)
            cin >> oper[i];
        
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
       
        cal(0, v[0]);
        
        printf("#%d %d\n", tt, maximum - minimum);
    }
}
*/
