//
// Created by pablorod on 3/29/2017.
//

#ifndef ANPI_POL_STRINGUTILS_H
#define ANPI_POL_STRINGUTILS_H
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <complex>
template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::vector<std::complex<double>> splitDouble(std::string &s , std::string &delimiter)
{
    std::vector<std::complex<double>> result ={(0.0,0.0)};
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::complex<double> d =atof(token.c_str());
        result.insert(result.begin(),d);
        s.erase(0, pos + delimiter.length());
    }
    result.insert(result.begin(),atof(s.c_str()));
    result.pop_back();
    return result;
}
#endif //ANPI_POL_STRINGUTILS_H
