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

vector<list<int>> adjList;

void addEdge(int src, int dest, bool isBiDir = true) {
    adjList[src].push_back(dest);
    if(isBiDir){
        adjList[dest].push_back(src);
    }
}

int countSubordinates(int root, vector<int>&dp){
    int ans = 0;
    if(dp[root] != -1) return dp[root];
    for(auto& neigh : adjList[root]){
        ans += 1 + countSubordinates(neigh, dp);
    }
    return dp[root] = ans;
}

void solve() {
    int n;
    cin>>n;
    adjList.clear();
    adjList.resize(n+1,list<int> ());
    vector<int> inDeg(n+1,0);
    inDeg[1] = n-1;
    vector<int> dp(n+1, -1);
    for(int i = 2; i <= n; i++){
        int ele;
        cin>>ele;
        if(ele == 1) continue;
        addEdge(ele, i, false);
    }
    for(int i = 1; i <= n; i++){
        unordered_set<int> st;
        if(i == 1){
            cout<<n-1<<" ";
        }else{
            cout<<countSubordinates(i, dp)<<" ";
        }
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