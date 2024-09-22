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


vector<list<int>> adj;
void addEdge(int src , int des){
    adj[src].push_back(des);
}
string alien(string dict[], int n, int k) {
    string ans = "";
    int sz = 0;
    for(int i = 0 ; i < dict->size(); i++){
        sz = max(sz, (int)dict[i].size());
    }
    for(int i = 0 ; i < sz ; i++){
        int prev = INT_MIN;
        for(int j = 0; j < n; j++){
            
        }
    }
    return ans;
}
void solve() {
    string dict[] = {"baa","abcd","abca","cab","cad"};
    cout<<alien(dict,5, 4);
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