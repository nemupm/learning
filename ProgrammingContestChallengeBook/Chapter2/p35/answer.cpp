#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

using namespace std;

int n,m;
char map[100][100] = {'.'};
int answer = 0;

void fill(int x,int y){
    map[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx;
            int ny = y + dy;
            if(0 <= nx && nx < n && 0 <= ny && ny < m
                && map[nx][ny] == 'W'){
                fill(nx,ny);
            }

        }
    }
    return;
}

int main() {
    // to shorten time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> m;
    REP(i,n){
        REP(j,m){
            cin >> map[i][j];
        }
    }

    REP(i,n){
        REP(j,m){
            if(map[i][j] == 'W'){
                answer++;
                fill(i,j);
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
