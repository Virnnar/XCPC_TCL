#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> b(n - 2);
    for (auto &i: b) cin >> i;
    for (int i = 1; i + 1 < n - 2; i++)
        if (b[i] == 0) {
            if (b[i - 1] == b[i + 1] and b[i - 1] == 1)
                return puts("NO"), void();
        }
    puts("YES");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}







