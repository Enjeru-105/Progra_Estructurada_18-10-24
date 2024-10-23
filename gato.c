#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf

void tablero(char xo[][3]);
int coords(int *jug, char xo2[][3]);
int ganador(char xo3[][3]);

int main(){
    char juego[3][3]= {{'\0'}};
    int i,j;
    int contador=0;
    int jugador=1;
    int win=0;
    do{
        contador=0;
        p("****JUEGO DEL GATO****\n\n");
        tablero(juego);
        p("\ny=Filas , x=Columnas");
        p("\n");
        p("\nCoordenadas jugables:\n");
        p("y   x\n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(juego[i][j]=='\0')
                    p("%i , %i\n",i,j);
                else
                    contador++;
            }
        }
        if(contador!=9){
            if(jugador%2!=0){
                p("\nJugador 1: x\n");
                win = coords(&jugador,juego);
            }
            else{
                p("\nJugador 2: o\n");
                win = coords(&jugador,juego);
            }
            if(win!=0){
            	system("cls");
            	tablero(juego);
                if(jugador%2!=0)
                    p("\nFELICIDADES!!! GANADOR: JUGADOR 1\n");
                else
                    p("\nFELICIDADES!!! GANADOR: JUGADOR 2\n");
            }
            system("pause");system("cls");
        }
        else
            p("\nYa no hay coordenadas jugables, es un empate!\n");
    }while(contador<9 && win==0);
    return 0;
}

void tablero(char xo[][3]){
    int i,j;
    p("   0   1   2\n");
    for(i=0;i<3;i++){
        p("%i ",i);
        for(j=0;j<3;j++){
            if(xo[i][j]!='\0')
                p(" %c ",xo[i][j]);
            else
                p("   ");
            if(j!=2)
                p("|");
        }
        if(i!=2)
            p("\n  ---%c---%c---",197,197);
        p("\n");
    }
    return;
}

int coords(int *jug, char xo2[][3]){
    int rep=0;
    int coord_x, coord_y;
    int gana=0;
    do{
        p("Que coordenada deseas jugar?\n");
        p("coordenada y: "); s("%i",&coord_y);
        p("coordenada x: "); s("%i",&coord_x);
        if(coord_y >= 0 && coord_y < 3 && coord_x >= 0 && coord_x < 3) {
            if (xo2[coord_y][coord_x]=='\0') {
                if (*jug % 2 != 0)
                    xo2[coord_y][coord_x]='x';
                else
                    xo2[coord_y][coord_x]='o';
                rep++;
            } 
			else
                p("\nError, esa casilla ya est%c ocupada. Ingresa nuevas coordenadas\n\n",160);
        }
		else 
            p("\nError, coordenadas fuera de rango. Deben estar entre 0 y 2\n\n");
    }while(rep==0);
    gana = ganador(xo2);
    if(gana==0)
        *jug+=1;
    return gana;
}

int ganador(char xo3[][3]){
    if (xo3[0][0] != '\0' && xo3[0][0] == xo3[0][1] && xo3[0][1] == xo3[0][2])
        return 1;
    if (xo3[1][0] != '\0' && xo3[1][0] == xo3[1][1] && xo3[1][1] == xo3[1][2])
        return 1;
    if (xo3[2][0] != '\0' && xo3[2][0] == xo3[2][1] && xo3[2][1] == xo3[2][2])
        return 1;
    if (xo3[0][0] != '\0' && xo3[0][0] == xo3[1][0] && xo3[1][0] == xo3[2][0])
        return 1;
    if (xo3[0][1] != '\0' && xo3[0][1] == xo3[1][1] && xo3[1][1] == xo3[2][1])
        return 1;
    if (xo3[0][2] != '\0' && xo3[0][2] == xo3[1][2] && xo3[1][2] == xo3[2][2])
        return 1;
    if (xo3[0][0] != '\0' && xo3[0][0] == xo3[1][1] && xo3[1][1] == xo3[2][2])
        return 1;
    if (xo3[2][0] != '\0' && xo3[2][0] == xo3[1][1] && xo3[1][1] == xo3[0][2])
        return 1;
    return 0;
}
