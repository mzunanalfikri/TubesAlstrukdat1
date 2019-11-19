#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "arraydin.h"
#include "bangunan.h"
#include "listlinier.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "queue.h"
#include "stackt.h"
#include "state.h"
#include "graph.h"
#include "pcolor.h"
#include "function.h"

int main() {
    // DEKLARASI ADT YANG DIGUNAKAN
    State S;
    MATRIKS Map;
    Graph G;
    
    boolean endgame;
    boolean extraTurn;

    extraTurn = false;
    endgame = false;
    ReadKonfigurasiFile(&S, &Map, &G);
    Turn(Player1(S)) = true;
    StatusPlayer(S, Map);

    while (!endgame){
        EnterCommad(S);
        ReadCmd();
        if (IsEQCKataString("ATTACK")){
            printf("menampilkan attack mechanism\n");
            Attack(&S, G);
        } else if (IsEQCKataString("LEVEL_UP")){
            LevelUp(&S);
        } else if (IsEQCKataString("SKILL")){
            printf("skill \n");
        } else if (IsEQCKataString("UNDO")) {
            printf("Undo \n");
        } else if (IsEQCKataString("END_TURN")){
            EndTurn(&S, &extraTurn);
            StatusPlayer(S,Map);
        } else if (IsEQCKataString("MOVE")){
            MovePasukan(&S, G);
        } else if (IsEQCKataString("EXIT")){
            endgame = true;
        } else if (IsEQCKataString("MAP")){
            CetakMatiksWarna(Map, S);
        } else if(IsEQCKataString("PRINT_ALL_BANGUNAN")){
            PrintAllBangunan(ArrayBangunan(S));
        } else if (IsEQCKataString("STATUS")) {
            StatusPlayer(S, Map);
        } else if (IsEQCKataString("HELP")){
            printf("tampilin help");
        } else if (IsEQCKataString("PRINT_GRAPH")) {
            PrintInfoGraph(G);
        }
        // disini lakukan pengecekan skiil bertamah
        //cek juga ada yang kalah atau enggak
    }

    return 0;
}