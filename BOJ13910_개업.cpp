//
//  main.cpp
//  BOJ13910_개업
//
//  Created by 신지식 on 04/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//
/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int plate, n;
int check[10001];
bool visit[10001];
queue<int> q;
vector<int> v, work;
set<int> s;

void find(){
    q.push(0);
    check[0] = 0;
    int out = 0;
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t == n) break;
        if(out == 1) break;
        for(auto a : s){
            q.push(a + t);
            printf("%d --\n", a + t);
            if(a+t > plate){
                out = 1;
                break;
            }
            if(check[a+t] == 0)
                check[a + t] = check[t] + 1;
            else{
                check[a + t] = min(check[a + t], check[t]+1);
            }
        }
    }
}
void dfs(int x, int cnt){
    if(cnt > 2){
        return;
    }
    else if(v.size() != 0){
        int sum = 0;
        s.clear();
        for(int i = 0; i < v.size(); i++){
            s.insert(v[i]);
            sum += v[i];
            printf("%d ", v[i]);
        }
        printf("\n--%d\n", sum);
        if(sum > 10000)
            return;
        else
            s.insert(sum);
        find();
    }
    
    if(x == n)
        return;
    v.push_back(work[x]);
    check[work[x]] = true;
    dfs(x+1, cnt + 1);
    check[work[x]] = false;
    v.pop_back();

    dfs(x+1, cnt);

}

int main(int argc, const char * argv[]) {
    cin >> plate >> n;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num <= plate)
            work.push_back(num);
       // check[work[i]] = true;
    }
    dfs(0, 0);
    
    printf("%d\n", check[n]);
}
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int plate, n, work[101], dp[10001];
int possible = 1e9;
int cook(int n){
    int &ret = dp[n];
    if(ret != -1) return ret;
    if(n == 0) return ret = 0;
    
    ret = possible;
    for(int i = 0; i < n; i++){
        if(work[i] <= n)
            ret = min(ret, cook(n - work[i])+1);
        for(int j = 0; j < n; j++)
            if(i != j && work[i] + work[j] <= n)
                ret = min(ret, cook(n - work[i] - work[j]) + 1);
    }
    return ret;
}

int main(){
    cin >> plate >> n;
    for(int i = 0; i < n; i++)
        cin >> work[i];
    memset(dp, -1, sizeof(dp));
    
    int ans = cook(n);
    if(ans == possible)
        cout << "-1" << "\n";
    else
        cout << ans << "\n";
    
}
/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int N, M, S[100], dp[10001];

int zzazang(int n){
    int &ret = dp[n];
    if(ret != -1) return ret;
    if(n == 0) return ret = 0;
    
    ret = IMPOSSIBLE;
    for(int i=0; i<M; i++){
        if(S[i] <= n) ret = min(ret, zzazang(n-S[i])+1);
        for(int j=0; j<M; j++)
            if(i != j && S[i]+S[j] <= n) ret = min(ret, zzazang(n-S[i]-S[j])+1);
    }
    return ret;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d", S+i);
    fill(dp, dp+10001, -1);
    
    int result = zzazang(N);
    printf("%d\n", result==IMPOSSIBLE ? -1 : result);
}
*/
