#include "include/genetica.hpp"

#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

void variacoes() {
    Genetica g;
    int quant = 0;

    steady_clock::time_point t1;
    steady_clock::time_point t2;

    t1 = steady_clock::now();

    for (int i = 0; i < MAX; i++) {
        quant++;
        g.genetic_algorithm();
        if (g.getMax().second == 100) break;
    }
    cout << quant << " geracoes " << " [ ";
    cout << g.getMax().first << " : " << g.getMax().second << " ] ";

    t2 = steady_clock::now();
    double tempo = duration_cast<duration<double>>(t2 - t1).count();

    cout << tempo << " s" << endl;
}

int main() {
    int m = 20;
    vector<std::thread> threads;

    for (int i = 0; i < m; i++)
        threads.push_back(std::thread(variacoes));

    for (auto &th : threads) th.join();

    return 0;
}