#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void burbuja(int *Arreglo, int lon){
	int i,j,k,Aux;

	for (i=0;i<(lon-1);i++){
		for (j=i+1;j<lon;j++){
			if(Arreglo[i] > Arreglo[j]){
				Aux=Arreglo[i];
				Arreglo[i]=Arreglo[j];
				Arreglo[j]=Aux;
			}
		}
	}	
	
	printf("\nOrdenados: \n");
	for(k=0; k<lon; k++){
		printf("%d\t",Arreglo[k]);
	}	
	printf("\n\n");

}


int main(int argc, char *argv[]) {
	bool Repetido;
	int opcPrin, opcSorteo, opcMenu, i, j,Repite,Lon=6, ValorBaloto=5000, ValorBalotoRevancha=7000,
		ContadorBaloto=0, ContadorBalotoRevancha=0, opcBaloto, TotalVentaBaloto=0, TotalVentaBalotoRe=0;
	int Numeros[6],Numeros2[6], NumerosSeries[6], NumerosSeries2[6], Resultados[6];
	FILE *Baloto, *BalotoRevancha, *Sorteo, *SorteoRevancha; /*Archivos*/
	Baloto = fopen("ventas.txt","a+");
	BalotoRevancha = fopen("ventas2.txt","a+");
	
	Sorteo = fopen("sorteo.txt","a+");
	SorteoRevancha = fopen("revancha.txt","a+");
		
	do{
		printf("MENU: \n");
		printf("1. Compra.\n");
		printf("2. Sorteo.\n");
		printf("3. Salir.\n");
		printf("Digite una opcion: \t");	
		scanf("%d",&opcPrin);
		system("cls");
		switch(opcPrin){
			case 1:{
				
				printf("MENU COMPRA: \n");
				printf("1. Automatico.\n");
				printf("2. Manual.\n");
				printf("3. Regresar al menu principal.\n");
				printf("Digite una opcion: \t");	
				
				scanf("%d",&opcMenu);
				system("cls");
				switch(opcMenu){
					case 1:{
						
						printf("\nDesea comprar el Baloto o el Baloto+Revancha?\n");
						printf("1. Baloto = $5000.\n");
						printf("2. Baloto + Revancha = $7000.\n");
						scanf("%d",&opcBaloto);
						system("cls");
						switch(opcBaloto){
						
							case 1:{
								
								ContadorBaloto++;
								system("cls");
								srand (time(NULL));
								for (i=0; i<Lon; i++) {
									Numeros[i] = rand()%45+1;
								}
								Repite = 1;
								
								/*Comprobar repeticiones*/
								while (Repite == 1) {
									Repite=0;
									for (i=0; i<Lon; i++) {
										for (j=i+1; j<Lon; j++) {
											
											if (Numeros[i] == Numeros[j] && Numeros[i] != 45) { /*Repetición*/
												printf("Hay repeticion. Cambio de %d por %d \n", Numeros[i], Numeros[i]+1);
												Numeros[i] = Numeros[i] +1;
												Repite = 1;									
											}
											if (Numeros[i] == Numeros[j] && Numeros[i] == 45) { /*Repetición*/
												Numeros[i] = Numeros[i] - rand()%44+1;
												printf("Hay repeticion de 45. Cambio de 45 por %d \n", Numeros[i]);
												Repite = 1;
											}
										}
									}
								}
								
								printf("NUMEROS: \n");
								for (i=0; i<Lon; i++) {
									printf("%d\t",Numeros[i]);
								}
								burbuja(Numeros,Lon);
								for (i=0; i<Lon; i++) {
									fprintf(Baloto,"%d ",Numeros[i]);
								}
								fclose(Baloto);
								
								printf("\n");
								system("PAUSE");
								system("cls");
							}break;
							
							case 2:{
								
								ContadorBalotoRevancha++;
								system("cls");
								srand (time(NULL));
								
								for (i=0; i<Lon; i++) {
									Numeros[i] = rand()%45+1;
								}
								for (i=0; i<Lon; i++) {
									Numeros2[i] = rand()%45+1;
								}
								
								Repite = 1;
								
								/*Comprobar repeticiones*/
								while (Repite == 1) {
									Repite=0;
									for (i=0; i<Lon; i++) {
										for (j=i+1; j<Lon; j++) {
											
											if (Numeros[i] == Numeros[j] && Numeros[i] != 45) { /*Repetición*/
												printf("Hay repeticion. Cambio de %d por %d \n", Numeros[i], Numeros[i]+1);
												Numeros[i] = Numeros[i] +1;
												Repite = 1;									
											}
											if (Numeros[i] == Numeros[j] && Numeros[i] == 45) { /*Repetición*/
												Numeros[i] = Numeros[i] - rand()%44+1;
												printf("Hay repeticion de 45. Cambio de 45 por %d \n", Numeros[i]);
												Repite = 1;
											}
										}
									}
								}
								
								Repite = 1;
								
								/*Comprobar repeticiones*/
								while (Repite == 1) {
									Repite=0;
									for (i=0; i<Lon; i++) {
										for (j=i+1; j<Lon; j++) {
											
											if (Numeros2[i] == Numeros2[j] && Numeros2[i] != 45) { /*Repetición*/
												printf("Hay repeticion. Cambio de %d por %d \n", Numeros2[i], Numeros2[i]+1);
												Numeros2[i] = Numeros2[i] +1;
												Repite = 1;									
											}
											if (Numeros2[i] == Numeros2[j] && Numeros2[i] == 45) { /*Repetición*/
												Numeros2[i] = Numeros2[i] - rand()%44+1;
												printf("Hay repeticion de 45. Cambio de 45 por %d \n", Numeros2[i]);
												Repite = 1;
											}
										}
									}
								}
								
								printf("BALOTO: \n");
								for (i=0; i<Lon; i++) {
									printf("%d\t",Numeros[i]);
								}
								burbuja(Numeros,Lon);
								for (i=0; i<Lon; i++) {
									fprintf(Baloto,"%d\t",Numeros[i]);
								}
								
								printf("REVANCHA: \n");
								for (i=0; i<Lon; i++) {
									printf("%d\t",Numeros2[i]);
								}
								burbuja(Numeros2,Lon);
								for (i=0; i<Lon; i++) {
									fprintf(BalotoRevancha,"%d\t",Numeros2[i]);
								}
								
								fclose(Baloto);
								fclose(BalotoRevancha);							
								printf("\n");
								system("PAUSE");
								system("cls");
							
							}break;
						}
												
					}break;
						
					case 2:{
					
						printf("\n  Desea comprar el Baloto o el Baloto+Revancha?\n");
						printf("1. Baloto = $5000.\n");
						printf("2. Baloto + Revancha = $7000.\n");
						scanf("%d",&opcBaloto);
						system("cls");
						switch(opcBaloto){
							case 1:{
								
								ContadorBaloto++;
								for(i=0; i<Lon; i++){ 
									Repetido = true; 
									while(Repetido){ 
										printf("Ingrese los numeros: ");
										scanf("%d",&Numeros[i]);
										fflush( stdin );
										Repetido = false; 
										
										for(j = 0; j < i; j++){ 
											if(Numeros[j] == Numeros[i]){ 
												Repetido = true; 
											} 
											if(Numeros[j] <= 0 || Numeros[j] > 45 || Repetido == true ){
												printf("ERROR: Ingreso un numero erroneo y/o repetido. Se invalida la compra.\n");
												system("PAUSE");
												system("cls");	
												return 0;		
											}
										}
									} 
								}
								
								printf("NUMEROS: \n");
								for (i=0; i<Lon; i++) {
									printf("%d\t",Numeros[i]);
								}
								burbuja(Numeros,Lon);
								for (i=0; i<Lon; i++) {
									fprintf(Baloto,"%d\t",Numeros[i]);
								}
								fclose(Baloto);
								printf("\n");	
								system("PAUSE");
								system("cls");
								system("exit");
								
							}break;
							case 2:{
								
								ContadorBalotoRevancha++;
								
								for(i=0; i<Lon; i++){ 
									Repetido = true; 
									while(Repetido){ 
										printf("Ingrese los numeros: ");
										scanf("%d",&Numeros[i]);
										fflush( stdin );
										Repetido = false; 
										
										for(j = 0; j < i; j++){ 
											if(Numeros[j] == Numeros[i]){ 
												Repetido = true; 
											} 
											if(Numeros[j] <= 0 || Numeros[j] > 45 || Repetido == true ){
												printf("ERROR: Ingreso un numero erroneo y/o repetido. Se invalida la compra.\n");
												system("PAUSE");
												system("cls");	
												return 0;		
											}
										}
									} 
								}
								
								for(i=0; i<Lon; i++){ 
									Repetido = true; 
									while(Repetido){ 
										printf("Ingrese los numeros: ");
										scanf("%d",&Numeros2[i]);
										fflush( stdin );
										Repetido = false; 
										
										for(j = 0; j < i; j++){ 
											if(Numeros2[j] == Numeros2[i]){ 
												Repetido = true; 
											} 
											if(Numeros2[j] <= 0 || Numeros2[j] > 45 || Repetido == true ){
												printf("ERROR: Ingreso un numero erroneo y/o repetido. Se invalida la compra.\n");
												system("PAUSE");
												system("cls");	
												return 0;		
											}
										}
									} 
								}
								
								printf("BALOTO: \n");
								for (i=0; i<Lon; i++) {
									printf("%d\t",Numeros[i]);
								}
								burbuja(Numeros,Lon);
								for (i=0; i<Lon; i++) {
									fprintf(Baloto,"%d\t",Numeros[i]);
								}
								
								printf("REVANCHA: \n");
								for (i=0; i<Lon; i++) {
									printf("%d\t",Numeros2[i]);
								}
								burbuja(Numeros2,Lon);
								for (i=0; i<Lon; i++) {
									fprintf(BalotoRevancha,"%d\t",Numeros2[i]);
								}								
								
								fclose(Baloto);
								fclose(BalotoRevancha);
								printf("\n");	
								system("PAUSE");
								system("cls");
								system("exit");								
								
							}break;
						}
					}break;
						
					case 3:{
						system("exit");
					}break;
				}				
			}break;
			
			case 2:{
				
				printf("MENU SORTEO: \n");
				printf("1. Nuevo sorteo.\n");
				printf("2. Resultados baloto.\n");
				printf("3. Borrar las ventas realizadas.\n");
				printf("4. Regresar al menu principal.\n");
				printf("Digite una opcion: \t");	
				
				scanf("%d",&opcSorteo);
				system("cls");
				switch(opcSorteo){
					case 1:{
						srand (time(NULL));
						for (i=0; i<Lon; i++) {
							NumerosSeries[i] = rand()%45+1;
							
						}
						for (i=0; i<Lon; i++) {
							NumerosSeries2[i] = rand()%45+1;
							
						}
						Repite = 1;
						
						/*Comprobar repeticiones*/
						while (Repite == 1) {
							Repite=0;
							for (i=0; i<Lon; i++) {
								for (j=i+1; j<Lon; j++) {
									
									if (NumerosSeries[i] == NumerosSeries[j] && NumerosSeries[i] != 45) { /*Repetición*/
										printf("Hay repeticion. Cambio de %d por %d \n", NumerosSeries[i], NumerosSeries[i]+1);
										NumerosSeries[i] = NumerosSeries[i] +1;
										Repite = 1;									
									}
									if (NumerosSeries[i] == NumerosSeries[j] && NumerosSeries[i] == 45) { /*Repetición*/
										NumerosSeries[i] = NumerosSeries[i] - rand()%44+1;
										printf("Hay repeticion de 45. Cambio de 45 por %d \n", NumerosSeries[i]);
										Repite = 1;
									}
								}
							}
						}

						Repite = 1;
						
						while (Repite == 1) {
							Repite=0;
							for (i=0; i<Lon; i++) {
								for (j=i+1; j<Lon; j++) {
									
									if (NumerosSeries2[i] == NumerosSeries2[j] && NumerosSeries2[i] != 45) { /*Repetición*/
										printf("Hay repeticion. Cambio de %d por %d \n", NumerosSeries2[i], NumerosSeries2[i]+1);
										NumerosSeries2[i] = NumerosSeries2[i] +1;
										Repite = 1;									
									}
									if (NumerosSeries2[i] == NumerosSeries2[j] && NumerosSeries2[i] == 45) { /*Repetición*/
										NumerosSeries2[i] = NumerosSeries2[i] - rand()%44+1;
										printf("Hay repeticion de 45. Cambio de 45 por %d \n", NumerosSeries2[i]);
										Repite = 1;
									}
								}
							}
						}
						
						printf("SERIE PARA BALOTO: \n");
						for (i=0; i<Lon; i++) {
							printf("%d\t",NumerosSeries[i]);
						}
						burbuja(NumerosSeries,Lon);
						for (i=0; i<Lon; i++) {
							fprintf(Sorteo,"%d\t",NumerosSeries[i]);
						}
						printf("\n\n");
						
						
						
						printf("SERIE PARA REVANCHA: \n");
						for (i=0; i<Lon; i++) {
							printf("%d\t",NumerosSeries2[i]);
						}
						burbuja(NumerosSeries2,Lon);
						for (i=0; i<Lon; i++) {
							fprintf(SorteoRevancha,"%d\t",NumerosSeries2[i]);
						}
						
						fclose(Sorteo);
						fclose(SorteoRevancha);
						printf("\n");
						system("PAUSE");
						system("cls");
					}break;
						
					case 2:{
						system("cls");
						TotalVentaBaloto = ValorBaloto*ContadorBaloto;
						TotalVentaBalotoRe= ValorBalotoRevancha*ContadorBalotoRevancha;
						
						printf("Se vendieron $%d en Baloto.\n",TotalVentaBaloto);
						printf("Se vendieron $%d en Baloto + Revancha \n",TotalVentaBalotoRe);
						printf("\n");
						
						
						Baloto = fopen("ventas.txt","r");
						BalotoRevancha = fopen("ventas2.txt","r");
						
						for (i=0; i<(ContadorBaloto*6); i++) {
							fscanf(Baloto,"%d",&Resultados[i]);
						}
						
						printf("Texto extraido: \n");
						for (i=0; i<(ContadorBaloto*6); i++) {
							printf("%d ",Resultados[i]);
						}
						
						
						fclose(Baloto);
						Sorteo = fopen("sorteo.txt","rt");
						SorteoRevancha = fopen("revancha.txt","rt");
						system("PAUSE");
						system("cls");
												
					}break;
						
					case 3:{
						
							remove("ventas.txt");
							remove("ventas2.txt");
							remove("sorteo.txt");
							remove("revancha.txt");							
							
							if((remove("sorteo.txt") && remove("ventas.txt") && remove("revancha.txt") && remove("ventas2.txt")) != 0){ /* Eliminamos el archivo*/
								printf("Los archivos fueron eliminados satisfactoriamente \n");
							}
							else{
								printf("No se pudieron eliminar los archivos \n");
							}
							printf("\n");
							system("PAUSE");
							system("cls");
							
					}break;
						
					case 4:{
						system("exit");
					}break;
				}
				
			}break;
				
			case 3:{
				return 0;
			}break;
		}
	}while(opcPrin != 3);
	
	return 0;
}

