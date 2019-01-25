//
//  main.cpp
//  BOJ6588_Goldbach conjecture
//
//  Created by 신지식 on 2018. 9. 23..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;

bool p[1000001];
int num[1000001];
int pn = 0;

int main(){
    p[0] = p[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(p[i] == false){
            num[pn++] = i;
            for(int j = i+i; j <= 1000000; j += i){
                p[j] = true;
            }
        }
    }
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 1; i < pn; i++){
            if(p[n - num[i]] == false){
                printf("%d = %d + %d\n", n, num[i], n-num[i]);
                break;
            }
        }
    }
}
