#ifndef FRAUDE_H
#define FRAUDE_H

#include<vector>
#include <string>
#include "pessoa.h"

class Fraude
{
public:
    //

    Fraude() = default;
    Fraude(Pessoa& pessoa);

    //

    Pessoa pessoaParaAnaliseFraude;
    std::vector<Pessoa> pessoasComFraude;
    static constexpr std::string DESCRICAO = "Fraude!";

    //

    void listarPessoasComFraude();
    bool validarRegras();

    std::string obterDescricaoValidacao() const
    {
        return DESCRICAO;
    }

};

#endif // FRAUDE_H
