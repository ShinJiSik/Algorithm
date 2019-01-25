//
//  main.cpp
//  SWEA_6719. 성수의 프로그래밍 강좌 시청
//
//  Created by 신지식 on 08/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    vector<int> v;
    float a = 0;
    int n, k;
    int i, j;
    int t;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        a = 0;
        scanf("%d %d", &n, &k);
        v.resize(n);
        for (j = 0; j < v.size(); j++) {
            scanf("%d", &v[j]);
        }
        sort(v.begin(), v.end());
        
        for (j = n-k; j < n; j++) {
            a = (a + v[j]) / 2;
        }
        
        printf("#%d %.6f\n", i + 1, a);
        v.clear();
    }
    
    return 0;
}
