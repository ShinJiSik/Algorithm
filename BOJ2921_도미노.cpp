//
//  main.cpp
//  BOJ2921_도미노
//
//  Created by 신지식 on 21/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int t = 1;
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += t * i;
        t++;
        sum += i*(i+1)/2;
    }
    cout << sum << "\n";
}
