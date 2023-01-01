#include "lib.h"
#include "F.h"


unsigned int Zodziai_eiluteje(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}


int random_pazymys()
{
	return rand() % 10 + 1;
}



void failo_generavimas(int tempvaik)
{
    int randsk;
    randsk = rand()% 3 + 3;
    string filas = "Studentai" + to_string(tempvaik)+".txt";
    ofstream w1(filas);
    w1 << setw(16) << left << "Vardas"
		<< setw(16) << left << "Pavarde";
    for(int n=0; n<randsk; n++)
    {
        w1 << setw(5) << "ND" + to_string(n+1);
    }
    w1 << "Egz." << endl;
    for (int j=0; j<tempvaik; j++)
    {
        w1 << setw(16) << "Vardas" + to_string(j+1)
			<< setw(16) << "Pavarde" + to_string(j+1);
        for(int k=0; k<randsk; k++)
        {
            w1 << setw(5) << random_pazymys();
        }
        w1 << setw(5) << random_pazymys() << endl;
    }
}

bool kieteku_suradimas(Vaikas SK)
{
	return (SK.paimti_galutini_vid() >= 5.0);
}

/*
double kieteku_suradimas(vector<Vaikas> SK)
{
    if(SK.paimti_galutini_vid() >= 5.0)
        return SK.paimti_galutini_vid();
}
*/


void skaitymas_is_failo (vector<Vaikas>& SK, int* kieknd, int tempvaik)
{
    auto start = std::chrono::high_resolution_clock::now();

    int temp;
    int vaikusk = 0;
    string buff;
    ifstream r;
    string filas = "Studentai" + to_string(tempvaik)+".txt";
    try{
        r.open(filas);
        if(!r)
            throw std::runtime_error("Nepavyko rasti failo");

            getline(r >> std::ws, buff);
            *kieknd = Zodziai_eiluteje(buff) - 3;
            while(true)
            {
                Vaikas vaik;
                string vardas, pavarde;
                int egzaminas;
                vector<int> nd;

                r >> vardas;

                if(r.eof())
                {
                    SK.pop_back();
                    break;
                }

                r >> pavarde;

                for(int i=0; i<*kieknd; i++)
                {
                    r >> temp;
                    nd.push_back(temp);
                }

                r >> egzaminas;

                vaik.sukurti_vaika(vardas, pavarde, nd, egzaminas);
                vaik.skaiciuoti_galutini_med();
                vaik.skaiciuoti_galutini_vid();
                vaikusk += 1;
                SK.resize(vaikusk);
                SK.push_back(vaik);
            }
            r.close();
    }
    catch(int e){}
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Duomenu nuskaitymas su vektorium uztruko: " << diff.count() << " s\n";
}


void isvedimas_i_faila(vector<Vaikas> SK, string pav)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    ofstream w1;

    w1.open(pav);

    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";



    for(int k=0; k<70; k++)
    {
        w1 << "_" ;
    }
    w1 << endl;


    for(int i=0; i<SK.size(); i++)
    {
        Vaikas temp_vaik = SK[i];
        w1 << left << setw(17) << temp_vaik.paimti_varda() << setw(17) << temp_vaik.paimti_pavarde() << setw(22) << temp_vaik.paimti_galutini_vid() <<
            setw(22) << temp_vaik.paimti_galutini_med() << endl;
    }

    w1.close();


    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Duomenu isvedimas i du failus su vektorium uztruko: " << diff1.count() << " s\n";
}

