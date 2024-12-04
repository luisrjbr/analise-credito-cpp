# Análise de Crédito

# Requisitos:

Sistema criado com os exemplos dados no curso C++ MasterClass. Será criado um sistema de Análise de Crédito dado por uma instituição financeira fictícia, sendo os requisitos criados a partir de interações com o ChatGPT, sendo ele o analista de negócio. Para criação de um módulo de Análise de Crédito deve ser feito também um módulo de Análise de Fraude.

O que é a concessão de crédito?

A concessão de crédito é o procedimento no qual uma instituição libera um valor para uma pessoa física ou jurídica, para isso são avaliados vários critérios pelas instituições detentoras do crédito antes de liberá-las. Esse case trata da concessão de crédito para pessoa física.

Passos para construção do módulo de Análise de Crédito:

Passo 1: Coleta e Validação de Dados do Usuário. Os Dados fornecidos serão CPF, Renda e Idade

- O CPF deve ser válidado seguindo as regras de validação do CPF;
- A idade deve ser maior que 18 e menor que 60;
- A Renda deve ser maior que 2000;
        
Passo 2: Consultar Histórico Internos do Usuário na Instituição
    
Identificar se o usuário possui histórico de crédito analisando informações anteriores.
Com o cpf verificar se tem algum produto contratado anteriormente na instituição, com o cpf + renda verificar no histórico de renda aumentou.
O único caso que ele deve ser aceito e se tem produto bancário e a renda aumentou. 

Passo 3: Verificar Padrão de Análise de Fraudes (Padrões e Anomalias)

Diferentes solicitações usando o mesmo CPF, mas informando renda e idade diferentes em diferentes requisições deve ser entendida como uma fraude.

Passo 4: Avaliação de Risco de Crédito

- Geração de Score de Risco de Crédito. Calcular um score de risco de crédito que considere os dados retornados nos passos 2 e 3.
Isso quer dizer que se tem produto bancário e a renda aumentou e não tem fraude pode proceguir.
Esse score é um nível de risco com as seguintes definições: “Baixo”, “Médio” ou “Alto”.
        		
	  	Idade		Renda		Score de Risco
        	>=18 <=30	>2000 <=10000	"Alto"
        	>=18 <=30	>10000		"Medio"
        	>30 <=60 	>2000 <=10000	"Medio"
        	>30 <=60	>10000		"Baixo"	

Passo 5: Aprovação ou Rejeição do Crédito Para Concessão do Limite

Com base no score de risco, definir um limite de crédito: 

  		Risco	Limite de Crédito	
  		"Alto"	2000
  		"Medio"	5000
  		"Baixo"	15000		
	
# Casos de Uso:     

Caso de Uso 1: Verificar Dados de Fraude do Usuário

    Nome do caso de uso: Verificar dados de fraude
    Objetivo: Validar dados do usuário para determinar risco de fraude antes da análise de crédito.
    Resumo do caso de uso: A aplicação deve verificar dados do usuário em bases internas.
    Atores: Usuário, Módulo de Prevenção a Fraudes
    Precondições: O usuário já forneceu dados pessoais (CPF, renda e idade) que já foram validados.
    Disparador: O usuário inicia uma solicitação de crédito.
    Sequência de ações primária:
        A aplicação coleta os dados pessoais do usuário e faz a validação do CPF, renda e idade.
	A aplicação envia os dados ao Módulo de Prevenção a Fraudes.
        O Módulo de Prevenção a Fraudes verifica padrão conhecido de fraude em que diferentes requisições com os mesmos dados deve ser entendida como uma fraude.
        O Módulo de Prevenção a Fraudes retorna se é uma fraude ou não.
    Sequências de ações alternativas:
        Caso dados inválidos sejam detectados: A aplicação solicita ao usuário que corrija os dados e inicie a verificação novamente.
    Pós-condições: O sistema retorna o risco de fraude e a análise de crédito pode ser continuada ou bloqueada.
    Requisitos não funcionais: A verificação de fraude deve ocorrer em tempo real; o tempo de resposta deve ser inferior a 1 segundo.
    Glossário:
        Risco de fraude: Probabilidade do usuário estar associado a atividades fraudulentas.
	

Caso de Uso 2: Realizar Análise de Crédito do Usuário

    Nome do caso de uso: Realizar análise de crédito
    Objetivo: Analisar o perfil financeiro e de crédito do usuário para determinar sua Aprovação, Score de Risco, e Limite.
    Resumo do caso de uso: A aplicação utiliza os dados pessoais e score de risco para calcular um limite de crédito.
    Atores: Usuário, Módulo de Análise de Crédito, Módulo de Prevenção a Fraudes
    Precondições: O usuário passou pela verificação de fraude, e o score de risco de crédito está disponível.
    Disparador: O crédito é fornecido após passar pela verificação de fraude.
    Sequência de ações primária:
        A aplicação inicia o processo de análise de crédito.
	Verifica se o usuário não tem fraude.
	Verifica se o usuário tem produto bancário e a renda aumentou 
 	Com base no score de risco define o limite de crédito
        Enviar a proposta ao usuário.
    Sequências de ações alternativas:
        Caso o usuário não passe nos critérios de validação: sistema suspende a análise de crédito e encaminha o caso para uma revisão manual.
    Pós-condições: A análise de crédito está completa, e o usuário recebe uma resposta de aprovação ou rejeição.
    Requisitos não funcionais: A análise de crédito deve ser rápida, com tempo de resposta abaixo de 2 segundos.
    Glossário:
        Score de crédito: Pontuação que indica a probabilidade de o usuário cumprir com as obrigações financeiras.
        Limite de crédito: Valor de crédito aprovado inicialmente para o usuário.
