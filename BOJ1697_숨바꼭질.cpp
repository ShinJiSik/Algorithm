//
//  main.cpp
//  BOJ1697_숨바꼭질
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, k;
    bool check[100001];
    int dist[100001];
    
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    check[n] = true;
    dist[n] = 0;
    
    while(!q.empty()){
        int x = q.front();

        q.pop();
        if(x * 2 <= 100000 && check[2*x] == 0){
            q.push(2*x);
            check[x*2] = true;
            dist[x*2] = dist[x] + 1;
        }
        if(x - 1 >= 0 && check[x-1] == 0){
            q.push(x-1);
            check[x-1] = true;
            dist[x-1] = dist[x] + 1;
        }
        if(x + 1 <= 100000 && check[x+1] == 0){
            q.push(x+1);
            check[x+1] = true;
            dist[x+1] = dist[x] + 1;
        }
        
    }
    
    printf("%d\n", dist[k]);
}
