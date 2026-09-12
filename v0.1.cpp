// student management program
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>


struct studentas{
    std::string vardas, pavarde;
    std::vector<int> paz;
    int exam;
    };
    
void printas(studentas &A);
double galutinis_vid(studentas &A);
double mediana(std::vector<int> paz);
double galutinis_med(studentas &A);
void generuoti_paz(studentas &A, int count);
void rodyti_meniu();
void rodyti_lentele(std::vector<studentas> &grupe);
void rankine_ivestis(std::vector<studentas> &grupe, studentas &A);
void automatine_ivestis(std::vector<studentas> &grupe, studentas &A);


int main(){
    srand(time(NULL));
    std::vector<studentas>grupe; 
    studentas A;
    int pasirinkimas;

    do{
        rodyti_meniu();
        std::cin >> pasirinkimas;

        switch(pasirinkimas){
            case 1:
                rankine_ivestis(grupe, A);
                rodyti_lentele(grupe);
                break;
            case 2:
                automatine_ivestis(grupe, A);
                rodyti_lentele(grupe);
                break;
            default:
                std::cout << "Netinkamas pasirinkimas";
        }

    } while(pasirinkimas != 0);

};

void printas(studentas &A){
    std::cout << "|" << std::left << std::setw(10) << A.vardas 
              << "|" << std::left << std::setw(10) << A.pavarde << "|"
              << std::left << std::setw(16) << std::setprecision(2)<< galutinis_vid(A) << "|"
              << std::left << std::setw(16) << std::setprecision(2)<< galutinis_med(A)<<  "|\n";
};

double galutinis_vid(studentas &A){
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

double galutinis_med(studentas &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double med = mediana(A.paz);
    
    return 0.4 * med + 0.6 * A.exam;
};

void generuoti_paz(studentas &A, int count){
    for(int i = 1; i <= count; i++){
        int num = (rand() % 10) + 1;
        A.paz.push_back(num);
    }
    A.exam = (rand() % 10) + 1;
};

void rodyti_meniu(){
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "         STUDENTU VALDYMO MENIU\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "1. Ivesti studentu duomenis rankiniu budu\n";
    std::cout << "2. Generuoti studentu pazymius atsitiktinai\n";
    std::cout << "0. Baigti darba\n";
    std::cout << "\nPasirinkite veiksma: ";
};

void rodyti_lentele(std::vector<studentas> &grupe){
    std::cout << '\n' << "Studentu duomenys: \n";
    std::cout << std::string(57, '-') << '\n';
    std::cout << "|" << std::left << std::setw(10) << "Vardas" 
              << "|" << std::left << std::setw(10) << "Pavarde" 
              << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
              << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    std::cout << std::string(57, '-') << '\n';
    for(studentas &B:grupe) printas(B);
    std::cout << std::string(57, '-') << '\n';
};

void rankine_ivestis(std::vector<studentas> &grupe, studentas &A){
    std::cout << "Iveskite studentu kieki: ";
    int n;
    std::cin >> n;

    for(int j=0; j < n; j++){
        std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string input1;
        std::cout << "Iveskite namu darbu pazymius.\n";
        std::cout << "Palikite tusia ir spauskite ENTER, kad testi.\n";
        int i = 1;

        do {
            std::cout << "Iveskite #" << i << " pazymi: ";
            std::getline(std::cin, input1);
            if (!input1.empty()){
                try {
                    int a = std::stoi(input1);
                    if (a >= 1 && a <= 10){
                        A.paz.push_back(a);
                        i++;
                    }
                    else {
                        std::cout << "Klaida! Pazymis turi buti nuo 1 iki 10.\n";
                    }
                }
                catch (...){
                    std::cout << "Klaida! Ivedete ne skaiciu, bandykite dar karta.\n";
                }
            }     
        } while(!input1.empty());

        std::string input2;
        while (true) {
            std::cout << "Iveskite egzamino pazymi: ";
            std::getline(std::cin, input2);

            try{
                A.exam = std::stoi(input2);
                if (A.exam >= 1 && A.exam <= 10){
                    grupe.push_back(A);
                    break;
                }
                else {
                    std::cout << "Klaida! Pazymis turi buti nuo 1 iki 10.\n";
                }
            } catch (...) {
                std::cout << "Klaida! Ivedete ne skaiciu, bandykite dar karta.\n";
            }
        }

        A.pavarde.clear();
        A.vardas.clear();
        A.paz.clear();
    }

};

void automatine_ivestis(std::vector<studentas> &grupe, studentas &A){
    std::cout << "Iveskite studentu kieki: ";
    int n;
    std::cin >> n;

    for(int j=0; j < n; j++){
        std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Iveskite kiek namu darbu pazymiu norite sugeneruoti: ";
        int kiekis;
        std::cin >> kiekis;
        generuoti_paz(A, kiekis);

        std::cout << "Namu darbu pazymiai: ";
        for ( int p: A.paz) {
            std::cout << p << " ";
        }
        std::cout << '\n';
        std::cout << "Egzamino pazymis: " << A.exam << '\n';
        grupe.push_back(A);

        A.pavarde.clear();
        A.vardas.clear();
        A.paz.clear();
    }
}
