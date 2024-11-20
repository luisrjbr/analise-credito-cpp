# analise-credito-cpp
Sistema criado com os exemplos dados no curso C++ MasterClass. Será criado um sistema de Análise de Crédito fictício, sendo os requisitos criados a partir de interações com o ChatGPT, sendo ele o analista de negócio. Para criação de um módulo de Análise de Crédito deve ser feito também um módulo de Análise de Fraude.

O que é a concessão de crédito?

A concessão de crédito é o procedimento no qual uma instituição libera um valor para uma pessoa física ou jurídica, para isso são avaliados vários critérios pelas instituições detentoras do crédito antes de liberá-las. Esse case trata da concessão de crédito para pessoa física.

Passos para construção do módulo de Análise de Crédito:

Passo 1: Coleta e Validação de Dados do Usuário. Os Dados fornecidos serão CPF, Renda e Idade e deve-se garantir que:
	
 	- Todos os campos estejam preenchidos, evitando valores nulos ou vazios;
	- O CPF deve ser válidado seguindo as regras de validação do CPF;
	- A idade deve ser maior que 18 e menor que 70;
	- A Renda deve ser maior que 2000;
        
Passo 2: Consulta a Dados Internos e Externos do Usuário
    Consulta ao Histórico Interno do Banco com o CPF do usuário:
        Identificar se o usuário possui histórico de crédito ou contas no banco e analisar informações anteriores.
        Checar informações como histórico de pagamento, eventuais atrasos e produtos bancários contratados (ex.: cartões de crédito, financiamentos).

    Consulta a Bases Externas de Crédito com o CPF do usuário:
        Conectar-se a bureaus de crédito (ex.: Serasa, SPC) para consultar o score externo e outras informações relevantes do histórico de crédito do usuário.
        Verificar registros de inadimplência, protestos e outras pendências financeiras.

Passo 3: Análise de Perfil e Capacidade de Pagamento

    Análise de Perfil do Usuário:
        Coletar informações demográficas (idade, localização, profissão) e verificar a consistência com o perfil de clientes do banco.
        Determinar uma faixa de crédito inicial com base em informações demográficas e perfil de crédito histórico.

    Cálculo da Capacidade de Pagamento:
        Se disponível, considerar informações de renda (fornecidas diretamente ou deduzidas de dados financeiros do banco).
        Estimar a capacidade de pagamento com base na renda e no histórico financeiro do cliente, ajustando a oferta de crédito para evitar superendividamento.

Passo 4: Avaliação de Risco de Crédito e Fraude

    Análise Integrada com o Módulo de Prevenção a Fraudes:
        Com base no score de risco de fraude (do módulo antifraude), ajustar o limite e os critérios de crédito:
            Usuários com risco de fraude elevado terão uma análise de crédito mais restrita.
            Usuários com baixo risco de fraude poderão ter critérios de análise de crédito mais flexíveis.

    Geração de Score de Risco de Crédito:
        Calcular um score de risco de crédito que considere:
            Dados de histórico interno e externo do usuário.
            Perfil demográfico.
            Score de risco de fraude.
        Atribuir um nível de risco ao usuário com base nesse score (ex.: “Baixo”, “Médio” ou “Alto”).

        Legenda Score:
        1 - Alto;
        2 - Médio;
        3 - Baixo;

Passo 5: Definição de Limite de Crédito e Condições de Empréstimo

    Cálculo de Limite de Crédito Inicial:
        Com base no score de risco de crédito e capacidade de pagamento, definir um limite de crédito inicial.
        Ajustar o limite de crédito conforme a análise de risco; usuários com score de crédito alto recebem um limite maior, enquanto usuários com score baixo recebem um limite menor.

    Condições de Empréstimo e Juros:
        Definir a taxa de juros e outras condições de crédito (ex.: prazo máximo) com base no score de crédito.
        Atribuir juros mais altos para perfis com maior risco e juros mais baixos para perfis com risco reduzido.

Passo 6: Aprovação ou Rejeição do Crédito

    Decisão de Aprovação de Crédito:
        Com base no score de crédito e no limite proposto, decidir se o crédito deve ser aprovado automaticamente ou se deve ser encaminhado para análise manual.
        Sinalizar automaticamente perfis de alto risco de crédito e fraude para revisão humana.

    Comunicação com o Usuário:
        Enviar uma resposta ao usuário com o status da solicitação:
            Caso aprovado, informar o limite de crédito concedido e condições do empréstimo.
            Caso rejeitado ou pendente de revisão manual, informar o usuário sobre o status da análise.

        CPF: deve ser validado se existe risco financeiro para o crédito avaliando em uma lista de registros na receita federal. Essa avaliação positivará ou negativará o crédito. 
        Após isso, será feita uma análise de crédito que retornará um score e um valor do crédito que poderá ser concedido, seguindo a seguinte tabela:
        	Idade		Renda		Score
        	>=18 <=30	>2000 <=10000	4
        	>=18 <=30	>10000		2
        	>30 <=60 	>2000 <=10000	3
        	>30 <=60	>10000		1		

      
	


