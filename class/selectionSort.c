#include <stdio.h>

void selectionSort(int vet[1000], int n){
  int i, j, posMenor=0, aux;

  for ( i = 0; i < n-1; i++)
  {
    for ( j = i; j < n; j++)
    {
      if(vet[j] < vet[posMenor]) posMenor = j;
    }
    aux = vet[i];
    vet[i] = vet[posMenor];
    vet[posMenor] = aux;
  }
  for ( i = 0; i < n; i++)
  {
    printf("%d\n", vet[i]);
  }
}

int main(){
  int vet[1000], n, i;
  scanf("%d", &n);
  for ( i = 0; i < n; i++)
  {
    scanf("%d", &vet[i]);
  }
  selectionSort(vet, n);
  
  return 0;
}