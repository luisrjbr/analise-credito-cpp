#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "score.h"
#include "pessoa.h"

using namespace CppMasterClass::Credito;
using namespace CppMasterClass::Pessoa;

// ======================================
// Mock da classe Pessoa
// ======================================
class MockPessoa : public Pessoa {
public:
    MOCK_METHOD(double, obterRenda, (), (const, override));
    MOCK_METHOD(short, obterIdade, (), (const, override));
};

// ======================================
// Teste: calcularScore
// ======================================

TEST(ScoreTest, CalcularScoreRiscoAltoPessoaIdadeEntre18e30eRendade5000) {
    MockPessoa mockPessoa;

    // Configurar o mock para simular uma pessoa com idade entre 18 e 30 e renda de 5000
    EXPECT_CALL(mockPessoa, obterIdade()).WillRepeatedly(::testing::Return(25));
    EXPECT_CALL(mockPessoa, obterRenda()).WillRepeatedly(::testing::Return(5000.0));

    Score score;
    ScoreDeRisco resultado = score.calcularScore(mockPessoa);

    EXPECT_EQ(resultado, ScoreDeRisco::ALTO);
}

TEST(ScoreTest, CalcularScoreRiscoMedioPessoaIdadeEntre18e30eRendaMaiorQue10000) {
    MockPessoa mockPessoa;

    // Configurar o mock para simular uma pessoa com idade entre 18 e 30 e renda maior que 10000
    EXPECT_CALL(mockPessoa, obterIdade()).WillRepeatedly(::testing::Return(25));
    EXPECT_CALL(mockPessoa, obterRenda()).WillRepeatedly(::testing::Return(11000.0));

    Score score;
    ScoreDeRisco resultado = score.calcularScore(mockPessoa);

    EXPECT_EQ(resultado, ScoreDeRisco::MEDIO);
}

TEST(ScoreTest, CalcularScoreRiscoMedioPessoaIdadeEntre31e60eRendaEntr2000e10000) {
    MockPessoa mockPessoa;

    // Configurar o mock para simular uma pessoa com idade entre 31 e 60 e renda de 5000
    EXPECT_CALL(mockPessoa, obterIdade()).WillRepeatedly(::testing::Return(40));
    EXPECT_CALL(mockPessoa, obterRenda()).WillRepeatedly(::testing::Return(5000.0));

    Score score;
    ScoreDeRisco resultado = score.calcularScore(mockPessoa);

    EXPECT_EQ(resultado, ScoreDeRisco::MEDIO);
}


TEST(ScoreTest, CalcularScoreRiscoBaixoPessoaIdadeEntre31e60eRendaDe15000) {
    MockPessoa mockPessoa;

    // Configurar o mock para simular uma pessoa com idade entre 31 e 60 e renda de 15000
    EXPECT_CALL(mockPessoa, obterIdade()).WillRepeatedly(::testing::Return(40));
    EXPECT_CALL(mockPessoa, obterRenda()).WillRepeatedly(::testing::Return(15000.0));

    Score score;
    ScoreDeRisco resultado = score.calcularScore(mockPessoa);

    EXPECT_EQ(resultado, ScoreDeRisco::BAIXO);
}

TEST(ScoreTest, CalcularScoreRiscoIndefinido) {
    MockPessoa mockPessoa;

    // Configurar o mock para simular uma pessoa com idade fora do intervalo válido
    EXPECT_CALL(mockPessoa, obterIdade()).WillRepeatedly(::testing::Return(17));
    EXPECT_CALL(mockPessoa, obterRenda()).WillRepeatedly(::testing::Return(1000.0));

    Score score;
    ScoreDeRisco resultado = score.calcularScore(mockPessoa);

    EXPECT_EQ(resultado, ScoreDeRisco::INDEFINIDO);
}
