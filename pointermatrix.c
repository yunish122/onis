
#include <stdio.h>
#include <stdlib.h>

void sizeofmat(int ***mat1, int ***mat2,int ***res,int row, int col){
    int i, j;
    *mat1 = (int **)malloc(row*sizeof(int*));//5
    *mat2 = (int **)malloc(row*sizeof(int*));
    *res = (int **)malloc(row*sizeof(int *));
    // so when dereferncing we are assigning the starting memory adress of the memoery block produced by the malloc
    for(i = 0; i<row; i++){
        (*mat1)[i] = (int *)malloc(col*sizeof(int));
        (*mat2)[i] = (int *)malloc(col*sizeof(int));
        (*res)[i] = (int *)malloc(col*sizeof(int));
    }
}
void freeing(int **mat1, int **mat2, int **res, int row){
    int i;
    for(i = 0; i < row; i++){
        free(mat1[i]);
        free(mat2[i]);
        free(res[i]);

    }
    free(mat1);
    free(mat2);
    free(res);
}

void addtion(int **mat1, int **mat2, int **res, int row, int col ){
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            res[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int row, col,i,j;
    int **mat1;
    int **mat2;
    int **res;

    printf("Enter rows: ");
    scanf("%d",&row);
    printf("Enter column: ");
    scanf("%d", &col);

    sizeofmat(&mat1, &mat2, &res,row, col);
    for(i=0; i <row;i++){
        for(j=0; j<col; j++){
            printf("Enter elements:%d %d: ",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
        printf("\n");
    }
    for(i=0; i <row;i++){
        for(j=0; j<col; j++){
            printf("Enter elements: %d %d: ",i,j);
            scanf("%d",&mat2[i][j]);
        }
        printf("\n");
    }
    addtion(mat1,mat2,res,row,col);
    freeing(mat1, mat2, res, row);
    return 0;


}