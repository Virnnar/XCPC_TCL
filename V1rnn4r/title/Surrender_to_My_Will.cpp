#include "Monday.h"

using namespace virmar;

void doit() {
    string s; cin >> s;
    int a = 0, b = 0;
    for (auto c: s)
        if (c == 'Y') a++;
        else if (c == 'N') b++;
    if (a >= 4) cout << 1;
    else if (b >= 2) cout << -1;
    else cout << 0;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}