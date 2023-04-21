#include "include/file.hpp"

/**
 * @brief remove pasta a base/checkout com arquivos e subpastas dentro
 * entao eh criado novamente as pasta base/checkout e subpastas
 */
void File::removeThanCreate() {
    std::uintmax_t n = fs::remove_all(_resource);
    cout << "Removido " << n << " arquivos ou diretorios" << endl;

    std::filesystem::create_directories(_resource);
    std::filesystem::create_directories(_resource + "/matriz");
    std::filesystem::create_directories(_resource + "/geracoes");
}

/**
 * @brief realiza a leitura do arquivo input.data e cria as matrizes de checkout
 *
 */
void File::readThanCreate() {
    ifstream myfile(_input);
    string line;

    Util util;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            _fileName.clear();
            util.tokenizar(line, _fileName, _vecInput);
            createMatriz();
        }
        myfile.close();
    } else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void File::createFile() {
    this->removeThanCreate();

    ofstream myfile(_input);
    string line;

    if (myfile.is_open()) {
        srand(time(nullptr));

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < 8; j++)
                myfile << (1 + rand() % 8) << " ";
            myfile << endl;
        }
        myfile.close();
    } else cout << "Nao foi possivel abrir o arquivo" << endl;

    this->readThanCreate();
}

void File::createMatriz() {
    string path = _resource;
    path.append("/matriz/").append(_fileName).append(".data");
    ofstream myfile(path);

    string line;
    int col = 0;

    int matriz[N][N] = { 0 };

    if (myfile.is_open()) {
        while (!_vecInput.empty()) {
            int line = _vecInput.front();
            _vecInput.pop();
            matriz[N - line][col++] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                myfile << matriz[i][j] << " ";
            myfile << endl;
        }
        myfile.close();
    } else cout << "Nao foi possivel abrir o arquivo" << endl;
}