#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define MOD 1000000007
#define F first
#define S second
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}

void solve() {
    int a,b;
    cin>>a>>b;
    vector<int> ans;
    while(b >= a){
        ans.push_back(b);
        if(a == b) break;
        if(b%2 == 0){
            b /= 2;
        }else if(b % 10 == 1){
            b /= 10;
        }else{
            cout<<"NO";
            return;
        }
    }
    if(a == b){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i = ans.size()-1; i >= 0 ; i--) cout<<ans[i]<<" ";
    }else{
        cout<<"NO"<<endl;
    }
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}