//
//  main.cpp
//  BOJ13908_비밀번호
//
//  Created by 신지식 on 02/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int n, m;
bool visit[10];
int ans = 0;
void dfs(int idx, int cnt){
    if(idx == n){
        if(cnt != m) return;
        ans++;
        return;
    }
    
    for(int i = 0; i <= 9; i++){
        if(visit[i]){
            visit[i] = false;
            dfs(idx + 1, cnt + 1);
            visit[i] = true;
            continue;
        }
        dfs(idx + 1, cnt);
    }
}


int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        visit[num] = true;
    }
    
    dfs(0, 0);
    cout << ans << "\n";
}
