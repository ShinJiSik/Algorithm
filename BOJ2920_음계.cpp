//
//  main.cpp
//  BOJ2920_음계
//
//  Created by 신지식 on 09/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[9];
    
    for(int i = 0; i < 8; i++)
        cin >> arr[i];
    
    int a = 0, d = 0, m = 0;
    for(int i = 1; i < 8; i++){
        if(arr[i-1] < arr[i]) a++;
        else if(arr[i-1] > arr[i]) d++;
        else m++;
    }
    
    if(a == 7) cout << "ascending\n";
    else if(d == 7) cout << "descending\n";
    else cout << "mixed\n";
}
