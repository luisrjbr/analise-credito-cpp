#include <iostream>
#include <format>
#include <unistd.h>
#include "pessoa.h"
#include "fraude.h"
#include "credito.h"

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
        std::cout << "\nPor Favor Aguarde. Seu Crédito está sendo analisado...\n" << std::endl;

        sleep(2);

        CppCredito::Credito credito;

        if(!credito.analisarRegrasPreCredito(pessoa))
            std::cout << credito.mensagemRegrasPreCredito << std::endl;
        else
        {
            //teste de stackoverflow
            constexpr size_t LIMITESTACK = ((((1024 * 1024) / sizeof(int))) * 8);

            if (credito.NUMEROPARCELAS >= LIMITESTACK)
            {
                std::cout << "Ocorreu um erro interno!" << std::endl;
            }
            else
            {
                std::cout << credito.mensagemRegrasPreCredito << std::endl;
                std::cout << "\nParabéns! Seu Crédito é de: " +
                                 std::format("{:.2f}", credito.informarLimiteDeCredito(pessoa));
                std::cout << "\n\nE será pago a você em " + std::to_string(credito.NUMEROPARCELAS) + " parcelas";
                std::cout << "\nNão se procupe, elas serão corrigidas sendo a maior parcela no valor de: " +
                                 std::format("{:.2f}", credito.obterNumeroParcelasDoCredito());
            }

        }
    }
    else
    {
        std::cout << "\n\nDados Incorretos! Verifique os Pré Requisitos.\n\n" << std::endl;
    }

    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << "\nLog dos Dados Fornecidos Como Entrada e Seus Tipos: " << std::endl;
    std::cout << pessoa << std::endl;
    std::cout << "\n-------------------------------------------" << std::endl;


    return 0;
}
