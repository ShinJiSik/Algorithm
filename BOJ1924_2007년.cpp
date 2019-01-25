//
//  main.cpp
//  BOJ1924_2007년
//
//  Created by 신지식 on 04/12/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.
//첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.
//첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int m, d, cal = 0;
    cin >> m >> d;
    for(int i = 0; i < (m-1); i++)
        cal += month[i];
    cal += d;
    cout << day[cal % 7] << "\n";
    
    int arr[3];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr+3);
    cout << arr[1] << "\n";
   
}
