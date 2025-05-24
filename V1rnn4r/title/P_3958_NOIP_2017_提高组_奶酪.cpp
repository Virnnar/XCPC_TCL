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

    const int N_BIT = 100000, N_MTX = 100;
    const int INF = 0X3F3F3F3F;

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

    ll qpow(ll a, ll b, ll p = 1 << 31) {
        ll res = 1 % p;
        while (b) {
            if (b & 1) res = (res * a) % p;
            a = (a * a) % p;
            b >>= 1;
        }
        return res;
    }

    template<typename T>
    inline T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    template<typename T>
    inline T lcm(T a, T b) {
        return a * b / gcd<T>(a, b);
    }

    class matrix {
    public:
        int n, m;
        int mod;
        int a[virmar::N_MTX][virmar::N_MTX];

    public:
        matrix(int flag = 0) {
            mset(a, 0);
            if (flag) {
                n = m = flag;
                for (int i = 1; i <= flag; i++) a[i][i] = 1;
            }
            mod = 1 << 31;
        }

        int* operator[](int i) {return a[i];}

        matrix operator*(matrix t) {
            matrix res;
            res.n = n, res.m = t.m;
            res.mod = mod;
            for (int k = 1; k <= m; k++)
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= t.m; j++)
                        res[i][j] = (res[i][j] + (a[i][k] * t[k][j]) % mod) % mod;
            return res;
        }

        matrix operator+(matrix t) {
            matrix res;
            res.n = n, res.m = t.m;
            res.mod = mod;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    res[i][j] = (a[i][j] + t[i][j]) % m;
            return res;
        }
    };

    class BinaryIndexedTree{
    public:
        int n;
        int tr[N_BIT];

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

const int N = 1E3 + 6;

ll n, h, r;

int f[N];

int find(int x) {
    if (x == f[x]) return x;
    int root = find(f[x]);
    return f[x] = root;
}

class node {
public:
    ll x, y, z;
public:
    node(ll x = 0, ll y = 0, ll z = 0):x(x), y(y), z(z) {}
}a[N];

bool jud(node p, node q) {
    ll d2 = (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) + (p.z - q.z) * (p.z - q.z);
    ll r2 = 2 * 2 * r * r;
    return d2 <= r2;
}

ll max_val[N], min_val[N];

void doit() {
    cin >> n >> h >> r;
    for (int i = 1; i <= n; i++) f[i] = i;
    mset(min_val, INF), mset(max_val, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        for (int j = 1; j < i; j++)
            if (jud(a[i], a[j])) {
                int fi = find(i), fj = find(j);
                if (fi == fj) continue;
                f[fi] = fj;
            }
    }
    for (int i = 1; i <= n; i++) {
        int t = find(i);
        max_val[t] = max(max_val[t], a[i].z + r);
        min_val[t] = min(min_val[t], a[i].z - r);
    }
    for (int i = 1; i <= n; i++)
        if (max_val[i] >= h and min_val[i] <= 0) return puts("Yes"), void();
    puts("No");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}