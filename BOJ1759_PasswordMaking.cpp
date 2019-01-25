//
//  main.cpp
//  BOJ1759_PasswordMaking
//
//  Created by 신지식 on 2018. 9. 25..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int l, c;
vector<char> v;

bool check(string password){
    int ja = 0;
    int mo = 0;
    
    for(int i = 0; i < password.length(); i++){
        if(password[i] == 'a' || password[i] == 'e' || password[i] == 'o' || password[i] == 'i' || password[i] == 'u')
            mo++;
        else
            ja++;
    }
    
    if(mo > 0 && ja > 1)
        return true;
    else
        return false;
}

void make(string password, int idx){
    if(password.length() == l){
        if(check(password))
            cout << password << "\n";
        return;
    }
    if(idx == c) return;
    
    make(password+v[idx], idx+1);
    make(password, idx+1);
    
}

int main(){
    cin >> l >> c;
    
    for(int i = 0; i < c; i++){
        char a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    make("", 0);
}
