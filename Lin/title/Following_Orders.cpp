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

const int N = 30, M = N << 1;

struct {int next, to;} e[M];
int head[N], num;

void add(int from, int to) {
    e[num] = {head[from], to};
    head[from] = num++;
}

int n;
string s;
int in_degree[N];
vector<int> a;
int topo[N];
bool v[N];

void dfs(int now, int cnt) {
    topo[cnt] = now;
    if (cnt == n) {
        for (int i = 1; i <= n; i++) cout << (char)(topo[i] + 'a');
        puts("");
        return;
    }
    v[now] = true;
    for (int i = head[now]; ~i; i = e[i].next) {
        int to = e[i].to;
        if (v[to]) continue;
        in_degree[to]--;
    }
    for (int i = 0; i < a.size(); i++)
        if (!in_degree[a[i]] and !v[a[i]])
            dfs(a[i], cnt + 1);
    for (int i = head[now]; ~i; i = e[i].next) {
        int to = e[i].to;
        if (v[to]) continue;
        in_degree[to]++;
    }
    v[now] = false;
}

void doit() {
    mset(head, -1), num = 0;
    mset(in_degree, 0);
    mset(v, false);

    string t;
    getline(cin, t);

    while (a.size()) a.pop_back();
    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))
            a.push_back(s[i] - 'a');
    sort(a.begin(), a.end());
    n = a.size();

    for (int i = 0; i < t.size(); i++)
        if (isalpha(t[i])) {
            int j = i + 1;
            while (!isalpha(t[j])) j++;
            // cout << t[i] << ' ' << t[j] << endl;
            add(t[i] - 'a', t[j] - 'a');
            in_degree[t[j] - 'a']++;
            i = j;
        }
    for (int i = 0; i < a.size(); i++)
        if (in_degree[a[i]] == 0) {
            // cout << i << ' ';
            dfs(a[i], 1);
        }
    puts("");
}

int main() {
    READ_ARC = false;
    // optimize();
    // int T = 1; cin >> T;
    while (getline(cin, s)) doit();
}





