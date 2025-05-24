#include "Monday.h"

using namespace virmar;

const int N = 2E5 + 6;

int s[N];

void init() {
    for (int i = 1; i <= 2E5; i++) {
        int cnt = 0, t = i;
        while (t) cnt++, t /= 3;
        s[i] = cnt;
    }
    for (int i = 1; i <= 2E5; i++) s[i] += s[i - 1];
}

void doit() {
    int l, r; cin >> l >> r;
    cout << s[r] - s[l - 1] + s[l] - s[l - 1] << endl;
}

int main() {
    init();
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}