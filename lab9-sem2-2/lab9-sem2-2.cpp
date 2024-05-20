#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cout << "Enter the number K: ";
    cin >> K;

    if (K <= 0) {
        cerr << "Error: K must be greater than 0." << endl;
        return 1;
    }

    vector<int> V;
    int num;
    cout << "Enter the elements of the vector V (enter a negative number to complete the entry):" << endl;
    while (cin >> num && num >= 0) {
        V.push_back(num);
    }

    // Пошук першого набору з K підряд розташованих позитивних чисел
    auto it = search_n(V.begin(), V.end(), K, 1, [](int a, int b) {
        return a > 0 && b > 0;
        });

    if (it != V.end()) {
        // Знайдено перший набір, продублюємо його
        V.insert(it + K, it, it + K);
    }

    cout << "Result after duplication:" << endl;
    for (int num : V) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
