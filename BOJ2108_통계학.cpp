//
//  main.cpp
//  BOJ2108_통계학
//
//  Created by 신지식 on 09/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//
//첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
//둘째 줄에는 중앙값을 출력한다.
//셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
//넷째 줄에는 범위를 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, a;
    int arr[8002] = {0, };
    vector<int> v, v2;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
        arr[a+4000]++;
    }
    
    
    sort(v.begin(), v.end());
    double sum = 0;
    int median = 0, most = 0, range;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        arr[v[i]+4000]++;
    }
    
    for(int i = 0; i < 8001; i++){
        if(arr[i] > most){
            most = arr[i];
            v2.clear();
            v2.push_back(i);
        }
        else if(arr[i] == most)
            v2.push_back(i);
    }
    
    if(v2.size() == 1) most = v2[0] - 4000;
    else most = v2[1] - 4000;
    
    sum = (int)floor((sum / n) + 0.5);
    median = v[v.size()/2];
    range = v[v.size()-1] - v[0];
    cout << sum << "\n" << median << "\n" << most << "\n" << range << "\n";
}
