//
//  main.cpp
//  BOJ_10871_X보다 작은 수
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, x, num;
    cin >> n >> x;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num < x)
            printf("%d ",num);
    }
    printf("\n");
}
