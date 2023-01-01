#ifndef VAIKAS_H_INCLUDED
#define VAIKAS_H_INCLUDED
#include "lib.h"


class Vaikas
{
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid;
    double galutinis_med;

public:
    Vaikas() : egzaminas(0) { };
    void sukurti_vaika(string vardas_, string pavarde_, vector<int> pazymiai_, int egzaminas_);
    void sukurti_pazymi(int paz);
    void istrinti_nd();
    string paimti_varda() const { return vardas; }
    string paimti_pavarde() const { return pavarde; }
    int paimti_egzamina() const { return egzaminas; }
    int paimt_nd_skaiciu() const { return pazymiai.size(); }
    void skaiciuoti_galutini_vid();
    void skaiciuoti_galutini_med();
    double paimti_galutini_vid() const { return galutinis_vid; }
    double paimti_galutini_med() const { return galutinis_med; }

    ~Vaikas();
    Vaikas(const Vaikas &kitas);
    Vaikas& operator=(Vaikas& kitas);
};

#endif // VAIKAS_H_INCLUDED
