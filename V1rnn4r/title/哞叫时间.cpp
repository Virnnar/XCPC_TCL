#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (auto &i: s) i -= 'a';
    vector<vector<int> > cnt(30, vector<int>(30)), st(30, vector<int>(30, 0));

    auto update = [&](int l, int r, int v) {
        l = max(l, 0), r = min(r, n - 1);
        for (int i = l; i + 2 <= r; i++) {
            char a = s[i], b = s[i + 1], c = s[i + 2];
            if (a != b and b == c) {
                cnt[a][b] += v;
                if (cnt[a][b] >= m) st[a][b] = 1;
            }
        }
    };
    update(0, n - 1, 1);
    for (int i = 0; i < n; i++) {
        char t = s[i];
        update(i - 2, i + 2, -1);
        for (int j = 0; j < 26; j++)
            if (j != t) {
                s[i] = j;
                update(i - 2, i + 2, 1);
                update(i - 2, i + 2, -1);
            }
        s[i] = t;
        update(i - 2, i + 2, 1);
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (st[i][j])
                ans++;
    cout << ans << endl;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (st[i][j])
                cout << (char)('a' + i) << (char)('a' + j) << (char)('a' + j) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}