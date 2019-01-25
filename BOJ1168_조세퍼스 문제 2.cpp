//
//  main.cpp
//  BOJ1168_조세퍼스 문제 2
//
//  Created by 신지식 on 04/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//
// 선형큐x 원형큐 o

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    int idx = 0;
    cout << "<";
    while(v.size() != 1){
        idx += m - 1;
        if(idx >= v.size())
            idx %= v.size();
        
        cout << v[idx] << ", ";
        v.erase(v.begin() + idx);
    }
    cout << v[0] << ">\n";
}

