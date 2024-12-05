#include "Studentas.h"
#include <numeric>
#include <algorithm> // for std::copy

// Default constructor
Studentas::Studentas() : vardas(""), pavarde(""), egz(0), galutinis(0.0) {}

// Parameterized constructor
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
        nd = other.nd; // Vector's assignment operator handles deep copying
        egz = other.egz;
        galutinis = other.galutinis;
    }
    return *this;
}

// Destructor definition
Studentas::~Studentas() {
    // No special cleanup required
}

// Getter for vardas
string Studentas::getVardas() const {
    return vardas;
}

// Setter for vardas
void Studentas::setVardas(const string& v) {
    vardas = v;
}

// Getter for pavarde
string Studentas::getPavarde() const {
    return pavarde;
}

// Setter for pavarde
void Studentas::setPavarde(const string& p) {
    pavarde = p;
}

// Getter for nd
vector<int> Studentas::getNd() const {
    return nd;
}

// Setter for nd
void Studentas::setNd(const vector<int>& n) {
    nd = n;
    calculateGalutinis();
}

// Getter for egz
int Studentas::getEgz() const {
    return egz;
}

// Setter for egz
void Studentas::setEgz(int e) {
    egz = e;
    calculateGalutinis();
}

// Getter for galutinis (non-const version)
double& Studentas::getGalutinis() {
    return galutinis;
}

// Getter for galutinis (const version)
const double& Studentas::getGalutinis() const {
    return galutinis;
}

// Private method to calculate the final grade
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
