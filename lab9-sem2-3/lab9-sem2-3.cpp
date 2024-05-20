#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> V = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };// Приклад вектора

    // Сортування вектора
    sort(V.begin(), V.end());

    // Видалення елементів, що повторюються
    auto last = unique(V.begin(), V.end());
    V.erase(last, V.end());

    if (V.size() < 3) {
        cerr << "Error: Vector contains less than three elements." << endl;
        return 1;
    }

    cout << "Result:" << endl;
    for (auto it = V.rbegin() + 1; it != V.rend() - 1; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
