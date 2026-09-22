// studentu valdymo programa
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>


struct studentas{
    std::string vardas, pavarde;
    std::vector<int> paz;
    int exam;
    };

const std::vector<std::string> vardai = {
    "Jonas", "Lukas" "Emilija", "Ieva", "Tomas", "Pijus", "Liepa", "Austeja"
};

const std::vector<std::string> pavardes = {
    "Jonaitis", "Petraits", "Kazlauskas", "Jankauskas",
    "Pocius", "Stankevicius", "Butkus", "Vaitkus"

};

    
void printas(const studentas &A);
double galutinis_vid(const studentas &A);
double mediana(std::vector<int> paz);
double galutinis_med(const studentas &A);
void generuoti_paz(studentas &A, int count, std::mt19937 &mt);
void rodyti_meniu();
void rodyti_lentele(const std::vector<studentas> &grupe);
void rankine_ivestis(std::vector<studentas> &grupe);
void automatine_ivestis(std::vector<studentas> &grupe);
void failo_nuskaitymas(std::vector<studentas> &grupe, std::string failoPavadinimas);
void rusiavimas(std::vector<studentas> &grupe);
int ar_skaicius(std::string tekstas, int min, int max);
void rasyti_i_faila(const std::vector<studentas> &grupe, std::string failoPavadinimas);
void rodyti_rezultatus(const std::vector<studentas> &grupe);

int main(){
    srand(time(NULL));
    std::vector<studentas>grupe; 
    int pasirinkimas;

    do{
        rodyti_meniu();
        pasirinkimas = ar_skaicius("\nPasirinkite veiksma (0-3): ", 0, 3);

        switch(pasirinkimas){
            case 0:
                std::cout << "Baigiamas darbas\n";
                break;
            case 1:
                rankine_ivestis(grupe);
                rusiavimas(grupe);
                rodyti_lentele(grupe);
                break;
            case 2:
                automatine_ivestis(grupe);
                rusiavimas(grupe);
                rodyti_rezultatus(grupe);
                break;
            case 3: {
                std::cout << "Įveskite failo pavadinimą: ";
                std::string failas;
                std::cin >> failas; 
                failo_nuskaitymas(grupe, failas);
                rusiavimas(grupe);
                if(!grupe.empty()){
                    rodyti_rezultatus(grupe);
                }
                break;
                }
        }

    } while(pasirinkimas != 0);
};

void printas(const studentas &A){
    std::cout << "|" << std::left << std::setw(14) << A.vardas 
              << "|" << std::left << std::setw(16) << A.pavarde << "|"
              << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_vid(A) << "|"
              << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_med(A)<<  "|\n";
};

double galutinis_vid(const studentas &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double suma = std::accumulate(A.paz.begin(), A.paz.end(), 0.0);
    double vidurkis = suma / A.paz.size();

    return 0.4 * vidurkis + 0.6 * A.exam;
};

double mediana(std::vector<int> paz){
    if (paz.empty()) return 0.0;

    std::sort(paz.begin(), paz.end());
    int n = paz.size();

    if (n % 2 != 0){
        return paz[n / 2];
    }
    else{
        return (paz[(n-1) / 2] + paz[n / 2]) / 2.0;
    }
}; 

double galutinis_med(const studentas &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double med = mediana(A.paz);
    
    return 0.4 * med + 0.6 * A.exam;
};

void generuoti_paz(studentas &A, int count, std::mt19937 &mt){
    std::uniform_int_distribution<int> dist(1, 10);

    for(int i = 1; i <= count; i++){
        int num = dist(mt);
        A.paz.push_back(num);
    }
    A.exam = dist(mt);
};

void rodyti_meniu(){
    std::cout << "\n------------------------------------------------\n";
    std::cout << "|           STUDENTŲ VALDYMO SISTEMA           |\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "| 1. Įvesti studentų duomenis rankiniu būdu    |\n";
    std::cout << "| 2. Generuoti studentų pažymius atsitiktinai  |\n";
    std::cout << "| 3. Nuskaityti duomenis iš failo              |\n";
    std::cout << "| 0. Baigti darbą                              |\n";
    std::cout << "------------------------------------------------\n";
};

void rodyti_lentele(const std::vector<studentas> &grupe){
    std::cout << '\n' << "Studentų duomenys: \n";
    std::cout << std::string(67, '-') << '\n';
    std::cout << "|" << std::left << std::setw(14) << "Vardas" 
              << "|" << std::left << std::setw(16) << "Pavardė" 
              << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
              << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    std::cout << std::string(67, '-') << '\n';
    for(const studentas &B : grupe) printas(B);
    std::cout << std::string(67, '-') << '\n';
};

void rankine_ivestis(std::vector<studentas> &grupe){
    int n;
    n = ar_skaicius("Įveskite studentų kiekį: ", 1, 100);

    for(int j=0; j < n; j++){
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
    }

};

void automatine_ivestis(std::vector<studentas> &grupe){
    int stud_kiekis;
    stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 10000000);
    
    int nd_kiekis;
    nd_kiekis = ar_skaicius("Įveskite kiek namų darbų pažymių norite sugeneruoti: ", 1, 10); 

    std::random_device rd;
    std::mt19937 mt(rd());

    for(int j=0; j < stud_kiekis; j++){
        studentas tempStudentas;
        tempStudentas.vardas = "Vardas" + std::to_string(j + 1);
        tempStudentas.pavarde = "Pavarde" + std::to_string(j + 1);
        generuoti_paz(tempStudentas, nd_kiekis, mt);
        grupe.push_back(tempStudentas);
    }
};

void failo_nuskaitymas(std::vector<studentas> &grupe, std::string failoPavadinimas){
    std::ifstream f(failoPavadinimas);

    if(!f.is_open()){
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << '\n';
        return;
    }
    
    std::string tekstas;

    std::getline (f, tekstas);
    while(std::getline(f, tekstas)){
        std::stringstream ss(tekstas);
        studentas tempStudentas;
        
        ss >> tempStudentas.vardas >> tempStudentas.pavarde;

        int skaicius;
        std::vector<int> visiSkaiciai;
        while (ss >> skaicius){
            visiSkaiciai.push_back(skaicius);
        }

        if (!visiSkaiciai.empty()){
            tempStudentas.exam = visiSkaiciai.back();
            visiSkaiciai.pop_back();
            tempStudentas.paz = visiSkaiciai;
        }

        grupe.push_back(tempStudentas);
    }

    f.close();
};

void rusiavimas(std::vector<studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(),
        [](const studentas &a, const studentas &b){
            if (a.pavarde != b.pavarde){
                return a.pavarde < b.pavarde;
            }
            return a.vardas < b.vardas;
    });
};

int ar_skaicius(std::string tekstas, int min, int max){
    int skaicius;
    while(true){
        std::cout << tekstas;
        if(std::cin >> skaicius && skaicius >= min && skaicius <= max){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return skaicius;
        }

        std::cout << "Klaida! Įveskite tinkama skaičių nuo " << min << " iki " << max << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}; 

void rasyti_i_faila(const std::vector<studentas> &grupe, std::string failoPavadinimas){
    std::ofstream f(failoPavadinimas);

    if (!f.is_open()) {
        std::cout << "Klaida! Nepavyko sukurti rezultatų failo.\n";
        return;
    }

    f << std::string(67, '-') << '\n';
    f << "|" << std::left << std::setw(14) << "Vardas" 
      << "|" << std::left << std::setw(16) << "Pavardė" 
      << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
      << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    f << std::string(67, '-') << '\n';

    for(const auto &s : grupe){
        f << "|" << std::left << std::setw(14) << s.vardas 
          << "|" << std::left << std::setw(16) << s.pavarde << "|"
          << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_vid(s) << "|"
          << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_med(s)<<  "|\n";
    }

    f.close();
    std::cout << "Rezultatai sėkmingai išsaugoti faile: " << failoPavadinimas << "\n";
};

void rodyti_rezultatus(const std::vector<studentas> &grupe) {
    int limit = 30; 

    if (grupe.size() > limit) {
        std::cout << "\nStudentų kiekis didelis (" << grupe.size() << ")."; 
        std::cout << "Rezultatai bus išsaugoti faile.\n";
        std::string failoPavadinimas;
        std::cout << "Įveskite failo pavadinim į kurį norite išsaugoti rezultatus: ";
        std::cin >> failoPavadinimas;
        rasyti_i_faila(grupe, failoPavadinimas);
    } else {
        rodyti_lentele(grupe);
    }
};

