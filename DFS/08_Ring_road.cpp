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

#define pp pair<int,int>
vector<list<pp>> adjList;

void addEdge(int src , int des , int wt){
    adjList[src].push_back({des, wt});
    adjList[des].push_back({src, (-1*wt)});
}


int dfs(){
    int src = 1;
    int parent = src;
    int weight = 0;
    
    do{
        int next = 0;
        int negativeNext = 0;
        for(auto& child : adjList[src]){
            if(parent == child.first) continue;
            if(child.second > 0){
                next = child.first;
                weight += child.second;
                break;
            }else{
                negativeNext = child.first;
            }
        }
        if(next == 0) next = negativeNext;
        parent = src;
        src = next;
    } while (src != 1);
    return  weight;
}

void solve() {
    int n;
    cin>>n;
    adjList.clear();
    adjList.resize(n+1);
    int total = 0;
    for(int i = 0; i < n; i++){
        int src, des, wt;
        cin>>src>>des>>wt;
        addEdge(src, des, wt);
        total += wt;
    }
    int ans = dfs();
    cout<<min(ans , total-ans);
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