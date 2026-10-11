// studentu valdymo programa
#include <iostream>
#include "studentas.h"
#include "basic_funkcijos.h"
#include "Vfunkcijos.h"
#include "Lfunkcijos.h"
#include <array>
#include <list>


int main(){
    std::random_device rd;
    std::mt19937 mt(rd());

    rodyti_konteineri();
    int konteineris = ar_skaicius("\nPasirinkite konteinerį (1-2): ", 1, 2);
    
    if (konteineris == 1){
        paleisti_programa<std::vector<studentas>>(mt);
    }
    else if (konteineris == 2){
        paleisti_programa<std::list<studentas>>(mt);
    }
}