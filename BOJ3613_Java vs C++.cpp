//
//  main.cpp
//  BOJ3613_Java vs C++
//
//  Created by 신지식 on 2018. 9. 29..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string s;
/*
bool cpp(){
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] != '_'){
            if(s[i] < 'a' || s[i] > 'z'){
                return false;
            }
        }
    }
    return true;
}

bool java(){
    int len = s.length();
    if(s[0] < 'a' || s[0] > 'z')
        return false;

    for(int i = 1; i < len; i++){
        if(!(s[i] >= 'a' && s[i] <= 'z')){
            if(!(s[i] >= 'A' && s[i] <= 'Z')){
                printf("00");
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> s;

    string ans = "";
    if(cpp()){//c++이면
        int i = 0;
        while(1){
            if(s[i] == '\0')
                break;
            
            if(i > 0 && s[i-1] == '_'){
                ans += s[i] - 32;
            }
            else{
                if(s[i] == '_'){}
                else
                    ans += s[i];
            }
            i++;
        }
        cout << ans << "\n";
    }
    else if(java()){//java면
        int i = 0;
        while(1){
            if(s[i] == '\0')
                break;

            if(s[i] >= 65 && s[i] <= 90){
                ans += "_";
                ans += s[i] + 32;
            }
            else{
                ans += s[i];
            }
            
            i++;
        }
        
        cout << ans << "\n";
    }
    else{
        printf("Error!\n");
    }
}
 */

int n, m;
int arr[10][10];
bool check[10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void fill(){
    
}

int main(){
    cin >> n >> m;
    int arr[10][10];
    int c = 1;
    int s = 0;
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < m; j++){
            
        }
    }
}
