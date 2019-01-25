//
//  main.cpp
//  BOJ11725_트리의 부모 찾기
//
//  Created by 신지식 on 07/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
int n;
vector<int> v[MAX];
int depth[MAX];
int parent[MAX];
bool check[MAX];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[1] = 0;
    check[1] = true;
    
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y : v[x]){
            if(check[y] == false){
                depth[y] = depth[x] + 1;
                check[y] = true;
                q.push(y);
                parent[y] = x;
            }
        }
    }
    
    for(int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
}
