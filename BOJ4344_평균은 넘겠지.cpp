//
//  main.cpp
//  BOJ4344_평균은 넘겠지
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m, num;
    cin >> n;
    vector<float> re;
    while(n--){
        cin >> m;
        vector<float> v;
        float sum = 0;
        for(int i = 0; i < m; i++){
            cin >> num;
            v.push_back(num);
            sum += num;
        }
        sum = sum/m;
        float count = 0;
        for(int i = 0; i < m; i++){
            if(v[i] > sum)
                count++;
        }
        re.push_back(count/m * 100);
    }
    
    for(int i = 0; i < re.size(); i++)
        printf("%.3f%%\n", re[i]);
}
