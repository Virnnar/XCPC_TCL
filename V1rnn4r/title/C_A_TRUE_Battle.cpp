#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    string s; cin >> s;
    for (auto &i: s) i -= '0';
    if (s[0] || s[n - 1]) return puts("YES"), void();
    for (int i = 1; i < n; i++)
        if (s[i] && s[i - 1]) return puts("YES"), void();
    puts("NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

// 101010   111111








