#ifndef INIMIGO
#define INIMIGO

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"
#include "inimigo.h"
#include "cristal.h"

typedef struct {
    
    Rectangle hitbox_inimigo;
    float vida_inimigo;
    bool ativo;

}Enemy;

Enemy* initVilao(Enemy* Recvilao, Texture2D mapa){

    Recvilao[0].vida_inimigo = 60;
    Recvilao[1].vida_inimigo = 30;
    Recvilao[2].vida_inimigo = 30;
    Recvilao[3].vida_inimigo = 30;
    Recvilao[4].vida_inimigo = 60;
    Recvilao[5].vida_inimigo = 60;
    Recvilao[6].vida_inimigo = 1000;

    Recvilao[3].hitbox_inimigo.x = 300; Recvilao[3].hitbox_inimigo.y = 550; Recvilao[3].hitbox_inimigo.width = 80; Recvilao[3].hitbox_inimigo.height = 80;
    Recvilao[1].hitbox_inimigo.x = 1230; Recvilao[1].hitbox_inimigo.y = 550; Recvilao[1].hitbox_inimigo.width = 80; Recvilao[1].hitbox_inimigo.height = 80;
    Recvilao[2].hitbox_inimigo.x = 200; Recvilao[2].hitbox_inimigo.y = 100; Recvilao[2].hitbox_inimigo.width = 80; Recvilao[2].hitbox_inimigo.height = 80;
    Recvilao[0].hitbox_inimigo.x = -55; Recvilao[0].hitbox_inimigo.y = 300; Recvilao[0].hitbox_inimigo.width = 100; Recvilao[0].hitbox_inimigo.height = 135;
    Recvilao[4].hitbox_inimigo.x = 1570; Recvilao[4].hitbox_inimigo.y = 300; Recvilao[4].hitbox_inimigo.width = 100; Recvilao[4].hitbox_inimigo.height = 135;
    Recvilao[5].hitbox_inimigo.x = 758; Recvilao[5].hitbox_inimigo.y = 50; Recvilao[5].hitbox_inimigo.width = 100; Recvilao[5].hitbox_inimigo.height = 135;
    Recvilao[6].hitbox_inimigo.x = 750; Recvilao[6].hitbox_inimigo.y = 340; Recvilao[6].hitbox_inimigo.width = 100; Recvilao[6].hitbox_inimigo.height = 100;

     for(int j = 0; j < 7; j++){
        Recvilao[j].ativo = 1;
     }

    return Recvilao;
}
Enemy* inimigoAcertado(Personagem perso, Enemy* inimigo, int i, int* morreu, Sound* tema, int time,  Sound* efeitos){
    
    if(i == -1){
        perso.hitbox_ataque.x = perso.posicao.x + 20;
        perso.hitbox_ataque.y = perso.posicao.y + 60;
    }

     else{
        perso.hitbox_ataque.x = perso.posicao.x + 100;
        perso.hitbox_ataque.y = perso.posicao.y + 60;
    }

    perso.hitbox_ataque.height = perso.hitbox.height;
    perso.hitbox_ataque.width = perso.hitbox.width;

    if(time >= 1){
        DrawRectangle(inimigo[3].hitbox_inimigo.x + 30, inimigo[3].hitbox_inimigo.y - 10, inimigo[3].vida_inimigo * 2 , 13 , DARKPURPLE);
        DrawRectangleLines(inimigo[3].hitbox_inimigo.x + 30, inimigo[3].hitbox_inimigo.y - 10, 60 , 15, BLACK);
        DrawRectangle(inimigo[0].hitbox_inimigo.x - 5, inimigo[0].hitbox_inimigo.y - 13, inimigo[0].vida_inimigo * 2 , 13 , MAROON);
        DrawRectangleLines(inimigo[0].hitbox_inimigo.x - 5, inimigo[0].hitbox_inimigo.y - 13, 120 , 15, BLACK);
    }

    if(time >= 15){
        DrawRectangle(inimigo[1].hitbox_inimigo.x + 30, inimigo[1].hitbox_inimigo.y - 10, inimigo[1].vida_inimigo * 2 , 13 , DARKPURPLE);
        DrawRectangleLines(inimigo[3].hitbox_inimigo.x + 30, inimigo[3].hitbox_inimigo.y - 10, 60 , 15, BLACK);
        DrawRectangle(inimigo[4].hitbox_inimigo.x - 5, inimigo[4].hitbox_inimigo.y - 13, inimigo[4].vida_inimigo * 2 , 13 , MAROON);
        DrawRectangleLines(inimigo[0].hitbox_inimigo.x - 5, inimigo[0].hitbox_inimigo.y - 13, 120 , 15, BLACK);
    }

    if(time >= 40){
        DrawRectangle(inimigo[2].hitbox_inimigo.x + 30, inimigo[2].hitbox_inimigo.y - 10, inimigo[2].vida_inimigo * 2 , 13 , DARKPURPLE);
        DrawRectangleLines(inimigo[3].hitbox_inimigo.x + 30, inimigo[3].hitbox_inimigo.y - 10, 60 , 15, BLACK);
        DrawRectangle(inimigo[5].hitbox_inimigo.x - 5, inimigo[5].hitbox_inimigo.y - 13, inimigo[5].vida_inimigo * 2 , 13 , MAROON);
        DrawRectangleLines(inimigo[0].hitbox_inimigo.x - 5, inimigo[0].hitbox_inimigo.y - 13, 120 , 15, BLACK);
    }
        
        
    DrawRectangle(inimigo[6].hitbox_inimigo.x , inimigo[6].hitbox_inimigo.y + 110, inimigo[6].vida_inimigo / 10 , 13 , PURPLE);
    DrawRectangleLines(inimigo[6].hitbox_inimigo.x, inimigo[6].hitbox_inimigo.y + 108, 100 , 17, BLACK);

    for(int j = 0; j < 6; j++){
    
    if(CheckCollisionRecs(perso.hitbox_ataque, inimigo[j].hitbox_inimigo) && IsKeyPressed(KEY_K)){
        DrawText("HIT!", perso.posicao.x + 50, perso.posicao.y - 25, 20, ORANGE);
        inimigo[j].vida_inimigo -= 10;
        PlaySound(efeitos[3]);

        if(inimigo[j].vida_inimigo <= 0){
            
            if(j == 3){
            inimigo[3].vida_inimigo = 30;
            inimigo[3].hitbox_inimigo.x = 300; inimigo[3].hitbox_inimigo.y = 550; inimigo[3].hitbox_inimigo.width = 80; inimigo[3].hitbox_inimigo.height = 80;
            }
            else if(j == 1){
             inimigo[1].vida_inimigo = 30;
             inimigo[1].hitbox_inimigo.x = 1230; inimigo[1].hitbox_inimigo.y = 550; inimigo[1].hitbox_inimigo.width = 80; inimigo[1].hitbox_inimigo.height = 80;
            }
            else if(j == 2){
            inimigo[2].vida_inimigo = 30;
            inimigo[2].hitbox_inimigo.x = 200; inimigo[2].hitbox_inimigo.y = 100; inimigo[2].hitbox_inimigo.width = 80; inimigo[2].hitbox_inimigo.height = 80;
            }
            else if(j == 0){
            inimigo[0].vida_inimigo = 60;
            inimigo[0].hitbox_inimigo.x = -55; inimigo[0].hitbox_inimigo.y = 300; inimigo[0].hitbox_inimigo.width = 100; inimigo[0].hitbox_inimigo.height = 135;
            }
            else if(j == 4){
            inimigo[4].vida_inimigo = 60;
            inimigo[4].hitbox_inimigo.x = 1570; inimigo[4].hitbox_inimigo.y = 300; inimigo[4].hitbox_inimigo.width = 100; inimigo[4].hitbox_inimigo.height = 135;
            }
            else if(j == 5){
            inimigo[5].vida_inimigo = 60;
            inimigo[5].hitbox_inimigo.x = 758; inimigo[5].hitbox_inimigo.y = 50; inimigo[5].hitbox_inimigo.width = 100; inimigo[5].hitbox_inimigo.height = 135;
            }
        }
    }

        if(CheckCollisionRecs(inimigo[6].hitbox_inimigo, inimigo[0].hitbox_inimigo)){
            inimigo[6].vida_inimigo -= 0.3;
            DrawText("PERIGO!!", inimigo[6].hitbox_inimigo.x - 25, inimigo[6].hitbox_inimigo.y + 50, 40, ORANGE);
        }
        if(CheckCollisionRecs(inimigo[6].hitbox_inimigo, inimigo[4].hitbox_inimigo)){
            inimigo[6].vida_inimigo -= 0.3;
            DrawText("PERIGO!!", inimigo[6].hitbox_inimigo.x - 25, inimigo[6].hitbox_inimigo.y + 50, 40, ORANGE);
        }
        if(CheckCollisionRecs(inimigo[6].hitbox_inimigo, inimigo[5].hitbox_inimigo)){
            inimigo[6].vida_inimigo -= 0.3;
            DrawText("PERIGO!!", inimigo[6].hitbox_inimigo.x - 25, inimigo[6].hitbox_inimigo.y + 50, 40, ORANGE);
        }

        if(inimigo[6].vida_inimigo <= 0){
            abrirGameOver(&morreu, &tema);
        }
    }
    return inimigo;
}

void personagemAcertado(Personagem* perso, Enemy* inimigo, int *morreu, Sound *Tema, Cristal* cristal){

    for(int j = 0; j < 6; j++){
    if(CheckCollisionRecs(perso->hitbox, inimigo[j].hitbox_inimigo))
        perso->vida_atual = (float)(perso->vida_atual) - 0.3;
    
    }

    DrawRectangle(perso->posicao.x + 48, perso->posicao.y + 26, perso->vida_atual , 13 , GREEN);
    if(perso->vida_atual <= 0){
        abrirGameOver(&morreu, &Tema);
        perso->ativo = 0;
    }

    for(int i=0;i<2;i++){
        if(CheckCollisionRecs(perso->hitbox, cristal[i].hitbox_cristal) &&  cristal[i].ativo_cristal == 1 && perso->max_vida > perso->vida_atual){
            perso->vida_atual = (float)(perso->vida_atual) + 0.3;
            cristal[i].vida_cristal = (float)(cristal[i].vida_cristal) - 0.3;
        }
        if(cristal[i].vida_cristal <=0){
            cristal[i].ativo_cristal = 0;
        }
    }
    for(int k=0;k<2;k++){
    DrawRectangle(cristal[k].hitbox_cristal.x + 30, cristal[k].hitbox_cristal.y + 105, cristal[k].vida_cristal , 13 , LIME);
    DrawRectangleLines(cristal[k].hitbox_cristal.x + 30, cristal[k].hitbox_cristal.y + 105, 68, 15, BLACK);
    }
}

void movimentarvilao(Rectangle personagem, Enemy *vilao, int time){
    
    if(time >= 1){
        if(CheckCollisionRecs(personagem, vilao[3].hitbox_inimigo)==0){
            if(personagem.x < vilao[3].hitbox_inimigo.x)
                vilao[3].hitbox_inimigo.x -= 0.75f;
            if(personagem.x > vilao[3].hitbox_inimigo.x)
                vilao[3].hitbox_inimigo.x += 0.75f;
            if(personagem.y < vilao[3].hitbox_inimigo.y)
                vilao[3].hitbox_inimigo.y -= 0.75f;
            if(personagem.y > vilao[3].hitbox_inimigo.y)
                vilao[3].hitbox_inimigo.y += 0.75f;
        }
    
            if(vilao[6].hitbox_inimigo.x + vilao[6].hitbox_inimigo.width <= vilao[0].hitbox_inimigo.x)
                vilao[0].hitbox_inimigo.x -= 0.65f;
            if(vilao[6].hitbox_inimigo.x >= vilao[0].hitbox_inimigo.x + vilao[0].hitbox_inimigo.width)
                vilao[0].hitbox_inimigo.x += 0.65f;
            if(vilao[6].hitbox_inimigo.y + vilao[6].hitbox_inimigo.height <= vilao[0].hitbox_inimigo.y)
                vilao[0].hitbox_inimigo.y -= 0.65f;
            if(vilao[6].hitbox_inimigo.y >= vilao[0].hitbox_inimigo.y + vilao[0].hitbox_inimigo.height)
                vilao[0].hitbox_inimigo.y += 0.65f;
            
    }
    if(time >= 15){ 
        if(CheckCollisionRecs(personagem,vilao[1].hitbox_inimigo)==0){
            if(personagem.x <vilao[1].hitbox_inimigo.x)
               vilao[1].hitbox_inimigo.x -= 1.0f;
            if(personagem.x >vilao[1].hitbox_inimigo.x)
               vilao[1].hitbox_inimigo.x += 1.0f;
            if(personagem.y <vilao[1].hitbox_inimigo.y)
               vilao[1].hitbox_inimigo.y -= 1.0f;
            if(personagem.y >vilao[1].hitbox_inimigo.y)
               vilao[1].hitbox_inimigo.y += 1.0f;
        }    

            if(vilao[6].hitbox_inimigo.x + vilao[6].hitbox_inimigo.width <= vilao[4].hitbox_inimigo.x)
                vilao[4].hitbox_inimigo.x -= 0.65f;
            if(vilao[6].hitbox_inimigo.x >= vilao[4].hitbox_inimigo.x + vilao[4].hitbox_inimigo.width)
                vilao[4].hitbox_inimigo.x += 0.65f;
            if(vilao[6].hitbox_inimigo.y + vilao[6].hitbox_inimigo.height <= vilao[4].hitbox_inimigo.y)
                vilao[4].hitbox_inimigo.y -= 0.65f;
            if(vilao[6].hitbox_inimigo.y >= vilao[4].hitbox_inimigo.y + vilao[4].hitbox_inimigo.height)
                vilao[4].hitbox_inimigo.y += 0.65f;
            
    }
    if(time >= 40){
        if(CheckCollisionRecs(personagem, vilao[2].hitbox_inimigo)==0){
            if(personagem.x < vilao[2].hitbox_inimigo.x)
                vilao[2].hitbox_inimigo.x -= 0.8f;
            if(personagem.x > vilao[2].hitbox_inimigo.x)
                vilao[2].hitbox_inimigo.x += 0.8f;
            if(personagem.y < vilao[2].hitbox_inimigo.y)
                vilao[2].hitbox_inimigo.y -= 0.8f;
            if(personagem.y > vilao[2].hitbox_inimigo.y)
                vilao[2].hitbox_inimigo.y += 0.8f;
        }  

            if(vilao[6].hitbox_inimigo.x + vilao[6].hitbox_inimigo.width <= vilao[5].hitbox_inimigo.x)
                vilao[5].hitbox_inimigo.x -= 0.65f;
            if(vilao[6].hitbox_inimigo.x >= vilao[5].hitbox_inimigo.x + vilao[5].hitbox_inimigo.width)
                vilao[5].hitbox_inimigo.x += 0.65f;
            if(vilao[6].hitbox_inimigo.y + vilao[6].hitbox_inimigo.height <= vilao[5].hitbox_inimigo.y)
                vilao[5].hitbox_inimigo.y -= 0.65f;
            if(vilao[6].hitbox_inimigo.y >= vilao[5].hitbox_inimigo.y + vilao[5].hitbox_inimigo.height)
                vilao[5].hitbox_inimigo.y += 0.65f;
            
    }
}

#endif 