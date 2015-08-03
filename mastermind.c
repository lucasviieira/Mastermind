#include<stdio.h>

int sequencia[5];
//int sequenciaUsuario[5] = {9,9,9,9,9};
int sequenciaResposta[5] = {9,9,9,9,9};
int contGeral = 0;
int tentativas = 0;

void geraSequencia();
void geraSequenciaResposta(int *sequencia);
void traduzSequencia(int valor);
void embaralhaSequencia();
void pedeUsuario();

void geraSequencia(){

// 0 = preto, 1 = branco, 2 = azul, 3 = amarelo, 4 = verde e 5 = vermelho.

int i = 0;
// randomiza uma sequencia de 5 cores que podem se repetir
    for(i = 0; i < 5; i++){
        sequencia[i] = rand() % 6;
        printf("%d ", sequencia[i]);
    }


}

void geraSequenciaResposta(int *sequenciaUsuario){

int i = 0;
int j = 0;
// verifica a cor digitada pelo usuario e compara com a da resposta correta
// 6 = Laranja e 7 == Marrom e 9 = nada
sequenciaResposta[0] = 9;
sequenciaResposta[1] = 9;
sequenciaResposta[2] = 9;
sequenciaResposta[3] = 9;
sequenciaResposta[4] = 9;

    for(i = 0; i < 5; i ++){
        for(j = 0; j < 5; j++){
            if(sequencia[i] == sequenciaUsuario[j]){
                if(i == j){
                    sequenciaResposta[i] = 6;
                    //printf("\nLaranja");
                    j = 5;
                }
                else{
                    sequenciaResposta[i] = 7;
                    //printf("\nMarrom");
                }
            }
        }
    }
}

void traduzSequencia(int valor){

// pega o numero da posicao e diz qual eh a cor correspondente
    switch(valor){
        case 0:
            printf("Preto ");
        break;

        case 1:
            printf("Branco ");
        break;

        case 2:
            printf("Azul ");
        break;

        case 3:
            printf("Amarelo ");
        break;

        case 4:
            printf("Verde ");
        break;

        case 5:
            printf("Vermelho ");
        break;

        case 6:
            printf("Laranja ");
        break;

        case 7:
            printf("Marrom ");
        break;

        default:
            printf("ERROU ");
    }
}

void embaralhaSequencia(){

int i = 0;
int contL = 0;
int contM = 0;
// embaralha a sequencia, colocando os lanrajas no começo, os marrons no meio e os vazios no final
contGeral = 0;
    for(i = 0; i < 5; i++){
        if(sequenciaResposta[i] == 6){
            contL++;
        }
        else if(sequenciaResposta[i] == 7){
            contM++;
        }
    }

    for(i =0; i < 5; i++){
        if(contL != 0){
            sequenciaResposta[i] = 6;
            contL--;
            contGeral++;
        }

        else if(contM != 0){
            sequenciaResposta[i] = 7;
            contM--;
        }
        else{
            sequenciaResposta[i] = 9;
        }
    }
}

void pedeUsuario(){

int i = 0;
int sequenciaUsuario[5];

    for(i = 0; i < 5; i++){
        printf("\nDigite a cor %d\n", i+1);
        scanf("%d", &sequenciaUsuario[i]);
    }

    geraSequenciaResposta(sequenciaUsuario);

    system("cls");

    printf("\nEsta eh a sequencia digitada:\n");
    for(i = 0; i < 5; i ++){
        traduzSequencia(sequenciaUsuario[i]);
    }

    //printf("\n");
    //for(i = 0; i < 5; i ++){
    //    traduzSequencia(sequenciaResposta[i]);
    //}

    printf("\n\nEsta eh a dica da sequencia correta:\n");
    embaralhaSequencia();
    for(i = 0; i < 5; i ++){
        traduzSequencia(sequenciaResposta[i]);
    }

    printf("\n\n");
    system("pause");
}

int main(){

int i = 0;

    srand(time(NULL));
    geraSequencia();
    pedeUsuario();
    tentativas++;

    while(tentativas < 12){

        if(contGeral == 5){
            system("cls");
            printf("\nParabens, voce venceu!!!!!!!!!!\n");
            system("pause");
            exit(0);
        }
        else{
            system("cls");
            tentativas++;
            pedeUsuario();
        }
    }
    system("cls");
    printf("\nVoce chegou no maximo de tentativas\n");
    printf("\nA sequencia correta era:\n\n");
    printf("\n\n");

    for(i = 0; i < 5; i++){
        traduzSequencia(sequencia[i]);
    }

    return 0;
}
