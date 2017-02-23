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

const int MAX_N = 1000;
const int MAX_M = 1000;
int n,m;
char s[MAX_N], t[MAX_M];
// dp[x][y]: max substring length between s(x..n) and t(y..m)
int dp[MAX_N][MAX_M];

void solve(){
    dp[n-1][m-1] = s[n-1] == t[m-1] ? 1 : 0;
    if(n > 1){
        dp[n-2][m-1] = 0;
        if(s[n-1] == t[m-1]) dp[n-2][m-1] = 1;
        else if(s[n-2] == t[m-1]) dp[n-2][m-1] = 1;
    }else if(m > 1){
        dp[n-1][m-2] = 0;
        if(s[n-1] == t[m-1]) dp[n-1][m-2] = 1;
        else if(s[n-1] == t[m-2]) dp[n-1][m-2] = 1;
    }
    RREP(i,n){
        RREP(j,m){
            if(s[i] == t[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n; cin >> m;
    REP(i,n) cin >> s[i];
    REP(i,m) cin >> t[i];

    solve();
    cout << dp[0][0] << "\n";
    return 0;
}
