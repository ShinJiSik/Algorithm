//
//  main.cpp
//  Sum Of GCD
//
//  Created by 신지식 on 2018. 9. 12..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>

using namespace std;
int t, n;
int arr[101];
int gcd(int x, int y){
    if(y == 0)
        return x;
    else
        return gcd(y, x % y);
}


int main(){
    int t;
    
    cin >> t;
    
    while(t--){
        long long sum = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> arr[j];
        
        for(int j = 0; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                sum += gcd(arr[j], arr[k]);
            }
        }
        
        cout << sum << '\n';
    }
}
