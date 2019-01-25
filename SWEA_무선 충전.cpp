//
//  main.cpp
//  SWEA_무선 충전
//
//  Created by 신지식 on 2018. 10. 15..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int m, a, apx, apy, apc, app;
int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct ap{
    int x;
    int y;
    int c;
    int p;
};


int diff(int xa, int ya, int xb, int yb){
    return abs(xa - xb) + abs(ya - yb);
}

int main(int argc, const char * argv[]) {
    int test_case;
    
    cin >> test_case;
    
    for(int t = 1; t <= test_case; t++){
        cin >> m >> a;
        
        int usera[110];
        int userb[110];
        usera[0] = 0, userb[0] = 0;
        for(int i = 1; i <= m; i++)
            cin >> usera[i];
        for(int i = 1; i <= m; i++)
            cin >> userb[i];
        
        vector<ap> info;
        for(int i = 0; i < a; i++){
            cin >> apx >> apy >> apc >> app;
            info.push_back({apy, apx, apc, app});
        }
        
        int a_x = 1, a_y = 1;
        int b_x = 10, b_y = 10;
        int ans = 0;
        
        for(int i = 0; i <= m; i++){
            a_x = a_x + dir[usera[i]][0];
            a_y = a_y + dir[usera[i]][1];
            b_x = b_x + dir[userb[i]][0];
            b_y = b_y + dir[userb[i]][1];
            
            vector<int> checkA;
            vector<int> checkB;
            
            for(int j = 0; j < a; j++){
                if(info[j].c >= diff(a_x, a_y, info[j].x, info[j].y))
                    checkA.push_back(j);
                if(info[j].c >= diff(b_x, b_y, info[j].x, info[j].y))
                    checkB.push_back(j);
            }
            
            int charge = 0;
            int len1 = (int)checkA.size();
            int len2 = (int)checkB.size();
            if(len1 == 0){ //B만 충전중
                for(int j = 0; j < len2; j++){
                    int tmp = info[checkB[j]].p;
                    if(tmp > charge)
                        charge = tmp;
                }
            }
            else if(len2 == 0){ //A만 충전중
                for(int j = 0; j < len1; j++){
                    int tmp = info[checkA[j]].p;
                    if(tmp > charge)
                        charge = tmp;
                }
            }
            else{//둘다 충전중
                for(int j = 0; j < len1; j++){
                    for(int k = 0; k < len2; k++){
                        int tmp;
                        if(checkA[j] == checkB[k]){
                            tmp = info[checkA[j]].p;
                        }
                        else{
                            tmp = info[checkA[j]].p + info[checkB[k]].p;
                        }
                        
                        if(tmp > charge)
                            charge = tmp;
                    }
                }
            }
            ans += charge;
        }
        printf("#%d %d\n", t, ans);
    }
}
