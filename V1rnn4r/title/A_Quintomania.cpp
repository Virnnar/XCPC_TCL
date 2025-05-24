#include "Monday.h"

using namespace virmar;

void doit() {
    int n, jud = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int t = abs(a[i] - a[i - 1]);
        if (!(t == 7 or t == 5)) jud = 1;
    }
    puts(jud ? "NO" : "YES");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}