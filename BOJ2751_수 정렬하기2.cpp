//
//  main.cpp
//  BOJ2751_수 정렬하기2
//
//  Created by 신지식 on 03/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.



#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}
