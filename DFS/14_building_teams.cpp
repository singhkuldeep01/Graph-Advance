#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast_io ios::sync_with_stdio(0);cin.tie(0);

vector<vector<int>> adj;
vector<int> team;

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1; // Assign team 1 to the start node
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (team[neighbor] == 0) {
                // Assign the opposite team to the neighbor
                team[neighbor] = 3 - team[node];
                q.push(neighbor);
            } else if (team[neighbor] == team[node]) {
                // Conflict found, graph is not bipartite
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.clear();
    adj.resize(n + 1);
    team.clear();
    team.resize(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    solve();
    return 0;
}