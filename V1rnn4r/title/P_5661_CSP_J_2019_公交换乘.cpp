#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, ans = 0;

struct node {
    int w, t;
};

int main() {
    cin >> n;
    queue<node> Q;
    for (int i = 1; i <= n; i++) {
        int p, w, t; cin >> p >> w >> t;
        if (!p) {
            ans += w;
            cout << w << endl;
            Q.push({w, t});
        } else {
            bool f = false;
            while (Q.size()) {
                int now = Q.front(); Q.pop();
                if (t - now <= 45) {f = true; break;}
            }
            if (!f) ans += w, cout << w << endl;;
        }
    }
    cout << ans << endl;
}
