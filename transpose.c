#include <stdio.h>
#include <stdlib.h>

void allmac(int ***mat1, int ***T, int row, int col){
    *mat1 = (int**)malloc(row*sizeof(int*));
    *T = (int**)malloc(row*sizeof(int*));
    for(int i = 0; i < row; i++){
        (*mat1)[i] = (int*)malloc(col * sizeof(int));
        (*T)[i] = (int *)malloc(col * sizeof(int));
    }
}
void freeing(int **mat1, int **T, int row){
    for(int i = 0; i < row; i++){
        free(mat1[i]);
        free(T[i]);
    }
    free(mat1);
    free(T);
}
void transpose(int **mat, int **T, int row, int col){
    int i,j;
    for(i = 0; i < row; i++){
        for(j=0; j < col; j++){
            T[j][i] = mat[i][j];
        }
    }
    //output
    for(i = 0; i < col; i++){
        for(j=0; j < row; j++){
            printf("%d",T[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int row, col;
    int **mat;
    int **T;
    int i,j;

    printf("Enter rows: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col );
//input
    allmac(&mat, &T, row,col);

    for(i = 0; i < row; i++){
        for(j=0; j < col; j++){
            printf("Enter the element %d %d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
        printf("\n");
    }

    for ( i = 0; i < row; i++)
    {
        for(j=0;j<col;j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\nAfter transpose:\n");
    
    

    transpose(mat,T,row,col);
    freeing(mat,T,row);

    return 0;
}
