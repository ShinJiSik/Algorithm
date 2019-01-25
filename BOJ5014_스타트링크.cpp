//
//  main.cpp
//  BOJ5014_스타트링크
//
//  Created by 신지식 on 2018. 10. 20..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int f, g, s, u ,d;
queue<int> q;
int check[1000002];
bool cnt[1000002];

void bfs(int go){
    check[go] = 0;
    q.push(go);
    cnt[go] = true;
    while(!q.empty()){
        int move = q.front();
        q.pop();
        
        if(move + u <= f){
            if(cnt[move + u] == false){
                q.push(move+u);
                cnt[move + u] = true;
                check[move + u] = check[move] + 1;
            }
        }
    
        if(move - d >= 1){
            if(cnt[move - d] == false){
                q.push(move-d);
                cnt[move - d] = true;
                check[move - d] = check[move] + 1;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> f >> s >> g >> u >> d;
    memset(check, -1, sizeof(check));
    bfs(s);
    
    if(cnt[g] == false)
        printf("use the stairs\n");
    else
        printf("%d\n", check[g]);
}
