//
//  main.cpp
//  BOJ2609_GCD_LCM
//
//  Created by 신지식 on 2018. 9. 23..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}


int main(){
    int a, b;
    
    cin >> a >> b;
    int GCD = gcd(a,b);
    int LCM = GCD*(a/GCD)*(b/GCD);
    cout << GCD << "\n" << LCM << "\n";
}
