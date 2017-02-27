#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>

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

const int MAX_N = 100;
const int MAX_K = 100000;
int n;
int a[MAX_N], m[MAX_N];
int K;
// dp[x+1][y]: int; max number of items(index x) to remain when to create y until the item(index x)
// if impossible, -1
int dp[MAX_N+1][MAX_K+1];

bool solve(){
    fill(dp[0], dp[0] + (MAX_N + 1) * (MAX_K + 1), -1);
    dp[0][0] = 0;
    REPS(i,n) dp[i][0] = m[i-1];
    REP(i, n){
        REP(j, K+1){
            if(dp[i][j] >= 0){
                dp[i+1][j] = m[i];
            }else if(j - a[i] < 0 || dp[i+1][j-a[i]] <= 0){
                dp[i+1][j] = -1;
            }else{
                dp[i+1][j] = dp[i+1][j-a[i]] - 1;
            }
        }
    }
    return dp[n][K] >= 0;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> m[i];
    cin >> K;
    cout << (solve() ? "Yes" : "No") << "\n";
    return 0;
}
