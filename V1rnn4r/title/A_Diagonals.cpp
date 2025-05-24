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

    const int N_BIT = 500006, N_MTX = 100;
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
        matrix(int n = 0, int m = 0, int mod = 1000) {
            this -> n = n;
            this -> m = m;
            this -> mod = mod;
        }

        int* operator[](int i) {return a[i];}

        matrix operator*(matrix t) {
            matrix res(n, t.m, mod);
            for (int k = 1; k <= m; k++)
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= t.m; j++)
                        res[i][j] = (res[i][j] + (a[i][k] * t[k][j]) % mod) % mod;
            return res;
        }

        matrix operator+(matrix t) {
            matrix res(n, t.m, mod);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    res[i][j] = (a[i][j] + t[i][j]) % mod;
            return res;
        }
    };

    template<typename T>
    class BinaryIndexedTree{
    public:
        int n;
        T tr[N_BIT];

    public:
        void init(int n) {
            this -> n = n;
            mset(tr, 0);
        }

        int lowbit(int x) {return x & -x;}

        void add(int p, T x) {
            for (int i = p; i <= n; i += lowbit(i))
                tr[i] += x;
        }

        T get(int p) {
            T res = 0;
            for (int i = p; i; i -= lowbit(i))
                res += tr[i];
            return res;
        }
    };
}

using namespace virmar;

void doit() {
    int n, k; cin >> n >> k;
    if (k == 0) return puts("0"), void();
    if (k <= n) return puts("1"), void();
    ll now = n, cnt = 1;
    for (int i = n - 1; i >= 1; i--) {
        now += i, cnt++;
        if (k <= now) return cout << cnt << endl, void();
        now += i, cnt++;
        if (k <= now) return cout << cnt << endl, void();
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}