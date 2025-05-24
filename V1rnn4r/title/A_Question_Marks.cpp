#include "Monday.h"

using namespace virmar;

void doit() {
    int n; string s; cin >> n >> s;
    int a[4] = {0};
    for (auto i: s) if (i != '?') a[i - 'A'] = min(n, a[i - 'A'] + 1);
    int ans = 0;
    for (auto i: a) ans += i;
    // cout << endl;
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}