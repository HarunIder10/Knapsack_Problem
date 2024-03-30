#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Knapsack problemi için çözümü hesaplayan fonksiyon
int knapsack(int capacity, vector<int>& returns, vector<int>& risks) {
    int N = returns.size();
    vector<vector<int>> DP(N + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= N; ++i) {
        int ret = returns[i - 1], risk = risks[i - 1];
        for (int sz = 1; sz <= capacity; ++sz) {
            DP[i][sz] = DP[i - 1][sz];
            if (risk <= sz) // Eğer risk sınırlar içindeyse
                DP[i][sz] = max(DP[i][sz], DP[i - 1][sz - risk] + ret);
        }
    }

    return DP[N][capacity];
}

int main() {
    int budget = 50;
    vector<int> returns = {10, 20, 30, 40};
    vector<int> risks = {5, 10, 15, 20};

    int maxReturn = knapsack(budget, returns, risks);
    cout << "Maximum return for given budget: " << maxReturn << endl;

    return 0;
}
