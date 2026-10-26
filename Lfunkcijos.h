#pragma once 

#include "studentas.h"
#include <string>
#include <list>
#include <random>


void rankine_ivestis(std::list<studentasl> &grupe);

void automatine_ivestis(std::list<studentasl> &grupe, std::mt19937 &mt);

void nuskaityti_faila(std::list<studentasl> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::list<studentasl> &grupe);

void rusiavimasG(std::list<studentasl> &grupe);

void dalinti_studentus1(std::list<studentasl> &grupe, std::list<studentasl> &kietiakai, std::list<studentasl> &vargsiukai);

void dalinti_studentus2(std::list<studentasl> &grupe, std::list<studentasl> &vargsiukai);

void dalinti_studentus3(std::list<studentasl> &grupe, std::list<studentasl> &vargsiukai);