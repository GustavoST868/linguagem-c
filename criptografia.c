#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void) {

  setlocale(LC_ALL,"portuguese");

  char frase[10000];
 
  char palavras[10000]={"A vida é um presente maravilhoso que recebemos ao nascer. Com ela, temos a oportunidade de explorar o mundo, de aprender, de amar e de crescer como seres humanos. Mas também enfrentamos desafios e dificuldades, que nos tornam mais fortes e resilientes.Não podemos controlar tudo o que acontece conosco, mas podemos escolher como reagir diante das situações. Podemos escolher ser positivos, ter esperança e acreditar que as coisas vão melhorar. Podemos escolher ser gratos por aquilo que temos, em vez de focar no que falta.A vida também é feita de relações humanas. Amigos, familiares, colegas de trabalho, todos fazem parte do nosso convívio social. É importante cultivar essas relações, pois elas nos trazem alegria, companheirismo e apoio nos momentos difíceis.A natureza é outro presente que recebemos. As paisagens deslumbrantes, os animais fascinantes, as plantas exuberantes, tudo isso é uma fonte de inspiração e de paz interior. Devemos cuidar da natureza e preservá-la para as futuras gerações.A vida é uma jornada, cheia de altos e baixos, mas também de muita beleza e significado. Cada um de nós tem um propósito na vida, algo que nos move e nos motiva. Descobrir esse propósito pode ser um desafio, mas é uma busca que vale a pena.Ao final da vida, o que importa é o legado que deixamos para trás. Não são as coisas materiais que contam, mas sim as memórias, os valores e as experiências que compartilhamos com as pessoas que amamos. Que possamos viver a vida com sabedoria, amor e generosidade, deixando um mundo melhor do que aquele que encontramos."};
 
  strcpy(frase,palavras);
 
  int tamanho = strlen(frase);

  //Criptografar vogais:
  for(int i=0;i<tamanho;i++){
   
  if(frase[i]=='a'){
    frase[i]='!';
  }
    if(frase[i]==' '){
    frase[i]='*';
  }

     
  if(frase[i]=='e'){
    frase[i]='@';
  }

     
  if(frase[i]=='i'){
    frase[i]='#';
  }

     
  if(frase[i]=='o'){
    frase[i]='$';
  }

     
  if(frase[i]=='u'){
    frase[i]='%';
  }
  }

  //Criptografia de consoantes

  for(int i=0;i<tamanho;i++){

    if(frase[i]=='l'){
      frase[i]='>';
    }

    if(frase[i]=='m'){
      frase[i]='<';
    }

    if(frase[i]=='n'){
      frase[i]='?';
    }

    if(frase[i]=='b'){
      frase[i]='+';
    }
    if(frase[i]=='c'){
      frase[i]='-';
    }

  }

  //Mostrar a frase criptografaga;
 
  printf("\n\n%s",frase);

  //descriptografar

  //Criptografar vogais:
  for(int i=0;i<tamanho;i++){

     if(frase[i]=='*'){
    frase[i]=' ';
  }

   
  if(frase[i]=='!'){
    frase[i]='a';
  }

     
  if(frase[i]=='@'){
    frase[i]='e';
  }

     
  if(frase[i]=='#'){
    frase[i]='i';
  }

     
  if(frase[i]=='$'){
    frase[i]='o';
  }

     
  if(frase[i]=='%'){
    frase[i]='u';
  }
  }

  //Descriptografar consoantes

  for(int i=0;i<tamanho;i++){

    if(frase[i]=='>'){
      frase[i]='l';
    }

    if(frase[i]=='<'){
      frase[i]='m';
    }

    if(frase[i]=='?'){
      frase[i]='n';
    }

    if(frase[i]=='+'){
      frase[i]='b';
    }
    if(frase[i]=='-'){
      frase[i]='c';
    }

  }
//Mostrar a frase criptografaga;
 
  printf("\n\n\n%s",frase);

 
  return 0;
}
