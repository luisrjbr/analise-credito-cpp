# analise-credito-cpp
Sistema criado para validar meus aprendizados da turma C++ MasterClass


O que é a concessão de crédito?

A concessão de crédito é o procedimento no qual uma instituição libera um valor para uma pessoa física ou jurídica, para isso são avaliados vários critérios pelas instituições detentoras do crédito antes de liberá-las. Esse case trata da concessão de crédito para pessoa física.

Qual escopo do sistema?

Antes da etapa de concessão de crédito ocorre a análise de crédito do solicitante. Para isso o solicitante deve fornecer alguns dados cadastrais como: CPF, idade e renda. 


Qual cliente queremos conceder limite?

	Clientes com boa pontuação (score)

Como funciona um Limite automático?
	
	Para aqueles que já são clientes com boa pontuação (score), estão aumentando deus gastos no cartão e bons pagadores será concedido um limite adicional.

Regras:

- Os dados fornecidos pelo solicitante (pessoa pedindo crédito) serão: CPF, Idade e Renda e avaliados da seguinte forma:

        CPF: deve ser válidado seguindo as regras de validação do CPF;
        Idade: deve ser maior que 18 e menor que 60;
        Renda: deve ser maior que 2000;
        
- Para a avaliação do crédito: 
        CPF: deve ser validado se existe risco financeiro para o crédito avaliando em uma lista de registros na receita federal. Essa avaliação positivará ou negativará o crédito. 
        Após isso, será feita uma análise de crédito que retornará um score e um valor do crédito que poderá ser concedido, seguindo a seguinte tabela:
        	Idade		Renda		Score
        	>=18 <=30	>2000 <=10000	4
        	>=18 <=30	>10000		2
        	>30 <=60 	>2000 <=10000	3
        	>30 <=60	>10000		1
        		
        Legenda Score:
        1 - Ótimo;
        2 - Bom;
        3 - Ruim;
        4 - Péssimo;
        
Em d+1 todos os cpfs criados pela receita federal são enviados para a base do bureaut 


	


