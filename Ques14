#include<stdio.h>
#define MAX 10
void readSparse(int b[][3])
{
    int i;
    printf("Enter size of the matrix:\n");
    scanf("%d%d",&b[0][0],&b[0][1]);
    printf("Enter no. of non-zero elements:\n");
    scanf("%d",&b[0][2]);
    for(i = 1; i <= b[0][2]; i++)
    {   printf("Enter triplet (row, column, value) :\n");
        scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
    }
}
 
void printSparse(int b[][3])
{
    int i,j,k = 1;
    printf("\nThe matrix is...\n");
    for(i = 0; i < b[0][0]; i++)
    {   for(j = 0; j < b[0][1]; j++)
        { if(b[k][0] == i && b[k][1] == j)
          {   printf("%d ", b[k][2]);
              k++;
          }
          else
              printf("0 ");
        }
        printf("\n");
    }
}
 
void transpose(int a[][3], int b[][3])
{
    int i,j,k=1;
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    if(b[0][2] > 0)
    {    for(i=0;i<a[0][1];i++)
         {    for(j=1;j<=a[0][2];j++)
              {    if(a[j][1]==i)
                   {    b[k][0] = a[j][1];
                        b[k][1] = a[j][0];
                        b[k][2] = a[j][2];
                        k++;
                   }
              }
         }
    }
}
 
int add(int sp1[][3], int sp2[][3], int sp3[][3])
{   int k1, k2, k3, tot1, tot2;
    if(sp1[0][0] == sp2[0][0] && sp1[0][1] == sp2[0][1])
    {    tot1 = sp1[0][2]; tot2 = sp2[0][2];
         k1 = k2 = k3 = 1;
         while ( k1 <= tot1 && k2 <= tot2)
         {    if ( sp1[k1][0] < sp2[k2][0] )
              {    sp3[k3][0] = sp1[k1][0];
                   sp3[k3][1] = sp1[k1][1];
                   sp3[k3][2] = sp1[k1][2];
                   k3++; k1++;
              }
              else if ( sp1[k1][0] > sp2[k2][0] )
              {    sp3[k3][0] = sp2[k2][0];
                   sp3[k3][1] = sp2[k2][1];
                   sp3[k3][2] = sp2[k2][2];
                   k3++; k2++;
              }
              else
              {    if ( sp1[k1][1] < sp2[k2][1] )
                   {    sp3[k3][0] = sp1[k1][0];
                        sp3[k3][1] = sp1[k1][1];
                        sp3[k3][2] = sp1[k1][2];
                        k3++; k1++;
                   }
                   else if ( sp1[k1][1] > sp2[k2][1] )
                   {    sp3[k3][0] = sp2[k2][0];
                        sp3[k3][1] = sp2[k2][1];
                        sp3[k3][2] = sp2[k2][2];
                        k3++; k2++;
                   }
                   else
                   {    sp3[k3][0] = sp2[k2][0];
                        sp3[k3][1] = sp2[k2][1];
                        sp3[k3][2] = sp1[k1][2] + sp2[k2][2];
                        k3++; k2++; k1++;
                   }
              }
         }
         while ( k1 <=tot1 )
         {    sp3[k3][0] = sp1[k1][0];
              sp3[k3][1] = sp1[k1][1];
              sp3[k3][2] = sp1[k1][2];
              k3++; k1++;
         }
         while ( k2 <= tot2 )
         {    sp3[k3][0] = sp2[k2][0];
              sp3[k3][1] = sp2[k2][1];
              sp3[k3][2] = sp2[k2][2];
              k3++; k2++;
         }
         sp3[0][0] = sp1[0][0];
         sp3[0][1] = sp1[0][1];
         sp3[0][2] = k3-1;
    }
    else
         printf("\nInvalid Dimensions.\n");
}
 
void multiply(int sp1[][3], int sp2[][3], int sp3[][3])
{
    int k1,k2,k3,i,mat1RNo,mat2CNo,sum,tot1,tot2;
 
    int sp2Transpose[MAX][3];
    tot1=sp1[0][2];tot2=sp2[0][2];
 
    if(sp1[0][1] == sp2[0][0])
    {
        transpose(sp2,sp2Transpose);
        k1 = k3 = 1;
        while(k1 <= tot1)
        {
            i = k1;
            k2 = 1;
            while(k2 <= tot2)
            {
                mat1RNo = sp1[k1][0];
                mat2CNo = sp2Transpose[k2][0];
                sum = 0;
                while(k1 <= tot1 && k2 <= tot2 && mat1RNo == sp1[k1][0] && mat2CNo == sp2Transpose[k2][0])
                {   if(sp1[k1][1] == sp2Transpose[k2][1])
                    {    sum = sum + sp1[k1][2] * sp2Transpose[k2][2];
                         k1++; k2++;
                    }
                    else if(sp1[k1][1] < sp2Transpose[k2][1])
                         k1++;
                    else
                         k2++;
                }
                if(sum != 0)
                {   sp3[k3][0] = mat1RNo;
                    sp3[k3][1] = mat2CNo;
                    sp3[k3][2] = sum;
                    k3++;
                }
                if(k2 <= tot2)
                    k1 = i;
                while(mat2CNo == sp2Transpose[k2][0] && k2 <= tot2)
                    k2++;
            }
            while(mat1RNo == sp1[k1][0] && k1 <= tot1)
                k1++;
        }
        sp3[0][0] = sp1[0][0];
        sp3[0][1] = sp2Transpose[0][0];
        sp3[0][2] = k3-1;
    }
}
 
int main()
{
  int a[MAX][3], b[MAX][3], c[MAX][3];
  readSparse(a);
  printSparse(a);
  readSparse(b);
  printSparse(b);
  multiply(a,b,c);
  printSparse(c);
  return 0;
}
