#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

char* checa(char* text,int v){  //Devuelve la frase/clave sin espacios
   int i=0,j=0,error=0;
char letra[]="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //valores aceptados
   for(i=0;i<strlen(text)-1;i++){      //checar si introduce caracter erroneo
        while(j<54){
    if(text[i]==letra[j])
        error++;
        j++;}
        if(error==0){
            printf("introdujiste caracter erroneo\n");
            printf("intenta de nuevo\n");
            exit(-1);
        }
        j=0;error=0;
   }
   if(v==1){
   for (i = j = 0; text[i] != '\0'; i++)
      if (text[i] != ' ')
         text[j++] = text[i];
   text[j] = '\0';
   }
    return text;
}

void vigenere(){
    int i,j=0,c=0,posc[500],vi=0,opc=0;
    unsigned int post[500],aux[500];
    char texto[500],clave[500];
    char* tex=&texto[0]; char* cla=&clave[0];
    char letras[]="abcdefghijklmnopqrstuvwxyz ";

    printf("1.-Encriptado\n2.-Desencriptado\n");
    scanf("%d",&opc);
    fflush( stdin );
    printf("ingrese frase: ");
    fgets(texto,500,stdin);
    checa(tex,vi);

            aux[i]=0;                  //para los espacios
        }
        else{
          aux[i]=posc[c];
         c++;}
        if(c==strlen(cla)-1)          //limitar valores de la clave
        c=0;j=0;
      //  printf("%d+%d\n",post[i],aux[i]); //ver la suma
    }
if(opc==1){   //Encriptado
    for(i=0;i<strlen(texto)-1;i++){        //sumar las dos cadenas
     if(post[i]+aux[i]>25){
            if(post[i]==32)
                printf(" ");
            else
                printf("%c",letras[post[i]+aux[i]-26]);//para el caso que salga del rango de a-z
     }
     else
      printf("%c",letras[post[i]+aux[i]]);}
}
else{                                //Desencriptar
     for(i=0;i<strlen(texto)-1;i++){
     if(post[i]-aux[i]>25){
            if(post[i]==32)
                printf(" ");
            else
                printf("%c",letras[post[i]-aux[i]+26]);//para el caso que salga del rango de a-z
     }
     else
      printf("%c",letras[post[i]-aux[i]]);}
}
}
