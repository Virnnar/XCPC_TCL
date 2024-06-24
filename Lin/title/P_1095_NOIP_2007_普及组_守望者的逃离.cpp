#include "Monday.h"

using namespace virmar;

const int N = 3E5 + 6;

int m, s, t;
int f[N];

void doit() {
    cin >> m >> s >> t;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= t; i++) {
        s1 += 17;
        if (m >= 10) m -= 10, s2 += 60;
        else m += 4;
        s1 = max(s1, s2);
        if (s1 >= s) {
            puts("Yes");
            cout << i << endl;
            return;
        }
    }
    cout << "No\n" << s1 << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}