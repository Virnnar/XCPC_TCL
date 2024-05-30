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

    const int N_ = 200017;

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

const int N = 2E5 + 6;

int n, m;
ll a[N], b[N];
ll sa[N], sb[N], smax[N];
BinaryIndexedTree BIT_n, BIT_m;

inline void del(int i) {
    if (a[i] > b[i]) BIT_n.add(i, -1);
    else BIT_m.add(i, -1);
}

inline void reset(int i) {
    if (a[i] > b[i]) BIT_n.add(i, 1);
    else BIT_m.add(i, 1);
}

inline int get_pos(bool &flag) {
    int l1 = 1, r1 = n + m + 1;
    while (l1 < r1) {
        int mid = (l1 + r1 + 1) >> 1;
        if (BIT_n.get(mid) <= n) l1 = mid;
        else r1 = mid - 1;
    }

    int l2 = 1, r2 = n + m + 1;
    while (l2 < r2) {
        int mid = (l2 + r2 + 1) >> 1;
        if (BIT_m.get(mid) <= m) l2 = mid;
        else r2 = mid - 1;
    }
    flag = l1 > l2; // true
    return min(l1, l2);
}

void doit() {
    n = read<int>(), m = read<int>();
    BIT_n.init(n + m + 10);
    BIT_m.init(n + m + 10);
    for (int i = 1; i <= n + m + 1; i++) a[i] = read<ll>();
    for (int i = 1; i <= n + m + 1; i++) b[i] = read<ll>();
    for (int i = 1; i <= n + m + 1; i++) {
        smax[i] = max(a[i], b[i]) + smax[i - 1];
        sa[i] = a[i] + sa[i - 1];
        sb[i] = b[i] + sb[i - 1];
        if (a[i] > b[i]) BIT_n.add(i, 1);
        else BIT_m.add(i, 1);
    }

    if (n == 0) {
        ll ans = sb[n + m + 1];
        for (int i = 1; i <= n + m + 1; i++) {
            cout << ans - b[i] << ' ';
        }
        cout << endl;
        return;
    }

    if (m == 0) {
        ll ans = sa[n + m + 1];
        for (int i = 1; i <= n + m + 1; i++) {
            cout << ans - a[i] << ' ';
        }
        cout << endl;
        return;
    }


    for (int i = 1; i <= n + m + 1; i++) {
        del(i);
        bool jud;
        int pos = get_pos(jud);

        ll ans = smax[pos];
        if (i <= pos) ans -= max(a[i], b[i]);
        if (jud) {
            ans += sa[n + m + 1] - sa[pos];
            if (i > pos) ans -= a[i];
        }
        else {
            ans += sb[n + m + 1] - sb[pos];
            if (i > pos) ans -= b[i];
        }
        cout << ans << ' ';
        reset(i);
    }
    cout << endl;
}

int main() {
    READ_ARC = false;
    // optimize();
    int T = 1; cin >> T;
    while (T--) doit();
}





