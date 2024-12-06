#include "Studentas.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm> // for std::copy

// Paprastas konstruktorius
Studentas::Studentas() : vardas(""), pavarde(""), egz(0), galutinis(0.0) {}

// Parametrizuotas konstruktorius
Studentas::Studentas(const string& v, const string& p, const vector<int>& n, int e)
    : vardas(v), pavarde(p), nd(n), egz(e) {
    calculateGalutinis();
}

// Copy constructor (deep copy)
Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), nd(other.nd), egz(other.egz), galutinis(other.galutinis) {}

// Copy assignment operator (deep copy)
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) { // Avoid self-assignment
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd; // Vektorius
        egz = other.egz;
        galutinis = other.galutinis;
    }
    return *this;
}

// Destruktorius
Studentas::~Studentas() {
    nd.clear();
}

// Įvesties operatorius
istream& operator>>(istream& in, Studentas& s) {
    cout << "Įveskite vardą: ";
    in >> s.vardas;

    cout << "Įveskite pavardę: ";
    in >> s.pavarde;

    cout << "Įveskite namų darbų pažymius (įveskite -1 pabaigti): ";
    s.nd.clear();
    int grade;
    while (in >> grade && grade != -1) {
        s.nd.push_back(grade);
    }
    in.clear();

    cout << "Įveskite egzamino pažymį: ";
    in >> s.egz;

    s.calculateGalutinis();

    return in;
}

// Išvesties operatorius
ostream& operator<<(ostream& out, const Studentas& s) {
    out << setw(15) << left << s.vardas
        << setw(15) << left << s.pavarde
        << setw(10) << left << fixed << setprecision(2) << s.galutinis;
    return out;
}


string Studentas::getVardas() const {
    return vardas;
}

void Studentas::setVardas(const string& v) {
    vardas = v;
}


string Studentas::getPavarde() const {
    return pavarde;
}

void Studentas::setPavarde(const string& p) {
    pavarde = p;
}


vector<int> Studentas::getNd() const {
    return nd;
}

void Studentas::setNd(const vector<int>& n) {
    nd = n;
    calculateGalutinis();
}


int Studentas::getEgz() const {
    return egz;
}

void Studentas::setEgz(int e) {
    egz = e;
    calculateGalutinis();
}


double& Studentas::getGalutinis() {
    return galutinis;
}

const double& Studentas::getGalutinis() const {
    return galutinis;
}

// Privatus metodas galutinio pažymio skaičiavimui
void Studentas::calculateGalutinis() {
    if (!nd.empty()) {
        double nd_avg = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
        galutinis = 0.4 * nd_avg + 0.6 * egz;
    } else {
        galutinis = 0.6 * egz;
    }
}

// Adds a new homework grade and recalculates the final grade
void Studentas::addNd(int grade) {
    nd.push_back(grade);
    calculateGalutinis();
}
