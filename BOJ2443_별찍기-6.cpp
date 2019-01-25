//
//  main.cpp
//  BOJ2443_별찍기-6
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++)
            printf(" ");
        for(int j = 0; j < 2*n - (i*2)+1; j++)
            printf("*");
        printf("\n");
    }
}
