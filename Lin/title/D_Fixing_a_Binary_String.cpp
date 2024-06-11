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
    using ull = unsigned long long;

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

const int P = 13331;
const int N = 2E5 + 6;

int n, k;
string s;
ull target[2];
ull frv[N], rev[N];

ull H(string s) {
    ull res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * P + s[i];
    }
    return res;
}

void doit() {
    mset(frv, 0), mset(rev, 0);
    cin >> n >> k >> s;
    s = '_' + s;
    string ans[2];
    for (int i = 0; i < n / k; i++) {
        ans[0] += string(k, '0' + (i & 1));
        ans[1] += string(k, '0' + ((i & 1) ^ 1));
    }
    target[0] = H(ans[0]);
    target[1] = H(ans[1]);

    ull p = 1;
    for (int i = n; i >= 1; i--) {
        frv[i] = s[i] * p + frv[i + 1];
        p *= P;
    }

    p = 1;
    for (int i = 1; i <= n; i++) {
        rev[i] = s[i] * p + rev[i - 1];
        p *= P;
    }

    p = P;

    for (int i = 1; i <= n; i++) {
        ull now = frv[i + 1] * p + rev[i];
        if (now == target[0] or now == target[1])
            return cout << i << endl, void();
        p *= P;
    }
    puts("-1");
}

int main() {
    READ_ARC = false;
    // optimize();
    int T = 1; cin >> T;
    while (T--) doit();
}





