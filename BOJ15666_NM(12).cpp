//
//  main.cpp
//  BOJ15666_NM(12)
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
int check[9];
set<vector<int>> s;

bool ascending(){
    for(int i = 0; i < m-1; i++)
        if(a[i] > a[i+1])
            return false;
    return true;
}

void dfs(int cnt, int idx){
    if(cnt == m){
        auto iter = s.find(a);
        s.insert(a);
        if(iter == s.end() && ascending()){
            for(int i = 0; i < m; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
        return;
    }
    for(int i = idx; i < n; i++){
        a.push_back(v[i]);
        dfs(cnt + 1, i);
        a.pop_back();
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    dfs(0, 0);
}
