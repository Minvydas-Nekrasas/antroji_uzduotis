#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

using namespace std;

class Studentas {
private:
    string vardas;              // Student's first name
    string pavarde;             // Student's last name
    vector<int> nd;             // Homework grades
    int egz;                    // Exam grade
    double galutinis;           // Final grade

    void calculateGalutinis();  // Calculates the final grade (private method)

public:
    // Constructors
    Studentas();
    Studentas(const string& v, const string& p, const vector<int>& n, int e);

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    // Destructor
    ~Studentas();

    // Getters
    string getVardas() const;
    string getPavarde() const;
    vector<int> getNd() const;
    int getEgz() const;
    double& getGalutinis(); // Non-const version
    const double& getGalutinis() const; // Const version

    // Setters
    void setVardas(const string& v);
    void setPavarde(const string& p);
    void setNd(const vector<int>& n);
    void setEgz(int e);

    // Methods
    void addNd(int grade); // Adds a grade to the homework list and recalculates
};

#endif
