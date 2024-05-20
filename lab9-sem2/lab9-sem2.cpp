#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Visit {
    int clientCode;
    int duration;
    int month;
    int year;
};

bool compareYears(const Visit& a, const Visit& b) {
    return a.year > b.year;
}

int main() {
    int K;
    cout << "Enter client code: ";
    cin >> K;

    vector<Visit> visits;

    // зчитування даних про відвідування з файла
    ifstream inputFile("visits.txt");
    if (!inputFile) {
        cerr << "Error with file oppening." << endl;
        return 1;
    }

    Visit visit;
    while (inputFile >> visit.clientCode >> visit.duration >> visit.month >> visit.year) {
        visits.push_back(visit);
    }

    inputFile.close();

    // Фільтрація відвідування для клієнту з кодом K
    vector<Visit> filteredVisits;
    for (const auto& v : visits) {
        if (v.clientCode == K) {
            filteredVisits.push_back(v);
        }
    }

    if (filteredVisits.empty()) {
        cout << "No data!" << endl;
        return 0;
    }

    // Сортирування по році
    sort(filteredVisits.begin(), filteredVisits.end(), compareYears);

    int currentYear = filteredVisits[0].year;
    int monthsAbove15Hours = 0;

    for (const auto& v : filteredVisits) {
        if (v.year != currentYear) {
            cout << monthsAbove15Hours << " " << currentYear << endl;
            monthsAbove15Hours = 0;
            currentYear = v.year;
        }

        if (v.duration > 15) {
            monthsAbove15Hours++;
        }
    }

    // Вивід для останнього року
    cout << monthsAbove15Hours << " " << currentYear << endl;

    return 0;
}
/* дані для файлу
101 20 3 2023
102 10 5 2022
101 18 6 2023
103 25 8 2023
101 12 8 2022
102 16 9 2023
101 22 10 2023
103 14 11 2023
102 17 12 2022

*/