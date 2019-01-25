//
//  main.cpp
//  BOJ5988_홀수일까 짝수일까
//
//  Created by 신지식 on 04/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        if((s[s.size()-1] - '0') % 2 == 0)
            cout << "even\n";
        else
            cout << "odd\n";
    }
}
