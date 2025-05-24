#include "Monday.h"

using namespace virmar;

void doit() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), p(n), d(n, 0);
    for (auto &i: a) cin >> i, i--;
    for (int i = 0; i < n; i++) p[a[i]] = i;
    for (int i = 0; i < n; i++) {
        d[min(i, p[i])]++;
        d[max(i, p[i])]--;
    }
    for (int i = 1; i < n; i++) d[i] += d[i - 1];

    string s; cin >> s;
    set<int> H;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == 'L' and s[i + 1] == 'R' and d[i])
            H.insert(i);
    

    while (q--) {
        int x; cin >> x; x--;
        if (s[x] == 'L') s[x] = 'R';
        else s[x] = 'L';

        if (s[x - 1] == 'L' and s[x] == 'R' and d[x - 1]) H.insert(x - 1);
        else H.erase(x - 1);

        if (s[x] == 'L' and s[x + 1] == 'R' and d[x]) H.insert(x);
        else H.erase(x);

        if (H.size()) puts("NO");
        else puts("YES");
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}