#include <iostream>

using namespace std;

int n,m;
int arr[8] = {0, };
bool visited[8] = {false, };

void dfs(int cnt) {
    if (cnt == m) {
        for (int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i+1;
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    dfs(0);

    return 0;
}