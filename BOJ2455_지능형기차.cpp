//
//  main.cpp
//  BOJ2455_지능형기차
//
//  Created by 신지식 on 21/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    int sum = 0;
    for(int i = 0; i < 4; i++){
        cin >> a >> b;
        if(b - a > 0)
            sum += b - a;
    }
    cout << sum << "\n";
}
