#include <stdio.h>

int main()
{
	int n,m,i,j,k,y,alloc[20][20],max[20][20],avail[50],ind=0,h;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter the number of resources\n");
	scanf("%d",&m);
	
	printf("Enter the allocated matrix\n");
	for(i=0;i<n;i++)
		{	for(j=0;j<m;j++)
				{	
					scanf("%d",&alloc[i][j]);
				}
		}
	printf("Enter max matrix\n");
	for(i=0;i<n;i++)
		{	
			for(j=0;j<m;j++)
				{	
					scanf("%d",&max[i][j]);
				}
		}
	printf("Enter available matrix\n");
	for(i=0;i<m;i++)
		{	
			scanf("%d",&avail[i]);
		}
	int finish[n], safesequence[n],work[m],need[n][m];
	for(i=0;i<m;i++)
		{	
			work[i]=avail[i];
		}
	for(i=0;i<n;i++)
		{
			finish[i]=0;
		}
	for(i=0;i<n;i++)
		{	
			for(j=0;j<m;j++)
				{
					need[i][j]=max[i][j]-alloc[i][j];
				}
		}
	printf("Need Matrix\n");
	for(i=0;i<n;i++)
		{	printf("\n");
			for(j=0;j<m;j++)
				{	
					printf("%d\t",need[i][j]);
				}
		}
	printf("\n");
	for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				{
					if(finish[i]==0)
					{	
						int flag=0;
							for(j=0;j<m;j++)
								{
									if(need[i][j]>work[j])
										{
											flag=1;
											h=1;
											break;
											
										}
								}
						if(flag==0)
							{
								safesequence[ind++]=i;
									for(y=0;y<m;y++)
										work[y]+=alloc[i][y];
										
									finish[i]=1;
									h=0;
							}
					}
				}
		}
	if(h==0)
	{
		printf("The system is in safe state\n");
		printf("Safe sequence : \n");
		for(i=0;i<n;i++)
		printf("p%d",safesequence[i]);
	}
	else
	{
		printf("The system is unsafe");
	}
	printf("\n");
}
			
		
									
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
