#include <iostream>
#include <string>

using namespace std;

class Passport {
protected:
    string name;
    string surname;
    string middleName;
    string nationality;
    string birthDate;
    string passportNumber;

public:
    Passport(string name, string surname, string middleName, string nationality, string birthDate, string passportNumber)
        : name(name), surname(surname), middleName(middleName), nationality(nationality), birthDate(birthDate), passportNumber(passportNumber) {}

    void print() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Middle Name: " << middleName << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Birth Date: " << birthDate << endl;
        cout << "Passport Number: " << passportNumber << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string foreignPassportNumber;
    string visas[20];
    int visaCount;

public:
    ForeignPassport(string name, string surname, string middleName, string nationality, string birthDate, string passportNumber, string foreignPassportNumber)
        : Passport(name, surname, middleName, nationality, birthDate, passportNumber), foreignPassportNumber(foreignPassportNumber), visaCount(0) {}

    void addVisa(const string& visa) {
        if (visaCount < 20) {
            visas[visaCount++] = visa;
        }
        else {
            cout << "Visa limit reached." << endl;
        }
    }

    void printForeignPass() {
        print();
        cout << "Foreign Passport Number: " << foreignPassportNumber << endl;
        cout << "Visas: ";
        for (int i = 0; i < visaCount; ++i) {
            cout << visas[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ForeignPassport ForeignPass("Nikita", "Iliuschenko", "Andreevich", "Ukrainian", "26.04.2006", "57838854-ABHD", "83672672-JNDU");
    ForeignPass.addVisa("Blau Karte,");
    ForeignPass.addVisa("Germany Residence Permit");
    ForeignPass.printForeignPass();
}