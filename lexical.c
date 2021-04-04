#include <stdio.h>
#include <stdlib.h>

int numero = 1;

int nome(char linha[], int indice, int coluna)
{
    int aux = coluna;
    int i=0;
    char identificador[20] = {};
    while( linha[aux] != ';' && linha[aux] != '=' && linha[aux] != ')' && linha[aux] != '(' && linha[aux] != '+' && linha[aux] != '-' && linha[aux] != '<' && linha[aux] != '>' && linha[aux] != ','  && linha[aux] != '[' && linha[aux] != '*' && linha[aux] != '/')
    {
        if( linha[aux] != ' ')
        {
            identificador[i] = linha[aux];
            i++;
        }
        aux++;
    }
    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Identificador", identificador);
    return(aux - 1);
}
void lexico(char linha[], int indice)
{
    int coluna;
    /* char data[256]; */
    for( coluna=0 ; coluna < 256; coluna++)
    {
        if( linha[coluna] != ' ')
        {
            /* data[i] = linha[i]; */
            if ( linha[coluna] == 'i' && linha[coluna+1] == 'n' && linha[coluna+2] == 't' && linha[coluna+3]==' ')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Variavel", "int");
                numero++;
                coluna = coluna + 3;
                coluna = nome(linha, indice, coluna);    
            }
            else if ( linha[coluna] == 'f' && linha[coluna+1] == 'l' && linha[coluna+2] == 'o' && linha[coluna+3] == 'a' && linha[coluna+4] == 't' && linha[coluna+5]==' ')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Variavel", "float");
                numero++;
                coluna = coluna + 5;
                coluna = nome(linha, indice, coluna); 
            }
            else if ( linha[coluna] == 'c' && linha[coluna+1] == 'h' && linha[coluna+2] == 'a' && linha[coluna+3] == 'r' && linha[coluna+4]==' ' )
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Variavel", "char");
                numero++;
                coluna = coluna + 4;
                coluna = nome(linha, indice, coluna); 
            }
            else if ( linha[coluna] == 'b' && linha[coluna+1] == 'o' && linha[coluna+2] == 'o' && linha[coluna+3] == 'l' && linha[coluna+4]==' ')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Variavel", "bool");
                numero++;
                coluna = coluna + 4;
                coluna = nome(linha, indice, coluna); 
            }
            else if ( linha[coluna] == 's' && linha[coluna+1] == 't' && linha[coluna+2] == 'r' && linha[coluna+3] == 'i' && linha[coluna+4] == 'n' && linha[coluna+5] == 'g' && linha[coluna+6]==' ')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Variavel", "string");
                numero++;
                coluna = coluna + 6;
                coluna = nome(linha, indice, coluna); 
            }
            else if (linha[coluna] == '+')
            {
                if ( linha[coluna+1] == '+')
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "++");
                    coluna++;
                    numero++;
                }
                else
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "+");
                    numero++;
                }
            }
            else if (linha[coluna] == '-')
            {
                if ( linha[coluna+1] == '-')
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "--");
                    numero++;
                    coluna++;
                }
                else
                {   
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "-"); 
                    numero++; 
                }
            }
            else if (linha[coluna] == '/')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "/");
                numero++;
            }
            else if (linha[coluna] == '*')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "*");
                numero++;
            }
            else if (linha[coluna] == '%')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "%%");
                numero++;
            }
            else if (linha[coluna] == '=')
            {
                if ( linha[coluna+1] == '=')
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "==");
                    numero++;
                    coluna++;
                }
                else
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "=");
                    numero++;
                }
            }
            else if (linha[coluna] == '!' && linha[coluna+1] == '=')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "!=");
                numero++;
                coluna++;
            }
            else if (linha[coluna] == '<')
            {
                if ( linha[coluna+1] == '=')
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "<=");
                    numero++;
                    coluna++;
                }
                else
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "<");
                    numero++;
                }
            }
            else if (linha[coluna] == '>')
            {
                if ( linha[coluna+1] == '=')
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", ">=");
                    numero++;
                    coluna++;
                }
                else
                {
                    printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", ">");
                    numero++;
                }
            }
            else if (linha[coluna] == '&')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "&");
                numero++;
            }
            else if (linha[coluna] == '|')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Operador", "|");
                numero++;
            }
            else if (linha[coluna] == ';')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", ";");
                numero++;
                return;
            }
            else if (linha[coluna] == '{')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", "{");
                numero++;
            }
            else if (linha[coluna] == '(')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", "(");
                numero++;
            }
            else if (linha[coluna] == '}')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", "}");
                numero++;
            }
            else if (linha[coluna] == ')')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", ")");
                numero++;
            }
            else if (linha[coluna] == '[')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", "[");
                numero++;
            }
            else if (linha[coluna] == ']')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", "]");
                numero++;
            }
            else if (linha[coluna] == ',')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", ",");
                coluna++;
                numero++;
                coluna = nome(linha, indice, coluna); 
            }
            else if (linha[coluna] == '"')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Delimitador", "\"");
                numero++;
                int i=0;
                char identificador[30] = {};
                int aux = coluna + 1;
                while(linha[coluna+1] != '"')
                {
                  identificador[i] = linha[coluna+1];
                  coluna++;
                  i++;
                }
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, aux, numero, "Identificador - String de Char", identificador);
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 2, numero, "Delimitador", "\"");
                coluna++;
            }
            else if ( linha[coluna] == 'f' && linha[coluna+1] == 'o' && linha[coluna+2] == 'r' )
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Keyword", "for");
                numero++;
                coluna = coluna + 2;  
            }
            else if ( linha[coluna] == 'i' && linha[coluna+1] == 'f' )
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Keyword", "if");
                numero++;
                coluna = coluna + 1;  
            }
            else if ( linha[coluna] == 'w' && linha[coluna+1] == 'h' && linha[coluna+2] == 'i' && linha[coluna+3] == 'l' && linha[coluna+4] == 'e' )
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Keyword", "while");
                numero++;
                coluna = coluna + 4;  
            }
            else if ( linha[coluna] == 'p' && linha[coluna+1] == 'r' && linha[coluna+2] == 'i' && linha[coluna+3] == 'n' && linha[coluna+4] == 't')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Keyword", "print");
                numero++;
                coluna = coluna + 4;
            }
            else if ( linha[coluna] == 's' && linha[coluna+1] == 'c' && linha[coluna+2] == 'a' && linha[coluna+3] == 'n')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Keyword", "scan");
                numero++;
                coluna = coluna + 3;
            }
            else if ( linha[coluna] == 'c' && linha[coluna+1] == 'o' && linha[coluna+2] == 'n' && linha[coluna+3] == 's' && linha[coluna+4] == 't')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Variavel", "const");
                numero++;
                coluna = coluna + 4;
            }
            else if ( linha[coluna] == '0' || linha[coluna] == '1' || linha[coluna] == '2' || linha[coluna] == '3' || linha[coluna] == '4' || linha[coluna] == '5' || linha[coluna] == '6' || linha[coluna] == '7' || linha[coluna] == '8' || linha[coluna] == '9' )
            {
                int i=0;
                char identificador[30] = {};
                int aux = coluna + 1;
                while(linha[coluna] == '0' || linha[coluna] == '1' || linha[coluna] == '2' || linha[coluna] == '3' || linha[coluna] == '4' || linha[coluna] == '5' || linha[coluna] == '6' || linha[coluna] == '7' || linha[coluna] == '8' || linha[coluna] == '9' )
                {
                  identificador[i] = linha[coluna];
                  coluna++;
                  i++;
                }
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, aux, numero, "Valor numerico", identificador);
                numero++;
                coluna--;
            }
            else if ( linha[coluna] == 'T' && linha[coluna+1] == 'R' && linha[coluna+2] == 'U' && linha[coluna+3] == 'E')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Valor booleano", "TRUE");
                numero++;
                coluna = coluna + 3;
            }
            else if ( linha[coluna] == 'F' && linha[coluna+1] == 'A' && linha[coluna+2] == 'L' && linha[coluna+3] == 'S' && linha[coluna+4] == 'E')
            {
                printf("          [%04d, %04d] (%04d, %20s) {%s}\n", indice, coluna + 1, numero, "Valor booleano", "FALSE");
                numero++;
                coluna = coluna + 4;
            }
            else
            {
                coluna = nome(linha, indice, coluna);
                numero++; 
            }
        }
    }

}
int main(int argc, char *argv[]) 
{
    if( argc == 2 ) 
    {
      printf("Carregando %s\n", argv[1]);
    }
    else if( argc > 2 ) 
    {
        printf("Informe só uma entrada.\n");
        exit(0);
    }
    else 
    {
        printf("Informe alguma entrada\n");
        exit(0);
    }

    FILE *f;
    char linha[256] = {};
    int indice = 1;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Não foi possível abrir o arquivo %s",argv[1]);
        exit(0);
    }
    while (fgets(linha, sizeof(linha), f))
    {
        printf("\n%04d  %s\n",indice, linha);
        lexico(linha, indice);
        indice++;
    }
    fclose(f);
    return 0;
}