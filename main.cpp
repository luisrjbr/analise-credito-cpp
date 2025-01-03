#include <iostream>
#include "pessoa.h"
#include "fraude.h"
#include "credito.h"

#include <unistd.h>

namespace CppPessoa = CppMasterClass::Pessoa;
namespace CppCredito = CppMasterClass::Credito;

int main()
{
    //OK - 60402039009 - Cpf sem impedimento de fraude e com produto contratado
    //NOK - 41852198060 - Cpf com impedimento de fraude, mas com produto contratado
    //NOK - 13935782098 - Cpf sem impedimento de fraude, mas sem produto contratado

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

    CppPessoa::Pessoa pessoa(input_cpf,input_renda,input_idade);

    if(pessoa.validarPessoa())
    {
        std::cout << "\n\nDados Informados Corretos!" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "\nSeu Crédito está sendo analisado...\n" << std::endl;

        sleep(2);

        CppCredito::Credito credito;

        std::cout << credito.analisarRegrasPreCredito(pessoa) << std::endl;
    }
    else
    {
        std::cout << "\n\nDados Incorretos! Verifique os pré requisitos.\n\n" << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "\nDados Fornecidos Como Entrada: " << std::endl;
    std::cout << pessoa << std::endl;
    std::cout << "\n-------------------------------------------" << std::endl;


    return 0;
}
