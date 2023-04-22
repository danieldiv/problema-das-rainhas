#include "include/file.hpp"

/**
 * @brief remove a pasta base/resource com arquivos e subpastas dentro
 * entao eh criado novamente as pasta base/resource e subpastas
 */
void File::removeThanCreate() {
    std::uintmax_t n = fs::remove_all(_resource);
    cout << "Removendo " << n << " arquivos e/ou diretorios" << endl;

    std::filesystem::create_directories(_resource);
    std::filesystem::create_directories(_resource + "/matriz");
    std::filesystem::create_directories(_resource + "/geracoes");
}

/**
 * @brief realiza a leitura do arquivo input.data e cria as matrizes de checkout
 *
 */
void File::readThanCreate(Populacao &p) {
    ifstream myfile(_input);
    string line;

    Util util;

    if (myfile.is_open()) {
        cout << "Lendo arquivo de entrada" << endl;
        cout << "Gerando matrizes a partir da populacao" << endl;
        cout << "Contabilizando rainhas que se atacam" << endl;

        while (getline(myfile, line)) {
            _fileName.clear();
            util.tokenizar(line, _fileName, _vecInput);
            createMatriz(p);
        }
        myfile.close();
    } else cout << "Nao foi possivel abrir o arquivo" << endl;
}

/**
 * @brief cria uma populacao de tamanho MAX
 *
 * O tamanho da populacao eh a quantidade de variacoes do conjunto de 8 rainhas (individuos)
 *
 * Exemplo: 1 4 4 2 1 5 1 5
 */
void File::createFile(Populacao &p) {
    this->removeThanCreate();

    ofstream myfile(_input);
    string line;

    if (myfile.is_open()) {
        cout << "Criando populacao aleatoria de tamanho " << MAX << " com " << N << " individuos" << endl;
        srand(time(nullptr));

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < N; j++)
                myfile << (1 + rand() % N) << " ";
            myfile << endl;
        }
        myfile.close();
    } else cout << "Nao foi possivel abrir o arquivo" << endl;

    this->readThanCreate(p);
}

/**
 * @brief realiza a leitura do arquivo input.data para gerar uma matriz e armazenar em arquivos
 *
 * o arquivo gerado contera o nome das posicoes das rainhas na matriz
 */
void File::createMatriz(Populacao &p) {
    // string path = _resource;
    // path.append("/matriz/").append(_fileName).append(".data");
    // ofstream myfile(path);

    // string line;
    int col = 0;

    int matriz[N][N] = { 0 };

    while (!_vecInput.empty()) {
        int line = _vecInput.front();
        _vecInput.pop();
        matriz[N - line][col++] = 1;

        p.setInput(line);
    }
    p.setVariante(_fileName, matriz);

    // if (myfile.is_open()) {
    //     while (!_vecInput.empty()) {
    //         int line = _vecInput.front();
    //         _vecInput.pop();
    //         matriz[N - line][col++] = 1;

    //         p.setInput(line);
    //     }
    //     p.setVariante(_fileName, matriz);

    //     for (int i = 0; i < N; i++) {
    //         for (int j = 0; j < N; j++)
    //             myfile << matriz[i][j] << " ";
    //         myfile << endl;
    //     }
    //     myfile.close();
    // } else cout << "Nao foi possivel abrir o arquivo" << endl;
}