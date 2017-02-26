#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

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
const int MAX_V = 100;
const int MAX_W = 10000000;
const int MAX_N = 100;
const int INF = MAX_W * MAX_N + 1;
int n;
int w[MAX_N], v[MAX_N];
int W;
// dp[x][y]: the minumum weights of items on condition that the index of the items is less than x - 1 and total value is y
int dp[MAX_N][MAX_V * MAX_N + 1];

int solve(){
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    REP(i,n){
        REP(j,MAX_V * MAX_N + 1){
            if(j-v[i] < 0){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
            if(dp[i+1][j] < INF) eprintf("%d\n",dp[i+1][j]);
        }
    }
    int answer = 0;
    REP(j,MAX_V * MAX_N + 1){
        if(dp[n][j] <= W){
            answer = j;
            eprintf("dp[n][j]=%d,W=%d,j=%d\n",dp[n][j],W,j);
        }
    }
    return answer;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    REP(i,n) cin >> w[i];
    REP(i,n) cin >> v[i];
    cin >> W;

    cout << solve() << "\n";
    return 0;
}
