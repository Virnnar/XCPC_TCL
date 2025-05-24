#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    string s; cin >> s;
    
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += s[i] == '1';

    if (cnt == n) return puts("1"), void();

    cout << cnt << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}