//
//  main.cpp
//  BOJ1248_맞춰봐
//
//  Created by 신지식 on 2018. 10. 7..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
string str;
vector<int> ans;
char sign[22][22];
int sum[12];
bool check(int idx){
    for(int i = 1; i < idx; i++){
        if(sign[i][idx] == '+'){
            if(sum[idx] - sum[i-1] <= 0)
                return false;
        }
        if(sign[i][idx] == '-'){
            if(sum[idx] - sum[i-1] >= 0)
                return false;
        }
        if(sign[i][idx] == '0'){
            if(sum[idx] - sum[i-1] != 0)
                return false;
        }
    }

    return true;
}

void dfs(int x) {
    if(x == n + 1){
        for(int i = 0; i < n; i++)
            printf("%d ", ans[i]);
        printf("\n");
        exit(0);
    }

    if(sign[x][x] == '+'){
        for(int j = 1; j <= 10; j++){
            ans.push_back(j);
            sum[x] = sum[x-1] + ans[x-1];
            if(check(x))
                dfs(x + 1);
            ans.pop_back();
        }
    }
    if(sign[x][x] == '-'){
        for(int j = -1; j >= -10; j--){
            ans.push_back(j);
            sum[x] = sum[x-1] + ans[x-1];
            if(check(x))
                dfs(x + 1);
            ans.pop_back();
        }
    }
    if(sign[x][x] == '0'){
        ans.push_back(0);
        sum[x] = sum[x-1];
        dfs(x + 1);
        ans.pop_back();
    }
}

int main(){
    cin >> n;
    cin >> str;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            sign[i][j] = '#';
    
    int k = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            sign[i][j] = str[k]; k++;
        }
    }

    dfs(1);
}


































/*
int n;
string str;
vector<char> sign, first;
vector<int> ans;

bool check(int start){
    if(start > first.size())
        return true;

    int sum = 0;
    int i = first[start];
    int j = first[start+1];
    int k = start;
    while(i < j){
        
        sum += ans[k];
        if(sign[i] == '+'){
            if(sum <= 0)
                return false;
        }
        if(sign[i] == '-'){
            if(sum >= 0)
                return false;
        }
        if(sign[i] == '0'){
            if(sum != 0)
                return false;
        }
        i++;
        k++;

    }
    check(start+1);

    return true;
}

void dfs(int idx, int cnt){
    if(cnt == n){
        if(check(0)){
            for(int i = 0; i < n; i++)
               printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }

    if(sign[first[idx]] == '+'){
        for(int i = 1; i <= 10; i++){
            ans.push_back(i);
            dfs(idx+1, cnt+1);
            ans.pop_back();
        }
    }
    if(sign[first[idx]] == '-'){
        for(int i = 1; i <= 10; i++){
            ans.push_back(-i);
            dfs(idx+1, cnt+1);
            ans.pop_back();
        }
    }
    if(sign[first[idx]] == '0'){
        dfs(idx+1, cnt+1);
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> n;
    cin >> str;
    
    int len = str.length();
    for(int i = 0; i < len; i++)
        sign.push_back(str[i]);
    
    int a = 0;
    int k = n;
    while(a < len){// && k > 0){
        first.push_back(a);
        a += k;
        k -= 1;
    }
    
    for(int i = 0; i < n; i++){
        dfs(i, 0);
    }
}
 */
