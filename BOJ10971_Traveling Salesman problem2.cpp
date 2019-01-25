//
//  main.cpp
//  BOJ10971_Traveling Salesman problem2
//
//  Created by 신지식 on 2018. 9. 24..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
/*
int city;
int arr[11][11];
int visited[11];
int ans;

void dfs(int now, int next, int cost, int visit){
    if(now == next && visit == city){
        ans = min(ans, cost);
        return;
    }
    for(int i = 0; i < city; i++){
        if(arr[next][i] == 0) continue;
        if(cost + arr[next][i] > ans) continue;
        if(!visited[i]){
            visited[i] = 1;
            dfs(now, i, cost + arr[next][i], visit+1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> city;
    
    for(int i = 0; i < city; i++)
        for(int j = 0; j < city; j++)
            cin >> arr[i][j];
    
    ans = 987654321;
    
    for(int i = 0; i < city; i++)
        dfs(i, i, 0, 0);
    
    printf("%d\n", ans);
}
*/

int n;
int arr[11][11];
bool visit[11];
int ans;
int start;
void dfs(int now, int cost, int cnt){
    if(visit[now] == false){
        visit[now] = true;
        cnt++;
        for(int i = 0; i < n; i++){
            if(arr[now][i] != 0){
                dfs(i, arr[now][i] + cost, cnt);
            }
        }
        visit[now] = false;
    }
    
    if(cnt == n && start == now){
        ans = min(ans, cost);
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    ans = 987654321;
    for(int i = 0; i < n; i++){
        start = i;
        dfs(i, 0, 0);
    }
    
    printf("%d\n", ans);
}
