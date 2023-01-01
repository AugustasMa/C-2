#include "lib.h"
#include "Vaikas.h"
#include "F.h"


using namespace std;

int main()
{
    int tempvaik, kieknd;
    vector<Vaikas> A;
    string pav;


    cout << "Iveskite vaiku skaiciu: ";
    cin >> tempvaik;

    failo_generavimas(tempvaik);

    skaitymas_is_failo(A, &kieknd, tempvaik);

    vector<Vaikas> vargsiukai_A(A.size());
    remove_copy_if(A.begin(), A.end(), vargsiukai_A.begin(), kieteku_suradimas);
    //remove_if(A.begin(), A.end(), kieteku_suradimas(A)>5);

    isvedimas_i_faila(vargsiukai_A, "vargsiukai.txt");
    isvedimas_i_faila(A, "Studentai" + to_string(tempvaik)+".txt");


    return 0;
}
