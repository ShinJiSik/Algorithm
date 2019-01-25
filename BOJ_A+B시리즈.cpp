//
//  main.cpp
//  BOJ_A+B시리즈
//
//  Created by 신지식 on 04/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a + b << "\n";
    }
    
    //7
    /*
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a + b << "\n";
    }
    */
    
    //6
    /*
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << (s[0]-'0') + (s[2]-'0') << "\n";
    }
    */
    //5
    /*
    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        cout << a + b << "\n";
    }
    */
    //4
    /*
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", a + b);
    }*/
}
