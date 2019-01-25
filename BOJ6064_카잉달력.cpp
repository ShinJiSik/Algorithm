//
//  main.cpp
//  BOJ6064_카잉달력
//
//  Created by 신지식 on 2018. 10. 5..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int m, n, x, y, tmp;
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    
    while(t--){
        cin >> m >> n >> x >> y;
        
        for(int i = x ;; i += m){
            if(i % n == 0)
                tmp = n;
            else
                tmp = i % n;
            if(tmp == y){
                printf("%d\n", i);
                break;
            }
            if(n * m < i){
                printf("-1\n");
                break;
            }
        }
    }
}
