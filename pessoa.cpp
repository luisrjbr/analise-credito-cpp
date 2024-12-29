#include "pessoa.h"
#include "utilitario.h"

Pessoa::Pessoa(std::string cpf, double renda, uint8_t idade) : m_cpf(cpf), m_renda(renda), m_idade(idade)
{
    m_cpfConvertido = Utilitario::converteCpfParaValidacao(m_cpf);
}

bool Pessoa::validarPessoa()
{
    return m_pessoavalida = (validarCPF(m_cpfConvertido)
                            &&validarRenda()
                            && validarIdade());
}

//Passo 3: Verificar Padrão de Análise de Fraudes (Padrões e Anomalias)
//Todas as listas são fakes para testes
void Pessoa::listarPessoasComProdutoContratado()
{
    //60402039009, 68269984086, 06696577009, 71411558057, 41852198060

    char input_cpf1[12] {'6','0','4','0','2','0','3','9','0','0','9'};
    char input_cpf2[12] {'6','8','2','6','9','9','8','4','0','8','6'};
    char input_cpf3[12] {'0','6','6','9','6','5','7','7','0','0','9'};
    char input_cpf4[12] {'7','1','4','1','1','5','5','8','0','5','7'};
    char input_cpf5[12] {'4','1','8','5','2','1','9','8','0','6','0'};

    Pessoa::pessoasComProdutosContratados.push_back(Pessoa(input_cpf1, 1500, 25));
    Pessoa::pessoasComProdutosContratados.push_back(Pessoa(input_cpf2, 2500, 35));
    Pessoa::pessoasComProdutosContratados.push_back(Pessoa(input_cpf3, 3500, 45));
    Pessoa::pessoasComProdutosContratados.push_back(Pessoa(input_cpf4, 4500, 55));
    Pessoa::pessoasComProdutosContratados.push_back(Pessoa(input_cpf5, 5500, 58));
}


bool Pessoa::validarRegras()
{
    //cria uma lista fake de pessoas com produtos contratados
    listarPessoasComProdutoContratado();

    for(Pessoa pessoa : Pessoa::pessoasComProdutosContratados)
    {
        if(obterCpf() == pessoa.obterCpf())
        {
            return false;
        }
    }
    //a pessoa não tem produto
    return true;
}

//Código pego do repositóriohttps://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
//Retorno: [1] - Se for válido | [0] - Se for inválido
int Pessoa::validarCPF(char* cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
             (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
             (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
             (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i]-48) * j;
            digito2 %= 11;
            if(digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if((cpf[10]-48) != digito2)
                return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

