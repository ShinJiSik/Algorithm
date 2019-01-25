//
//  main.cpp
//  BOJ2003_수들의 합2
//
//  Created by 신지식 on 14/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n, num, m;
    vector<long long> v;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    
    long long s = 0, e = 0, sum = 0;
    int ans = 0;
    while(s != v.size()){
        if(sum >= m){
            sum -= v[s];
            s++;
        }
        else if(s == n || e == n) break;
        else{
            sum += v[e];
            e++;
        }
        if(sum == m)
            ans++;
    }
    
    cout << ans << "\n";
}
