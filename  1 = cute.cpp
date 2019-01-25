//
//  main.cpp
//   1 = cute
//
//  Created by 신지식 on 20/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int num, cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num == 1)
            cnt++;
    }
    if(cnt > n - cnt)
        cout << "Junhee is cute!" << "\n";
    else
        cout << "Junhee is not cute!" << "\n";
}
