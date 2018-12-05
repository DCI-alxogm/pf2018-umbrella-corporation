#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float T[255],h[255],m[255],x[255],y[255],z[255],vx[255],vy[255],vz[255],dx[255][255],fx[255][255],sumx[255],dy[255][255],fy[255][255],sumy[255],dz[255][255],fz[255][255],sumz[255];	
	#define G 6.67
	int i,j,k,fil=0;
	char nombre[20],lin;
	FILE *o;		
	printf("El programa lee un archivo con nombre que se define a continuacion, el archivo tendra que estar ordenado de la forma\n t total-aumento de t-masa-posicion x-y-z-velocidad x-y-z\ninserta el nombre del archivo a abrir: ");
	scanf("%s",&nombre);
	o=fopen(nombre,"r");
  		while (fscanf(o,"%f %f %f %f %f %f %f %f %f",&T[fil],&h[fil],&m[fil],&x[fil],&y[fil],&z[fil],&vx[fil],&vy[fil],&vz[fil])!= EOF){
        	fil++;
    	}	
	fclose(o);
    printf("%d\n",fil);
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
   			if(dz[i][j]!=0){
				fz[i][j]=G*m[i]*m[j]/(dz[i][j]*dz[i][j]);
    			sumz[i]+=fz[i][j];
			}
    		printf("%f\t %f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",dx[i][j],fx[i][j],sumx[i],dy[i][j],fy[i][j],sumy[i],dz[i][j],fz[i][j],sumz[i]);
		}
		printf("\n");
	}
	
	return 0;
}
