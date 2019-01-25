//
//  main.cpp
//  BOJ13900_순서쌍의 곱의 합
//
//  Created by 신지식 on 05/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//
/*
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v, make;
bool check[100001];
long long ans = 0;
void dfs(int idx, int cnt){
    if(cnt == 2){
        int t = 1;
        for(int i = 0; i < cnt; i++)
            t *= make[i];
        ans += t;
        return;
    }
    if(idx == n) return;
    
    check[idx] = true;
    make.push_back(v[idx]);
    dfs(idx + 1, cnt + 1);
    make.pop_back();
    check[idx] = false;
    
    dfs(idx + 1, cnt);
    
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    dfs(0, 0);
    cout << ans << "\n";
}
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    long long sum = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        ans += sum * num;
        sum += num;
    }
    
    cout << ans << "\n";
}
