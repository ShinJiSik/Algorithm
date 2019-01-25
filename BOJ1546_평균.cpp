//
//  main.cpp
//  BOJ1546_평균
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<float> v;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    int last = (int)v.size()-1;
    float sum = 0;
    for(int i = 0; i < (int)v.size(); i++){
        sum += (v[i]*100 / v[last]);
    }
    
    printf("%f\n" ,sum/n);
}
