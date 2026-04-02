#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int s;
    int t;
} eleitor;

int main(){
    int V = 0, C = 0;
    int i = 0, j=0;
    int temp[3];
    int *candidatos;
    eleitor *Eleitores;
    float pVencedor = 0;
    float sVencedor = 0;
    int max = 0, max2 = 0;
    
    scanf("%d %d", &V, &C);
    
    candidatos = calloc(sizeof(int), C+1);
    Eleitores = calloc(sizeof(eleitor), V);

    for (i = 0; i < V; i++)
    {
        scanf("%d %d %d", &Eleitores[i].p, &Eleitores[i].s, &Eleitores[i].t);
        
        if(Eleitores[i].p >= 1 && Eleitores[i].p<=C){
            candidatos[0]++;
            candidatos[Eleitores[i].p]++;
        }
    }

    if (candidatos[0] == 0){
        printf("0");
    } else{
        max = 1;
        for (i = 1; i < C+1; i++) {
            if ((candidatos[max]<candidatos[i])){
                max = i;
            }   
        }
            
        pVencedor = (float)candidatos[max]/(float)candidatos[0] *100;
        printf("%d %.2f", max, pVencedor);

        if (pVencedor < 50)
        {
            for ( i = 1; i <= C; i++)
            {
                if (max2 == 0)
                {
                    if (i!=max) max2 = i;
                } else if (candidatos[max2]<candidatos[i] && i!=max) max2 = i;
            }
            
            candidatos[0] = 0;
            candidatos[max] = 0;
            candidatos[max2] = 0;
            for (int i = 0; i < V; i++)
            {
                if (Eleitores[i].p == max || Eleitores[i].p == max2)
                {
                    candidatos[0]++;
                    candidatos[Eleitores[i].p]++;
                } else if(Eleitores[i].s == max || Eleitores[i].s == max2){
                    candidatos[0]++;
                    candidatos[Eleitores[i].s]++;
                } else if (Eleitores[i].t == max || Eleitores[i].t == max2)
                {
                    candidatos[0]++;
                    candidatos[Eleitores[i].t]++;
                }
            }
            
            if(candidatos[max]>candidatos[max2] || (candidatos[max]==candidatos[max2] && max < max2)){
                sVencedor = (float)candidatos[max]/(float)candidatos[0] *100;
                printf("\n%d %.2f", max, sVencedor);
            } else if (candidatos[max]<candidatos[max2] || (candidatos[max]==candidatos[max2] && max > max2)){
                sVencedor = (float)candidatos[max2]/(float)candidatos[0] *100;
                printf("\n%d %.2f", max2, sVencedor);
            }
        }
    }

    free(candidatos);
    free(Eleitores);

    return 0;
}