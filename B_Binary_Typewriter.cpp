#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    string s; cin >> s;
    s = '0' + s;
    int ans = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i] != s[i - 1])
            ans++;
    if (ans >= 3)
        cout << ans - 2 + n << endl;
    else if (ans == 2) cout << ans - 1 + n << endl;
    else cout << ans + n << endl;
}

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}