# Análise de Crédito

# Contexto:

Será criado um sistema com a intenção de treinar os conceitos aprendidos no curso C++ MasterClass. O problema que este sistema resolve é conceder, através de uma instituição financeira fictícia, crédito a uma determinada pessoa. Para isso, alguns domínios devem ser utilizados como o de análise de crédito e análise de fraude. Boa parte dos requisitos de negócio aqui utilizados foram criados a partir de interações com o ChatGPT, sendo ele o analista de negócio para esse exemplo. Para criação da análise de crédito deve ser feita validações da pessoa e análise de fraude.

O que é a concessão de crédito?

A concessão de crédito é o procedimento no qual uma instituição libera um valor para uma pessoa física ou jurídica, para isso, são avaliados vários critérios pelas instituições detentoras do crédito antes de liberá-las. Esse case trata da uma concessão de crédito fictícia para uma pessoa física.


# Requisitos:

Passos para construção de um módulo de Análise de Crédito:

Passo 1: Coleta e Validação de Dados da Pessoa. Os Dados fornecidos serão CPF, Renda e Idade

- O CPF deve ser válidado seguindo as regras de validação do CPF;
- A Idade deve ser maior que 18 e menor que 60;
- A Renda deve ser maior que 2000;
        
Passo 2: Consultar Histórico Internos do Usuário na Instituição
    
- Identificar pelo cpf da pessoa se esta tem algum produto contratado anteriormente na instituição;
- A instituição só deseja conceder crédito a usuários que tenha algum produto contratado anteriormente, se tiver um produto, pode seguir no fluxo da contratação do crédito;

Passo 3: Verificar Padrão de Análise de Fraudes (Padrões e Anomalias)

- Diferentes solicitações usando o mesmo CPF, mas informando renda e idade diferentes em diferentes requisições deve ser entendida como uma fraude;
- Só é possível seguir no fluxo da contratação do crédito se não tiver apontamento de fraude;

Passo 4: Avaliação de Risco de Crédito Para Geração de Score de Risco de Crédito. 

- Calcular um score de risco de crédito que considere as regras nos passos 2 e 3, isso quer dizer que se tem produto bancário e não tem fraude pode prosseguir;
- O Score é um nível de risco com as seguintes definições: “Baixo”, “Médio” ou “Alto”. E deve seguir a seguinte tabela:
        		
	  	Idade		Renda		Score de Risco
        	>=18 <=30	>2000 <=10000	"Alto"
        	>=18 <=30	>10000		"Medio"
        	>30 <=60 	>2000 <=10000	"Medio"
        	>30 <=60	>10000		"Baixo"	

Passo 5: Após o Cálculo do Score Definir o Limite de Crédito

- Com base no score de risco, definir um limite de crédito com base na seguinte tabela: 

  		Risco	Limite de Crédito	
  		"Alto"	3000
  		"Medio"	6000
  		"Baixo"	9000
  	
- A partir do limite de crédito informar que o pagamento será feito em 4 parcelas;
- Informar a maior parcela paga corrigida pelo valor de 1% ao mês sobre o valor recebido;
 
# Casos de Uso:     

Caso de Uso 1: Verificar Risco de Fraude da Pessoa

    Nome do caso de uso: Verificar Risco de Fraude da Pessoa
    Objetivo: Validar uso do sistema pela pessoa determinando o risco de fraude antes da análise de crédito.
    Resumo do caso de uso: A aplicação deve verificar se a pessoa está enquadrada no padrão de análise de Fraude de diferentes solicitações usando o mesmo CPF
    mas informando renda e idade diferentes em diferentes requisições.
    Atores: Pessoa e Fraude
    Precondições: A pessoa já forneceu dados pessoais (CPF, renda e idade) que já foram validados anteriormente.
    Disparador: A pessoa inicia uma solicitação de crédito.
    Sequência de ações primária:
		Após a validação do CPF, renda e idade o domínio de Prevenção a Fraudes faz sua validação utilizando como entrada o cpf da pessoa;
		O domínio de Prevenção a Fraudes verifica o padrão conhecido de fraude em que diferentes requisições com os mesmos dados deve ser entendida como uma fraude;
		O domínio de Prevenção a Fraudes retorna se é uma fraude ou não;
    Sequências de ações alternativas:
		Caso dados inválidos sejam detectados: A aplicação informa a pessoa que não é possível prosseguir com a análise de crédito.
    Pós-condições: O sistema retorna se tem risco de fraude e a análise de crédito pode prosseguir ou não.
    Requisitos não funcionais: A verificação de fraude deve ocorrer em tempo real e o tempo de resposta deve ser inferior a 1 segundo.
    Glossário:
		Risco de fraude: Probabilidade do usuário estar associado a atividades fraudulentas.
	

Caso de Uso 2: Realizar Análise do Limite de Crédito da Pessoa

    Nome do caso de uso: Realizar Análise do Limite de Crédito da Pessoa
    Objetivo: Definir um limite de crédito após analisar o score de risco da pessoa. Essa análise determinará o valor do limite de crédito.
    Resumo do caso de uso: A aplicação utiliza os dados pessoais para determinar o score de risco e com isso calcular um limite de crédito.
    Atores: Pessoa, Crédito e Fraude
    Precondições: A pessoa passou pela verificação dos dados pessoais, de fraude, e o score de risco de crédito está disponível.
    Disparador: O crédito é fornecido após ter o score de risco avaliado.
    Sequência de ações primária:
		A aplicação inicia o processo de análise de crédito e com base no score de risco é definido um limite de crédito com base na seguinte tabela: 	
  			Risco	Limite de Crédito	
  			"Alto"	3000
  			"Medio"	6000
  			"Baixo"	9000	
		Deve ser enviada a proposta do limite a pessoa conforme sua análise.
    Sequências de ações alternativas:
        	Nesse ponto as validações já foram realizadas e deve ser fornecido a pessoa seu limite conforme a tabela de limites.
    Pós-condições: A análise de crédito está completa, e o usuário recebe uma resposta de aprovação com o limite disponível.
    Requisitos não funcionais: A análise de crédito deve ser em tempo real, com tempo de resposta abaixo de 1 segundo.
    Glossário:
        	Score de crédito: Pontuação que indica a probabilidade de o usuário cumprir com as obrigações financeiras.
        	Limite de crédito: Valor de crédito aprovado inicialmente para o usuário.

  #Diagrama de Classes:
  ![image](https://github.com/user-attachments/assets/23fa84f6-5f91-44d4-9760-c1fcd7b22982)

