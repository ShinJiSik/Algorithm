//
//  main.cpp
//  BOJ11399_ATM
//
//  Created by 신지식 on 30/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int t, n;
    cin >> n;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    int ans = v[0];
    for(int i = 1; i < n; i++){
        ans += v[i];
        for(int j = 0; j <= i - 1; j++){
            ans += v[j];
        }
    }
    
    cout << ans << "\n";
}
