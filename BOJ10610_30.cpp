//
//  main.cpp
//  BOJ10610_30
//
//  Created by 신지식 on 30/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
vector<int> v, t;
bool check[100001];
int ans = 0;

void dfs(int cnt){
    if(cnt == v.size()-1){
        int sum = 0;
        
        for(int i = 0; i < t.size(); i++)
            sum = sum * 10 + t[i];
        sum *= 10;
        
        if(sum % 30 == 0){
            if(sum > ans)
                ans = sum;
        }
        return;
    }

    for(int i = 0; i < v.size()-1; i++){
        if(!check[i]){
            t.push_back(v[i]);
            check[i] = true;
            dfs(cnt+ 1);
            t.pop_back();
            check[i] = false;
        }
    }
}


int main(int argc, const char * argv[]) {
    string num;
    cin >> num;
    
    for(int i = 0; i < num.size(); i++)
        v.push_back(num[i] - '0');
    
    sort(v.begin(), v.end(), greater<>());
    if(v[v.size()-1] != 0)
        cout << "-1\n";
    else{
        dfs(0);
        cout << ans << "\n";
    }
}
*/


int main(){

    string s;
    cin >> s;
    int num = 0;
    for(int i = 0; i < s.size(); i++)
        num += s[i] - '0';
    
    sort(s.begin(), s.end(), greater<>());
    if(s[s.size()-1] == '0' && num % 3 == 0)
        cout << s << "\n";
    else
        cout << "-1\n";

}
