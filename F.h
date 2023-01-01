#ifndef F_H_INCLUDED
#define F_H_INCLUDED
#include "lib.h"
#include "Vaikas.h"

unsigned int Zodziai_eiluteje(std::string const& str);
int random_pazymys();
void failo_generavimas(int tempvaik);
bool kieteku_suradimas(Vaikas SK);
void skaitymas_is_failo (vector<Vaikas>& SK, int* kieknd, int tempvaik);
void isvedimas_i_faila(vector<Vaikas> SK, string pav);


#endif // F_H_INCLUDED
