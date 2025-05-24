#include "Monday.h"

using namespace virmar;

void doit() {
    string s; cin >> s;
    if (s.substr(0, 2) != "10" or s[2] == '0') return puts("NO"), void();
    int t = 0;
    for (int i = 2; i < s.size(); i++) t = t * 10 + s[i] - '0';
    puts(t >= 2 ? "YES" : "NO");
    // puts("YES");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}