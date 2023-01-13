#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(int recebe[], int num, int N_registros){
  for(int i = 0; i < (N_registros); i++){
    if(recebe[i] == num){
        return i;
    }
  }
  return 100;
}

void Tempo(char letra[], int tempo[], int num, int N_registros){
  for(int i = 0; i < (N_registros); i++){
    if(letra[i] == 'R')
      tempo[i] = tempo[i] + num;
  }
}

void main(){
  char *caractere;
  int aux1, aux2;
  int qtd_oficial = 0;
  int pos = 0;
  char carac, aux3;
  char enter;
  int vf, carac_tempo = 1;
  int N_registros, num = 0;
  scanf("%d", &N_registros);

  int *tempo = (int*) calloc((N_registros), sizeof(int));
  int *recebe = (int*) calloc((N_registros), sizeof(int));
  char *letra = (char*) malloc(N_registros * sizeof(char));

  //if(letra == NULL){
    //printf("memoria insuficiente()");
    //exit(1);
  //}

  for(int i = 0; i < N_registros; i++){
    enter = getchar();
    carac = getchar();
    scanf("%d", &num);
    caractere = &carac;
    //printf("%c %d\n", carac, num);
    //verifico se ele ja está na lista recebe
    vf = verifica(recebe, num, N_registros);
    //e em qual posição
    if(*caractere == 'R' || *caractere == 'E'){
      if(vf == 100){
        if(carac_tempo == 0){
          Tempo(letra, tempo, 1, N_registros);
        }
        recebe[pos] = num;
        letra[pos] = *caractere;
        pos++;
      }
      else{
        if(carac_tempo == 0){
          Tempo(letra, tempo, 1, N_registros);
        }
        //if(i == N_registros - 1)
          //Tempo(letra, tempo, 1, N_registros);
        //recebe[vf] = num;
        letra[vf] = *caractere;
      }
      carac_tempo = 0;
    }
    else if(*caractere == 'T'){
      carac_tempo = 1;
      Tempo(letra, tempo, num, N_registros);
    }


  }
  //loop para ordenar crescentemente
  int i = 0;
  while(1){
    if(tempo[i + 1] == 0 || recebe[i + 1] == 0){
      break;
    }
    else if(recebe[i] > recebe[i + 1]){
      aux1 = recebe[i + 1];
      aux2 = tempo[i + 1];
      aux3 = letra[i + 1];
      recebe[i + 1] =  recebe[i];
      tempo[i + 1] = tempo[i];
      letra[i + 1] = letra[i];
      recebe[i] = aux1;
      tempo[i] = aux2;
      letra[i] = aux3;
    }
    i++;
  }
  //loop para ver quantidade exata de registros contabilizados
  for(int i = 0; i <= N_registros; i++){
    if(tempo[i] == 0)
      break;
    else if(letra[i] == 'R'){
        printf("%d %d\n", recebe[i], -1);
        continue;
    }
    printf("%d %d\n", recebe[i], tempo[i]);
  }
}
