#include <iostream>
#include "pessoa.h"
#include "risco.h"

int main()
{
    //41852198060 - Cpf com impedimento

    char input_cpf[12];
    double input_renda;
    short input_idade;

    std::cout << "*** ATENÇÂO: Regras para validação: CPF Válido, Renda maior que R$ 2000,00 e idade entre 18 e 60 anos *** \n\n" << std::endl;

    std::cout << "Digite o número do CPF sem pontos, espaços ou traços:" << std::endl;
    std::cin.getline(input_cpf, 12, '\n');
    std::cout << "Digite sua renda com a casa decimal separada por ponto:" << std::endl;
    std::cin >> input_renda;
    std::cout << "Digite sua idade:" << std::endl;
    std::cin >> input_idade;

    Pessoa pessoa(input_cpf,input_renda,input_idade);

    if(pessoa.validarPessoa())
    {
        std::cout << "\n\nDados Corretos!" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        std::cout << "\nSeu Risco está sendo analisado..." << std::endl;
        Risco risco;
        if(risco.verificarPessoaComRisco(pessoa))
            std::cout << "\nInfelizmente não é possivel conceder seu crédito" << std::endl;
        else
            std::cout << "\nParabéns, seu cadastro não encontra-se com impedimentos" << std::endl;
    }
    else
    {
        std::cout << "\n\nDados Incorretos! Verifique os pré requisitos." << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Dados Fornecidos Como Entrada:" << std::endl;
    std::cout << "  " << pessoa << std::endl;

    return 0;
}

void testePessoaDadosPessoaisValidos()
{

}

void testePessoaDadosPessoaisInvalidos()
{

}
