#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<unordered_map>

#define mset(a, t) memset(a, t, sizeof a)

namespace virmar {
    using namespace std;
    using ll = long long;

    const int N_ = 100000;
    bool READ_ARG = false;

    void optimize() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    char buf[1<<21],*p1=buf,*p2=buf;
    inline int getc(bool arg = 0){
        if (arg == false) return getchar();
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
    }

    template<typename T>
    inline T read(int arg = READ_ARG) {
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

void doit() {
    ll a = read<ll>(), b = read<ll>();
    cout << a + b << endl;
}

int main() {
    virmar::READ_ARG = true;
    // optimize();
    int T = 1;// cin >> T;
    while (T--) doit();
}





