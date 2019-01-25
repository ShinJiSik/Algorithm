//
//  main.cpp
//  BOJ1181_단어정렬
//
//  Created by 신지식 on 05/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n;
vector<string> v;
set<string> word;
bool cmp(string s1, string s2){
    if(s1.length() < s2.length())
        return true;
    if(s1.length() == s2.length()){
        if(s1 < s2)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        word.insert(s);
    }
    
    for(auto str : word){
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(), cmp);
    int len = (int)v.size();
    for(int i = 0; i < len; i++)
        cout << v[i] << "\n";
}
