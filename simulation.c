#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()

{

int i;//counter
int n;//number por stars
double position[n][n][n];//arrange for spherical coordinates
float h;
float t_evol;

printf("introduce the number of elements\n");
scanf("%i",&n);
int a=n;
int b=n;
printf("introduce the evolution time\n");
scanf("%f",&t_evol);


double delta_temp=t_evol/h;




for(i=0;i<n;i++)
	{
	/*for(int j=0;j<a;j++)
		{
		for(int k=0;k<b;k++)
			{*/
			position[i][i][i]=0;/*initialization to zero*/
		//	}
	//	}
	}
int j;
int k;

for(i=0;i<n;i++)
	{
	position[i][j][k]=40;
	printf("%lf %lf %lf\n",position[i][j][k]);/*first column of the arrangement is set to be the radius, second element angle and third the azimuth angle*/
	}
	
return 0;


}
