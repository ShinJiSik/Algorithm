//
//  main.cpp
//  BOJ1389_케빈 베이컨의 6단계 법칙
//
//  Created by 신지식 on 03/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
int n, m;
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(1);
    }
}
