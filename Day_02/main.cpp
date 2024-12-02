#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool fortlaufendGroesser(const vector<int>& vWerte);
bool fortlaufendKleiner(const vector<int>& vWerte);
bool benachbarteDiv(const vector<int>& vWerte);
bool istSicherMitProblemDampener(const vector<int>& vWerte);

int main() {

    int sichereBerichte = 0;
    string sWert[5];
    int iWerte[5];
    string zeile;

    // Pfad zur Datei
    string dateiname = "Input_Day02.txt";

    // Datei öffnen
    ifstream datei(dateiname);

    while (getline(datei, zeile)) {
        stringstream iss(zeile);
        vector<int> vWerte;
        int zahl;

        while (iss >> zahl) {
            vWerte.push_back(zahl);
        }

        if (istSicherMitProblemDampener(vWerte)) {
            sichereBerichte++;
        }
    }
    cout << "Anzahl sicherer Berichte: " << sichereBerichte << endl;
    return 0;
}

bool fortlaufendGroesser(const vector<int>& vWerte){
    for (int i = 0; i < vWerte.size() - 1; i++) {
        if (vWerte[i] >= vWerte[i + 1]) {
            return false;
        }
    }
    return true;
}

bool fortlaufendKleiner(const vector<int>& vWerte) {
    for (int i = 0; i < vWerte.size() - 1; i++) {
        if (vWerte[i] <= vWerte[i + 1]) {
            return false;
        }
    }
    return true;
}

bool benachbarteDiv(const vector<int>& vWerte){
    for (int i = 0; i < vWerte.size() - 1; i++) {
        if (abs(vWerte[i] - vWerte[i + 1]) < 1 || abs(vWerte[i] - vWerte[i + 1]) > 3) {
            return false;;
        }
    }
    return true;
}

// Prüft, ob der Bericht sicher ist (direkt oder durch Entfernen eines Wertes)
bool istSicherMitProblemDampener(const vector<int>& vWerte) {
    // Direkt sicher?
    if ((fortlaufendGroesser(vWerte) || fortlaufendKleiner(vWerte)) && benachbarteDiv(vWerte)) {
        return true;
    }

    // Prüfen, ob das Entfernen eines Wertes den Bericht sicher macht
    for (size_t i = 0; i < vWerte.size(); ++i) {
        vector<int> modifiziert = vWerte;
        modifiziert.erase(modifiziert.begin() + i); // Entferne den i-ten Wert

        if ((fortlaufendGroesser(modifiziert) || fortlaufendKleiner(modifiziert)) && benachbarteDiv(modifiziert)) {
            return true;
        }
    }

    return false; // Weder direkt sicher noch durch Entfernen eines Wertes sicher
}