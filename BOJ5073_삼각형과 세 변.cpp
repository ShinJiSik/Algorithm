//
//  main.cpp
//  BOJ5073_삼각형과 세 변
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b, c;
    while(1){
        cin >> a >> b >> c;
        
        if(a == 0 && b == 0 && c == 0) break;
        else if(a == b && b == c && c == a)
            cout << "Equilateral" << "\n";
        else if(a + b <= c || b + c <= a || a + c <= b)
            cout << "Invalid" << "\n";
        else if(a == 0 || b == 0 || c == 0)
            cout << "Invalid" << "\n";
        else if(a == b || b == c || c == a)
            cout << "Isosceles" << "\n";
        else
            cout << "Scalene" << "\n";
    }
}
