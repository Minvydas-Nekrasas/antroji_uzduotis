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
void rikiuotiStudentus(vector<Studentas>& studentai, bool pagalVarda) {
    if (pagalVarda) {
        // rikiuojam pagal vardą
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            if (toLowerCase(a.vardas) == toLowerCase(b.vardas)) {
                // Jei pavardės tokios pačios, rikiuojam pagal pavardes
                return toLowerCase(a.pavarde) < toLowerCase(b.pavarde);
            }
            return toLowerCase(a.vardas) < toLowerCase(b.vardas); //lyginama pagal ASCII vertes
        });
    } else {
        // rikiuojam pagal pavardę
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            if (toLowerCase(a.pavarde) == toLowerCase(b.pavarde)) {
                // Jei pavardės tokios pačios, rikiuojam pagal
                return toLowerCase(a.vardas) < toLowerCase(b.vardas);
            }
            return toLowerCase(a.pavarde) < toLowerCase(b.pavarde);
        }); // [](funkcijos parametrai){funkcijos algoritmas}, su [] nurodom, kad tai lambda funkcija (kaip python lambda)
    }
}