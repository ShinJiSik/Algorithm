//
//  main.cpp
//  BOJ10818_최대, 최소
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int min = 987654321;
    int max = -987654321;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num < min)
            min = num;
        if(num > max)
            max = num;
    }
    cout << min << " " << max << "\n";
}
