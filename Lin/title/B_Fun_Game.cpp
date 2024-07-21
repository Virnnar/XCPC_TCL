#include "Monday.h"

using namespace virmar;

int n;
string a, b;

void doit() {
    cin >> n >> a >> b;
    if (a == b or a[0] == '1') return puts("YES"), void();
    int cnt = 1000000, pos = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '1') {cnt = i; break;}
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) {pos = i; break;}
    if (pos < cnt) puts("NO");
    else puts("YES");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}