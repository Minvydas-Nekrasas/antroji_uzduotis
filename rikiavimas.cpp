#include "rikiavimas.h"
#include <algorithm>

using namespace std;


// Pagalbinė funkcija rikiavimui
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}
// Funkcija studentų rikiavimui pagal vardą arba pavardę
void rikiuotiStudentus(vector<Studentas>& studentai, int sort_choice) {
    if (sort_choice == 1) {
        // Rikiuojam pagal vardą
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            if (toLowerCase(a.vardas) == toLowerCase(b.vardas)) {
                return toLowerCase(a.pavarde) < toLowerCase(b.pavarde);
            }
            return toLowerCase(a.vardas) < toLowerCase(b.vardas);
        });
    } else if (sort_choice == 0) {
        // Rikiuojam pagal pavardę
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            if (toLowerCase(a.pavarde) == toLowerCase(b.pavarde)) {
                return toLowerCase(a.vardas) < toLowerCase(b.vardas);
            }
            return toLowerCase(a.pavarde) < toLowerCase(b.pavarde);
        });
    } else if (sort_choice == 2) {
        // Rikiuojam pagal galutinį pažymį
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.galutinis > b.galutinis; // Didžiausias pirmas
        });
    }
}