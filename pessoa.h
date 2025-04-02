#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cstdint>
#include <memory>
#include <cstring>

namespace CppMasterClass::Pessoa
{

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
    virtual ~Pessoa() = default; // Sempre bom ter um destrutor virtual

    //

    std::vector<Pessoa> pessoasComProdutosContratados;
    inline static constexpr std::string DESCRICAO = "Pessoa!";
    inline static constexpr double RENDA_MINIMA = 2000.00;

    //

    int validarCPF(char* cpf);
    bool validarPessoa() noexcept;
    void listarPessoasComProdutoContratado() noexcept;
    bool validarRegras() noexcept;
    static char* converteCpfParaValidacao(std::string& cpf);

    bool validarRenda() const
    {
        return (m_renda > RENDA_MINIMA);
    }

    bool validarIdade() const
    {
        return (m_idade >= static_cast<double>(IdadeMinimaMaxima::IDADE_MINIMA)) && (m_idade <= static_cast<double>(IdadeMinimaMaxima::IDADE_MAXIMA));
    }

    std::string obterCpf() const
    {
        return m_cpf;
    }

    virtual double obterRenda() const
    {
        return m_renda;
    }

    virtual short obterIdade() const
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

//Sobrescreve o operador << para ter uma mensagem de saida padrão com informações do usuário
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

}

#endif // PESSOA_H
