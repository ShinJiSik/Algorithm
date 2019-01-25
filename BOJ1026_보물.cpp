//
//  main.cpp
//  BOJ1026_보물
//
//  Created by 신지식 on 14/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a, b;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        a.push_back(num);
    }
    
    for(int i = 0; i < n; i++){
        cin >> num;
        b.push_back(num);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
   
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i] * b[i];
    cout << ans << "\n";
}
