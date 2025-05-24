#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] <= k) a[i] = 1;
        else a[i] = -1;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    int l = n + 1, r = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] - s[0] >= 0) {l = i; break;}
    for (int i = n; i >= 1; i--)
        if (s[n] - s[i - 1] >= 0) {r = i; break;}
    
    if (l + 1 < r) return puts("YES"), void();

    auto check = [&]() {
        vector<int> msp(n + 1);
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i];
        msp[n] = s[n];
        for (int i = n - 1; i >= 1; i--)
            msp[i] = max(msp[i + 1], s[i]);
        for (int i = 1; i <= n - 2; i++)
            if (s[i] >= 0 and msp[i + 1] - s[i] >= 0) return true;
        return false;
    };

    if (check()) return puts("YES"), void();
    for (int i = 1; i < n - i + 1; i++)
        swap(a[i], a[n - i + 1]);
    if (check()) return puts("YES"), void();
    puts("NO");
    
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