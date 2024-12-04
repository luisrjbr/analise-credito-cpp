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
        
Passo 2: Consulta a Dados Internos e Externos do Usuário
    
- Consulta ao Histórico Interno da Instituição Financeira com o CPF do usuário:
Identificar se o usuário possui histórico de crédito ou contas no banco e analisar informações anteriores.
Checar informações como histórico de pagamento, eventuais atrasos e produtos bancários contratados
(ex.: cartões de crédito, financiamentos). Deve ser retornado se o cliente tem alguma inadimplência nos produtos contratados. 

Passo 3: Análise de Fraudes (Padrões e Anomalias)

    	- Verificação de Padrões Conhecidos de Fraudes:
        Uma solicitação usando o mesmo CPF, mas informando renda e idades diferentes em requisições 
	para análise de crédito deve ser entendida como uma fraude.

Passo 4: Avaliação de Risco de Crédito e Fraude

     	- Geração de Score de Risco de Crédito. Calcular um score de risco de crédito que considere os dados retornados nos passos 2 e 3.
      Esse score é um nível de risco com as seguintes definições: “Baixo”, “Médio” ou “Alto”. As seguintes regras devem ser respeitadas:
	
 	1 - Se tiver inadimplência (passo 2) ou alguma fraude o crédito deve ser negado e enviado para verificação manual.
  	2 - Se não tiver inadimplência  e tendo ou não inadimplência externa, verificar a tabela abaixo:
        	Idade		Renda		Score de Risco
        	>=18 <=30	>2000 <=10000	"Alto"
        	>=18 <=30	>10000		"Medio"
        	>30 <=60 	>2000 <=10000	"Medio"
        	>30 <=60	>10000		"Baixo"	

Passo 5: Aprovação ou Rejeição do Crédito

    	- Cálculo de Limite de Crédito Inicial:
        	Com base no score de risco, definir um limite de crédito inicial. Ajustar o limite de crédito conforme a análise de 
	 	risco com usuários com score de crédito alto recebem um limite maior, enquanto usuários com score baixo recebem um limite menor.

          	Risco	Limite de Crédito	
        	"Alto"	2000
        	"Medio"	4000
        	"Baixo"	6000		
	
# Casos de Uso:     

Caso de Uso 1: Verificar Dados de Fraude do Usuário

    Nome do caso de uso: Verificar dados de fraude
    Objetivo: Validar dados do usuário para determinar risco de fraude antes da análise de crédito.
    Resumo do caso de uso: A aplicação deve verificar dados do usuário em bases internas e externas, padrões e anomalias e calcular um score de risco de fraude.
    Atores: Usuário, Módulo de Prevenção a Fraudes
    Precondições: O usuário já forneceu dados pessoais (CPF, renda e idade) que já foram validados.
    Disparador: O usuário inicia uma solicitação de crédito.
    Sequência de ações primária:
        A aplicação coleta os dados pessoais do usuário e faz a validação do CPF, renda e idade.
	A aplicação envia os dados ao Módulo de Prevenção a Fraudes.
        O Módulo de Prevenção a Fraudes consulta bases externas de dados antifraude (ex.: SPC, Serasa).
	O Módulo de Prevenção a Fraudes verifica uma padrão conhecido de fraude, verificando se um cpf já foi informado com renda e idades diferentes.
        O Módulo de Prevenção a Fraudes calcula um score de risco de fraude.
        O Módulo de Prevenção a Fraudes retorna o score de risco de fraude para a aplicação principal.
    Sequências de ações alternativas:
        Caso dados inválidos sejam detectados: A aplicação solicita ao usuário que corrija os dados e inicie a verificação novamente.
        Caso o usuário seja classificado como alto risco de fraude: A aplicação bloqueia a análise de crédito e envia o caso para revisão manual.
    Pós-condições: O sistema possui um score de risco de fraude para o usuário, e a análise de crédito pode ser continuada ou bloqueada.
    Requisitos não funcionais: A verificação de fraude deve ocorrer em tempo real; o tempo de resposta deve ser inferior a 1 segundo.
    Glossário:
        Score de risco de fraude: Pontuação que indica a probabilidade de o usuário estar associado a atividades fraudulentas.
	

Caso de Uso 2: Realizar Análise de Crédito do Usuário

    Nome do caso de uso: Realizar análise de crédito
    Objetivo: Analisar o perfil financeiro e de crédito do usuário para determinar aprovação, limite e condições de crédito.
    Resumo do caso de uso: A aplicação utiliza os dados pessoais e históricos do usuário para calcular um score de crédito e definir condições de crédito.
    Atores: Usuário, Módulo de Análise de Crédito, Módulo de Prevenção a Fraudes
    Precondições: O usuário passou pela verificação de fraude, e o score de risco de fraude está disponível.
    Disparador: O crédito é fornecido após passar pela verificação de fraude.
    Sequência de ações primária:
        A aplicação inicia o processo de análise de crédito.
        O Módulo de Análise de Crédito consulta o histórico de crédito do usuário na base de dados interna do banco.
        O Módulo de Análise de Crédito consulta o score produzido pelo Módulo de Prevenção a Fraudes. 
	Com base no score de risco calcular o limite de crédito
        Enviar a proposta ao usuário.
    Sequências de ações alternativas:
        Caso o usuário tenha histórico de inadimplência: sistema suspende a análise de crédito e encaminha o caso para uma revisão manual.
    Pós-condições: A análise de crédito está completa, e o usuário recebe uma resposta de aprovação ou rejeição.
    Requisitos não funcionais: A análise de crédito deve ser rápida, com tempo de resposta abaixo de 2 segundos.
    Glossário:
        Score de crédito: Pontuação que indica a probabilidade de o usuário cumprir com as obrigações financeiras.
        Limite de crédito inicial: Valor de crédito aprovado inicialmente para o usuário.
