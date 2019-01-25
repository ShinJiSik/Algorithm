//
//  main.cpp
//  Samsung_UsingPool
//
//  Created by 신지식 on 2018. 9. 19..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int fee[4]; //비용
int use[13]; //사용 일 수
int cal[13]; //비용 계산
void pool(int month){
    
    if(fee[0] * use[month] > fee[1])
        cal[month] = cal[month - 1] + fee[1];
    else
        cal[month] = cal[month - 1] + fee[0] * use[month];
    
    if(month >= 3){
        if(cal[month - 3] + fee[2] < cal[month])
            cal[month] = cal[month - 3] + fee[2];
    }
    
    if(month == 12){
        if(cal[month] > fee[3])
            cal[month] = fee[3];
        
        return;
    }
    
    pool(month + 1);
}

int main(){
    int t;
    
    cin >> t;
    
    for(int a = 1; a <= t; a++){
        fee[0] = 0; use[0] = 0;
        for(int i = 0; i < 4; i++){
            cin >> fee[i];
        }
        for(int i = 1; i <= 12; i++){
            cin >> use[i];
            cal[i] = 0;
        }
        pool(1);
        
        cout << "#" << a << " " << cal[12] << "\n";
    }
    
}
