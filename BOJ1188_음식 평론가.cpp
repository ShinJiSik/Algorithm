//
//  main.cpp
//  BOJ1188_음식 평론가
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a % b);
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    cout << m - gcd(n, m) << "\n";
}
