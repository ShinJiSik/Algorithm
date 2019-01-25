//
//  main.cpp
//  BOJ1110_더하기 사이클
//
//  Created by 신지식 on 09/01/2019.
//  Copyright © 2019 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, a, b;
    cin >> n;
    
    int result = n, count = 0;
    bool check = false;
    while(count < 100){
        a = result / 10;
        b = result % 10;
        result = (b*10) + ((a+b)%10);
        count++;
        if(result == n){
            check = true;
            break;
        }
    }
    
    if(check == false)
        cout << "NO" << "\n";
    else
        cout << count << "\n";
}
