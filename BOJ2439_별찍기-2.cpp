//
//  main.cpp
//  BOJ2439_별찍기-2
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int t = n-1;
    while(t >= 0){
        for(int i = 0; i <= t-1; i++)
            printf(" ");
        for(int i = 0; i < n-t; i++)
            printf("*");
        printf("\n");
        t--;
    }
}
