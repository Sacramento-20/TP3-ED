// #include "ArvoreAVL.hpp"
// #include "variaveis.hpp"

// #include <getopt.h>
// #include <fstream>
// #include <string.h>
// #include <cstring>

// ifstream Arquivo_entrada; 
// ofstream Arquivo_saida;

// char Estrutura[4];

// void parse_args(int argc,char ** argv)
// // Descricao: le as opcoes da linha de comando e inicializa variaveis
// // Entrada: argc e argv
// // Saida: optescolhida, optx, opty, regmem, lognome
// {
//   // variaveis externas do getopt
//   extern char * optarg;
//   // extern int optind;

//   // variavel auxiliar
//   int c;
//   // smtc:

//   while ((c = getopt(argc, argv, "i:o:t:")) != EOF)
//       switch(c) {
//         case 'i':
//           Arquivo_entrada.open(optarg);
//           break;

//         case 'o':
//           Arquivo_saida.open(optarg, ios::app);
//           break;

//         case 't':
//           strcpy(Estrutura,optarg);
//           break;
        
//         default:
//         exit(1);
//     }
// }

// int main(int argc, char *argv[]){

//   parse_args(argc,argv);

//   Arquivo_saida << Estrutura << endl;

//   Arquivo_entrada.close();
//   Arquivo_saida.close();
// }
