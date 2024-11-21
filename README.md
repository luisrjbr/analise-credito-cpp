# Análise de Crédito

# Requisitos:

Sistema criado com os exemplos dados no curso C++ MasterClass. Será criado um sistema de Análise de Crédito fictício, sendo os requisitos criados a partir de interações com o ChatGPT, sendo ele o analista de negócio. Para criação de um módulo de Análise de Crédito deve ser feito também um módulo de Análise de Fraude.

O que é a concessão de crédito?

A concessão de crédito é o procedimento no qual uma instituição libera um valor para uma pessoa física ou jurídica, para isso são avaliados vários critérios pelas instituições detentoras do crédito antes de liberá-las. Esse case trata da concessão de crédito para pessoa física.

Passos para construção do módulo de Análise de Crédito:

Passo 1: Coleta e Validação de Dados do Usuário. Os Dados fornecidos serão CPF, Renda e Idade

	- O CPF deve ser válidado seguindo as regras de validação do CPF;
	- A idade deve ser maior que 18 e menor que 60;
	- A Renda deve ser maior que 2000;
        
Passo 2: Consulta a Dados Internos e Externos do Usuário
    
    	- Consulta ao Histórico Interno do Banco com o CPF do usuário:
        	Identificar se o usuário possui histórico de crédito ou contas no banco e analisar informações anteriores. Checar informações como histórico de pagamento, eventuais atrasos e produtos 			bancários contratados (ex.: cartões de crédito, financiamentos). Deve ser retornado se o cliente tem alguma inadimplência nos produtos contratados. 

    	- Consulta a Bases Externas de Crédito com o CPF do usuário:
        	Conectar-se a bureaus de crédito (ex.: Serasa, SPC) para consultar o score externo e outras informações relevantes do histórico de crédito do usuário. Verificar registros de inadimplência, 			protestos e outras pendências financeiras.

Passo 3: Análise de Fraudes (Padrões e Anomalias)

    	- Verificação de Padrões Conhecidos de Fraudes:
        	Solicitações usando o mesmo CPF, mas informando nomes e idades diferentes.

Passo 4: Avaliação de Risco de Crédito e Fraude

     	- Geração de Score de Risco de Crédito. Calcular um score de risco de crédito que considere os dados internos e externos consultados no passo 2 e 3. Atribuir um nível de risco ao usuário com base 		nesse score (“Baixo”, “Médio” ou “Alto”).

        	Idade		Renda		Score	Risco
        	>=18 <=30	>2000 <=10000	4	"Alto"
        	>=18 <=30	>10000		2	"Medio"
        	>30 <=60 	>2000 <=10000	3	"Medio"
        	>30 <=60	>10000		1	"Baixo"	

Passo 5: Aprovação ou Rejeição do Crédito

    	- Cálculo de Limite de Crédito Inicial:
        	Com base no score de risco de crédito, definir um limite de crédito inicial. Ajustar o limite de crédito conforme a análise de risco; usuários com score de crédito alto recebem um limite 			maior, enquanto usuários com score baixo recebem um limite menor.

     	- Decisão de Aprovação de Crédito:
        	Com base no score de crédito e no limite proposto, decidir se o crédito deve ser aprovado automaticamente ou se deve ser encaminhado para análise manual. Sinalizar automaticamente perfis de 			alto risco de crédito e fraude para revisão humana.
	
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
        O Módulo de Prevenção a Fraudes consulta a base de dados interna do banco.
        O módulo consulta bases externas de dados antifraude (ex.: SPC, Serasa).
        O módulo calcula um score de risco de fraude.
        O módulo retorna o score de risco de fraude para a aplicação principal.
    Sequências de ações alternativas:
        Caso dados inválidos sejam detectados: A aplicação solicita ao usuário que corrija os dados e inicie a verificação novamente.
        Caso o usuário seja classificado como alto risco de fraude: A aplicação bloqueia a análise de crédito e envia o caso para revisão manual.
    Pós-condições: O sistema possui um score de risco de fraude para o usuário, e a análise de crédito pode ser continuada ou bloqueada.
    Requisitos não funcionais: A verificação de fraude deve ocorrer em tempo real; o tempo de resposta deve ser inferior a 5 segundos.
    Glossário:
        Score de risco de fraude: Pontuação que indica a probabilidade de o usuário estar associado a atividades fraudulentas.
	

Caso de Uso 2: Realizar Análise de Crédito do Usuário

    Nome do caso de uso: Realizar análise de crédito
    Objetivo: Analisar o perfil financeiro e de crédito do usuário para determinar aprovação, limite e condições de crédito.
    Resumo do caso de uso: A aplicação utiliza os dados pessoais e históricos do usuário para calcular um score de crédito e definir condições de crédito.
    Atores: Usuário, Módulo de Análise de Crédito, Módulo de Prevenção a Fraudes
    Precondições: O usuário passou pela verificação de fraude, e o score de risco de fraude está disponível.
    Disparador: O usuário solicita crédito após passar pela verificação de fraude.
    Sequência de ações primária:
        A aplicação inicia o processo de análise de crédito.
        A aplicação consulta o histórico de crédito do usuário na base de dados interna do banco.
        A aplicação verifica o score de crédito do usuário em bureaus de crédito externos (ex.: SPC, Serasa).
        A aplicação calcula o score de crédito com base no histórico e nos dados demográficos.
        A aplicação calcula o limite de crédito inicial com base no score e na capacidade de pagamento.
        A aplicação define condições de crédito (ex.: taxa de juros, prazo).
        A aplicação envia a proposta ao usuário.
    Sequências de ações alternativas:
        Caso o score de risco de fraude seja alto: O sistema suspende a análise de crédito e encaminha o caso para uma revisão manual.
        Caso o usuário tenha histórico de inadimplência: O sistema reduz o limite de crédito e ajusta a taxa de juros.
    Pós-condições: A análise de crédito está completa, e o usuário recebe uma resposta de aprovação, rejeição ou pendência para análise manual.
    Requisitos não funcionais: A análise de crédito deve ser rápida, com tempo de resposta abaixo de 10 segundos.
    Glossário:
        Score de crédito: Pontuação que indica a probabilidade de o usuário cumprir com as obrigações financeiras.
        Limite de crédito inicial: Valor de crédito aprovado inicialmente para o usuário.
