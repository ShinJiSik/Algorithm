//
//  main.cpp
//  BOJ11652_카드
//
//  Created by 신지식 on 03/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<long long, int> m;

    long long num;
    for(int i = 0; i < n; i++){
        cin >> num;
        m[num] += 1;
    }
    
    long long ans = 0;
    long long dif = 0;
    for(auto &k : m){
        if(k.second > dif){
            dif = k.second;
            ans = k.first;
        }
        else if(dif == k.second && ans > k.first){
            ans = k.first;
        }
    }
    
    cout << ans << "\n";
}
