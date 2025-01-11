#include "arquivo.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <math.h>

char menu, retornar, titulos[50];
int comparador_Plano_de_fundo;

void titulo_escuro_ou_claro(char tituloAUX[50]) // funç o de mostrar a cor certa para o titulo
{
    if (comparador_Plano_de_fundo != 2)
    {
        printf("\n\n                                          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // cor da palavra...
        printf("      %s      ", tituloAUX);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        printf("                                                    \n");
    }
    else
    {
        printf("\n\n                                          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // cor da palavra...
        printf("      %s      ", tituloAUX);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("                                                    \n");
    }
}

float percentual_simples(float x, float y)
{
    float soma_total = x + y;
    float restante = x - y;
    float percentual = ((restante / x) * 100);
    return percentual;
}

int juros_simples_f()
{
    system("cls");
    titulo_escuro_ou_claro("      JUROS SIMPLES     "); // função de mostrar a cor certa para o titulo

    float capital;
    float taxa;
    int tempo_meses;
    float juros_simples;

    printf("\n    Informe o capital: ");
    scanf("%f", &capital);
    fflush(stdin);

    printf("\n    Informe a taxa em valor decimal a ser cobrada : [em %%]: ");
    scanf("%f", &taxa);
    fflush(stdin);

    printf("    Informe o tempo em meses: ");
    scanf("%d", &tempo_meses);
    fflush(stdin);

    juros_simples = (capital * (taxa / 100) * tempo_meses);

    printf("\n    O valor total resultante da aplicação em juros simples é R$%.2f", (capital + juros_simples));
    printf("\n\n\n                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
}

void modulo_investimentos()
{
    system("cls");
    titulo_escuro_ou_claro(" Módulo de investimento "); // função de mostrar a cor certa para o titul

    char escolha;

    printf("\n\n\n    Você deseja acessar um módolo que corresponde a investimentos ? [s/n]: ");
    scanf("%s", &escolha);
    fflush(stdin);

    if (escolha == 's' || escolha == 'S')
    {

        printf("\n    De uma maneira simples, investir é aplicar recursos\n");
        printf("    esperando retorno em um determinado período.\n\n");
        printf("\n    Um dos principais objetivos de investir é fazer com\n");
        printf("    que o dinheiro aumente, porém há uma parte que\n");
        printf("    envolve riscos ao aplicar determinado valor.\n\n");
        printf("\n    Um dos principais requisitos para um bom investidor\n");
        printf("    é saber analisar os riscos e potenciais  retornos.\n\n");
        printf("\n\n    Existem diversas maneiras de fazer investimentos,\n");
        printf("    e nós te indicamos investimentos de baixo risco.\n");

        printf("\n\n    Deseja saber mais sobre Investimento de baixo risco: [s/n]: ");
        scanf("%s", &escolha);
        fflush(stdin);

        if (escolha == 's' || escolha == 'S')
        {

            printf("\n    Investimento de baixo risco é uma modalidade de investimento   \n");
            printf("    que oferece menor possibilidade de perda de capital e maior    \n");
            printf("    estabilidade financeira. Geralmente, são opções de investimento   \n");
            printf("    com menor volatilidade e menor possibilidade de inadimplência,   \n");
            printf("    o que significa que o investidor tem menos chances de perder dinheiro.   \n");
        }
        printf("\n    >Alguns exemplos de investimentos de baixo risco são: \n");
        printf("        1. Tesouro Selic; \n        2. CDB de liquidez diária; \n        3. Fundos DI; \n        4. LCI/LCA.\n\n");
    }
    printf("\n\n                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
}
float CDI_RECURSIVIDADE(float ValorI, float Porcent, int AnosI) // calcular cdi por recursividade
{
    if (AnosI == 0)
    {
        return ValorI;
    }
    else
    {
        float valoradquirido = ValorI * (Porcent / 100);
        ValorI += valoradquirido;
        return CDI_RECURSIVIDADE(ValorI, Porcent, AnosI - 1);
    }
}
int calculadora_CDI() // opção de calcular cdi
{
    float valorinicial, porcentagemCDI;
    int AnosInvestidos;
    system("cls");
    titulo_escuro_ou_claro("           CDI          "); // função de mostrar a cor certa para o titulo
    printf("\n\n\n               O CDI (Certificado de Depósito Interbancário) é uma taxa de juros referencial utilizada no\n");
    printf("	      mercado financeiro brasileiro, que é obtida a partir das operações de empréstimos entre os\n");
    printf("	      bancos. Ele é utilizado como base para o cálculo de rendimentos de diversos investimentos\n");
    printf("		            e é um indicador importante no mercado financeiro do Brasil.\n\n");
    printf("                       NUBANK e OUTROS BANCOS custumão ultilizar 13,75 porcento ao ano no CDI                                     ");

    printf("\n\n\n\n    digite o valor investido no CDI: ");
    scanf("%f", &valorinicial);
    fflush(stdin);
    printf("\n    digite a porcentagem do CDI ao ano: ");
    scanf("%f", &porcentagemCDI);
    fflush(stdin);
    printf("\n    digite os anos investidos: ");
    scanf("%d", &AnosInvestidos);
    fflush(stdin);
    printf("\n\n                                                        RESULTADOS:                                                    \n\n");
    printf("\n    valor final: R$ %.2f", CDI_RECURSIVIDADE(valorinicial, porcentagemCDI, AnosInvestidos));
    printf("\n    valor ganho/juros ganho: R$ %.2f", CDI_RECURSIVIDADE(valorinicial, porcentagemCDI, AnosInvestidos) - valorinicial);
    printf("\n    porcentagem ganha ao mês: %.2f", (((CDI_RECURSIVIDADE(valorinicial, porcentagemCDI, AnosInvestidos) - valorinicial) / valorinicial) * 100) / 12);
    printf("\n\n                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
}

float calculo_investimentos()
{
    system("cls");
    titulo_escuro_ou_claro(" Cálculo de investimento "); // função de mostrar a cor certa para o titulo
    float valor_total, valor_investido, rendimento, numDias;
    float taxa_selic = 13.7;
    float taxa_CDI;
    float taxa_titulo;
    char escolha;

    printf("\n\n    Digite o valor a ser investido: ");
    scanf("%f", &valor_investido);
    fflush(stdin);

    printf("    Digite o número de dias do investimento: ");
    scanf("%f", &numDias);
    fflush(stdin);

    rendimento = valor_investido * (1 + (taxa_selic / 100) * (numDias / 252.0));
    valor_total = valor_investido + rendimento;

    printf("    Valor investido: R$ %.2f\n", valor_investido);
    printf("    Rendimento: R$ %.2f\n", rendimento);
    printf("    Valor final: R$ %.2f\n", valor_total);

    printf("\n    Deseja salvar no arquivo ? [s/n]: ");
    scanf("%s", &escolha);
    fflush(stdin);

    if (escolha == 's' || escolha == 'S')
    {

        FILE *arquivo;
        arquivo = fopen("ANÁLISE.txt", "w");

        if (arquivo == NULL)
        {
            printf("\n    Erro ao abrir o  arquivo.");
        }

        fprintf(arquivo, "\nInvestimentos : ");
        fprintf(arquivo, "\nValor investido: R$ %.2f\n", valor_investido);
        fprintf(arquivo, "\nRendimento: R$ %.2f\n", rendimento);
        fprintf(arquivo, "\nValor final: R$ %.2f\n", valor_total);

        fclose(arquivo);
    }
    printf("\n\n\n                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
}
int investimentos() // opção investimentos
{
    system("cls");
    titulo_escuro_ou_claro("     INVESTIMENTOS      "); // função de mostrar a cor certa para o titulo
    printf("\n\n                                                         DIGITE:                                                      \n\n");
    printf("\n                                             1 -   Módulo de investimento                                            \n");
    printf("\n                                             2 -  Cálculo de investimento                                            \n");
    printf("\n                                             3 -      simulador de CDI                                               \n");

    printf("\n                                             S -          Sair\n\n                                                           ");
    retornar = getch();
    if (retornar == 49)
    {
        modulo_investimentos();
    }
    if (retornar == 50)
    {
        calculo_investimentos();
    }
    if (retornar == 51)
    {
        calculadora_CDI();
    }
    return main();
}

struct analise_salario
{
    float porcentagem_aluguel;
    float porcentagem_alimentacao;
    float porcentagem_transporte;
    float porcentagem_outros_gastos;
    float total_gasto;
} an;// Utilizamos "an" para chamar a struct

int sugestoes()
{
    system("cls");
    titulo_escuro_ou_claro("       SUGESTÕES        "); // função de mostrar a cor certa para o titulo
    char escolha;
    int escolha_int;
    float gastos_essenciais, prio_finceiras, estilo_vida, gasto_livre;
    float objetivo_curto, objetivo_longo;
    printf("\n\n    Deseja ter acesso a uma análise de possíveis reduções de custos ?  [s/n]: ");
    scanf("%s", &escolha);
    fflush(stdin);

    if (escolha == 's' || escolha == 'S')
    {

        printf("\n\n    Sugestões de divisão de recursos: \n\n");

        printf("\n\n    1. Regra do 50-15-35:\n\n");
        printf("\n    >50%% para gastos essenciais.\n");
        printf("\n    >15%% para prioridades financeiras.\n");
        printf("\n    >35%% da sua renda deve ser para as despesas de estilo de vida.\n");

        printf("\n\n    2. Regra do 50-30-20: \n\n");
        printf("\n    >50%% da renda para os gastos essenciais e fixos.\n");
        printf("\n    >30%% para gastos variáveis relacionados ao estilo de vida.\n");
        printf("\n    >20%% para arcar com as prioridades financeiras que vão ajudar a alcançar sonhos e projetos.\n");

        printf("\n\n    3. Regra dos 60-10-10-20:\n\n");
        printf("\n    >60%% da sua renda deve ser destinada aos gastos básicos.\n");
        printf("\n    >10%% para os objetivos de curto prazo .\n");
        printf("\n    >10%% para objetivos de longo prazo.\n");
        printf("\n    >20%% para gastos livres.\n");

        printf("    Qual regra mais lhe agrada? [1/2/3]\n");
        scanf("%d", &escolha_int);
        fflush(stdin);

        if(escolha_int == 1){
            gastos_essenciais = an.porcentagem_aluguel + an.porcentagem_alimentacao;//gastos_essenciais recebe os valores que melhor adequão aos 50%% para Gastos Essenciais
            prio_finceiras = an.porcentagem_transporte;//prio_finceiras recebe os valores que melhor adequão aos 15%% para prioridades financeiras
            estilo_vida = an.porcentagem_outros_gastos;//estilo_vida recebe os valores que melhor adequão aos 35%% da sua renda deve ser para as despesas de estilo de vida.

            if(gastos_essenciais > 50){
                printf("\n    >Infelizmente seus Gastos Essenciais e Fixos ultrapassaram os 50%% de gastos estipulados\n");
            }
            if(prio_finceiras > 15){
                printf("\n    >Infelizmente suas Prioridades Financeiras ultrapassaram os 15%% de gastos estipulados\n");
            }
            if(estilo_vida > 35){
                printf("\n    >Infelizmente suas despesas de estilo de vida ultrapassaram os 35%% de gastos estipulados\n");
            }
            if(gastos_essenciais <= 50 && prio_finceiras <= 15 && estilo_vida <= 35){
                printf("\n    >Parabéns!! Sua divisão de rercusos está excelente.\n");
            }
        }
        if(escolha_int == 2){
            gastos_essenciais = an.porcentagem_aluguel + an.porcentagem_alimentacao;//gastos_essenciais recebe os valores que melhor adequão aos 50%% para Gastos Essenciais
            prio_finceiras = an.porcentagem_transporte;//prio_finceiras recebe os valores que melhor adequão aos 20%% para prioridades financeiras
            estilo_vida = an.porcentagem_outros_gastos;//estilo_vida recebe os valores que melhor adequão aos 30%% para gastos variáveis relacionados ao estilo de vida.

            if(gastos_essenciais > 50){
                printf("\n    >Infelizmente seus Gastos Essenciais ultrapassaram os 50%% de gastos estipulados\n");
            }
            if(prio_finceiras > 20){
                printf("\n    >Infelizmente suas Prioridades Financeiras ultrapassaram os 20%% de gastos estipulados\n");
            }
            if(estilo_vida > 30){
                printf("\n    >Infelizmente suas despesas de estilo de vida ultrapassaram os 30%% de gastos estipulados\n");
            }
            if(gastos_essenciais <= 50 && prio_finceiras <= 20 && estilo_vida <= 30){
                printf("\n    >Parabéns!! Sua divisão de rercusos está excelente.\n");
            }
        }
        if(escolha_int == 3){
            gastos_essenciais = an.porcentagem_aluguel + an.porcentagem_alimentacao+an.porcentagem_transporte;//gastos_essenciais recebe os valores que melhor adequão aos 60%% para Gastos Essenciais
            gasto_livre = an.porcentagem_outros_gastos;//gasto livre recebe os valores que melhor adequão aos 20%% para gastos livres

            if(gastos_essenciais > 60){
                printf("\n    >Infelizmente seus Gastos Básicos ultrapassaram os 60%% de gastos estipulados\n");

            }
            if(gasto_livre > 20){
                 printf("\n    >Infelizmente seu Gasto Livre ultrapassarou os 20%% de gastos estipulados\n");
            }
            if(gastos_essenciais <= 60 && gasto_livre <= 20){
                printf("\n    >Parabéns!! Sua divisão de rercusos está excelente.\n");
            }
        }
        printf("\n\n                                                aperte ENTER para continuar\n\t\t\t\t\t\t\t    ");
        retornar = getch();

        printf("\n\n    Outras maneiras de diminuir os gatos : \n\n");
        printf("\n    >Transporte:usar menos o carro,buscar outros meios como bicicleta.\n");
        printf("\n    >Faça e siga uma lista de supermercado.\n");
        printf("\n    >Diminua gastos com delivery.\n");
        printf("\n    >Revise seus planos multimídia e streaming.\n");
        printf("\n    >Economizar me viajens.\n");
        printf("\n\n                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
        retornar = getch();
        return main();
    }
}

int analise() // FUNÇÃO O ANALISE
{
    system("cls");
    FILE *arquivo_analise;

    float poupar, meses, acumolo_mensal;
    float salario, aluguel, alimentacao, transporte, outros_gastos, total_gasto; // relacionado a análise dos gastos;

    int numero_receitas; // controla o laços de repetiç o e tamanho dos vetores;
    int numero_gastos;

    char escolha;

    float soma_receitas = 0;
    float soma_gastos = 0;

    char nome_usuario[100]; // receber o nome do usuário;
    printf("\n    Informe o primeiro nome do usuário: ");
    scanf("%[^\n]s", nome_usuario); // alterado
    fflush(stdin);

    printf("\n\n    Bem-vindo %s, vamos começar a gerenciar seu financeiro.\n\n\n\n", nome_usuario);

    printf("    É importante ter em mente o porque da necessidade de gerenciar\n    a parte financeira,");
    printf("a maioria das pessoas gastam um certo quantitativo\n    de recurso sem necessidade,");
    printf("sendo possível amenizar esses gastos e\n    com isso ter mais recursos para priorizar");
    printf("o que realmente desejamos\n    atingir ou conquistar.\n\n\n");

    printf("\n    Vamos começar fazendo um orçamento claro e realista.\n\n");

    printf("\n    [Quantas receitas você  informará ?]: ");
    scanf("%d", &numero_receitas);
    fflush(stdin);

    float orcamento_receitas[numero_receitas]; // armazenar os dados referentes aos gastos;;

    for (int i = 0; i < numero_receitas; i++)
    {
        printf("    receita  %d: ", (i + 1));
        scanf("%f", &orcamento_receitas[i]);
        fflush(stdin);
    }
    printf("\n    Receitas informadas: ");

    for (int i = 0; i < numero_receitas; i++)
    {
        printf("\n    [Receita %d = %.2f]", (i + 1), orcamento_receitas[i]);
    }

    printf("\n\n    [Quantas gastos você  informará ?]: ");
    scanf("%d", &numero_gastos);
    fflush(stdin);

    float orcamento_gastos[numero_gastos]; // armazenar os dados referentes a receitas e gastos;;
    printf("\n");
    for (int i = 0; i < numero_gastos; i++)
    {
        printf("    Gasto %d  =", (i + 1));
        scanf("%f", &orcamento_gastos[i]);
        fflush(stdin);
    }

    printf("\n    Gastos  informadas: ");

    for (int i = 0; i < numero_gastos; i++)
    {
        printf("\n    [Gasto %d = %.2f]", (i + 1), orcamento_gastos[i]);
    }

    // Soma das receitas;

    for (int i = 0; i < numero_receitas; i++)
    {
        soma_receitas = soma_receitas + orcamento_receitas[i];
    }

    // Soma dos gastos;

    for (int i = 0; i < numero_gastos; i++)
    {
        soma_gastos = soma_gastos + orcamento_gastos[i];
    }

    printf("\n\n    De modo geral,o quantitativo que resta das receitas é de [%.2f]\n", (soma_receitas - soma_gastos));
    printf("    que corresponde a [ %.1f %% ] do valor total que é informado.\n\n", (percentual_simples(soma_receitas, soma_gastos)));

    printf("    Bom, de maneira simplificada, podemos observar que o percentual de\n    %.1f %% corresponde aos gastos que podem ser amenizados utilizando certas\n    estratégias, como:\n", (100 - percentual_simples(soma_receitas, soma_gastos)));
    printf("\n    >Fazer uma análise dos gastos mensais e identificar onde é possível reduzir os custos;");
    printf("\n    >Controlar as despesas, registrando tudo o que é gasto em um planilha ou aplicativo;");
    printf("\n    >Evitar compras por impulso e fazer uma lista do que realmente é necessário;");
    printf("\n    >Optar por marcas mais baratas, sem comprometer a qualidade dos produtos;");
    printf("\n    >Reduzir a frequência de compras de produtos desnecessários;\n\n\n");

    // Análise mais especifica dos gastos mensais;

    printf("\n    Digite o valor do seu salário R$: ");
    scanf("%f", &salario);
    fflush(stdin);

    printf("\n    Informe o valor do aluguel R$: ");
    scanf("%f", &aluguel);
    fflush(stdin);

    printf("\n    Qual é o seu gasto com alimentação R$: ");
    scanf("%f", &alimentacao);
    fflush(stdin);

    printf("\n    Informe o gasto com transporte R$: ");
    scanf("%f", &transporte);
    fflush(stdin);

    printf("\n    Qual o valor estimado dos  outros gastos R$: ");
    scanf("%f", &outros_gastos);
    fflush(stdin);

    // Cálculos que envolvem os gastos mensais;

    an.total_gasto = aluguel + alimentacao + transporte + outros_gastos;

    an.porcentagem_aluguel = (aluguel / salario) * 100; // percentuais dos gastos estimados;
    an.porcentagem_alimentacao = (alimentacao / salario) * 100;
    an.porcentagem_transporte = (transporte / salario) * 100;
    an.porcentagem_outros_gastos = (outros_gastos / salario) * 100;

    // Mostrar  os  resultados da análise;

    printf("\n\n");
    printf("    Seu salário corresponde a R$%.2f e seus gastos foram um total de R$%.2f no mês.\n", salario, an.total_gasto);
    printf("    O gasto com aluguel representa %.1f %% dos seus gastos mensais.\n", an.porcentagem_aluguel);
    printf("    O gasto com alimentação representa %.1f %% dos gastos mensais.\n", an.porcentagem_alimentacao);
    printf("    O gasto com transporte corresponde a %.1f %% dos gastos mensais.", an.porcentagem_transporte);
    printf("\n    Os outros gastos correspondem a %.1f %% dos gastos mensais.", an.porcentagem_outros_gastos);

    // perguntar ao usuário se deseja salvar os dados em um arquivo;

    printf("\n\n    Deseja salvar os dados em um arquivo ? (s/n): ");
    scanf("%s", &escolha);
    fflush(stdin);

    if (escolha == 'S' || escolha == 's')
    {
        arquivo_analise = fopen("ANÁLISE.txt", "a");

        if (arquivo_analise == NULL)
        {
            printf("\n    Erro ao abrir o arquivo para registrar a análise: ");
        }

        // Registrar os dados em um arquivo de texto;
        fprintf(arquivo_analise, "\n\n%s\n", nome_usuario);
        fprintf(arquivo_analise, "\nValores informados : \n");
        fprintf(arquivo_analise, "Salário : R$%.2f\n", salario); // Valores
        fprintf(arquivo_analise, "Aluguel : R$%.2f\n", aluguel);
        fprintf(arquivo_analise, "Alimentação :  R$%.2f\n", alimentacao);
        fprintf(arquivo_analise, "Transporte :  R$%.2f\n", transporte);
        fprintf(arquivo_analise, "Outros gastos :  R$%.2f\n", outros_gastos);

        // Respectivos percentuais :

        fprintf(arquivo_analise, "\n\nRespectivos percentuais : \n");
        fprintf(arquivo_analise, "Aluguel : %.1f%%\n", an.porcentagem_aluguel);
        fprintf(arquivo_analise, "Alimentação :  %.1f%%\n", an.porcentagem_alimentacao);
        fprintf(arquivo_analise, "Transporte :  %.1f%%\n", an.porcentagem_transporte);
        fprintf(arquivo_analise, "Outros gastos :  %.1f%%\n", an.porcentagem_outros_gastos);
        fprintf(arquivo_analise, "--------------------------");

        // Fechar o arquivo de  resgistro;
        fclose(arquivo_analise);

        printf("\n    >Os dados foram salvos.\n");
    }
    else
    {
        printf("\n    >Os dados não foram salvos.\n");
    }
    printf("\n\n                                                aperte ENTER para continuar\n\t\t\t\t\t\t\t    ");
    retornar = getch();

    printf("\n\n    Para ter uma ideia de como economizar pode garantir a existência de recurso futuros,\n    vamos fazer o seguinte cálculo:");
    printf("\n\n    >Informe uma quantidade que deseja poupar por mês: ");
    scanf("%f", &poupar);
    fflush(stdin);
    printf("    >Quantos meses deseja continuar poupando: ");
    scanf("%f", &meses);
    fflush(stdin);

    acumolo_mensal = poupar * meses;

    printf("\n\n    >No acúmulo mensal o valor guardado será R$%.2f.", acumolo_mensal);
    printf("\n\n\n                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
} // fim função analise.

int analises_salvas() // funç o para mostrar todos dados salvos
{
    system("cls");
    titulo_escuro_ou_claro("     ANÁLISES SALVAS    "); // funç o de mostrar a cor certa para o titulo

    char letras;
    FILE *arquivo_analise;

    arquivo_analise = fopen("ANÁLISE.txt", "r");
    while ((letras = fgetc(arquivo_analise)) != EOF)
    {
        if (letras == '\n')
        {
            printf("%c                                                ", letras);
        }
        else
        {
            printf("%c", letras);
        }
    }
    printf("\n\n\n                                                 aperte ENTER para voltar\n");
    printf("                                                            ou\n");
    printf("                                              aperte L para Limpar Análises\n\t\t\t\t\t\t\t    ");
    letras = getch();
    if (letras == 'L' || letras == 'l')
    {
        arquivo_analise = fopen("ANÁLISE.txt", "w");
        fclose(arquivo_analise);
    }
    FILE *cor_de_fundo;
    cor_de_fundo = fopen("cores.txt", "r");
    fscanf(cor_de_fundo, "%d", &comparador_Plano_de_fundo);
    fclose(cor_de_fundo);
    return main();
}

int introducao() // introduç o de oque é gerenciamento financeiro
{
    system("cls");
    titulo_escuro_ou_claro("       INTRODUÇÃO       "); // funç o de mostrar a cor certa para o titulo

    printf("\t\tO gerenciamento financeiro é uma disciplina que engloba o planejamento, organização,\n");
    printf("\t\tdireção e controle das atividades financeiras de uma organização ou de um indivíduo.\n");
    printf("\t\tEssa prática envolve a administração eficiente dos recursos financeiros disponíveis,\n");
    printf("\t\tcomo dinheiro, investimentos, financiamentos e riscos, com o objetivo de atingir\n");
    printf("\t\tmetas financeiras e estratégicas.\n\n");

    printf("\t\tO gerenciamento financeiro é fundamental para garantir o uso eficaz dos recursos\n");
    printf("\t\tfinanceiros, a sustentabilidade financeira e o crescimento de uma organização ou\n");
    printf("\t\tindivíduo. É uma área essencial para a tomada de decis?es financeiras informadas\n");
    printf("\t\te para a avaliação do desempenho financeiro. O conhecimento e a aplicação adequada\n");
    printf("\t\tdos princípios de gerenciamento financeiro são cruciais para o sucesso de qualquer\n");
    printf("\t\torganização ou pessoa na busca de suas metas financeiras e estratégicas.\n\n");

    printf("\t\tUma gestão financeira eficiente é fundamental para garantir a saúde financeira,\n");
    printf("\t\ta competitividade e a sustentabilidade de uma organização. Envolve o planejamento\n");
    printf("\t\tcuidadoso do orçamento, a análise e controle das despesas, a gestão do capital de giro,\n");
    printf("\t\ta tomada de decisões de investimento e financiamento, a gestão de riscos financeiros,\n");
    printf("\t\ta elaboração de relatórios financeiros precisos e a análise criteriosa do desempenho\n");
    printf("\t\tfinanceiro.\n\n");

    printf("\t\tO gerenciamento financeiro bem-sucedido permite a alocação eficiente dos recursos\n");
    printf("\t\tfinanceiros, a maximização do retorno sobre o investimento e a criação de uma base\n");
    printf("\t\tsólida para o crescimento e a expans o de uma organização. Em resumo, o gerenciamento\n");
    printf("\t\tfinanceiro é uma disciplina essencial para o sucesso financeiro de organizações e\n");
    printf("\t\tindivíduos, possibilitando a tomada de decisões informadas e estratégicas relacionadas\n");
    printf("\t\taos recursos financeiros disponíveis.\n\n");
    printf("                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
}

int creditos()
{
    system("cls");
    titulo_escuro_ou_claro("        CRÉDITOS:       "); // função de mostrar a cor certa para o titulo
    printf("\n\n\n\n\n                                                     Programado Por:                                                  \n\n\n");
    printf("                                                     Neemias Claudio                                                  \n\n");
    printf("                                                   Danilo S. R. Silva                                                 \n\n");
    printf("                                                   Gustavo S. Teixeira                                                \n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                aperte ENTER para voltar\n\t\t\t\t\t\t\t    ");
    retornar = getch();
    return main();
}
/***************************************************************************************     MENU     ****************************************************************************************/

int modoescuro() // função do modo escuro.
{
    while (menu != 20)
    {
        FILE *cor_de_fundo; // criador de arquivo que salva informa??o de cor de fundo!
        cor_de_fundo = fopen("cores.txt", "w");
        fprintf(cor_de_fundo, "%d", 2);
        fclose(cor_de_fundo);
        comparador_Plano_de_fundo = 2;
        system("cls");
        setlocale(LC_ALL, "Portuguese");
        system("color 0F"); // cor do fundo
        printf("\n            @@@@@@@#         .#@@@@@@#.  #@@@@@@@@@@@@@@@@@  .#@@@@@@@!       !@@@@@@#  .#@@@@@@:      #@@@@@@!        \n");
        printf("            @@@@@@@@@.      :@@@@@@@@#.  #@@@@@@@@@@@@@@@@@   #@@@@@@@@@!     :@@@@@@#   !@@@@@@.      #@@@@@@!        \n");
        printf("            @@@@@@@@@@:    !@@@@@@@@@#   !@@@@@@#             !@@@@@@@@@@@#   .@@@@@@!   !@@@@@@       #@@@@@@!        \n");
        printf("            @@@@@@@@@@@@ .@@@@@@@@@@@#   :@@@@@@@@@@@@@@@@    !@@@@@@!@@@@@@#. #@@@@@:   !@@@@@@       !@@@@@@:        \n");
        printf("            @@@@@@!!@@@@@@@@@#.@@@@@@#   :@@@@@@@#######@@    !@@@@@@  :@@@@@@@@@@@@@:   !@@@@@@       !@@@@@@:        \n");
        printf("            @@@@@@! :@@@@@@@@  @@@@@@#   #@@@@@@!             #@@@@@@    .@@@@@@@@@@@:   !@@@@@@:      #@@@@@@:        \n");
        printf("            @@@@@@#  .@@@@@!   @@@@@@#.  #@@@@@@@@@@@@@@@@@! .#@@@@@@      .#@@@@@@@@:   !@@@@@@@@@@@@@@@@@@@@         \n");
        printf("            @@@@@@#    @@@:   .@@@@@@@.  #@@@@@@@@@@@@@@@@@  .@@@@@@@         !@@@@@@:     !@@@@@@@@@@@@@@@#.          \n");
        titulo_escuro_ou_claro("GERENCIAMENTO FINANCEIRO"); // função de mostrar a cor certa para o titulo
        printf("\n                                                         DIGITE:                                                      \n\n");
        printf("\n                                                 1 - Começar Análise                                                 ");
        printf("\n                                                 2 - Análises Salvas                                                 ");
        printf("\n                                                 3 -   introdução                                                    ");
        printf("\n                                                 4 -  Juros Simples                                                  ");
        printf("\n                                                 5 - Juros Compostos                                                 ");
        printf("\n                                                 6 -  Investimentos                                                  ");
        printf("\n                                                 7 -    Sugestões                                                    ");
        printf("\n                                                 8 -   Modo Claro                                                    ");
        printf("\n                                                 C -    Créditos                                                     ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n                                                 F -     Fechar                                                      \n                                                           ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        menu = getch();
        fflush(stdin);

        if (menu == 49) // Começar!
        {
            analise();
        }
        if (menu == 50) // ANALISES SALVAS
        {
            printf(analises_salvas());
        }
        if (menu == 51) // intrudução
        {
            introducao();
        }
        if (menu == 52) // Juro simples
        {
            juros_simples_f();
        }
        if (menu == 53) // Juro compostos
        {
            juros_compostos_f();
        }
        if (menu == 54) // Investimentos
        {
            investimentos();
        }
        if (menu == 55) // sugestões
        {
            sugestoes();
        }
        if (menu == 56) // modo Claro
        {

            FILE *cor_de_fundo; // mudador de arquivo para voltar o arquivo para cor branca!
            cor_de_fundo = fopen("cores.txt", "w");
            fprintf(cor_de_fundo, "%d", 0);
            fclose(cor_de_fundo);
            printf(main());
        }
        if (menu == 'c' || menu == 'C') // CREDITOS
        {
            creditos();
        }

        if (menu == 'f' || menu == 'F') // fechar programa
        {

            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                 Programa Encerrado!!                                                \n\n\n\n\n\n\n\n\n\n\n\n\n");
            return 0;
        }
    }
}

int main() // função principal modo claro
{

    FILE *cor_de_fundo;
    cor_de_fundo = fopen("cores.txt", "r");                 // abrindo o aquivo que armazena a informação de qual modo está ativo, claro/escuro.
    fscanf(cor_de_fundo, "%d", &comparador_Plano_de_fundo); // colocando o numero que estiver dentro do arquivo dentro de uma variavel
    fclose(cor_de_fundo);

    while (menu != 20)
    {
        system("cls");
        if (comparador_Plano_de_fundo != 2) // visualizando qual plano de fundo está salvo na memoria atravez da variavel
        {
            setlocale(LC_ALL, "Portuguese");
            system("color F0"); // cor do fundo
            printf("\n            @@@@@@@#         .#@@@@@@#.  #@@@@@@@@@@@@@@@@@  .#@@@@@@@!       !@@@@@@#  .#@@@@@@:      #@@@@@@!        \n");
            printf("            @@@@@@@@@.      :@@@@@@@@#.  #@@@@@@@@@@@@@@@@@   #@@@@@@@@@!     :@@@@@@#   !@@@@@@.      #@@@@@@!        \n");
            printf("            @@@@@@@@@@:    !@@@@@@@@@#   !@@@@@@#             !@@@@@@@@@@@#   .@@@@@@!   !@@@@@@       #@@@@@@!        \n");
            printf("            @@@@@@@@@@@@ .@@@@@@@@@@@#   :@@@@@@@@@@@@@@@@    !@@@@@@!@@@@@@#. #@@@@@:   !@@@@@@       !@@@@@@:        \n");
            printf("            @@@@@@!!@@@@@@@@@#.@@@@@@#   :@@@@@@@#######@@    !@@@@@@  :@@@@@@@@@@@@@:   !@@@@@@       !@@@@@@:        \n");
            printf("            @@@@@@! :@@@@@@@@  @@@@@@#   #@@@@@@!             #@@@@@@    .@@@@@@@@@@@:   !@@@@@@:      #@@@@@@:        \n");
            printf("            @@@@@@#  .@@@@@!   @@@@@@#.  #@@@@@@@@@@@@@@@@@! .#@@@@@@      .#@@@@@@@@:   !@@@@@@@@@@@@@@@@@@@@         \n");
            printf("            @@@@@@#    @@@:   .@@@@@@@.  #@@@@@@@@@@@@@@@@@  .@@@@@@@         !@@@@@@:     !@@@@@@@@@@@@@@@#.          \n");
            titulo_escuro_ou_claro("GERENCIAMENTO FINANCEIRO"); // funç o de mostrar a cor certa para o titulo

            printf("\n                                                         DIGITE:                                                      \n\n");
            printf("\n                                                 1 - Começar Análise                                                 ");
            printf("\n                                                 2 - Análises Salvas                                                 ");
            printf("\n                                                 3 -   introdução                                                    ");
            printf("\n                                                 4 -  Juros Simples                                                  ");
            printf("\n                                                 5 - Juros Compostos                                                  ");
            printf("\n                                                 6 -  Investimentos                                                  ");
            printf("\n                                                 7 -    Sugestões                                                    ");
            printf("\n                                                 8 -   Modo Escuro                                                   ");
            printf("\n                                                 C -    Créditos                                                     ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
            printf("\n                                                 F -     Fechar                                                      \n                                                           ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

            menu = getch();
            fflush(stdin);

            if (menu == 49) // Começar!
            {
                analise();
            }
            if (menu == 50) // ANALISES SALVAS
            {
                printf(analises_salvas());
            }
            if (menu == 51) // intrudução
            {
                introducao();
            }
            if (menu == 52) // Juro simples
            {
                juros_simples_f();
            }
            if (menu == 53) // Juro compostos
            {
                juros_compostos_f();
            }
            if (menu == 54) // Investimentos
            {
                investimentos();
            }
            if (menu == 55) // sugestões
            {
                sugestoes();
            }
            if (menu == 56) // modo escuro
            {

                modoescuro();
            }
            if (menu == 'c' || menu == 'C') // CREDITOS
            {
                creditos();
            }

            if (menu == 'f' || menu == 'F') // fechar programa
            {

                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                 Programa Encerrado!!                                                \n\n\n\n\n\n\n\n\n\n\n\n\n");
                return 0;
            }
        }
        else // iniciando programa no modo escuro caso na memoria conste o numero 2
        {
            printf(modoescuro());
        }
    }
    system("pause");
    return 0;
}
