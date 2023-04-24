#include "include/file.hpp"
#include "include/genetica.hpp"

int main() {
    File f;
    Genetica g;

    f.createFile(g.getPopulacao());
    // p.showPopulacao();

    return 0;
}

/*
1) Inicialize a população de indivíduos. ========= OK

2) Avalie cada indivíduos na população. ========== OK

3) Selecione os melhores pais para gerar novos indivíduos.
Aplique os operadores  de recombinação e mutação a estes
pais de forma a gerar os indivíduos da nova  geração.

4) Apague os velhos membros da população.

5) Avalie todos os novos indivíduos e insira-os na população

6) Se o tempo acabou, ou o melhor indivíduos satisfaz os requerimentos da
solução do problema, retorne-o, caso contrário volte para o passo 3.
*/

// sobrevivencia do mais forte (melhor fitness)
// mantem 1..N individuos atravez d (clonagem)
// (reproducao) sexuada -> formacao de novo individuo atravez da combinaco de dois pais
// o genes dos pais sao recombinados (crossing-over)
// podem sofrer (mutacoes) 5%

// selecao da geracao
// 5% dos mais fortes sao (clonados) e adicionados na proxima geracao
// existe uma (chance) de 1% para enviar o mais fraco para a proxima geracao
// 5% dos mais fracos eh (desconsiderado) para reproducao
// populacao restante eh feita a (reproducao)

// privilegiar os mais fortes, mas nao despresar os mais fracos