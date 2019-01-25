//
//  main.cpp
//  BOJ14889_스타트와 링크
//
//  Created by 신지식 on 2018. 10. 7..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
int n;
int arr[21][21];
bool check[21];
vector<int> v, u;
int ans = 987654321;
int diff1 = 0, diff2= 0;

bool ascending(){
    for(int i = 0; i < n/2; i++){
        if(u[i] > u[i+1])
            return false;
    }
    return true;
}

void dfs(int x){
    if(x == n/2){
        if(ascending()){
            diff1 = 0, diff2 = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i != j && check[i] == true && check[j] == true)
                        diff1 += arr[i][j];
                    if(i != j && check[i] == false && check[j] == false)
                        diff2 += arr[i][j];
                }
            }
            int tmp = abs(diff1 - diff2);
            ans = min(ans, tmp);
        }
    }
    
    for(int i = x; i < n; i++){
        if(check[i] == false){
            check[i] = true;
            u.push_back(i);
            dfs(x+1);
            check[i] = false;
            u.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++)
        v.push_back(i);
    
    dfs(0);
    printf("%d\n", ans);
}
/*
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int visit[21];
int S[21][21];

int ans=987654321;
int cal() {
    vector<int> start;
    vector<int> link;
    for (int i = 1; i <= n; i++) {
        if (visit[i])
            start.push_back(i);
        else
            link.push_back(i);
    }
    int res1=0, res2=0;
    
    for (int i = 0; i < (n / 2) - 1; i++) {
        for (int j = i+1; j < n/2; j++) {
            int starti = start[i], startj = start[j];
            int linki = link[i], linkj = link[j];
            res1 += (S[starti][startj] + S[startj][starti]);
            res2 += (S[linki][linkj] + S[linkj][linki]);
        }
    }
    return abs(res1 - res2);
}
void dfs(int idx, int cnt) {
    if (cnt == n / 2) {
        ans = min(ans, cal());
        return;
    }
    for (int i = idx; i <= n; i++) {
        if (!visit[i]) {
            visit[i] = 1;
            dfs(i, cnt + 1);
            visit[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> S[i][j];
    
    for (int i = 1; i <= n; i++) {
        visit[i] = 1;
        dfs(i,1);
        visit[i] = 0;
    }
    cout << ans;
    cin >> n;
    return 0;
}
*/
