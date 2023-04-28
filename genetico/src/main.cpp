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

    cout << "Gerando novas populacoes ..." << endl;

    for (int i = 0; i < MAX; i++) {
        quant++;
        g.genetic_algorithm();
        if (g.getMax().second == 100) break;
    }
    cout << quant << " geracoes " << " [ ";
    cout << g.getMax().first << " : " << g.getMax().second << " ] ";

    int matriz[N][N] = { 0 };
    int col = 0;

    cout << endl;
    for (const auto &num : g.getMax().first)
        matriz[N - (num - '0')][col++] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    t2 = steady_clock::now();
    double tempo = duration_cast<duration<double>>(t2 - t1).count();

    cout << "\ntempo total: " << tempo << " s" << endl;
}

int main() {
    variacoes();
    // int m = 10;
    // vector<std::thread> threads;

    // for (int i = 0; i < m; i++) variacoes();
    //     threads.push_back(std::thread(variacoes));

    // for (auto &th : threads) th.join();

    return 0;
}