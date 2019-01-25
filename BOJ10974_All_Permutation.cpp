//
//  main.cpp
//  BOJ10974_All_Permutation
//
//  Created by 신지식 on 2018. 9. 24..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    
    do{
        for(int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        
        printf("\n");
    }while(next_permutation(arr, arr + n));
}
