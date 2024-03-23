#include <stdio.h>
#include <stdlib.h>

void print_field(int **,int,int);
int random_number(int,int);
void mine_randomizer(int **,int,int,int);
void mines_nearby(int **,int,int,int,int);
void pfield_file(int **,int,int,int,FILE *);

int main(int argc , char **argv)
{
    int x,y,k,i;
	int **field;
	FILE *fp;
	
	srand(time(NULL));
	
	
	printf("\n   _*MINESWEEPER*_");
	printf("\n_______________________________________________________________");
	printf("\n\nInsert number of rows: ");
	scanf("%d",&x);
	printf("\n_______________________________________________________________");
	printf("\n\nInsert number of columns: ");
	scanf("%d",&y);
	printf("\n_______________________________________________________________");
	printf("\n\nInsert number of mines: ");
	scanf("%d",&k);
	printf("\n_______________________________________________________________\n\n");
	
	
   field=(int **)calloc(x,sizeof(int *));
	    for(i=0;i<x;i++)
	      *(field+i)=(int *)calloc(y,sizeof(int));
	       
   mine_randomizer(field,x,y,k);
   print_field(field,x,y);
   
   
   
   
   fp=fopen("output.txt","w");
   
   if(fp==NULL)
	{
		printf("\nError!File did not open.");
		exit(1);
    }
    
    pfield_file(field,x*y,x,y,fp);
    
    fclose(fp);
   
   for(i=0;i<x;i++)
       free(field[i]);
       
   free(field);
   
   return 0;
}

void print_field(int **mat,int l,int c)
{
	int i,j;
	
	for(i=0;i<l;i++)
       {
	        for(j=0;j<c;j++)
	        {
	            if(mat[i][j]==-1)
	            printf("|_*_|");
	            else
	            {
	                mines_nearby(mat,i,j,l,c);
	                printf("|_%d_|",mat[i][j]);
	            }
            }
            printf("\n");
       }
	       	
}

int random_number(int A,int B)
{   
    int i;
	return rand()%(B-A+1)+A;	
}

void mine_randomizer(int **field,int l,int c,int k)
{
	int *mat1,*mat2;
	int i;
	
	
	mat1=(int *)malloc(k*sizeof(int));
	mat2=(int *)malloc(k*sizeof(int));
	
	for(i=0;i<k;i++)
		mat1[i]=random_number(0,l-1);
	for(i=0;i<k;i++)
		mat2[i]=random_number(0,c-1);
		
	for(i=0;i<k;i++)
	    {
		    if(field[mat1[i]][mat2[i]]==-1)
		       {
			   while(field[mat1[i]][mat2[i]]==-1)
		            {
		                mat1[i]=random_number(0,l-1);
		                mat2[i]=random_number(0,c-1);
		            }
		       field[mat1[i]][mat2[i]]=-1;
			   }
		    else 
		       field[mat1[i]][mat2[i]]=-1;
		      
	    }
	free(mat1);	
	free(mat2);	
}

void mines_nearby(int **field,int i,int j,int l,int c)
{
	int counter=0;
    
    for(int x = i - 1; x <= i + 1; x++)
	{
        for(int y = j - 1; y <= j + 1; y++)
		{
            if(x >= 0 && x < l && y >= 0 && y < c && !(x == i && y == j)) 
			{
                if(field[x][y] == -1)
				{
                    counter++;
                }
            }
        }
    }
	            
	            
	field[i][j]=counter;
            	
}


void pfield_file(int **M,int S,int l,int c,FILE *fp)
{

	int i,j;
	
	for(i=0;i<l;i++)
       {
	        for(j=0;j<c;j++)
	        {
	            if(M[i][j]==-1)
	            fprintf(fp,"|_*_|");
	            else
	            {
	                fprintf(fp,"|_%d_|",M[i][j]);
	            }
            }
            fprintf(fp,"\n");
       }
	       	
}

















