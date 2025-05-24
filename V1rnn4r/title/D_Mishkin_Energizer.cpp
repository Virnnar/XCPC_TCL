#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    string s; cin >> s;

    if (count(all(s), s[0]) == n) return puts("-1"), void();

    string base = "LIT";

    vector<int> ans;

    while (true) {
        vector<pair<int, char> > cnt;
        for (auto i: base) cnt.push_back(make_pair(count(all(s), i), i));
        sort(all(cnt));

        if (cnt[0].first == cnt[1].first && cnt[1].first == cnt[2].first) break;

        auto op = [&](int i) -> void {
            string t = base;
            t.erase(find(all(t), s[i])), t.erase(find(all(t), s[i + 1]));
            ans.push_back(i);
            s = s.substr(0, i + 1) + t[0] + s.substr(i + 1);
        };

        bool jud = false;

        for (int i = 0; i < s.size() - 1; i ++) {
            if (s[i] == s[i + 1]) continue;
            if (s[i] != cnt[0].second and s[i + 1] != cnt[0].second) {
                op(i);
                jud = true;
                break;
            }
        }

        if (jud) continue;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) continue;
            if (s[i] == cnt[2].second) {
                op(i), op(i + 1), op(i), op(i + 2); break;
            } else if (s[i + 1] == cnt[2].second) {
                op(i), op(i), op(i + 1), op(i + 3); break;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans) cout << i + 1 << endl;

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