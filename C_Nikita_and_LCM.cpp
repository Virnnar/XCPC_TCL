#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<iomanip>

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

int jud(vector<pair<int, int> > &a, int d) {
    ll LCM = 0, res = 0;
    for (auto [u, v]: a)
        if (d % u == 0) {
            if (LCM == 0) LCM = u;
            else LCM = lcm<ll>(LCM, u);
            res += v;
        }
    if (LCM != d) res = 0;
    return res;
}

void doit() {
    int n = read<int>();
    vector<int> a(n);
    for (auto &t: a) cin >> t;
    map<int, int> unique_element;
    for (auto t: a) unique_element[t]++;
    vector<pair<int, int> > b;
    for (auto t: unique_element)
        b.push_back(t);

    int max_val = *max_element(a.begin(), a.end());
    ll LCM = 1;
    for (auto [u, v]: b) {
        LCM = lcm<ll>(LCM, u);
        if (LCM > max_val) return cout << n << endl, void();
    }

    int ans = 0;
    for (int i = 1; i * i <= LCM; i++) {
        if (LCM % i == 0) {
            if (!unique_element.count(i))
                ans = max(ans, jud(b, i));
            if (!unique_element.count(LCM / i))
                ans = max(ans, jud(b, LCM / i));
        }
    }
    cout << ans << endl;

}

int main() {
    READ_ARC = false;
    // optimize();
    int T = 1; cin >> T;
    while (T--) doit();
}





