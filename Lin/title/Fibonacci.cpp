#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
// #include<unordered_map>
#include<algorithm>
#include<numeric>

#define mset(a, t) memset(a, t, sizeof a)

namespace virmar {
    using namespace std;
    // using ll = long long;
    typedef long long ll;

    const int N_ = 100000;

    bool READ_ARC = false;

    // void optimize() {
    //     ios::sync_with_stdio(false);
    //     cin.tie(nullptr);
    // }

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

const int MOD = 10000;

class matrix {
public:
    int a[4][4];

public:
    matrix(bool flag = false) {
        mset(a, 0);
        if (flag) {
            a[1][1] = a[2][2] = 1;
        }
    }

    int* operator[](int i) {return a[i];}
    
    matrix operator*(matrix t) {
        matrix res;
        for (int k = 1; k <= 2; k++)
            for (int i = 1; i <= 2; i++)
                for (int j = 1; j <= 2; j++)
                    res[i][j] = (res[i][j] + (a[i][k] * t[k][j]) % MOD) % MOD;
        return res;
    }

    void display() {
        cout << a[1][1] << ' ' << a[1][2] << endl;
        cout << a[2][1] << ' ' << a[2][2] << endl;
    }
};

matrix base;

matrix qpow(matrix a, int b) {
    matrix res(true);
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int n;

void doit() {
    matrix ans = qpow(base, n);
    cout << ans[1][2] << endl;

}

int main() {
    base[1][1] = 1;
    base[1][2] = 1;
    base[2][1] = 1;
    base[2][2] = 0;
    READ_ARC = false;
    // optimize();
    while (cin >> n, n != -1) doit();
}





