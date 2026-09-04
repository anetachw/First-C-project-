// Pratybu programa 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct studentas{
    std::string vardas, pavarde;
    std::vector<int> paz;
    int exam;
    };
    
void printas(studentas A);

int main(){
    std::vector<studentas>grupe; 
    studentas A;
    int k;
    std::cout << "Iveskite studentu kieki: ";
    int n;
    std::cin >> n;
    for(int j=0; j < n; j++){
        std::cout << "Iveskite per tarpa studentu varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cout << "Iveskite semestro pazymiu kieki: ";
        std::cin >> k;
        
        for (int i = 0; i < k; i++){
            //std::cin >> A.paz[i];
            std::cout << "Iveskite " << i+1 << " pazymi: ";
            int a;
            std::cin >> a;
            A.paz.push_back(a);
        }
    
    std::cout << "Iveskite egzamino pazymi: ";
    std::cin >> A.exam;
    grupe.push_back(A);
    A.pavarde.clear();
    A.vardas.clear();
    A.paz.clear();
    }
    
    std::cout << "Studento duomenys: \n";
    for(studentas B:grupe) printas(B);
}

void printas(studentas A){
    std::cout << "|" << std::left << std::setw(10) << A.vardas << "|" << std::left << std::setw(10) << A.pavarde << "|";
    for(int p: A.paz)
    std::cout << std::right << std::setw(3) << p << "|";
    std::cout << std::right << std::setw(5) << "|\n";
}
