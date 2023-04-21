#ifndef UTIL_HPP__
#define UTIL_HPP__

#include <sstream>
#include <string>
#include <queue>

class Util {
private:
public:
    void tokenizar(std::string text, std::string &fileName, std::queue<int> &vec);
};

#endif