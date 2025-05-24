#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<ll, vector<ll> > H;
    for (int i = 2; i <= n; i++) {
        ll u = a[i] + i - 1;
        ll v = u + i - 1;
        H[u].push_back(v);
    }
    set<ll> v;
    function<void(ll)> dfs = [&](ll u) -> void {
        if (v.count(u)) return;
        v.insert(u);
        for (ll v : H[u]) dfs(v);
    };
    dfs(n);
    cout << *v.rbegin() << "\n";
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}