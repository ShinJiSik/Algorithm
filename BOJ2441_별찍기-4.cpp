//
//  main.cpp
//  BOJ2441_별찍기-4
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int k = 0; k < i; k++)
            printf(" ");
        for(int j = n; j > i; j--)
            printf("*");
        printf("\n");
    }
}
