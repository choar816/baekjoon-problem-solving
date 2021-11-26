#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void func(vector<int> v) {
    for (int i=0; i<8; i++) {
        for (int j=i+1; j<9; j++) {
            // i, j번째 원소를 뺐을 때 합이 100이면
            if (accumulate(v.begin(), v.end(), 0) - v[i] - v[j] == 100) {
                // i번째 요소를 지우고, i < j 이므로 j-1번째 요소를 지운다.
                v.erase(v.begin() + i);
                v.erase(v.begin() + j - 1); // 처음에 j번째 요소를 지웠다가 틀렸다.

                sort(v.begin(), v.end()); // 오름차순으로 정렬
                for (auto n: v) {
                    cout << n << "\n";
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dwarf(9);
    for (int i=0; i<9; i++) {
        cin >> dwarf[i];
    }
    
    func(dwarf);
    
	return 0;
}

// 조합(combination)으로 구현했을 때, 답이 여러개일 때 여러개 모두 출력됐다.
