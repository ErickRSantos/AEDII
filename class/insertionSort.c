#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vet, int n){
  int i,j, x;
  for (i = 2; i <= n; i++)
  {
    x = vet[i];
    j = i-1;
    vet[0] = x;
    while (x<vet[j]){
      vet[j+1] = vet[j];
      j--;
    }
    vet[j+1] = x;    
  }
}

int main(){
  int *vet, n, i;
  scanf("%d", &n);
  vet = malloc(sizeof(int)*(n+1)); 
  vet[0] = 0;
  for (i = 1; i <n+1; i++)
  {
    scanf("%d", vet+i);
  }
  printf("Original: ");
  for (i = 1; i < n+1; i++)
  {
    printf("%d ", *(vet+i));
  }
  printf("\n");
  insertionSort(vet, n);
  printf("Ordenado: ");
  for (i = 1; i < n+1; i++)
  {
    printf("%d ", *(vet+i));
  }
  printf("\nFIM");
  free(vet);
  return 0;
}