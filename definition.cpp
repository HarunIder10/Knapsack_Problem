#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Knapsack problemi için çözümü hesaplayan fonksiyon
// capacity: sırt çantasının maksimum kapasitesi
// weights: öğelerin ağırlıklarını içeren vektör
// values: öğelerin değerlerini içeren vektör
int knapsack(int capacity, vector<int>& weights, vector<int>& values) {
    // Öğe sayısını al
    int N = weights.size();
    // Dinamik programlama tablosunu oluştur
    vector<vector<int>> DP(N + 1, vector<int>(capacity + 1, 0));

    // Her öğe için döngü
    for (int i = 1; i <= N; ++i) {
        // Öğenin ağırlığı ve değerini al
        int w = weights[i - 1], v = values[i - 1];
        // Çantanın kapasitesi için döngü
        for (int sz = 1; sz <= capacity; ++sz) {
            // Önceki öğe olmadan elde edilen maksimum değeri al
            DP[i][sz] = DP[i - 1][sz];
            // Eğer şu anki öğeyi almak daha fazla değer sağlarsa, al
            if (sz >= w && DP[i - 1][sz - w] + v > DP[i][sz])
                DP[i][sz] = DP[i - 1][sz - w] + v;
        }
    }

    // Maksimum karı döndür
    return DP[N][capacity];
}

int main() {
    // Test verileriyle knapsack fonksiyonunu çağır ve sonuçları yazdır
    int capacity = 10;
    vector<int> values = {1, 4, 8, 5};
    vector<int> weights = {3, 3, 5, 6};
    cout << "Maximum profit for capacity " << capacity << ": " << knapsack(capacity, weights, values) << endl;

    capacity = 7;
    values = {2, 2, 4, 5, 3};
    weights = {3, 1, 3, 4, 2};
    cout << "Maximum profit for capacity " << capacity << ": " << knapsack(capacity, weights, values) << endl;

    return 0;
}
