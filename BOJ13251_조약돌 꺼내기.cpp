//
//  main.cpp
//  BOJ13251_조약돌 꺼내기
//
//  Created by 신지식 on 13/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int m, k, num, total = 0;
    vector<int> v;
    vector<double> val;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        cin >> num;
        v.push_back(num);
        total += num;
    }
    cin >> k;
    
    double ans = 0.0;
    int t = total;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < m; j++){
            
        }
    }
    
    
    
}
