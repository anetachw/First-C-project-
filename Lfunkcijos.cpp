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


void rankine_ivestis(std::list<studentas> &grupe){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 30);

    for (int j=0; j < stud_kiekis; j++){
        studentas tempStudentas;

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

void automatine_ivestis(std::list<studentas> &grupe, std::mt19937 &mt){


};

void nuskaityti_faila(std::list<studentas> &grupe, const std::string failoPavadinimas){

};

void rusiavimasPV(std::list<studentas> &grupe){

};

void rusiavimasG(std::list<studentas> &grupe){

};

void dalinti_studentus(std::list<studentas> &grupe, std::list<studentas> &kietiakai, std::list<studentas> &vargsiukai){


};

void spartos_analize(std::list<studentas> &grupe, std::list<studentas> &kietiakai, 
                     std::list<studentas> &vargsiukai, std::string failoPavadinimas, int kartojimai){



};