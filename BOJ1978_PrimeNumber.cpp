//
//  main.cpp
//  BOJ1978_PrimeNumber
//
//  Created by 신지식 on 2018. 9. 23..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool prime(int x){
    if(x < 2)
        return false;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;

    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(prime(v[i]))
            count++;
    }
    
    cout << count << "\n";
}
