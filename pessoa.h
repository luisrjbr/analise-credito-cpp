#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdint>

class Pessoa
{
public:
    enum{RENDA_MINIMA = 1000, RENDA_MAXIMA = 10000};
    enum {IDADE_MINIMA = 18, IDADE_MAXIMA = 70};

    Pessoa() = default;
    Pessoa(std::string cpf, double renda, short idade);

    int validarCPF(char* cpf);

    bool validarRenda() const
    {
        return (m_renda >= RENDA_MINIMA) && (m_renda <= RENDA_MAXIMA);
    }

    bool validarIdade() const
    {
        return (m_idade >= IDADE_MINIMA) && (m_idade <= IDADE_MAXIMA);
    }

    bool validarPessoa() const
    {
        return m_pessoavalida;
    }

    const std::string obterCpf()
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
