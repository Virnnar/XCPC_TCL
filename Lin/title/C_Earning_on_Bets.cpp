#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
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

bool check(vector<ll> &a, vector<ll> &b, ll x, ll max_val) {
    int n = a.size();
    for(int i = 0; i < n; i ++ )
        b[i] = x * max_val / a[i];
    ll sum = 0;
    for(int i = 0; i < n; i ++ ) sum += b[i];
    for(int i = 0; i < n; i ++ )
        if(a[i] * b[i] <= sum)
            return false;
    return true;
}

void doit() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i;

    ll max_val = *max_element(a.begin(), a.end());

    ll l = 1, r = 1E9;
    while(l < r) {
        ll mid = l + r >> 1;
        if(check(a, b, mid, max_val)) r = mid;
        else l = mid + 1;
    }

    if(!check(a, b, l, max_val)) return puts("-1"), void();


    for(auto i: b) cout << i << ' ';
        cout << endl;
}

int main() {
    READ_ARC = false;
    // optimize();
    int T = 1; cin >> T;
    while (T--) doit();
}





