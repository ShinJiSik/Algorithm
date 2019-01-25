//
//  main.cpp
//  BOJ2562_최댓값
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int max = 0, idx = 0, n;
    for(int i = 0; i < 9; i++){
        cin >> n;
        if(n > max){
            max = n;
            idx = i + 1;
        }
    }
    cout << max << "\n" << idx << "\n";
}
