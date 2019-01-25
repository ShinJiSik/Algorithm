//
//  main.cpp
//  BOJ10989_수정렬하기3
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

//counting sort
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int arr[10001] = {0, };
    int num;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        arr[num]++;
    }
    
    for(int i = 1; i <= 10000; i++){
        if(arr[i] != 0){
            for(int j = 0; j < arr[i]; j++)
                printf("%d\n", i);
        }
        else
            continue;
    }
    
    return 0;
}
