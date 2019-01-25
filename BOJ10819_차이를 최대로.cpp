//
//  main.cpp
//  BOJ10819_차이를 최대로
//
//  Created by 신지식 on 2018. 10. 23..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<int > v;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        int tmp = 0;
        for(int i = 0; i < n-1; i++)
            tmp += abs(v[i]-v[i+1]);

        if(tmp > ans)
            ans = tmp;
        
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans << "\n";
}
