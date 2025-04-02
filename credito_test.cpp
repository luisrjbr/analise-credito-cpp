#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "credito.h"
#include "pessoa.h"
#include "fraude.h"
#include "score.h"

using testing::Return;

// ======================================
// Mock da classe Score
// ======================================
class MockScore : public CppMasterClass::Credito::Score {
public:
    MOCK_METHOD(CppMasterClass::Credito::ScoreDeRisco, calcularScore,
                (CppMasterClass::Pessoa::Pessoa& pessoa),
                (noexcept));
};

// ======================================
// Classe derivada para injetar Score
// ======================================
class TestCredito : public CppMasterClass::Credito::Credito {
public:
    void setScore(std::unique_ptr<CppMasterClass::Credito::Score> score) {
        m_score = std::move(score);
    }
};

using namespace CppMasterClass::Credito;
namespace testing = ::testing;

// ======================================
// Teste: analisarRegrasPreCredito
// ======================================

// 1) Caso de falha: Fraude retorna false
//    - Usar um CPF que NÃO está em Fraude, e assim Fraude::validarRegras() = false
TEST(CreditoTest, AnalisarRegrasPreCreditoFalhaPorFraude) {
    TestCredito credito;

    // "99999999999" não aparece em Fraude::listarPessoasComFraude()
    CppMasterClass::Pessoa::Pessoa p("99999999999", 5000, 40);

    bool resultado = credito.analisarRegrasPreCredito(p);
    EXPECT_FALSE(resultado);
    EXPECT_FALSE(credito.mensagemRegrasPreCredito.empty());
}

// 2) Caso de falha: Pessoa falha (CPF inválido)
TEST(CreditoTest, AnalisarRegrasPreCreditoFalhaPorPessoa) {
    TestCredito credito;

    // CPF com todos os dígitos iguais => invalidado
    CppMasterClass::Pessoa::Pessoa p("11111111111", 3000, 30);

    bool resultado = credito.analisarRegrasPreCredito(p);
    EXPECT_FALSE(resultado);
    EXPECT_FALSE(credito.mensagemRegrasPreCredito.empty());
}

// 3) Caso de falha: Pessoa está na lista de produtos contratados
//    Ex. CPF "41852198060" -> consta em listarPessoasComProdutoContratado(),
//    então Pessoa::validarRegras() = false. Mesmo se Fraude fosse true,
//    a parte do "resultadoPessoa" falha.
TEST(CreditoTest, AnalisarRegrasPreCreditoFalhaPorPessoaJaPossuiProduto) {
    TestCredito credito;

    // "41852198060" -> está em Pessoa::listarPessoasComProdutoContratado()
    CppMasterClass::Pessoa::Pessoa p("41852198060", 3000, 30);

    bool resultado = credito.analisarRegrasPreCredito(p);
    EXPECT_FALSE(resultado);
    EXPECT_FALSE(credito.mensagemRegrasPreCredito.empty());
}

// ======================================
// Teste: informarLimiteDeCredito
// ======================================
TEST(CreditoTest, InformarLimiteDeCreditoAlto) {
    TestCredito credito;
    auto mockScore = std::make_unique<MockScore>();
    EXPECT_CALL(*mockScore, calcularScore(testing::_))
        .WillRepeatedly(Return(ScoreDeRisco::ALTO));  // Força ALTO

    credito.setScore(std::move(mockScore));

    CppMasterClass::Pessoa::Pessoa p("94089300029", 3000.0, 30);
    float limite = credito.informarLimiteDeCredito(p);

    EXPECT_FLOAT_EQ(limite, 3000.0f);
    EXPECT_FLOAT_EQ(credito.creditoFornecido, 3000.0f);
}

// ======================================
// Teste: obterNumeroParcelasDoCredito
// ======================================
TEST(CreditoTest, ObterNumeroParcelasDoCredito) {
    TestCredito credito;
    // Força um valor de créditoFornecido > 0
    credito.creditoFornecido = 4000.0f;

    float maiorParcela = credito.obterNumeroParcelasDoCredito();
    // Observando a lógica, arrParcelas é de int:
    //
    //   arrParcelas[0] = 1000 + (1000 * 0.01) = 1010 (int truncado)
    //   arrParcelas[1] = 1010 + (1010 * 0.01) = 1010 + 10.1  => 1020 (int truncado)
    //   arrParcelas[2] = 1020 + (1020 * 0.01) = 1020 + 10.2  => 1030 (int truncado)
    //   arrParcelas[3] = 1030 + (1030 * 0.01) = 1030 + 10.3  => 1040 (int truncado)
    //
    // maiParcela = 1040
    EXPECT_FLOAT_EQ(maiorParcela, 1040.0f);
}

// ======================================
// Teste: obterScore
// ======================================
TEST(CreditoTest, ObterScoreValido) {
    TestCredito credito;
    auto mockScore = std::make_unique<MockScore>();
    // Não precisamos de expectativa específica aqui,
    // pois só queremos garantir que obterScore() funciona
    credito.setScore(std::move(mockScore));

    const Score& s = credito.obterScore();
    // Se não deu crash, tá ok.
    SUCCEED();
}
