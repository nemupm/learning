#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int INF = 100000;

typedef pair<int, int> P;

int n,m;
char maze[100][100];
int sx,sy; // start
int gx,gy; // goal
int d[100][100]; // distance

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<P> q;

    REP(i,100){
        REP(j,100){
            d[i][j] = INF;
        }
    }
    q.push(P(sx,sy));
    d[sx][sy] = 0;

    while(q.size() > 0){
        P p = q.front();
        q.pop();
        if(p.first == gx && p.second == gy) break;
        REP(i,4)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m
                && maze[nx][ny] != '#' && d[nx][ny] == INF){
                d[nx][ny] = d[p.first][p.second] + 1;
                q.push(P(nx,ny));
                eprintf("%d,%d:%d\n",nx,ny,d[nx][ny]);
            }
        }
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> m;
    REP(i,n){
        REP(j,m){
            cin >> maze[i][j];
            if (maze[i][j] == 'S'){
                sx = i; sy = j;
            }else if(maze[i][j] == 'G'){
                gx = i; gy = j;
            }
        }
    }
    bfs();
    cout << d[gx][gy] << "\n";
    return 0;
}
