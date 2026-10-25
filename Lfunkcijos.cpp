#include "basic_funkcijos.h"
#include "Lfunkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <chrono>


void rankine_ivestis(std::list<studentasl> &grupe){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 30);

    for (int j=0; j < stud_kiekis; j++){
        studentasl tempStudentas;

        std::cout << "Įveskite per tarpa studento vardą ir pavardę: ";
        std::cin >> tempStudentas.vardas >> tempStudentas.pavarde;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string input1;
        std::cout << "Įveskite namų darbų pažymius.\n";
        std::cout << "Palikite tuščia ir spauskite ENTER, kad tęsti.\n";
        int i = 1;

        do {
            std::cout << "Įveskite #" << i << " pažymį: ";
            std::getline(std::cin, input1);
            if (!input1.empty()){
                try {
                    int a = std::stoi(input1);
                    if (a >= 1 && a <= 10){
                        tempStudentas.paz.push_back(a);
                        i++;
                    }
                    else {
                        std::cout << "Klaida! Pažymis turi būti nuo 1 iki 10.\n";
                    }
                }
                catch (...){
                    std::cout << "Klaida! Ivedėte ne skaičių, bandykite dar karta.\n";
                }
            }     
        } while(!input1.empty());

        std::string input2;
        while (true) {
            std::cout << "Įveskite egzamino pažymį: ";
            std::getline(std::cin, input2);

            try{
                tempStudentas.exam = std::stoi(input2);
                if (tempStudentas.exam >= 1 && tempStudentas.exam <= 10){
                    break;
                }
                else {
                    std::cout << "Klaida! Pažymis turi būti nuo 1 iki 10.\n";
                }
            } catch (...) {
                std::cout << "Klaida! Ivedėte ne skaičių, bandykite dar karta.\n";
            }
        }
        grupe.push_back(tempStudentas);
        auto it = grupe.begin();
        std::advance(it, j);
        std::cout << "Objekto adresas atmintyje: " << &(*it) << '\n'; 
    }
};

void automatine_ivestis(std::list<studentasl> &grupe, std::mt19937 &mt){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 1000000);
    int nd_kiekis = ar_skaicius("Įveskite kiek namų darbų pažymių norite sugeneruoti: ", 1, 10); 

    for(int j=0; j < stud_kiekis; j++){
        studentasl tempStudentas;
        tempStudentas.vardas = "Vardas" + std::to_string(j + 1);
        tempStudentas.pavarde = "Pavarde" + std::to_string(j + 1);
        generuoti_paz(tempStudentas, nd_kiekis, mt);
        grupe.push_back(tempStudentas);
    }

};

void nuskaityti_faila(std::list<studentasl> &grupe, const std::string failoPavadinimas){
    std::ifstream f(failoPavadinimas, std::ios::ate);

    if(!f.is_open()){
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << '\n';
        return;
    };

    std::streamsize file_size = f.tellg();
    f.seekg(0, std::ios::beg); 
    size_t eil_sk = file_size / 134;
    
    std::string eilute;
    std::getline (f, eilute);

    std::stringstream ss;
    while(std::getline(f, eilute)){
        if (eilute.empty()) continue;
        ss.str(eilute);
        ss.clear();

        studentasl tempStudentas; 
        ss >> tempStudentas.vardas >> tempStudentas.pavarde;

        int skaicius;
        while (ss >> skaicius){
            tempStudentas.paz.push_back(skaicius);
        }

        if (!tempStudentas.paz.empty()){
            tempStudentas.exam = tempStudentas.paz.back();
            tempStudentas.paz.pop_back();
        }

        grupe.push_back(tempStudentas);
    }

    f.close();
};

void rusiavimasPV(std::list<studentasl> &grupe){
    grupe.sort([](const studentasl &a, const studentasl &b){
        if (a.pavarde != b.pavarde){
            return a.pavarde < b.pavarde;
        }
        return a.vardas < b.vardas;
    });
};

void rusiavimasG(std::list<studentasl> &grupe){
    grupe.sort([](const studentasl &a, const studentasl &b){
            return galutinis_vid(a) > galutinis_vid(b);
    });
};

void dalinti_studentus1(std::list<studentasl> &grupe, std::list<studentasl> &kietiakai, std::list<studentasl> &vargsiukai){
    auto atrinkti = std::stable_partition(grupe.begin(), grupe.end(), [](const studentasl &s) {
        return galutinis_vid(s) >= 5.0;
    });

    kietiakai.assign(grupe.begin(), atrinkti);
    vargsiukai.assign(atrinkti, grupe.end());
};

void dalinti_studentus2(std::list<studentasl> &grupe, std::list<studentasl> &vargsiukai){
    auto atrinkti = std::stable_partition(grupe.begin(), grupe.end(), [](const studentasl &s) {
        return galutinis_vid(s) >= 5.0;
    });

    vargsiukai.assign(atrinkti, grupe.end());
    grupe.erase(atrinkti, grupe.end());
}