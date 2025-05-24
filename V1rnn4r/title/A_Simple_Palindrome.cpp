#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    string s = "aeiou", ans;
    int t = n / 5;
    for (int i = 0; i < 5; i++)
        ans += string((t + (i < n % 5)), s[i]);
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}