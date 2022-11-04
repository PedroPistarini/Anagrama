/*
    MATHEUS ECKE MEDEIROS - RA: 22004797
    PEDRO FERNANDES DI GRAZIA - RA: 22002293
    PEDRO HENRIQUE RIBEIRO PISTARINI - RA: 22000341
    VICTOR ARONI FERNANDES - RA: 22000397
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int menu();
void cabecalho();
void jogo(char banco_de_palavra[][21], char palavras_corretas[][21], char palavras_erradas[][21], int esc);
void modo_facil(int esc);
void modo_medio(int esc);
void modo_dificil(int esc);
void quadros(int esc);
int valida_palavra(char palavra[]);
int testa_correta(char banco_de_palavra[][21], char palavras_corretas[][21], char palavras_erradas[][21], int x);
void you_win();
void game_over();
void mudacor(int cor);

int main()
{
    int esc;

    do
    {
        esc=menu();
        switch(esc)
        {
        case 1:
            system("cls");
            modo_facil(esc);
            break;

        case 2:
            system("cls");
            modo_medio(esc);
            break;

        case 3:
            system("cls");
            modo_dificil(esc);
            break;

        case 4:
            system("cls");
            printf("PROGRAMA ENCERRADO");
            return 0;
        }
    } while (esc<1 || esc>4);

    printf("\n\n\n");
    return 0;
}

int menu()
{
    int escolha;

    printf("\n  DIFICULDADE ");
    mudacor(8);
    printf("\n====================");
    mudacor(15);
    printf("\n [01]");
    mudacor(10);
    printf(" FACIL");
    mudacor(15);
    printf("\n [02]"); 
    mudacor(14);
    printf(" MEDIO");
    mudacor(15);
    printf("\n [03]");
    mudacor(12);
    printf(" DIFICIL");
    mudacor(15);
    printf("\n [04] FINALIZAR JOGO\n");
    printf("\n ESCOLHA: ");
    scanf("%d", &escolha);
    return escolha;
}

void cabecalho()
{
    mudacor(8);
    printf("================================================================");
    mudacor(11);
    printf("\n\n\t\t\t  [ ANAGRAMA ]\n");
    mudacor(3);
    printf("\n\t  REGRAS:");
    mudacor(15);
    printf("\n\t    > Formar palavras com quadro a seguir!");
    printf("\n\t    > Descubra 20 palavras escondidas!");
    printf("\n\t    > Depois de 5 erros o jogo acaba!");
    printf("\n\t    > Aperte ENTER para encerrar o jogo!");
    printf("\n\n\t\t\t   BOA SORTE!\n\n");
    mudacor(8);
    printf("================================================================");
    mudacor(15);
}

void jogo(char banco_de_palavra[][21], char palavras_corretas[][21], char palavras_erradas[][21], int esc)
{
    int acertos=0, erros=0, x=0, sn;

    do
    {
        system("cls");
        cabecalho();
        printf("\n\n");
        mudacor(11);
        printf("\t\t       [ QUADRO DE LETRAS ]\n\n");
        mudacor(15);
        quadros(esc);
        mudacor(8);
        printf("\n\n================================================================\n");
        mudacor(10);
        printf("\n ACERTOS: (%d de 20)", acertos);
        mudacor(12);
        printf("\t\tERROS: (%d de 10)\n", erros);
        mudacor(15);
        printf("\n PALAVRAS CORRETAS >");
        for (int i=0; i<20; i++)
        {
            printf("\t%s", palavras_corretas[i]);
            if(i==4||i==9||i==14||i==19)
            {
                printf("\n\t\t");
            }
        }
        printf("\n PALAVRAS ERRADAS  >");
        for (int i=0; i<10; i++)
        {
            printf("\t%s", palavras_erradas[i]);
            if(i==4)
            {
                printf("\n\t\t");
            }
        }

        int k=testa_correta(banco_de_palavra, palavras_corretas, palavras_erradas, x);

        if(k==0)
        {
            acertos++;
        }
        else if(k==1)
        {
            erros++;
            x++;
        }
        else if(k==2)
        {
            printf("\n PALAVRA JA DIGITADA!");
            Sleep(1500);
        }
        else if(k==3)
        {
            mudacor(8);
            printf("\n\n================================================================");
            mudacor(15);
            printf("\n\n DESEJA VER O BANCO DE PALAVRAS?\n");
            printf("\n [01] SIM");
            printf("\n [02] NAO");
            do
            {
                printf("\n\n ESCOLHA: ");
                scanf("%d", &sn);
                switch (sn)
                {
                    case 1:
                        mudacor(8);
                        printf("\n================================================================\n\n");
                        mudacor(11);
                        printf("\t\t     [ BANCO DE PALAVRAS ]\n\n\t");
                        mudacor(15);
                        for (int i=0; i<20; i++)
                        {
                            printf("\t%s", banco_de_palavra[i]);
                            if(i==4||i==9||i==14||i==19)
                            {
                                printf("\n\t");
                            }
                        }
                        mudacor(8);
                        printf("\n================================================================\n\n");
                        mudacor(15);
                        break;    
                    case 2:
                    printf("\nJOGO ENCERRADO\n\n\n");
                }
            } while (sn<1 || sn>2);
            return;
        }
    
    }while (erros<10 && acertos<20);

    if(acertos==20)
    {
        you_win();
        return;
    }
    else if(erros==10)
    {
        game_over();
        return;
    }
}

void modo_facil(int esc)
{
    char banco_de_palavra[][21] = {"OVO", "BOM", "GOL", "PAI", "BAR", "LEI", "REI", "MAR", "SIM", "LUZ", "SOL", "ASA", "RUA", "BOLO", "CASO", "LEVE", "LUXO", "MODA", "VIDA", "OLHO"};
    char palavras_corretas[][21] = {"***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "****", "****", "****", "****", "****", "****", "****"};
    char palavras_erradas[][21] = {"____", "____", "____", "____", "____", "____", "____", "____", "____", "____"};

    jogo(banco_de_palavra, palavras_corretas, palavras_erradas, esc);
}

void modo_medio(int esc)
{
    char banco_de_palavra[][21] = {"PEDRA", "PRATO", "BANCO", "BLUSA", "CAIXA", "MOUSE", "ROSCA", "DENTE", "TAMPA", "VERDE", "MARROM", "TECLA", "AREIA", "BOLSA", "ARROZ", "IDEIA", "PODER", "MORAL", "HONRA", "JUSTO"};
    char palavras_corretas[][21] = {"*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****", "*****"};
    char palavras_erradas[][21] = {"_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____"};

    jogo(banco_de_palavra, palavras_corretas, palavras_erradas, esc);
}

void modo_dificil(int esc)
{
    char banco_de_palavra[][21] = {"POSTAR", "LEGADO", "GENTIL", "ASTUTO", "FORMAL", "JULGAR", "VULGAR", "CASUAL", "HOSTIL", "ALHEIO", "PRESSA", "GANHAR", "MACACO", "INFAME", "ANSEIO", "APONTAR", "SUBLIME", "CULTURA", "ALEGRIA", "AMPUTAR"};
    char palavras_corretas[][21] = {"******", "******", "******", "******", "******", "******", "******", "******", "******", "******", "******", "******", "******", "******", "******", "*******", "*******", "*******", "*******", "*******"};
    char palavras_erradas[][21] = {"______", "______", "______", "______", "______", "______", "______", "______", "______", "______"};

    jogo(banco_de_palavra, palavras_corretas, palavras_erradas, esc);
}

void quadros(int esc)
{
    if(esc==1)
    {
        printf("\t\t      B    C    L    M    V \n\t\t      R    O    G    P    A \n\t\t      S    O    E    E    U\n\t\t      X    I    D    H    A");
    }
    if(esc==2)
    {
        printf("\t\t      P    B    C    M    R \n\t\t      D    T    A    H    I \n\t\t      V    Z    I    E    O\n\t\t      L    A    U    S    X \n\t\t      R    N    J    E    M");
    }
    if(esc==3)
    {
        printf("\t\t      P    L    G    A    F \n\t\t      J    V    C    H    M \n\t\t      S    O    T    R    E\n\t\t      S    D    N    I    A \n\t\t      U    T    U    C    B");
    }
}

int valida_palavra(char palavra[])
{
    for (int i=0; i<strlen(palavra); i++)
    {
        if (isalpha(palavra[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int testa_correta(char banco_de_palavra[][21], char palavras_corretas[][21], char palavras_erradas[][21], int x)
{
    char palavra_digitada[21];

    do
    {
        printf("\n\n RESPOSTA: ");
        fflush(stdin);
        scanf("%[^\n]", palavra_digitada);
        strupr(palavra_digitada);
        if(strlen(palavra_digitada)==0)
        {
            return 3;
        }
    } while (valida_palavra(palavra_digitada)==1);

    for (int i=0; i<20; i++)
    {
        if (strcmp(palavra_digitada, palavras_corretas[i])==0)
        {
            return 2;
        }

        if (strcmp(palavra_digitada, banco_de_palavra[i])==0)
        {
            strcpy(palavras_corretas[i], palavra_digitada);
            return 0;
        }
    }
    strcpy(palavras_erradas[x], palavra_digitada);

    return 1;
}

void you_win()
{
    mudacor(10);
    system("cls");
    Sleep(500);
    printf("\n||      ||     |||||||     ||      ||"); Sleep(200);
    printf("\n ||    ||    ||       ||   ||      ||"); Sleep(200);
    printf("\n  ||  ||     ||       ||   ||      ||"); Sleep(200);
    printf("\n   ||||      ||       ||   ||      ||"); Sleep(200);
    printf("\n    ||       ||       ||   ||      ||"); Sleep(200);
    printf("\n    ||       ||       ||   ||      ||"); Sleep(200);
    printf("\n    ||         |||||||       ||||||  "); Sleep(200);
    printf("\n\n                                   "); Sleep(300);
    printf("\n||             ||    ||    |||     ||"); Sleep(200);
    printf("\n||             ||    ||    ||||    ||"); Sleep(200);
    printf("\n ||           ||     ||    || ||   ||"); Sleep(200);
    printf("\n  ||    |    ||      ||    ||  ||  ||"); Sleep(200);
    printf("\n   ||  |||  ||       ||    ||   || ||"); Sleep(200);
    printf("\n    |||| ||||        ||    ||    ||||"); Sleep(200);
    printf("\n     ||   ||         ||    ||     |||"); Sleep(200);
    mudacor(15);
}

void game_over()
{
    mudacor(12);
    system("cls");
    Sleep(500);
    printf("\n|||||||||||||   ||||||||||||    ||          ||   ||||||||||| "); Sleep(200);
    printf("\n||              ||        ||    ||||      ||||   ||          "); Sleep(200);
    printf("\n||              ||        ||    ||  ||  ||  ||   ||          "); Sleep(200);
    printf("\n||    |||||||   ||        ||    ||    ||    ||   ||||||||    "); Sleep(200);
    printf("\n||         ||   ||||||||||||    ||          ||   ||          "); Sleep(200);
    printf("\n||         ||   ||        ||    ||          ||   ||          "); Sleep(200);
    printf("\n|||||||||||||   ||        ||    ||          ||   ||||||||||| "); Sleep(200);
    printf("\n\n                                                           "); Sleep(300);
    printf("\n  |||||||||     ||        ||    |||||||||||      ||||||||||||"); Sleep(200);
    printf("\n||         ||   ||        ||    ||               ||        ||"); Sleep(200);
    printf("\n||         ||   ||        ||    ||               ||        ||"); Sleep(200);
    printf("\n||         ||   ||        ||    ||||||||         ||||||||||||"); Sleep(200);
    printf("\n||         ||    ||      ||     ||               ||     ||   "); Sleep(200);
    printf("\n||         ||     ||    ||      ||               ||      ||  "); Sleep(200);
    printf("\n  |||||||||         ||||        |||||||||||      ||       || "); Sleep(200);
    mudacor(15);
}

void mudacor(int cor)
{
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida,cor);
}
