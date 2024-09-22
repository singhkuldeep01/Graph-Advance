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
vector<int> team;
void bipartrite(int src){
    team[src] = 1;
    queue<int> qu;
    qu.push(src);
    while(qu.size()){
        int node = qu.front();
        qu.pop();
        for(auto & child : adj[node]){
            if(team[child] == 0){
                team[child] = 3 - team[node];
                qu.push(child);
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    adj.resize(n+1);
    team.resize(n+1,0);
    for(int i = 1; i < n ; i++){
        int src, des;
        cin>>src>>des;
        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    for(int i = 1; i <=n ; i++){
        if(team[i] == 0 ) bipartrite(i);
    }
    int a = 0;
    int b = 0;
    for(int i = 1 ; i < team.size(); i++){
        if(team[i] == 1) a++;
        else if(team[i] == 2) b++;
    }
    int total = a*b;
    cout<<total-(n-1);
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}