#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
void slove(){
    int n;
    cin>>n;
    vector<int>a(n),b(n+1);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    bool flag=false;
    ll ans=0,d=INF;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
        ll u=min(a[i],b[i]),v=max(a[i],b[i]);
        if(u<=b.back()&&b.back()<=v) flag=true;
        else{
             d=min(d,abs(b.back()-v));
            d=min(d,abs(b.back()-u));
        }
    } 
    if(flag) cout<<ans+1<<endl;
    else cout<<ans+d+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}