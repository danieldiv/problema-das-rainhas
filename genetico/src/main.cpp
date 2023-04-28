#include "include/genetica.hpp"

#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

int main() {
    Genetica g;
    int quant = 0;

    steady_clock::time_point t1;
    steady_clock::time_point t2;

    t1 = steady_clock::now();

    cout << "Gerando novas populacoes ..." << endl;

    for (int i = 0; i < MAX; i++) {
        quant++;
        g.genetic_algorithm();
        if (g.getMax().second == 100)break;
    }
    cout << quant << " geracoes" << endl << endl;
    cout << g.getMax().first << " " << g.getMax().second << endl << endl;

    int val;
    int col = 0;
    int matriz[N][N] = { 0 };

    for (const auto &num : g.getMax().first)
        matriz[N - (num - '0')][col++] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    t2 = steady_clock::now();
    double tempo = duration_cast<duration<double>>(t2 - t1).count();

    cout << endl << "tempo total: " << tempo << " s" << endl;

    return 0;
}