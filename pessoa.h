#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
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
    Pessoa() = default;
    Pessoa(std::string cpf, double renda, short idade);

    int validarCPF(char* cpf);

    bool validarRenda() const
    {
        return (m_renda >= static_cast<double>(RendaMinima::RENDA_MINIMA));
    }

    bool validarIdade() const
    {
        return (m_idade >= static_cast<double>(IdadeMinimaMaxima::IDADE_MINIMA)) && (m_idade <= static_cast<double>(IdadeMinimaMaxima::IDADE_MAXIMA));
    }

    bool validarPessoa() const
    {
        return m_pessoavalida;
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

private:
    bool m_pessoavalida : 1 {false};
    std::string m_cpf;
    double m_renda;
    uint8_t m_idade : 7;
};

inline std::ostream& operator <<(std::ostream& ostr, Pessoa& pessoa)
{
    ostr << "[CPF: '"   << pessoa.obterCpf()
         << "', Renda: '"  << pessoa.obterRenda()
         << "', Idade: '" << pessoa.obterIdade() << "']";

    return ostr;
}


#endif // PESSOA_H
