#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float T[255],h[255],m[255],x[255],y[255],z[255],vx[255],vy[255],vz[255],dx[255][255],fx[255][255],sumx[255],dy[255][255],fy[255][255],sumy[255],dz[255][255],fz[255][255],sumz[255],sumxx[255],sumyy[255],sumzz[255];	
	#define G -1 //6.67e-11 en metros 2.67e-60 en parsecs 1.992e-44 en UA
	int i,j,k,rep,fil=0,npi=0,u;
	char nombre[20],it[255];
	FILE *o;
	printf("El programa tiene dos opciones:\n\n1.-utiliza coordenadas ya establecidas en un archivo a dar.\n2.- genera las cordenadas de distintas masas posicionadas como esferas.\n\nInserta 1-2 segun cporresponda");		
	scanf("%d",&u);
	switch(u){
	
case 1:	printf("El programa lee un archivo con nombre que se define a continuacion, el archivo tendra que estar ordenado de la forma\n t total-aumento de t-masa-posicion x-y-z-velocidad x-y-z\ninserta el nombre del archivo a abrir: ");
		scanf("%s",&nombre);
		o=fopen(nombre,"r");
  			while (fscanf(o,"%f %f %f %f %f %f %f %f %f",&T[fil],&h[fil],&m[fil],&x[fil],&y[fil],&z[fil],&vx[fil],&vy[fil],&vz[fil])!= EOF){
        		fil++;
    		}	
		fclose(o);
    	rep=T[0]/h[0];
    	for(k=0;k<rep;k++){	
    		for(i=0;i<fil;i++){
    			for(j=0;j<fil;j++){
    				dx[i][j]=x[i]-x[j];
    				dy[i][j]=y[i]-y[j];
    				dz[i][j]=z[i]-z[j];
    				if(dx[i][j]!=0||-0){
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
					printf("%f\t%f\t%f\t%f\t%f\t%f\n",dx[i][j],x[i],x[j],fx[i][j],sumxx[i]);

				}
				x[i]=x[i]+h[0]*vx[i]+(0.5)*sumx[i]*h[0]*h[0];
				y[i]=y[i]+h[0]*vy[i]+(0.5)*sumy[i]*h[0]*h[0];
				z[i]=z[i]+h[0]*vz[i]+(0.5)*sumz[i]*h[0]*h[0];
				printf("\n");
			}
			for(i=0;i<fil;i++){
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
				vx[i]=vx[i]+(0.5)*(sumx[i]+sumxx[i])*h[0];
				vy[i]=vy[i]+(0.5)*(sumy[i]+sumyy[i])*h[0];
				vz[i]=vz[i]+(0.5)*(sumz[i]+sumzz[i])*h[0];
			}
			npi++;
			sprintf(it,"%i",npi ); //convertir contador en string en cada repeticion para su uso en el nombre de cada archivo de iteracion
			printf("\n");
			strcat(it,".txt");//concatenar string para nombramiento final del archivo de la iteracion correspondiente
			o=fopen(it,"w");
				fprintf(o,"X\t Y\t Z\tVx \tVy \tVz\n");
				for(i=0;i<fil;i++){
					fprintf(o,"%f %f %f %f %f %f \n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
				}
			fclose(o);
		}
		break;

case 2:
	printf("yoyo");
	//pones lo de generar las coordenadas velocidades y das un aumento de tiempo y tiempo total determinado y cambias poquito el codigo mio(solo le modificas h[] y T[]) dejandolas como constantes ;)//
	break;

default: printf("yoyox2");
}
return 0;	
			}
