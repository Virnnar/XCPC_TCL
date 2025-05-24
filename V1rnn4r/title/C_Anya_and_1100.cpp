#include "Monday.h"

using namespace virmar;

void doit() {
    string s; cin >> s; s = '_' + s;
    int n = s.size() - 1, m; cin >> m;
    vector<int> a(n + 1);


    function<bool(int)> jud = [&](int p) -> bool{
        if (p < 1 or p > n - 3) return false;
        if (s.substr(p, 4) == "1100") return true;
        return false;
    };

    int cnt = 0;
    for (int i = 1; i <= n - 3; i++)
        if (jud(i)) cnt++, a[i] = 1;

    while (m--) {
        int p, v; cin >> p >> v;
        s[p] = v + '0';
        for (int i = max(1, p - 3); i <= min(n - 3, p + 3); i++) {
            bool t = jud(i);
            if (t and a[i] == 0) cnt++, a[i] = 1;
            if (t == 0 and a[i]) cnt--, a[i] = 0;
        }
        puts(cnt ? "YES" : "NO");
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}