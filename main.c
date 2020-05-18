#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
float arr[100];
void knapsack(int n,float weight[],float profit[],float capacity)
{
	float X[n],tp = 0,temp;
	int i,j,u;
	u=capacity;
	for(i=0;i<n;i++)
		X[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(weight[i] <= u)
		{
			for(j = 0;j < n;j++)
			{
				if(weight[i] == arr[j])
					break;
			}
			X[j]=1.0;
			tp += profit[i];
			u -= weight[i];
		}
		else
			break;
	}
	if(i<n)
	{
		temp = (u/weight[i]);
		tp=tp+(temp*profit[i]);
	}
	printf("the result vector is::");
	for(j=0;j< n;j++)
		printf("%4.0f\t",X[j]);
	printf("\nMaximum profit is:: %4.2f\n",tp);
}
int main(int argc,char* argv[])
{
	float weight[100],profit[100],capacity,X;
	int i,j,num=0;
	float ratio[100],temp,ch;
	char c;
	FILE *in;
	in = fopen(argv[1],"r");
	if((!in)||(in == NULL))
	{
		printf("error in opening file \n");
		exit(1);
	}
	i = 0;
	while(!feof(in))
		fscanf(in,"%f",&arr[i++]);
	fclose(in);
	num = i/2;
	for(i = 0;i < num;i++)
		weight[i]= arr[i];
	j = num;
	for(i = 0;i < num;i++)
		profit[i] = arr[j++];
	for(i = 0;i < num;i++)
		ratio[i] = (profit[i])/(weight[i]);
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;

				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;

				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
		}
	}
	capacity = atoi(argv[2]);
	knapsack(num,weight,profit,capacity);
	return 0;
}
