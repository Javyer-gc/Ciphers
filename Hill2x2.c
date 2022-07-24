#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int euclides(int dete){      //calcular el mcd
int mayor=0,i=1;
int r[100]={dete,26},q[100]={0},x[100]={1,0},y[100]={0,1};
while(r[i]!=0){
   q[i]=r[i-1]/r[i];
   r[i+1]=r[i-1]%r[i];
   x[i+1]=x[i-1]-(q[i]*x[i]);
   y[i+1]=y[i-1]-(q[i]*y[i]);
    i++;
   if(x[i-1]>y[i-1])
    mayor=x[i-1];
   else
    mayor=y[i-1];
}
//printf("\nmcd:%d  cofb:%d  cofm:%d",r[i-1],x[i-1],y[i-1]);// ver el mcd
if(r[i-1]!=1){
      printf("\n No tiene inversa el mcd\nintenta con otra clave");
      exit(-1);
}
return mayor;
}

void Hill(){
int i=0,j=0,tam=0,opc=0;
char letras[]="abcdefghijklmnopqrstuvwxyz ";
char texto[500];char *tex=&texto[0];
int post[500];
int *pos=&post[0];
int ceros[500]; int* cer=&ceros[0];
printf("1.-Encriptado\n2.-Desencriptado\n");
scanf("%d",&opc);

printf("Ingrese frase: ");
fflush(stdin);
fgets(texto,500,stdin);

       for (int i=0;tex[i]!='\0';++i){   //Pasar a minusculas
		tex[i]=tolower(tex[i]);}

    for(i=0;i<strlen(tex)+1;i++){            //Dar posicion de letras a texto
      while(j<27){
        if(tex[i]==letras[j])
        post[i]=j;
        j++;
       }
       j=0;

if(tex[i]=='\0'){   //poner 0 despues del fin de la cadena
        post[i-1]=0;
    post[i]=0;
    post[i+1]=0;
    post[i+2]=0;
    post[i+3]=0;
    }
    }

    for(i=0;i<strlen(tex)+4;i++){ //almacenar espacios
       ceros[i]=post[i];
    }

  for (i = j = 0; i < strlen(tex)-1 ; i++)   //quitar espacios
      if (post[i] != 26)
         post[j++] = post[i];

j=0;
while(j!=strlen(tex)-1){  //tamaño del texto sin espacios
        if(texto[j]!=32){
          tam++;
        }
       j++;
}
    cifrado(pos,tex,cer,tam,opc);
    }
//***************************************************************
void cifrado(int* post, char*texto, int* ceros,int tama,int opci){
int c=0,k=0,i=0,j=0;
int clave[500],aux[500];
char posc[4];
char letra[]="abcdefghijklmnopqrstuvwxyz ";
int det=0;int inv[500];int auxi[500];

      //introducir clave
while(det==0){   //checar que la clave sea valida
      printf("Ingrese clave de 4 digitos(letras): ");
        fflush(stdin);
        fgets(posc,500,stdin);

       for(i=0;i<4;i++){            //Dar posicion de letras a texto
      while(j<27){
        if(posc[i]==letra[j])
        clave[i]=j;
        j++;
       }
       j=0;
    }
  printf("clave:\n");           //imprimir clave
      for(i=0;i<4;i++){
            if(c!=2)                   //para que se vea bonito
             printf("%d ",clave[i]);
            else
             printf("\n%d ",clave[i]);
             c++;
    }
     det=clave[0]*clave[3]-(clave[1]*clave[2]);   //sacar el determinante
     if(det==0)printf("Error esta clave no tiene inversa\n");
    }

//printf("\n determinante: %d\n",det);
    c=0;

    if(opci==1){
  for(i=0;i<tama;i++){      //Realizar multiplicacion clave*texto
        aux[i]=clave[c+j]*post[k]+clave[c+1+j]*post[k+1];
   //  printf("%d * %d + %d * %d= %d \n",clave[c+j],post[k],clave[c+1+j],post[k+1],aux[i]); //ver operaciones
        j=c+1;
        c++;
        if(j==2 || c==2){
            j=0;
            c=0;
            k=k+2;
            }
        }
        c=0;
           for(i=0;i<tama;i++){   //modulo 26 texto cifrado
        if(aux[i]>26)
            aux[i]=aux[i]%26;
        }

        printf("\nCifrado: ");
    for(i=0;i<strlen(texto)-1;i++){      //imprimir cifrado hill
       if(ceros[i]==26){
        printf(" ");
       }
       else
       {
           printf("%c",letra[aux[c]]);
           c++;
       }
        }
    }
    else{
    //*************** sacar inversa********
        det=euclides(det);   //checar que es valida la clave si mcd=1
   inv[0]=clave[3];    //transpuesta
   inv[1]=-1*clave[1];
   inv[2]=-1*clave[2];
   inv[3]=clave[0];
printf("\n");

for(i=0;i<4;i++){          //pasar a mod 26 la transpuesta
    if(inv[i]<0)
        inv[i]=inv[i]+26;
}

 for(i=0;i<4;i++){        //transpuesta*det euclides
        inv[i]=(inv[i]*det)%26;
 }

 j=0;
 k=0;
 c=0;
printf("\n");
   for(i=0;i<tama;i++){      //Realizar multiplicacion inversa*aux(encriptado)
        auxi[i]=inv[c+j]*post[k]+inv[c+1+j]*post[k+1];  //cambiar por aux si es sin if
   // printf("%d * %d + %d * %d= %d \n",inv[c+j],post[k],inv[c+1+j],post[k+1],auxi[i]); //ver operaciones
        j=c+1;
        c++;
        if(j==2 || c==2){
            j=0;
            c=0;
            k=k+2;
            }
        }
 c=0;
         printf("Desencriptado: ");
        for(i=0;i<strlen(texto)-1;i++){      //imprimir desencriptado
       if(ceros[i]==26){
        printf(" ");
       }
       else
       {
           printf("%c",letra[auxi[c]%26]);
           c++;
       }
        }
    }
}
