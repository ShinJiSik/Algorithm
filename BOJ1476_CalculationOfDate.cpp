//
//  main.cpp
//  BOJ1476_CalculationOfDate
//
//  Created by 신지식 on 2018. 9. 23..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;

int e, s, m;
int main(){
    scanf("%d %d %d", &e, &s, &m);
    int count = 0;
    int i = 0, j = 0, k = 0;
    
    while(1){
        if(i == e && j == s && k == m)
            break;
        
        i++; j++; k++;
        if(i > 15)
            i = 1;
        if(j > 28)
            j = 1;
        if(k > 19)
            k = 1;
        
        count++;
    }
    
    printf("%d\n", count);
}
