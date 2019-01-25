//
//  main.cpp
//  BOJ11721_열 개씩 끊어 출력하기
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    char a[101];
    cin >> a;
    int i = 0;
    while(a[i] != '\0'){
        cout << a[i++];
        if(i % 10 == 0) cout << "\n";
    }
}
