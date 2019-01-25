//
//  main.cpp
//  BOJ15665_NM(11)
//
//  Created by 신지식 on 2018. 9. 28..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, m;
vector<int> v, a;
set<vector<int>> s;

void dfs(int cnt){
    if(cnt == m){
        auto iter = s.find(a);
        s.insert(a);
        if(iter == s.end()){
            for(int i = 0; i < m; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
        return;
    }
    for(int i = 0; i < n; i++){
        a.push_back(v[i]);
        dfs(cnt + 1);
        a.pop_back();
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    dfs(0);
}
