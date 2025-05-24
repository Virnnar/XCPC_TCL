#include "Monday.h"

using namespace virmar;

const int ANS[] = {0, 1, 2, 2, 3, 3};

void doit() {
    int n; cin >> n;
    if (n < 6) {
        cout << ANS[n] << endl;
        for (int i = 1; i <= n; i++) cout << ANS[i] << ' ';
        return puts(""), void();
    }
    cout << 4 << endl;
    for (int i = 1; i <= n; i++)
        cout << (i % 4 + 1) << ' ';
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}