#include "Monday.h"

using namespace virmar;

const int N = 50;

int n, m;
int a[N], s[10];
int f[N][N][N][N];

void doit() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, t; i <= m; i++) cin >> t, s[t]++;
    int maxx = 0, now;
    f[0][0][0][0] = a[1];
    for(int i1=0;i1<=s[1];i1++){
		for(int i2=0;i2<=s[2];i2++){
			for(int i3=0;i3<=s[3];i3++){
				for(int i4=0;i4<=s[4];i4++){
					if(i1==0&&i2==0&&i3==0&&i4==0)continue;
					maxx=0;now=1+i1+2*i2+3*i3+4*i4;
					if(i1!=0)maxx=max(maxx,f[i1-1][i2][i3][i4]+a[now]);
					if(i2!=0)maxx=max(maxx,f[i1][i2-1][i3][i4]+a[now]);
					if(i3!=0)maxx=max(maxx,f[i1][i2][i3-1][i4]+a[now]);
					if(i4!=0)maxx=max(maxx,f[i1][i2][i3][i4-1]+a[now]);
					f[i1][i2][i3][i4]=max(maxx,f[i1][i2][i3][i4]);
				}
			}
		}
	}
    cout<<f[s[1]][s[2]][s[3]][s[4]]<<endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}