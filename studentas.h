#pragma once

#include <string>
#include <vector>
#include <list>


struct studentasv{
    std::string vardas, pavarde;
    std::vector<int> paz;
    int exam;
};

struct studentasl{
    std::string vardas, pavarde;
    std::list<int> paz;
    int exam;
};