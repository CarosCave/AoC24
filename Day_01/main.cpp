#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int findNumber(std::vector<int> numbers, int target);

int main() {
    vector<int> array_1;
    vector<int> array_2;
    vector<int> zeilenDiv;
    vector<int> tempSim;

    int tempDiv, finalSum, finalSim;

    string zeile, tempZeile, tempZahl1, tempZahl2;

    // Pfad zur Datei
    string dateiname = "Input_Day01.txt";

    // Datei öffnen
    ifstream datei(dateiname);

    while (getline(datei, zeile)) {
        stringstream ss(zeile);

        ss >> tempZahl1;
        ss >> tempZahl2;

        array_1.push_back(stoi(tempZahl1));
        array_2.push_back(stoi(tempZahl2));
    }

    sort(array_1.begin(), array_1.end());
    sort(array_2.begin(), array_2.end());

    // Start Aufgabe 1
    for (int i = 0; i < array_1.size(); i++) {
        tempDiv = abs(array_1[i] - array_2[i]);
        zeilenDiv.push_back(tempDiv);
    }

    finalSum = accumulate(zeilenDiv.begin(), zeilenDiv.end(), 0);

    cout << "Summe der Differenzen: " << finalSum << endl;
    // Ende Aufgabe 1

    // Start Aufgabe 2

    for (int i = 0; i < array_1.size(); i++) {
        tempSim.push_back(array_1[i] * findNumber(array_2, array_1[i]));
    }

    finalSim = accumulate(tempSim.begin(), tempSim.end(), 0);
    cout << "Summe der Aehnlichkeiten: " << finalSim << endl;
    // Ende Aufgabe 2

    datei.close();
    return 0;
}

int findNumber(std::vector<int> numbers, int target) {
    int retVal = 0;

    auto temp = std::find(numbers.begin(), numbers.end(), target);

    while (temp != numbers.end()) {
        retVal++;

        temp = std::find(temp + 1, numbers.end(), target);
    }
    return retVal;
}