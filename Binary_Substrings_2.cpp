#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    string s; cin >> s;
    reverse(all(s));
    s = '_' + s;
    for (int i = 1; i < s.size(); i++)
        s[i] -= '0';
    auto nxt = [&](string t) -> string {
        string res = "_1"; res[1] -= '0';
        for (int i = 1; i < t.size(); i++) {
            if (!t[i]) continue;
            for (int j = 1; j < res.size(); j++) res[j] *=  t[i];
            for (int j = 1; j < res.size() - 1; j++) res[j + 1] += res[j] / 10, res[j] %= 10;
            while (res[res.size() - 1] >= 10) {
                char c = res[res.size() - 1] / 10;
                res[res.size() - 1] %= 10;
                res += string(1, c);
            }
        }
        return res;
    };
    do {
        s = nxt(s);
        for (int i = s.size() - 1; i >= 1; i--) {
            cout << (int)s[i];
        }
        cout << endl;
    } while(s.size() > 2);
}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; // cin >> T;
    while (T --> 0) doit();
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

void init() {
    // freopen("Root.in", "r", stdin);
    // freopen("Root.out", "w", stdout);
}