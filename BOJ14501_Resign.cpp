//
//  main.cpp
//  BOJ14501_Resign
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
vector<pair<int, int>> v;
int ans = INT_MIN;

void maxcost(int now, int day, int cost){
    if(now + day > n) return;
    
    for(int i = now + day; i < n; i++){
        maxcost(i, v[i].first, cost + v[i].second);
    }
    
    ans = max(ans, cost);
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int t, p;
        cin >> t >> p;
        v.push_back(make_pair(t, p));
    }
    ans = 0;
    for(int i = 0; i < n; i++)
        maxcost(i, v[i].first, v[i].second);
    printf("%d\n", ans);
}
