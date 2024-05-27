#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<numeric>
#include<algorithm>

#define mset(a, t) memset(a, t, sizeof a)

using namespace std;
using ll = long long;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
    return x * f;
}

void doit() {
    
}

int main() {
    // cin.tie(0) -> sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

