//
//  main.cpp
//  SWEA_5658.보물상자 비밀번호
//
//  Created by 신지식 on 2018. 10. 4..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n, k;

vector<char> v;
set<string> s;
vector<long long> ans;
void convert(string str){
    long long cal = 0;
    for(int i = 0; i < str.length(); i++){
        if ('0' <= str[i] && str[i] <= '9') {
            cal = cal * 16 + (str[i] - '0');
        } else {
            cal = cal * 16 + (str[i] - 'A' + 10);
        }
    }
    ans.push_back(cal);
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    
    for(int a = 1; a <= t; a++){
        cin >> n >> k;
        int div = n/4;
        
        for(int i = 0; i < n; i++){
            char a;
            cin >> a;
            v.push_back(a);
        }
        
        
        for(int i = 0; i < n; i++){
            string tmp = "";
            for(int j = 0; j < div; j++){
                tmp += v[j];
            }
            s.insert(tmp);
            auto au = v.end();
            v.insert(au, v[0]);
            v.erase(v.begin()+0);
        }
        
        for(auto str : s){
            convert(str);
        }
        sort(ans.begin(), ans.end(), greater<long long>());

        printf("#%d %lld\n", a, ans[k-1]);
        v.clear();
        ans.clear();
        s.clear();
    }
}

/*
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

char str[51];
vector<int> ans;
int n,k;
int stoi(char x){
    
    if('0'<=x && x<='9') return x-'0';
    else return 10 + x-'A';//if('A'<= x && x<='F')
    
}
int change(int idx){
    
    int r = n/4;
    
    for(int i=0;i<4;i++){
        int start = (1<<(n-1));
        int value = 0;
        for(int j=0;j<r;j++){
            int tmp = stoi(str[idx]);
            for(int k=3;k>=0;k--){
                if(tmp&(1<<k)) value += start;
                start/=2;
            }
            idx = (idx+1)%n;
        }
        ans.push_back(value);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int T;
    
    scanf("%d",&T);
    
    for(int ii=1;ii<=T;ii++){
        scanf("%d %d",&n,&k);
        scanf("%s",str);
        
        for(int i=0;i<n/4;i++) change( (n-i)%n );
        
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        printf("#%d %d\n",ii, ans[ans.size()-k]);
        
        ans.clear();
    }
    
    
    return 0;
}
*/
