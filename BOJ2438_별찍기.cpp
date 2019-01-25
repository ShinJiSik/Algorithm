//
//  main.cpp
//  BOJ2438_별찍기
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int t = 0;
    while(t != n){
        for(int i = 0; i <= t; i++)
            printf("*");
        
        printf("\n");
        t++;
    }
}
