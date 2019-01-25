//
//  main.cpp
//  BOJ11651_좌표 정렬하기2
//
//  Created by 신지식 on 03/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//
//2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
        if(a.first < b.first)
            return true;
    
    return false;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a, b, n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << "\n";
}
