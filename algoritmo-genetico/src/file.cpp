#include "include/file.hpp"

/**
 * @brief remove a pasta base/resource com arquivos e subpastas dentro
 * entao eh criado novamente as pasta base/resource e subpastas
 */
void File::removeThanCreate() {
    std::uintmax_t n_resource = fs::remove_all(_resource);
    std::uintmax_t n_logs = fs::remove_all(_log);
    cout << "Removendo " << n_resource + n_logs << " arquivos e/ou diretorios" << endl;

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
        createLog(p.orderPopulacao());
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
 * @brief Cria um arquivo adicionando a geracao atual
 *
 * @param ordered
 */
void File::createLog(type_order ordered) {
    ofstream myfile(_log, std::ios::app);
    string line;

    if (myfile.is_open()) {
        myfile << "Geracao: " << _geracao++ << endl;
        for (const auto &[key, value] : ordered) {
            myfile << key << " " << value << endl;
        }
        myfile << endl;
        myfile.close();
    } else cout << "Nao foi possivel abrir o arquivo" << endl;

}

/**
 * @brief gera uma matriz com as localizacoes das 8 rainhas
 *
 */
void File::createMatriz(Populacao &p) {
    int col = 0;
    int matriz[N][N] = { 0 };

    while (!_vecInput.empty()) {
        int line = _vecInput.front();
        _vecInput.pop();
        matriz[N - line][col++] = 1;
        p.setInput(line);
    }
    p.setVariante(_fileName, matriz);
}

void File::printMatriz(int(&matriz)[N][N]) {
    cout << endl << _fileName << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}