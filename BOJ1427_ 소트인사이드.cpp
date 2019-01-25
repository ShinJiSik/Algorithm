//
//  main.cpp
//  BOJ1427_ 소트인사이드
//
//  Created by 신지식 on 09/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    string n;
    vector<int> v;
    int t;
    cin >> n;
    
    for(int i = 0; i < n.size(); i++){
        t = n[i] - '0';
        v.push_back(t);
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << "\n";
}
