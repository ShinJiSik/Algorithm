//
//  main.cpp
//  BOJ2442_별찍기-5
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
        for(int j = n-i; j > 0; j--)
            printf(" ");
        for(int k = 0; k < i*2 - 1; k++)
            printf("*");
        printf("\n");
    }
}
