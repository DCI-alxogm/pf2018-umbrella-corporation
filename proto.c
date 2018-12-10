#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	float T[255],h[255],m[255],x[255],y[255],z[255],vx[255],vy[255],vz[255],dx[255][255],fx[255][255],sumx[255],dy[255][255],fy[255][255],sumy[255],dz[255][255],fz[255][255],sumz[255],sumxx[255],sumyy[255],sumzz[255];	
	#define G -1 //, usa la que se adapte a las coordenadas que vas a hacer en tu parte pero la meastra dijo que en mega parsecs asi que quedaria de 4300, la formula tiene un negativo asi que creo le debes poner - a la G aqui para que no haya problemas
	int i,j,k,rep,fil=0,npi=0;
	char nombre[20],it[255];
	FILE *o;
		printf("El programa lee un archivo con nombre que se define a continuacion, el archivo tendra que estar ordenado de la forma\n t total-aumento de t-masa-posicion x-y-z-velocidad x-y-z\ninserta el nombre del archivo a abrir: ");
		scanf("%s",&nombre);//escanear variable segun el archivo que tenga el usuario, solo correrar adecuadamente si esta bien organizado y hay columnas exclusivas tambien pata tiempo total aumento de tiempo y masa
		o=fopen(nombre,"r"); //abrir archivo que indique el usuario 
  			while (fscanf(o,"%f %f %f %f %f %f %f %f %f",&T[fil],&h[fil],&m[fil],&x[fil],&y[fil],&z[fil],&vx[fil],&vy[fil],&vz[fil])!= EOF){ //escanear variables hasta que no detecte mas filas
        		fil++;//contar numero de filas
    		}	
		fclose(o);
    	rep=T[0]/h[0];//hacer calculo de cuantas repeticiones se haran con el tiempo total dividido entre el aumento
    	for(k=0;k<rep;k++){	 //for para hacer las repeticiones
    		for(i=0;i<fil;i++){//primer for para posicionarse solo en una coordenada
    			for(j=0;j<fil;j++){//segundo for para moverse entre las coordenadas y compararla con la [i] del for anterior
    				dx[i][j]=x[i]-x[j];//calcular distancia x entre la posicion[i] con las demás[j]
    				dy[i][j]=y[i]-y[j];
    				dz[i][j]=z[i]-z[j];
    				if(dx[i][j]!=0||-0){//si la distancia x es diferente de 0 o -0 calcular fuerza e irla sumando para la fuerza neta que sentira la particula
						fx[i][j]=G*m[i]*m[j]/(dx[i][j]*dx[i][j]);
    					sumx[i]+=fx[i][j];
					}
   					if(dy[i][j]!=0||-0){
						fy[i][j]=G*m[i]*m[j]/(dy[i][j]*dy[i][j]);
    					sumy[i]+=fy[i][j];
					}
   					if(dz[i][j]!=0||-0){
						fz[i][j]=G*m[i]*m[j]/(dz[i][j]*dz[i][j]);
    					sumz[i]+=fz[i][j];
					}

				}
				x[i]=x[i]+h[0]*vx[i]+(0.5)*sumx[i]*h[0]*h[0];//calcular las nuevas posiciones en x, se usa solo h[0] ya que sera el mismo valor
				y[i]=y[i]+h[0]*vy[i]+(0.5)*sumy[i]*h[0]*h[0];
				z[i]=z[i]+h[0]*vz[i]+(0.5)*sumz[i]*h[0]*h[0];
			}
			for(i=0;i<fil;i++){//es lo mismo de arriba simplemente se calcula una nueva fuerza neta de cada particula con las posiciones nuevas para usarse en el calculo de la nueva velocidad
    			for(j=0;j<fil;j++){
    				dx[i][j]=x[i]-x[j];
    				dy[i][j]=y[i]-y[j];
  		  			dz[i][j]=z[i]-z[j];
    				if(dx[i][j]!=0||-0){
						fx[i][j]=G*m[i]*m[j]/(dx[i][j]*dx[i][j]);
    					sumxx[i]+=fx[i][j];
					}
   					if(dy[i][j]!=0||-0){
						fy[i][j]=G*m[i]*m[j]/(dy[i][j]*dy[i][j]);
    					sumyy[i]+=fy[i][j];
					}
   					if(dz[i][j]!=0||-0){
						fz[i][j]=G*m[i]*m[j]/(dz[i][j]*dz[i][j]);
    					sumzz[i]+=fz[i][j];
					}	
				}
				vx[i]=vx[i]+(0.5)*(sumx[i]+sumxx[i])*h[0];//calculo de la nueva velocidad en x
				vy[i]=vy[i]+(0.5)*(sumy[i]+sumyy[i])*h[0];
				vz[i]=vz[i]+(0.5)*(sumz[i]+sumzz[i])*h[0];
			}
			npi++;
			sprintf(it,"%i",npi ); //convertir contador en string en cada repeticion para su uso en el nombre de cada archivo de iteracion
			strcat(it,".txt");//concatenar string para nombramiento final del archivo de la iteracion correspondiente
			o=fopen(it,"w");
				for(i=0;i<fil;i++){//for para imprimir en el archivo cada dato nuevo de posiciones y velocidades correspondientes a cada particula
					fprintf(o,"%f %f %f %f %f %f \n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
				}
			fclose(o);
		}

return 0;	
			}
