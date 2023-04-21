#include "include/util.hpp"

void Util::tokenizar(std::string text, std::string &fileName, std::queue<int> &vec) {
    char del = ' ';

    std::stringstream sstream(text);
    std::string token;

    while (getline(sstream, token, del)) {
        fileName.append(token);
        vec.push(atoi(token.c_str()));
    }
}