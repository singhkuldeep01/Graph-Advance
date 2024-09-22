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

bool isBipartrite(vector<list<int>>& adj , int src , vector<int> &gender){
    gender[src] = 1;
    // male
    queue<int> qu;
    qu.push(src);
    while(qu.size()){
        int node = qu.front();
        qu.pop();
        for(auto & child : adj[node]){
            if(gender[child] == 0){
                gender[child] = 3 - gender[node];
                qu.push(child);
            }else if(gender[child] == gender[node]){
                return false;
            }
        }
    }
    return true;
}

void solve(int sce) {
    int n,m;
    cin >> n >> m;
    vector<list<int>> adj(n + 1);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> gender(n+1,0);
    for(int i = 1; i <= n ; i++){
        if(gender[i] == 0){
            bool ans = isBipartrite(adj,i,gender);
            if(!ans){
                cout << "Scenario #" << sce << ":" << endl;
                cout << "Suspicious bugs found!" << endl;
                return;
            }
        }
    }
    cout << "Scenario #" << sce << ":" << endl;
    cout << "No suspicious bugs found!" << endl;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    cin>>t;
    int i = 1;
    while(t--) {
        solve(i);
        i++;
    }
    return 0;
}