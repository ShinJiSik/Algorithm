//
//  main.cpp
//  BOJ14226_이모티콘
//
//  Created by 신지식 on 2018. 10. 2..
//  Copyright © 2018년 Shin Ji Sik. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int s;
int emoj[2001][2001];

int main(int argc, const char * argv[]) {
    cin >> s;
    
    memset(emoj, -1, sizeof(emoj));
    queue<pair<int, int>> q;
    q.push(make_pair(1,0));
    emoj[1][0] = 0;
    
    while(!q.empty()){
        int smile = q.front().first;
        int clip = q.front().second;
        q.pop();
        if(smile == s){
            printf("%d\n", emoj[smile][clip]);
            return 0;
        }
        if(emoj[smile][smile] == -1){
            q.push(make_pair(smile, smile));
            emoj[smile][smile] = emoj[smile][clip] + 1;
        }
        if(smile + clip < 2000 && emoj[smile+clip][clip] == -1){
            q.push(make_pair(smile+clip, clip));
            emoj[smile+clip][clip] = emoj[smile][clip] + 1;
        }
        if(smile - 1 && emoj[smile-1][clip] == -1){
            q.push(make_pair(smile-1, clip));
            emoj[smile-1][clip] = emoj[smile][clip] + 1;
        }
    }
}
