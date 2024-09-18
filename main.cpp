#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

int main(){
    Studentas x;
    int darbai, pazymys;

    //Prašom duomenų ir juos įrašom į struktūrą
    cout << "Įrašyk studento vardą: ";
    getline(cin, x.vardas);

    cout << "įrašyk studento pavardę: ";
    getline(cin, x.pavarde);

    cout << "Kiek namų darbų? ";
    cin >> darbai;

    for (int i = 0; i < darbai; ++i) {
        cout << "Įrašyk namų darbo pažymį " << i + 1 << ": ";
        cin >> pazymys;
        x.nd.push_back(pazymys);  // Įdedam į vektorių
    }
    cout << "Įrašyk egzamino rezultatą: ";
    cin >> x.egz;
}