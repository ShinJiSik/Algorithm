//
//  main.cpp
//  BOJ1931_회의실배정
//
//  Created by 신지식 on 30/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct diss{
    int start, end;
};
bool cmp(const diss &a, const diss &b){
    if(a.end == b.end)
        return a.start < b.start;
    else
        return a.end < b.end;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<diss> v;
    
    int s, e, count = 0;
    
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end(), cmp);
    int stand = 0;
    for(int i = 0; i < n; i++){
        if(stand <= v[i].start){
            stand = v[i].end;
            count++;
        }
    }
    cout << count << "\n";
}
