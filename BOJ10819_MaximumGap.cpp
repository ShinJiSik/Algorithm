//
//  main.cpp
//  BOJ10819_MaximumGap
//
//  Created by 신지식 on 2018. 9. 24..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        int sum = 0;

        for(int i = 0 ; i < v.size()-1; i++){
            sum += abs(v[i]-v[i+1]);
        }
        ans = max(ans, sum);
    }while(next_permutation(v.begin(), v.end()));
    
    printf("%d\n", ans);
    
}
