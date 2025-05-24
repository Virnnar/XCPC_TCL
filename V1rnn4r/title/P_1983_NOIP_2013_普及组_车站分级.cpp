#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<numeric>

#define mset(a, t) memset(a, t, sizeof a)

namespace virmar {
    using namespace std;
    using ll = long long;

    const int N_ = 100000;

    bool READ_ARC = false;

    void optimize() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    char buf[1<<21],*p1=buf,*p2=buf;
    inline int getc(int arg = READ_ARC){
        if (arg == false) return getchar();
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
    }

    template<typename T>
    inline T read(int arg = READ_ARC) {
        T x = 0, f = 1;
        char c = getc(arg);
        while (!isdigit(c)) {if (c == '-') f = -1; c = getc(arg);}
        while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getc(arg);
        return x * f;
    }

    template<typename T>
    inline T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    template<typename T>
    inline T lcm(T a, T b) {
        return a * b / gcd<T>(a, b);
    }

    class BinaryIndexedTree{
    public:
        int n;
        int tr[N_];

    public:
        void init(int n) {
            this -> n = n;
            mset(tr, 0);
        }

        int lowbit(int x) {return x & -x;}

        void add(int p, int x) {
            for (int i = p; i <= n; i += lowbit(i))
                tr[i] += x;
        }

        int get(int p) {
            int res = 0;
            for (int i = p; i; i -= lowbit(i))
                res += tr[i];
            return res;
        }
    };
}

using namespace virmar;

const int N = 1E3 + 6, M = 1E6 + 7;

struct {int next, to;} e[M];
int head[N], num;
int in_deg[N];

void add(int from, int to) {
    e[num] = {head[from], to};
    head[from] = num++;
    in_deg[to]++;
}

int n, m;
bool v[N];
int lev[N];
bool jud[N][N];

void dfs(int now) {
    for (int i = head[now]; ~i; i = e[i].next) {
        int to = e[i].to;
        lev[to] = max(lev[to], lev[now] + 1);
        in_deg[to]--;
        if (in_deg[to] == 0) dfs(to);
    }
}

void doit() {
    mset(head, -1), num = 0;
    mset(jud, false);
    n = read<int>(), m = read<int>();
    for (int i = 1; i <= m; i++) {
        vector<int> a;
        for (int j = 1; j <= n; j++) v[j] = false;
        int s = read<int>();
        for (int j = 1; j <= s; j++) {
            int t = read<int>();
            a.push_back(t);
            v[t] = true;
        }
        for (int j = a.front(); j <= a.back(); j++)
            if (v[j] == false) {
                for (auto to: a) {
                    if (jud[j][to]) continue;
                    jud[j][to] = true;
                    add(j, to);
                }
            }
    }
    for (int i = 1; i <= n; i++)
        if (in_deg[i] == 0) lev[i] = 1, dfs(i);
    cout << *max_element(lev + 1, lev + n + 1) << endl;
}

int main() {
    READ_ARC = true;
    optimize();
    int T = 1;// cin >> T;
    while (T--) doit();
}




