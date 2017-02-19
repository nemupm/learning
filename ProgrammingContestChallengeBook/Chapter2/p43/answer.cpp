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

const int MAX_N = 100000;
int n;
int s[MAX_N], t[MAX_N];
pair<int, int> itv[MAX_N];

int solve(){
    REP(i,n){
        eprintf("%d,%d\n",t[i],s[i]);
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv, itv + n);
    int ans = 0;
    int currentTime = -1;
    REP(i,n){
        int startTime = itv[i].second;
        int endTime = itv[i].first;
        eprintf("%d,%d\n",startTime,endTime);
        if (currentTime < startTime)
        {
            ans++;
            currentTime = endTime;
        }
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> s[i];
    REP(i,n) cin >> t[i];
    cout << solve() << "\n";
    return 0;
}
