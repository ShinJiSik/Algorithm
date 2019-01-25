//
//  main.cpp
//  BOJ2440_별찍기-3
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for(int j = 0; j < n; j++){
        for(int i = n; i > j; i--)
            printf("*");
        printf("\n");
    }
}

