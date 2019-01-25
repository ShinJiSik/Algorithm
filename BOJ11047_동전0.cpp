//
//  main.cpp
//  BOJ11047_동전0
//
//  Created by 신지식 on 30/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

//그리디
//k보다 큰 값은 받을 필요 없음.

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, k, count = 0;
    
    cin >> n >> k;
    
    vector<int> use;
    int coin;
    for(int i = 0; i < n; i++){
        cin >> coin;
        if(coin <= k)
            use.push_back(coin);
    }
    
    int m_use = (int)use.size()-1;
    
    while(k != 0){
        int tmp = k / use[m_use];
        if(tmp != 0){
            k %= use[m_use];
            count += tmp;
        }
        m_use--;
    }
    
    cout << count << "\n";
}
