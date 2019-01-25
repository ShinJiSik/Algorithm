//
//  main.cpp
//  BOJ6603_Lotto
//
//  Created by 신지식 on 2018. 9. 25..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> p;
void make(int idx, int cnt){
    if(cnt == 6){
        for(int i = 0; i < p.size(); i++)
            printf("%d ", p[i]);
        printf("\n");
        return;
    }
    int len = v.size();
    if(len == idx) return;
    p.push_back(v[idx]);
    make(idx + 1, cnt + 1);
    p.pop_back();
    make(idx + 1, cnt);
}

int main(){
    while(1){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        make(0, 0);
        printf("\n");
        
        v.clear();
    }
}
