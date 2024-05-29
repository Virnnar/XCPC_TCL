#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>

#define mset(a, t) memset(a, t, sizeof a)

namespace virmar {
    using namespace std;
    using ll = long long;

    const int N_ = 1000000;

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
    inline T read(int arg = 0) {
        T x = 0, f = 1;
        char c = getc(arg);
        while (!isdigit(c)) {if (c == '-') f = -1; c = getc(arg);}
        while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getc(arg);
        return x * f;
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

const int N = 1E6 + 6;

int n, m, pos;
int a[N], ans[N];
int v[N];
BinaryIndexedTree BIT;

struct query{
    int l, r, id;
    bool operator<(struct query t) {
        return r < t.r;
    }
} Q[N];

void doit() {
    mset(v, 0);
    n = read<int>();
    for (int i = 1; i <= n; i++) a[i] = read<int>();
    m = read<int>();
    for (int i = 1; i <= m; i++) Q[i] = {read<int>(), read<int>(), i};

    sort(Q + 1, Q + m + 1);

    BIT.init(n);

    pos = 1;
    for (int i = 1; i <= m; i++) {
        while (pos <= Q[i].r) {
            if (v[a[pos]]) BIT.add(v[a[pos]], -1);
            v[a[pos]] = pos;
            BIT.add(pos, 1);
            pos++;
        }
        ans[Q[i].id] = BIT.get(Q[i].r) - BIT.get(Q[i].l - 1);
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;

    // cout << n << endl;
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << endl << m << endl;
    // for (int i = 1; i <= m; i++)
    //     cout << Q[i].l << ' ' << Q[i].r << ' ' << Q[i].id << endl;
}

int main() {
    READ_ARC = true;
    // optimize();
    int T = 1; // cin >> T;
    while (T--) doit();
}





