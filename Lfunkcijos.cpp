#include "basic_funkcijos.h"
#include "Lfunkcijos.h"
#include "Tfunkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <chrono>


void rankine_ivestis(std::vector<studentas> &grupe);
void automatine_ivestis(std::vector<studentas> &grupe, std::mt19937 &mt);
void nuskaityti_faila(std::vector<studentas> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::vector<studentas> &grupe);
void rusiavimasG(std::vector<studentas> &grupe);

void dalinti_studentus(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, std::vector<studentas> &vargsiukai);
void spartos_analize(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, 
                     std::vector<studentas> &vargsiukai, std::string failoPavadinimas, int kartojimai);
