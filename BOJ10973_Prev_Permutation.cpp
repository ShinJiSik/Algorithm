//
//  main.cpp
//  BOJ10973_Prev_Permutation
//
//  Created by 신지식 on 2018. 9. 24..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    vector<int> v;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    
    if(prev_permutation(v.begin(), v.end())){
        for(int i = 0; i < v.size(); i++)
            printf("%d ", v[i]);
    }
    else
        printf("-1");
    printf("\n");
}
