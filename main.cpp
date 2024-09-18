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
    vector<Studentas> studentai;
    int darbai, pazymys, stud_skaicius;

    cout << "Kiek bus studentų? ";
    cin >> stud_skaicius;

    //Prašom duomenų ir juos įrašom į struktūrą kiekvienam studentui
    for (int i = 0; i < stud_skaicius; ++i) {
        Studentas x;
        cout << "\nDuomenys studento nr. " << i + 1 << ":\n";

        cin.ignore(); //išvengiam \n bug'o

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
}