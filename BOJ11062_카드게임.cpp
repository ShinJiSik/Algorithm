//
//  main.cpp
//  BOJ11062_카드게임
//
//  Created by 신지식 on 15/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int t, n, k;
    vector<int> v;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int m = 0, g = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> k;
            v.push_back(k);
        }
        int s = 0, e = (int)v.size()-1;
        int cnt = 1;
        while(cnt != v.size()+1){
            if(cnt % 2 != 0){
                if(v[s] > v[e]){
                    m += v[s];
                    s++;
                }
                else{
                    m += v[e];
                    e--;
                }
            }
            else{
                if(v[s] > v[e]){
                    g += v[s];
                    s++;
                }
                else{
                    g += v[e];
                    e--;
                }
            }
            cnt++;
        }
        int result = max(m, g);
        
        cout << result << "\n";
        v.clear();
    }
}
