//
//  main.cpp
//  Samsung_MountainRoute
//
//  Created by 신지식 on 2018. 9. 8..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int t, n, k;
int arr[9][9];
bool check[9][9];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt;
int ans = 0;
void dfs(int x, int y, int cnt, int count){
    ans = max(ans, cnt);
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && check[nx][ny] == false){
            if(arr[x][y] > arr[nx][ny]){
                check[nx][ny] = true;
                dfs(nx, ny, cnt+1, count);
                check[nx][ny] = false;
            }
            else if(arr[x][y] <= arr[nx][ny] && arr[nx][ny] - k < arr[x][y] && count == 1){
                check[nx][ny] = true;
                int tmp = arr[nx][ny];
                arr[nx][ny] = arr[x][y] - 1;
                dfs(nx, ny, cnt+1, 0);
                arr[nx][ny] = tmp;
                check[nx][ny] = false;
            }
        }
    }
}

int main(){
    cin >> t;
    
    for(int a = 1; a <= t; a++){
        cin >> n >> k;
        
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
                if(arr[i][j] > max)
                    max = arr[i][j];
            }
        }
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == max){
                    check[i][j] = true;
                    dfs(i, j, 1, 1);
                    check[i][j] = false;
                }
            }
        }
        
        printf("#%d %d\n", a, ans);
    }
}

/*
#include<iostream>
#include<algorithm>
using namespace std;


int T;          // 테스트 케이스 수
int N, K;       // N : 한 변의 길이 , K : 최대 공사 가능 깊이
int map[9][9];  // 맵 저장 2차원 배열
int max_length; // 가장 긴 등산로
int max_height; // 가장 높은 봉우리
int chk[9][9];  // 중복 확인용 배열
int dir_y[4] = {-1,0,1,0};  // 12시 부터 시계 방향
int dir_x[4] = {0,1,0,-1};

void engine(int n,int y,int x,int can)
{
    int here_y = y;     // 현재 y좌표
    int here_x = x;     // 다음 x좌표
    int can_dig = can;  // 깍기 가능 (1이면 가능 , 0이면 불가)
    max_length = max(max_length, n);
    for (int i = 0; i < 4; i++)     // 4방향 돌기
    {
        int next_y = here_y + dir_y[i];
        int next_x = here_x + dir_x[i];
        if (next_y < 1 || next_x < 1 || next_y > N || next_x > N) continue; // 범위를 벗어나면 제외
        if (map[here_y][here_x] > map[next_y][next_x] && !chk[next_y][next_x]) // 낮은 높이로 이동
        {
            chk[next_y][next_x] = 1;
            engine(n + 1 , next_y, next_x, can_dig);
            chk[next_y][next_x] = 0;
        }
        else if (map[here_y][here_x] <= map[next_y][next_x] && map[here_y][here_x] > map[next_y][next_x] - K && !chk[next_y][next_x] && can_dig)    // 갈려고 하는 곳이 높지만, 땅을 파서 가능한 경우
        {
            int tmp = map[next_y][next_x];
            chk[next_y][next_x] = 1;
            map[next_y][next_x] = map[here_y][here_x] - 1;      // 지형을 깍을 때 무조건 K만큼 깍을 필요가 없음
            engine(n + 1 , next_y, next_x, 0);
            map[next_y][next_x] = tmp;                          // 지형 깍기전으로 되돌리기
            chk[next_y][next_x] = 0;
        }
    }
}
void input()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        max_height = 0;
        max_length = 0;
        cin >> N >> K;
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                cin >> map[j][k];
                max_height = max(max_height, map[j][k]);    // 가장 높은 봉우리 저장
                //chk[j][k] = 0;        // 체크 배열 초기화
            }
        }
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (map[j][k] == max_height)
                {
                    chk[j][k] = 1;
                    engine(1, j, k, 1);
                    chk[j][k] = 0;
                }
            }
        }
        
        cout << '#' << i << ' ' << max_length << '\n';
    }
}

int main()
{
    input();
    
    return 0;
}
*/

