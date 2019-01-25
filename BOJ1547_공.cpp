//
//  main.cpp
//  BOJ1547_공
//
//  Created by 신지식 on 2018. 10. 18..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int m;
    cin >> m;
    int arr[3];
    arr[0] = 1;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(arr[a-1] == 1){
            arr[b-1] = 1;
            arr[a-1] = 0;
        }
        else if(arr[b-1] == 1){
            arr[b-1] = 0;
            arr[a-1] = 1;
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(arr[i] == 1){
            printf("%d\n", i+1);
        }
    }
}
