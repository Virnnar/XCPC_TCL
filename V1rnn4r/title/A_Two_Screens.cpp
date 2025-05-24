#include "Monday.h"

using namespace virmar;

const int N = 200;

void doit() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int p = 0;
    while (p < min(n, m)) {
        if (s[p] != t[p]) break;
        p++;
    }
    cout << n + m - max(p - 1, 0) << endl;
    // cout << f[n][m] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}