#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
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

const int MAX_N = 10000;
int N;
int L, P;
int A[MAX_N + 1];
int B[MAX_N + 1];

int solve() {
    int ans = 0, pos = 0, tank = P;
    int i = 0;
    priority_queue<int> pq;
    A[N] = L;
    B[N] = 0;

    while(pos < L){
        while(tank < A[i] - pos){
            if(pq.empty()) return -1;
            tank += pq.top();
            pq.pop();
            ans++;
        }
        tank -= A[i] - pos;
        pos = A[i];
        pq.push(B[i]);
        i++;
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> L; cin >> P;
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    cout << solve() << "\n";
    return 0;
}

