#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cstdint>

enum class RendaMinima
{
    RENDA_MINIMA = 2000
};

enum class IdadeMinimaMaxima
{
    IDADE_MINIMA = 18, IDADE_MAXIMA = 70
};


class Pessoa
{
public:

    //

    Pessoa() = default;
    Pessoa(std::string cpf, double renda, uint8_t idade);

    //

    std::vector<Pessoa> pessoasComProdutosContratados;
    static constexpr std::string DESCRICAO = "Pessoa!";

    //

    int validarCPF(char* cpf);
    bool validarPessoa();
    void listarPessoasComProdutoContratado();
    bool validarRegras();

    //Passo 1: Coleta e Validação de Dados do Usuário. Os Dados fornecidos serão CPF, Renda e Idade
    bool validarRenda() const
    {
        return (m_renda >= static_cast<double>(RendaMinima::RENDA_MINIMA));
    }

    //Passo 1: Coleta e Validação de Dados do Usuário. Os Dados fornecidos serão CPF, Renda e Idade
    bool validarIdade() const
    {
        return (m_idade >= static_cast<double>(IdadeMinimaMaxima::IDADE_MINIMA)) && (m_idade <= static_cast<double>(IdadeMinimaMaxima::IDADE_MAXIMA));
    }

    std::string obterCpf() const
    {
        return m_cpf;
    }

    double obterRenda() const
    {
        return m_renda;
    }

    short obterIdade() const
    {
        return m_idade;
    }

    std::string obterDescricaoValidacao() const
    {
        return DESCRICAO;
    }

private:
    bool m_pessoavalida : 1 {false};
    std::string m_cpf;
    char* m_cpfConvertido;
    double m_renda;
    uint8_t m_idade : 7;
};

inline std::ostream& operator <<(std::ostream& ostr, Pessoa& pessoa)
{
    ostr    << "[CPF: '"   << pessoa.obterCpf()
            << "', Tipo CPF: '"  << typeid(pessoa.obterCpf()).name() << "']"
            << "'\n[Renda: '"  << pessoa.obterRenda()
            << "', Tipo Renda: '"  << typeid(pessoa.obterRenda()).name() << "']"
            << "'\n[Idade: '" << pessoa.obterIdade()
            << "', Tipo Idade: '"  << typeid(pessoa.obterIdade()).name() << "']";


    return ostr;
}


#endif // PESSOA_H
