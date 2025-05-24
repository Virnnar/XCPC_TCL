#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;

    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        string s; cin >> s;
        if (s.size() != n) {
            puts("NO");
            continue;
        }
        bool jud = true;
        map<int, char> H;
        map<char, int> P;
        for (int j = 0; j < n; j++) {
            if (H.count(a[j]) == 0) H[a[j]] = s[j];
            else if (s[j] != H[a[j]]) {jud = false; break;}
            if (P.count(s[j]) == 0) P[s[j]] = a[j];
            else if (a[j] != P[s[j]]) {jud = false; break;}
        }
        puts(jud ? "YES" : "NO");
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}