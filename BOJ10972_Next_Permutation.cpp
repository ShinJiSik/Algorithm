//
//  main.cpp
//  BOJ10972_Next_Permutation
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
        int t;
        cin >> t;
        v.push_back(t);
    }
    if(next_permutation(v.begin(), v.end())){
        for(int i = 0; i < v.size(); i++)
            printf("%d ", v[i]);
    }
    else
        printf("-1");
    printf("\n");
}
