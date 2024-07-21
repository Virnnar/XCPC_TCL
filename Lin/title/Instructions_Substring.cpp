#include "Monday.h"

using namespace virmar;

const int N = 2E5 + 6;

int n, x, y;
string s;
ll sx[N];

pair<int, int> sy[N];
vector<pair<int, int> > ans;
map<int, vector<int> > H;
vector<int> val;
int ANS;

void doit() {
    cin >> n >> x >> y;
    cin >> s; s = '_' + s;
    for (int i = 1; i <= n; i++) {
        sy[i].second = i;
        if (s[i] == 'W') sy[i].first = sy[i - 1].first + 1;
        else if (s[i] == 'S') sy[i].first = sy[i - 1].first - 1;
        else sy[i].first = sy[i - 1].first;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'D') sx[i] = sx[i - 1] + 1;
        else if (s[i] == 'A') sx[i] = sx[i - 1] - 1;
        else 
    }

    sort(sy + 1, sy + n + 1);

    for (int i = 1; i <= n; i++)
        cout << sy[i].first << ' ' << sy[i].second << endl;
    puts("______");

    for (int i = 1; i <= n; i++)
        H[sy[i].first].push_back(sy[i].second);

    for (int i = 1; i <= n; i++) 
        if (val.size() == 0 or (val.back() != sy[i].first)) val.push_back(sy[i].first);

    for (auto i: val) {
        int t = i - y;
        if (H[t].empty()) continue;
        // cout << t << ' ' << i << endl;
        for (auto l: H[t])
            for (auto r: H[i]) {
                if (r <= l) continue;
                // cout << l << ' ' << r << endl;
                if (sx[r] - sx[l] == x) ANS += n - r + 1;
            }
    }
    cout << ANS << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}