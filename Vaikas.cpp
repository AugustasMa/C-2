#include "lib.h"
#include "Vaikas.h"

Vaikas::~Vaikas()
{
    pazymiai.clear();
    egzaminas = NULL;
    galutinis_med = NULL;
    galutinis_vid = NULL;
}

Vaikas::Vaikas(const Vaikas& kitas)
{
    vardas = kitas.vardas;
    pavarde = kitas.pavarde;
    pazymiai = kitas.pazymiai;
    egzaminas = kitas.egzaminas;
    galutinis_med = kitas.galutinis_med;
    galutinis_vid = kitas.galutinis_vid;
}





Vaikas &Vaikas::operator=(Vaikas& kitas)
{
    if (&kitas == this)
        return *this;
    swap(vardas, kitas.vardas);
    swap(pavarde, kitas.pavarde);
    swap(pazymiai, kitas.pazymiai);
    swap(egzaminas, kitas.egzaminas);
    swap(galutinis_vid, kitas.galutinis_vid);
    swap(galutinis_med, kitas.galutinis_med);
    return *this;
}





void Vaikas::sukurti_vaika(string vardas1, string pavarde1, vector<int> pazymiai1, int egzaminas1)
{
	vardas =  vardas1;
	pavarde =  pavarde1;
	pazymiai =  pazymiai1;
	egzaminas =  egzaminas1;
	galutinis_vid = 0;
	galutinis_med = 0;
}


void Vaikas::sukurti_pazymi(int paz)
{
    pazymiai.resize(pazymiai.size() + 1);
    pazymiai.push_back(paz);
}


void Vaikas::istrinti_nd()
{
    pazymiai.clear();
}


void Vaikas::skaiciuoti_galutini_vid()
{
	int pazymiu_suma = accumulate(pazymiai.begin(), pazymiai.end(), 0);;
	int pazymiu_vidurkis = pazymiu_suma / pazymiai.size();
	galutinis_vid = 0.4 * pazymiu_vidurkis + 0.6 * egzaminas;
}


void Vaikas::skaiciuoti_galutini_med()
{
    vector<int> pazymiu_masyvas;
    for (int i = 0; i < pazymiai.size(); i++)
        pazymiu_masyvas.push_back(pazymiai[i]);
    pazymiu_masyvas.push_back(egzaminas);

    sort(pazymiu_masyvas.begin(), pazymiu_masyvas.end());
    float pazymiu_mediana;

    if (pazymiu_masyvas.size() == 0)
    {
        pazymiu_mediana = 0;
    }
    else if (pazymiu_masyvas.size() % 2 == 0)
    {
        pazymiu_mediana = (pazymiu_masyvas[pazymiu_masyvas.size() / 2] + pazymiu_masyvas[pazymiu_masyvas.size() / 2 - 1]) / 2.0;
    }
    else
    {
        pazymiu_mediana = pazymiu_masyvas[(pazymiu_masyvas.size() - 1) / 2];
    }
    galutinis_med = 0.4 * pazymiu_mediana + 0.6 * egzaminas;
}
