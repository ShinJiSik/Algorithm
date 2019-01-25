//
//  main.cpp
//  SWEA_프로세서 연결하기
//
//  Created by 신지식 on 22/11/2018.
//  Copyright © 2018 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int arr[13][13];
bool check[13][13];
int n, connection = 0, ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct core{
    int x, y, visit;
};
vector<core> v;

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
            check[i][j] = false;
        }
    }
}

bool go(int x, int y, int dir, int wire, ){
    
}

void dfs(int idx, int connect, int cnt){
    if(idx == v.size()){
        if(ans > connect)
            ans = connect;
        return;
    }
    
    if(v[idx].visit == 1)
        dfs(idx+1, connect+1, cnt);
    else{
        int nsew = 0;
        for(int i = 0; i < 4; i++){
            int ncnt = 0;
            if (go(v[idx].x, v[idx].y, i, -1, ncnt, 0))
                // ncnt + cnt = 이동한 전선의 길이 + 이동전 전선의 길이
                dfs(idx + 1, connect + 1, ncnt + cnt);
            
            else
                nsew += 1;
            
            //전선 복구
            // ncnt는 이동한 전선의 길이, ncnt만큼 -1을 0으로 바꿔줌
            go(v[idx].x, v[idx].y, i, 1, ncnt, ncnt);
        }
        if(nsew == 4)
            dfs(idx + 1, connect, cnt);
    }
    

    
}

int main(int argc, const char * argv[]) {
    int test_case;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> test_case;
    
    for(int t = 1; t <= test_case; t++){
        cin >> n;
        ans = 987654321;
        connection = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
                if(i != 0 || j != 0 || i != n-1 || j != n-1){
                    v.push_back({i, j, 0});
                }
                else{
                    v.push_back({i, j, 1});
                }
            }
        }
        dfs(0, 0, 0);
        
        cout << "#" << t << " " << ans << "\n";
        init();
        v.clear();
    }
}

#include <iostream>
using namespace std;

typedef struct core {
    int r, c;        // 코어 위치
};
core c[12];          // 확인 할 코어 구조체
int N, M;            // 보드 크기, 확인 할 코어 개수
int map[12][12];     // 보드
int fin_max, res;    // 전원 연결한 최대 코어 개수, 그 때의 전선 길이의 최소값
int dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };    // 이동 방향

// 보드 출력
void printmap(int a[12][12]) {
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << a[i][j];
        cout << endl;
    }
}

// 전선 길이 합산
int cirsum(int cmap[12][12]) {
    int a = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (cmap[i][j] == 2)    a++;
    return a;
}

// 전선 깔기
void solve(int cnum, int cmap[12][12], int fin) {
    // 종료 조건
    if (cnum >= M) {
        // 성공 개수가 최대인 경우
        if (fin > fin_max) {
            fin_max = fin;
            res = cirsum(cmap);
        }
        // 성공 개수가 최대값과 같은 경우
        else if (fin == fin_max) {
            int tmp = cirsum(cmap);
            res = res < tmp ? res : tmp;
        }
        return;
    }
    
    // 4방향 탐색 (시계방향)
    for (int d = 0; d < 4; d++) {
        int nr = c[cnum].r;    // 좌표 초기화
        int nc = c[cnum].c;
        bool ok = true;        // 전원 연결 성공 여부
        int circnt = 0;        // 전선 설치 횟수
        // 선 깔기
        while (1) {
            nr += dir[d][0];
            nc += dir[d][1];
            // 종료 조건
            if (nr<0 || nr>=N || nc<0 || nc>=N)
                break;
            if (cmap[nr][nc] != 0) {
                ok = false;
                break;
            }
            // 전선 설치
            cmap[nr][nc] = 2;
            circnt++;
        }
        // 전선 설치 완료 후 재귀탐색
        if (ok) {
            solve(cnum + 1, cmap, fin + 1);
        }
        // 전선 삭제
        nr = c[cnum].r + dir[d][0];
        nc = c[cnum].c + dir[d][1];
        for (int i = 0; i < circnt; i++, nr += dir[d][0], nc += dir[d][1])
            cmap[nr][nc] = 0;
    }
    // 전원 연결하지 않고 재귀탐색
    solve(cnum + 1, cmap, fin);
}

int main() {
    int T, tc;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        // 변수 초기화 및 지도 입력
        M = 0;
        fin_max = -1;
        res = 1000;
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                // 코어 입력 시
                if (map[i][j] == 1) {
                    // 이미 연결된 코어
                    if (i == 0 || i == N - 1 || j == 0 || j == N - 1)    continue;
                    // 연결되지 않은 코어
                    else {
                        c[M].r = i;
                        c[M].c = j;
                        M++;
                    }
                }
            }
        }
        // 탐색 시작
        solve(0, map, 0);
        cout << "#" << tc << " " << res << endl;
    }
    return 0;
}
