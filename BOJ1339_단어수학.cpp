//
//  main.cpp
//  BOJ1339_단어수학
//
//  Created by 신지식 on 2018. 10. 6..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int n;
int alpha[27];
int main(int argc, const char * argv[]) {
    cin >> n;

    for(int t = 0; t < n; t++){
        string str;
        cin >> str;
        int len = str.length();
        for(int i = 0; i < len; i++){
            alpha[str[i] - 'A'] += pow(10, len-i-1);
        }
    }
    sort(alpha, alpha+27, greater<int>());
    
    int ans = 0;
    int j = 0;
    for(int i = 9; i >= 0; i--){
        ans += (i * alpha[j]);
        j++;
    }
    printf("%d\n", ans);
}
