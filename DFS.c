#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int matrix[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}
                };

void DFS(int i){
    printf("%d ",i);
    visited[i]=1;
    for(int j= 0; j<7; j++){
    if (matrix[i][j] == 1 && !visited[j]) {
            DFS(j);
    }
}
}

int main(){
// DFS Initialization
    int i;
    printf("Enter Start Number(0-6): ");
    scanf("%d",&i);
    DFS(i);
    return 0;
}
