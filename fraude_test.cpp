#include <gtest/gtest.h>
#include "fraude.h"
#include "pessoa.h"

using namespace CppMasterClass::Credito;
using namespace CppMasterClass::Pessoa;

//
// Teste de unidade para a classe Fraude
//
TEST(FraudeTest, ConstrutorPadrao) {
    // Construtor padrão
    Fraude f;

    // Verifica se a pessoaParaAnaliseFraude ainda está "vazia"
    // (ou seja, sem CPF definido). Depende de como você deseja
    // considerar o estado inicial. Aqui, assumimos que, se não
    // passamos nada, o CPF fica vazio.
    EXPECT_TRUE(f.pessoaParaAnaliseFraude.obterCpf().empty());

    // Verifica se o vetor de fraudes está inicialmente vazio
    // antes de chamar listarPessoasComFraude()
    EXPECT_EQ(f.pessoasComFraude.size(), 0u);
}

TEST(FraudeTest, ConstrutorComPessoa) {
    // Cria uma pessoa para análise
    Pessoa p("99999999999", 3000.0, 40);

    // Cria o objeto Fraude passando a pessoa
    Fraude f(p);

    // Verifica se a pessoa armazenada no Fraude é mesma
    EXPECT_EQ(f.pessoaParaAnaliseFraude.obterCpf(), "99999999999");
    EXPECT_DOUBLE_EQ(f.pessoaParaAnaliseFraude.obterRenda(), 3000.0);
    EXPECT_EQ(f.pessoaParaAnaliseFraude.obterIdade(), 40);
}

TEST(FraudeTest, ListarPessoasComFraudePopulaLista) {
    Fraude f;

    // Lista deve estar vazia antes
    EXPECT_EQ(f.pessoasComFraude.size(), 0u);

    // Chama o método para popular
    f.listarPessoasComFraude();

    // Agora deve conter as 4 pessoas fixas
    EXPECT_EQ(f.pessoasComFraude.size(), 4u);

    // Verifica alguns CPFs
    EXPECT_EQ(f.pessoasComFraude[0].obterCpf(), "94089300029");
    EXPECT_EQ(f.pessoasComFraude[1].obterCpf(), "44440285058");
    EXPECT_EQ(f.pessoasComFraude[2].obterCpf(), "71925017001");
    EXPECT_EQ(f.pessoasComFraude[3].obterCpf(), "41852198060");
}

TEST(FraudeTest, ValidarRegrasRetornaTrueParaCPFNaLista) {
    // 1) CPF que está incluído em listarPessoasComFraude()
    //    Exemplo: "94089300029"
    Pessoa p("94089300029", 3000.0, 30);
    Fraude f(p);

    bool result = f.validarRegras();

    // Espera-se true, pois a pessoa com esse CPF está na lista de fraude
    EXPECT_TRUE(result);
}

TEST(FraudeTest, ValidarRegrasRetornaFalseParaCPFNaoListado) {
    // 2) CPF que NÃO está em listarPessoasComFraude()
    //    Exemplo: "99999999999"
    Pessoa p("99999999999", 3000.0, 30);
    Fraude f(p);

    bool result = f.validarRegras();

    // Espera-se false, pois a pessoa com esse CPF NÃO está na lista
    EXPECT_FALSE(result);
}

TEST(FraudeTest, ObterDescricaoValidacao) {
    // Verifica a string DESCRICAO = "Fraude!"
    Fraude f;
    EXPECT_EQ(f.obterDescricaoValidacao(), "Fraude!");
}
