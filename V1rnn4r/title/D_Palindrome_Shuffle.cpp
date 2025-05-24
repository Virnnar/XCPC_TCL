#include "Monday.h"

using namespace virmar;

bool check(int x, string &s) {
    vector<int> cnt(26);
    int n = s.size();
    for (int i = 0; i < x; i++)
        cnt[s[i] - 'a']++;
    bool res = true;
    for (int i = 0; i < min(n / 2, n - x); i++) {
        char c = s[n - i - 1];
        if (i < x) {
            res &= cnt[c - 'a'] > 0;
            cnt[c - 'a']--;
        } else res &= (c == s[i]);
    }
    for (auto i : cnt) res &= (i % 2 == 0);
    return res;
}

void doit() {
    string s; cin >> s;
    int i = 0, j = s.size() - 1;
    while (i < j and s[i] == s[j]) i++, j--;
    if (i > j) return puts("0"), void();
    s = s.substr(i, j - i + 1);
    int ans = s.size();
    for (int p = 0; p < 2; p++) {
        int l = 0, r = s.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, s)) r = mid;
            else l = mid + 1;
        }
        ans = min(ans, l);
        reverse(all(s));
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}