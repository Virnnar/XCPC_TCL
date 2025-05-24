#include "Monday.h"

using namespace virmar;

const int N = 1E6 + 6;

int n;
int a[N];
bool v[N];

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], v[i] = false;
    vector<int> Q;
    for (int i = 1; i <= n; i++) 
        if (!v[i]) {
            int now = i;
            int cnt = 0;
            while (!v[now]) {
                v[now] = true;
                cnt++;
                now = a[now];
            }
            if (cnt > 1) Q.push_back(cnt);
        }
    sort(Q.begin(), Q.end());
    ll ans = 0;
    // for (auto t: Q) cout << t << ' ';
    // puts("\n----");
    for (int i = 0; i < Q.size(); i++) {
        if (Q[i] == 2) {
            ans++;
            if (i + 1 < Q.size()) {
                if (Q[i + 1] == 2) Q[i + 1] = 0;
                if (Q[i + 1] > 2) Q[i + 1]--;
            }
        }else if (2 <= Q[i] and Q[i] <= 4) ans++;
        else if (Q[i] > 4) ans += ((Q[i] - 4) + 2) / 3 + 1;
        // else if (Q[i] > 4) ans += ((Q[i] - 4) + 2) / 3 + 1;
        // if (Q[i] == 2 and Q[i + 1] == 2) ans++, Q[i + 1] = 0;
        // if (Q[i] == 2 and Q[i + 1] > 2) ans++, Q[i + 1]--;
        // else if (3 <= Q[i] and Q[i] <= 4) ans++;
        // else if (Q[i] > 4) ans += ((Q[i] - 4) + 2) / 3 + 1;
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = true;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}