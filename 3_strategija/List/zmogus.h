#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    // Konstruktoriai
    Zmogus() : vardas(""), pavarde("") {}
    Zmogus(const string& v, const string& p) : vardas(v), pavarde(p) {}

    virtual ~Zmogus() {}

    // Getteriai
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }

    // Setteriai
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
};

#endif
