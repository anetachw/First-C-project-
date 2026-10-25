#pragma once 

#include "studentas.h"
#include <string>
#include <random>


void rankine_ivestis(std::vector<studentasv> &grupe);
void automatine_ivestis(std::vector<studentasv> &grupe, std::mt19937 &mt);
void nuskaityti_faila(std::vector<studentasv> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::vector<studentasv> &grupe);
void rusiavimasG(std::vector<studentasv> &grupe);

void dalinti_studentus(std::vector<studentasv> &grupe, std::vector<studentasv> &kietiakai, std::vector<studentasv> &vargsiukai);
