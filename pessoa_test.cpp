#include <gtest/gtest.h>
#include <sstream>
#include "pessoa.h"

using namespace CppMasterClass::Pessoa;

//
// Testes para a classe Pessoa
//
TEST(PessoaTest, ConstrutorPadrao) {
    Pessoa p;

    // Esperamos que o construtor padrão deixe o CPF vazio,
    // renda e idade como zero (ou valores default).
    EXPECT_TRUE(p.obterCpf().empty());
    EXPECT_DOUBLE_EQ(p.obterRenda(), 0.0);
    EXPECT_EQ(p.obterIdade(), 0);
}

TEST(PessoaTest, ConstrutorParametrizado) {
    Pessoa p("12345678901", 3500.0, 25);

    EXPECT_EQ(p.obterCpf(), "12345678901");
    EXPECT_DOUBLE_EQ(p.obterRenda(), 3500.0);
    EXPECT_EQ(p.obterIdade(), 25);
}

TEST(PessoaTest, ValidarPessoaValida) {
    // Usa um CPF válido e que não é composto por todos os dígitos iguais
    // Renda > RENDA_MINIMA e idade entre 18 e 70
    Pessoa p("94089300029", 3000.0, 30);

    bool result = p.validarPessoa();
    EXPECT_TRUE(result); // Espera-se verdadeiro
}

TEST(PessoaTest, ValidarPessoaInvalidaPorCPF) {
    // Exemplo de CPF com todos os dígitos iguais: "11111111111"
    // Isso deve invalidar o CPF
    Pessoa p("11111111111", 3000.0, 30);

    bool result = p.validarPessoa();
    EXPECT_FALSE(result); // Espera-se falso
}

TEST(PessoaTest, ValidarPessoaInvalidaPorRenda) {
    // Renda abaixo do mínimo de 2000.00
    Pessoa p("94089300029", 1500.0, 30);

    bool result = p.validarPessoa();
    EXPECT_FALSE(result);
}

TEST(PessoaTest, ValidarPessoaInvalidaPorIdade) {
    // Idade fora do intervalo [18..70]
    Pessoa p("94089300029", 3000.0, 10); // Muito jovem

    bool result = p.validarPessoa();
    EXPECT_FALSE(result);

}

TEST(PessoaTest, ListarPessoasComProdutoContratado) {
    Pessoa p;
    // vetor deve estar vazio inicialmente
    EXPECT_TRUE(p.pessoasComProdutosContratados.empty());

    p.listarPessoasComProdutoContratado();
    // Agora deve ter 5 pessoas no vetor
    EXPECT_EQ(p.pessoasComProdutosContratados.size(), 5u);

    // Verifica se algum CPF esperado está na lista
    EXPECT_EQ(p.pessoasComProdutosContratados[0].obterCpf(), "60402039009");
    EXPECT_EQ(p.pessoasComProdutosContratados[1].obterCpf(), "68269984086");
    // ...
}

TEST(PessoaTest, ValidarRegrasRetornaFalseSeCPFNaLista) {
    // "41852198060" consta em listarPessoasComProdutoContratado()
    Pessoa p("41852198060", 3000, 40);
    bool regrasOk = p.validarRegras();

    EXPECT_FALSE(regrasOk); // Deve retornar false pois esse CPF já possui produto
}

TEST(PessoaTest, ValidarRegrasRetornaTrueSeCPFNaoListado) {
    // CPF que não está na lista de pessoas com produtos
    Pessoa p("99999999999", 3000, 40);
    bool regrasOk = p.validarRegras();

    EXPECT_TRUE(regrasOk); // Deve retornar true pois esse CPF não possui produto
}

TEST(PessoaTest, ConverteCpfParaValidacao) {
    // Verifica se a função está realmente convertendo
    std::string cpfOriginal = "94089300029";
    char* cpfConvertido = Pessoa::converteCpfParaValidacao(cpfOriginal);

    // Ao converter, deve manter mesmo conteúdo e acrescentar '\0' no final
    // Vamos verificar caractere a caractere
    for (size_t i = 0; i < cpfOriginal.size(); ++i) {
        EXPECT_EQ(cpfConvertido[i], cpfOriginal[i]);
    }
    // E verificar se tem just '\0' no final
    EXPECT_EQ(cpfConvertido[cpfOriginal.size()], '\0');

    // Precisamos desalocar manualmente, pois converteCpfParaValidacao() dá um .release()
    delete[] cpfConvertido;
}

TEST(PessoaTest, TestOperadorDeInsercao) {
    // Cria uma pessoa e imprime
    Pessoa p("99999999999", 2500.0, 35);
    std::ostringstream oss;
    oss << p; // Usa o operador <<

    std::string output = oss.str();
    // Verifica se contém informações esperadas
    EXPECT_NE(output.find("99999999999"), std::string::npos); // CPF deve aparecer
    EXPECT_NE(output.find("2500"), std::string::npos);        // Renda deve aparecer
    EXPECT_NE(output.find("35"), std::string::npos);          // Idade deve aparecer
}
