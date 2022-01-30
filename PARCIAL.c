#include<stdio.h>


void funciondos (char tipo, float monto, float *ac, float *am,float *ag,int *cc, int *cm, int *cg){
    // ac acumulador de C, am acumulador M; ag acumulador G
    // cc contador c , cm contador de M , cg contador de G
    if(tipo == 'C' || tipo == 'c' ){
    *ac += monto;
    (*cc)++;
   }
   if(tipo == 'M' || tipo == 'm'){
    *am += monto;
    (*cm)++;
   }
   if(tipo == 'G' || tipo == 'g'){
    *ag += monto;
    (*cg)++;
   }

   return;
}



void funcionuno ( int*cantventas, float*max   ,char *maxclase ,float *totventas){
int empresas,p, acumventas,cc,cm,cg,nventas;
char tipo;
float ag, am,ac, monto, totc, totg, totm;

//x cantidad de concesionarias , i=concesionarias

printf("ingrese la cantidad de concesionarias\n");
scanf("%d",&p);
fflush(stdin);

for(empresas=1; empresas<=p ;empresas++){

ag=0;
am=0;
ac=0;
cc=0;
cm=0;
cg=0;

do{

printf("ingrese el numero de venta: \n");
  scanf("%d",&nventas);
  fflush(stdin);
  }while(nventas<0);


  while(nventas != 0){
   (*cantventas)++;
	 printf("ingrese el tipo de vehiculo\n");
	 scanf("%c", &tipo);
	 fflush(stdin);

    printf("ingrese el monto de la venta\n");
    scanf ("%f", &monto);
    fflush(stdin);

funciondos(tipo, monto,&ac, &am,&ag,&cc,&cm,&cg);

*totventas += monto;


  do{
     printf("ingrese el numero de venta: \n");
     scanf("%d",&nventas);
     fflush(stdin);
  }while(nventas<0);

} // fuera del while

 printf("concesionaria %d:\n", empresas);
 printf("C:%.4f  , %d  Total de ventas\n",ac,cc);
 printf("M:%.4f  , %d  Total de ventas\n",am,cm);
 printf("G:%.4f  , %d  Total de ventas\n",ag,cg);


totc +=ac;
totm +=am;
totg +=ag;


} // fuera del for

  if (totc>*max){
      *max= totc;
      *maxclase ='C';
}
   if (totm>*max){
    *max= totm;
    *maxclase ='M';
}
  if (totg>*max){
    *max= totg;
    *maxclase ='G';
}

return;
}


int main (){

int cantventas=0;
float max=0,totventas=0,nventas=0;
char maxclase;


funcionuno(&cantventas, &max ,  &maxclase, &totventas);

printf ("El total de ventas es de : %d\n", cantventas);
printf ("El tipo que facturo es %c con un total de %.2f\n",maxclase,max);
printf ("El total facturado es: %.2f\n", totventas);


return 0;
}
