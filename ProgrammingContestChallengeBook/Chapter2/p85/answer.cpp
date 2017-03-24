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

int N;
int K;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

int solve() {
    int ans = 0;
    int type;
    int x, y;
    // 1A: the case that animal 1 is A.
    // 3*N: 1A, 2A, ..., NA, 1B, 2B, ..., NB, 1C, 2C, ..., NC
    UnionFind uf = UnionFind(3*N);
    REP(i, K){
        cin >> type;
        cin >> x; cin >> y;
        if(type == 1){
            if(uf.findSet(x, y + N) || uf.findSet(x, y + 2 * N)){
                // incorrect information
                eprintf("%dth information is incorrect.\n",i+1);
                ans++;
                continue;
            }
            uf.unionSet(x, y);
            uf.unionSet(x + N, y + N);
            uf.unionSet(x + 2 * N, y + 2 * N);
        }else{
            if(uf.findSet(x, y) || uf.findSet(x, y + 2 * N)){
                // incorrect information
                eprintf("%dth information is incorrect.\n",i+1);
                ans++;
                continue;
            }
            uf.unionSet(x, y + N);
            uf.unionSet(x + N, y + 2 * N);
            uf.unionSet(x + 2 * N, y);
        }
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N; cin >> K;
    cout << solve() << "\n";
    return 0;
}

