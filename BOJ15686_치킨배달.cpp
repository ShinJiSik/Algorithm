//
//  main.cpp
//  BOJ15686_치킨배달
//
//  Created by 신지식 on 2018. 10. 17..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> check;
int ans = 987654321;

void dfs(int cnt){
    if(cnt == chicken.size()){
        if(check.size() == m){
            /*
            for(int i = 0; i < check.size(); i++)
                printf("%d %d\n", check[i].first, check[i].second);
            printf("\n");
             */
            int total = 0;
            for(int i = 0; i < house.size(); i++){
                int minhouse = 987654321;
                for(int j = 0; j < m; j++){
                    int dist = abs(house[i].first - check[j].first) + abs(house[i].second - check[j].second);
                    
                    minhouse = min(dist, minhouse);
                }
                total += minhouse;
            }
            ans = min(ans, total);
        }
        return;
    }
    
    check.push_back({chicken[cnt].first, chicken[cnt].second});
    dfs(cnt + 1);
    check.pop_back();
    
    dfs(cnt + 1);
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            
            if(num == 1)
                house.push_back({i, j});
            if(num == 2)
                chicken.push_back({i, j});
        }
    }
    
    dfs(0);
    printf("%d\n", ans);
}
