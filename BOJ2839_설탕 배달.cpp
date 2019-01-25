//
//  main.cpp
//  BOJ10718_We Love Kriii
//
//  Created by 신지식 on 28/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;
vector<int> five, three;
int main(){
    int sugar;
    int ans = 987654321;
    
    cin >> sugar;
    
    for(int i = 0; i <= sugar; i++){
        if(i % 3 == 0)
            three.push_back(i);
        if(i % 5 == 0)
            five.push_back(i);
    }
    bool cor = false;
    for(int i = 0; i < five.size(); i++){
        for(int j = 0; j < three.size(); j++){
            if(five[i] + three[j] == sugar){
                if(ans > i + j){
                    ans = i + j;
                    cor = true;
                }
            }
        }
    }
    if(cor == false)
        cout << "-1\n";
    else
        cout << ans << "\n";
}
