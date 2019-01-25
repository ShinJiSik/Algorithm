//
//  main.cpp
//  BOJ1977_완전제곱수
//
//  Created by 신지식 on 13/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int n, m;
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    int to = sqrt(m);
    int sum = 0, min = 987654321;
    bool ok = false;
    for(int i = 1; i <= to; i++){
        if(i*i >= n && i*i <= m){
            ok = true;
            sum += i*i;
            if(i*i < min)
                min = i * i;
        }
    }
    if(ok == true)
        cout << sum << "\n" << min << "\n";
    else
        cout << "-1" << "\n";
}
