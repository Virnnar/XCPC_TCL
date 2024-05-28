#include<iostream>
#include<algorithm>
#include<numeric>//lcmºÍgcd
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
int culc(vector<PII>&v,int b){
    int cnt=0,LCM=0;
    for(auto [p,c]:v){
        if(b%p==0){
            if(LCM==0) LCM=p;
            else LCM=lcm(LCM,p);
            cnt+=c;
        }
    }
    if(LCM!=b) cnt=0;
    return cnt;
}
void solve(){
    int n,mx=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    LL LCM=1;
    for(auto p:a){
        LCM=lcm(LCM,p);
        if(LCM>mx){
            cout<<n<<endl;
            return;
        }
    }
    map<int,int> cnt;
    for(auto j:a) cnt[j]++;
    vector<PII> vt;
    for(auto j:cnt) vt.push_back(j);
    int res=0;
    for(int i=1;i*i<mx;i++){
        if(mx%i==0){
            if(!cnt.count(i)){
                res=max(res,culc(vt,i));
            }
            if(!cnt.count(mx/i)){
                res=max(res,culc(vt,mx/i));
            }
        }
    }
    cout<<res<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}