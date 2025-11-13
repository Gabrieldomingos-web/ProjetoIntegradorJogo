#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<stdio.h>
#include<allegro5/allegro_primitives.h>
int TelaInicial(int tela) {
    bool sair = false;
    al_init();
    al_init_image_addon();
    al_install_mouse();
    al_install_keyboard();

    ALLEGRO_DISPLAY* janela = al_create_display(1600, 900);
    ALLEGRO_BITMAP* fundo_Inicial = al_load_bitmap("Página_InicialNova.png");
    ALLEGRO_BITMAP* fundoInstr = al_load_bitmap("Página_Instruções.png");
    ALLEGRO_BITMAP* fundoCreditos = al_load_bitmap("Página_creditos.png");
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_mouse_event_source());
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_draw_scaled_bitmap(fundo_Inicial, 0, 0, 1920, 1080, 0, 0, 1600, 900, 0);
    while (!sair) {
        ALLEGRO_EVENT evento;
        while (al_get_next_event(fila, &evento)) {

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//se fechar a janela essa linha sera executada 
                sair = true;

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {//se esc for apertado esse if fechará o jogo
                    sair = true;
                }
            }
            if (tela == 0) {
                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((evento.mouse.x >= 645 && evento.mouse.x <= 931) && evento.mouse.y >= 583 && evento.mouse.y <= 701) {
                        sair = true;
                        tela = 3;
                    }
                    if ((evento.mouse.x >= 642 && evento.mouse.x <= 961) && evento.mouse.y >= 732 && evento.mouse.y <= 804) {
                        tela = 1;
                        al_rest(0.3);
                    }
                    if ((evento.mouse.x >= 1442 && evento.mouse.x <= 1544) && evento.mouse.y >= 734 && evento.mouse.y <= 845) {
                        tela = 6;

                    }
                }
            }

        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        if (tela == 0)
            al_draw_scaled_bitmap(fundo_Inicial, 0, 0, 1920, 1080, 0, 0, 1600, 900, 0);
        else if (tela == 1)
            al_draw_scaled_bitmap(fundoInstr, 0, 0, 1920, 1080, 0, 0, 1600, 900, 0);
        else if (tela == 6)
            al_draw_scaled_bitmap(fundoCreditos, 0, 0, 1920, 1080, 0, 0, 1600, 900, 0);
        if (tela == 1) {
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((evento.mouse.x >= 695 && evento.mouse.x <= 876) && evento.mouse.y >= 698 && evento.mouse.y <= 779) {
                    tela = 0;
                    al_rest(0.3);
                }
            }
        }
        if (tela == 6) {
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((evento.mouse.x >= 697 && evento.mouse.x <= 876) && evento.mouse.y >= 735 && evento.mouse.y <= 821) {
                    tela = 0;
                    al_rest(0.3);
                }
            }
        }
        al_flip_display();
    }
    al_destroy_bitmap(fundo_Inicial);
    al_destroy_bitmap(fundoInstr);
    al_destroy_event_queue(fila);
    al_destroy_display(janela);
    if (tela == 3) {
        return 3;
    }
    else return 1;
}

int calcular_chao(int x, int tela, int y) {
    if (tela == 2) {
        if (x <= 123) return 630;
        if (x <= 211) return 689;
        if (x <= 299) return 742;
        if (x <= 467) return 774;
        if (x <= 570) return 739;
        if (x <= 606) return 705;
        if (x <= 678) return 665;
        if (x <= 739) return 625;
        if (x <= 810) return 574;
        if (x <= 939) return 518;
        if (x <= 1009) return 479;
        if (x <= 1102) return 420;
        if (x <= 1177) return 478;
        if (x <= 1254) return 532;
        if (x <= 1327) return 581;
        if (x <= 1379) return 638;
        if (x <= 1454) return 696;
        if (x <= 2215) return 774;
        if (x <= 2250) return 737;
        if (x <= 2300) return 700;
        return 654;
    }
    if (tela == 3) {
        if (x >= -8 && x <= 133 && y <= 216)return 216;
        if (x >= 286 && x <= 496 && y <= 186) return 186;
        if (x <= 100 && y <= 551) return 551;
        if (x <= 344 && y <= 366) return 366;
        if (x <= 322 && y <= 597) return 597;
        if (x <= 492 && y <= 398) return 398;
        if (x <= 542 && y <= 403) return 403;
        if (x >= 486 && x <= 516 && y <= 529 && y >= 400) return 529;
        if (x >= 324 && x <= 568 && y > 523 && y <= 773) return 773;
        if (x >= 568 && x <= 945 && y <= 242) return 242;
        if (x <= 664 && y <= 523) return 523;
        if (x <= 876 && y <= 483) return 483;
        if (x <= 704 && y <= 745 && y > 523) return 745;
        if (x <= 766 && y <= 817) return 817;
        if (x <= 822 && y <= 807) return 807;
        if (x <= 848 && y <= 789) return 789;
        if (x >= 945 && x <= 1002 && y <= 222) return 222;
        if (x <= 1230 && y <= 212) return 212;
        if (x <= 1044 && y <= 473) return 473;
        if (x <= 988 && y <= 717) return 717;
        if (x <= 1138 && y <= 653) return 653;
        if (x >= 1222 && x <= 1236 && y <= 340) return 340;
        if (x >= 1236 && x <= 1250 && y <= 328) return 328;
        if (x >= 1250 && x <= 1320 && y <= 318)return 318;
        if (x <= 1344 && y <= 569) return 569;
        if (x <= 1456 && y <= 557) return 557;
    }
}
int Colisao_Left(int x, int y, int v, int tela) {
    int novo_x = x;
    if (tela == 2) {
        if (y < 631 && x > 0 && x <= 124) novo_x -= v;
        else if (y < 691 && x > 124 && x <= 215) novo_x -= v;
        else if (y < 746 && x > 215 && x <= 303) novo_x -= v;
        else if (y < 780 && x > 303 && x <= 469) novo_x -= v;
        else if (x > 470 && x <= 1007) novo_x -= v;
        else if (y <= 420 && x > 1007 && x <= 1102) novo_x -= v;
        else if (y <= 480 && x > 1102 && x <= 1177) novo_x -= v;
        else if (y <= 535 && x > 1177 && x <= 1254) novo_x -= v;
        else if (y <= 585 && x > 1254 && x <= 1327) novo_x -= v;
        else if (y <= 640 && x > 1327 && x <= 1379) novo_x -= v;
        else if (y <= 700 && x > 1379 && x <= 1454) novo_x -= v;
        else if (y <= 776 && x > 1454 && x <= 2380) novo_x -= v;
        return novo_x;
    }
    if (tela == 3) {
        if (x >= 0 && x <= 133 && y <= 216)  novo_x -= v;
        if (x >= 492 && y <= 403)  novo_x -= v;
        if (x >= 344 && x <= 492 && y <= 398)  novo_x -= v;
        if (x >= 134 && x <= 343 && y <= 366)  novo_x -= v;
        if (x >= 486 && x <= 516 && y <= 529)  novo_x -= v;
        if (x >= 516 && x <= 664 && y <= 523)  novo_x -= v;
        if (x >= 664 && x <= 876 && y <= 483)  novo_x -= v;
        if (x >= 876 && y <= 473)  novo_x -= v;
        if (x >= 324 && x <= 704 && y >= 528 && y <= 773)  novo_x -= v;
        if (x >= 704 && y <= 817)  novo_x -= v;
        if (x >= 0 && x <= 100 && y >= 368 && y <= 551)  novo_x -= v;
        if (x >= 100 && x <= 340 && y >= 368 && y <= 597)  novo_x -= v;
        return novo_x;
    }
}

int Colisao_Right(int x, int y, int v, int tela) {
    int novo_x = x;
    if (tela == 2)
    {
        if (x < 469) novo_x += v;
        else if (y < 742 && x > 469 && x <= 567) novo_x += v;
        else if (y < 710 && x > 567 && x <= 603) novo_x += v;
        else if (y < 670 && x > 603 && x <= 675) novo_x += v;
        else if (y < 630 && x > 675 && x <= 734) novo_x += v;
        else if (y < 579 && x > 734 && x <= 805) novo_x += v;
        else if (y < 523 && x > 805 && x <= 937) novo_x += v;
        else if (y <= 480 && x > 937 && x <= 1007) novo_x += v;
        else if (y <= 421 && x > 1007 && x <= 1102) novo_x += v;
        else if (y <= 774 && x > 1102 && x <= 2204) novo_x += v;
        else if (y <= 737 && x > 2204 && x <= 2238) novo_x += v;
        else if (y <= 700 && x > 2238 && x < 2285) novo_x += v;
        else if (y <= 654 && x > 2285 && x < 2380) novo_x += v;
        return novo_x;
    }
    if (tela == 3) {
        if (x >= -5 && x <= 550 && y <= 403) novo_x += v;
        if (x >= 486 && x < 516 && y > 403 && y <= 529) novo_x += v;
        if (x >= 516 && x < 663 && y > 403 && y <= 523) novo_x += v;
        if (x >= 664 && x < 876 && y > 250 && y <= 483) novo_x += v;
        if (x >= 876 && x <= 1138 && y > 250 && y <= 473) novo_x += v;
        if (x >= 988 && x < 1138 && y > 483 && y <= 653) novo_x += v;
        if (x >= 848 && x <= 988 && y > 483 && y <= 717) novo_x += v;
        if (x >= 822 && x < 848 && y > 483 && y <= 789) novo_x += v;
        if (x >= 704 && x < 766 && y > 483 && y <= 817) novo_x += v;
        if (x >= 766 && x < 822 && y > 483 && y <= 807) novo_x += v;
        if (x >= 568 && x < 704 && y > 529 && y <= 745) novo_x += v;
        if (x >= 320 && x < 568 && y > 529 && y <= 773) novo_x += v;
        if (x >= 568 && x < 938 && y <= 242) novo_x += v;
        if (x >= 938 && x < 1002 && y <= 222) novo_x += v;
        if (x >= 1002 && x < 1235 && y <= 212) novo_x += v;
        if (x >= 1250 && x < 1320 && y <= 318) novo_x += v;
        if (x >= 1236 && x < 1250 && y <= 328) novo_x += v;
        if (x >= 1222 && x < 1236 && y <= 340) novo_x += v;
        if (x >= 1138 && x < 1344 && y > 350 && y <= 569) novo_x += v;
        if (x >= 1344 && x < 1456 && y <= 557) novo_x += v;
        if (x >= -5 && x < 340 && y > 366 && y <= 597) novo_x += v;
        return novo_x;

    }
}
bool Dano(int x, int y) {
    if (x >= 300 && x <= 332 && y == 774)return true;
    if (x >= 467 && x <= 508 && y == 739)return true;
    if (x >= 1327 && x <= 1340 && y == 638)return true;
    if (x >= 1379 && x <= 1380 && y == 696)return true;
    if (x >= 1552 && x <= 1636 && y == 774)return true;
    if (x >= 2090 && x <= 2160 && y == 774)return true;
    return false;
}

struct Posicaopersonagem
{
    int x, y, gravidade, vida;
    int v[2];
};
struct Posicaofundo
{
    bool no_chao;
    int width, height, chao, movimento;
};
struct tiro {
    int x, y;
    int xfinal, yfinal;
};
int Telaestomago(int tela) {
    struct Posicaopersonagem p;
    p.x = 20; p.y = 630; p.v[0] = 4; p.v[1] = 0; p.gravidade = 5; p.vida = 3;
    struct Posicaofundo f;
    f.width = 0; f.height = 0; f.no_chao = true; f.chao = 630; f.movimento = 0;
    bool right = false, left = false, up = false, dano = false;
    int x_mapa = p.x;
    int sair = 1;
    int tempo = 0;
    bool desenhar = false;
    int camera = 4;
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_EVENT_QUEUE* fila_eventos = al_create_event_queue();
    ALLEGRO_DISPLAY* janela = al_create_display(1600, 900);
    ALLEGRO_BITMAP* fundo = al_load_bitmap("tela1.png");
    ALLEGRO_BITMAP* life = al_load_bitmap("life.png");
    ALLEGRO_BITMAP* personagem = al_load_bitmap("personagem.png");
    ALLEGRO_BITMAP* NPC = al_load_bitmap("NPCtela1.png");
    ALLEGRO_BITMAP* movimentoleft = al_load_bitmap("personagemleft.png");
    ALLEGRO_BITMAP* movimentoright = al_load_bitmap("personagemright.png");
    ALLEGRO_TIMER* timer = al_create_timer(2.0 / 60);

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    al_draw_scaled_bitmap(personagem, f.width, f.no_chao, 1920, 1080, 0, 0, 1600, 900, 0);
    al_draw_bitmap(personagem, p.x, p.y, 0);
    al_start_timer(timer);
    while (tela == 2) {
        ALLEGRO_EVENT evento;

        al_wait_for_event(fila_eventos, &evento);
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            tela = 1;
        }
        else if (evento.type == ALLEGRO_EVENT_TIMER)
            desenhar = true;
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (evento.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT: left = true; break;
            case ALLEGRO_KEY_RIGHT: right = true; break;
            case ALLEGRO_KEY_A: left = true; break;
            case ALLEGRO_KEY_D: right = true; break;
            case ALLEGRO_KEY_UP:up = true; break;
            case ALLEGRO_KEY_W:up = true; break;
            case ALLEGRO_KEY_ESCAPE: tela = 1; break;
            case ALLEGRO_KEY_ENTER:  printf(" x = %d y = %d", x_mapa, p.y);
                if (x_mapa >= 376 && x_mapa <= 400) {
                    printf("%d", p.x);
                }
                if (x_mapa >= 2350)tela = 3;
            }
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
            switch (evento.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT: left = false; break;
            case ALLEGRO_KEY_RIGHT: right = false; break;
            case ALLEGRO_KEY_UP:up = false; break;
            case ALLEGRO_KEY_W:up = false; break;
            case ALLEGRO_KEY_A: left = false; break;
            case ALLEGRO_KEY_D: right = false; break;
            }
        }
        if (tempo > 0)
            tempo--;
        if (Dano(x_mapa, p.y)) {
            if (tempo == 0) {
                p.vida -= 1;
                tempo = 30;
            }
        }
        //eixo X
        if (left) {
            int colisao = Colisao_Left(x_mapa, p.y, p.v[0], tela);
            if (colisao != x_mapa) {
                x_mapa = colisao;
                if (x_mapa >= 960 && x_mapa <= 1700)
                    f.width += p.v[0];
                else
                    p.x -= p.v[0];
            }
        }

        if (right) {
            int colisao = Colisao_Right(x_mapa, p.y, p.v[0], tela);
            if (colisao != x_mapa) {
                x_mapa = colisao;
                if (x_mapa >= 960 && x_mapa <= 1770)
                    f.width -= p.v[0];
                else
                    p.x += p.v[0];
            }
        }



        // eixo Y
        f.chao = calcular_chao(x_mapa, tela, p.y);
        if (up && f.no_chao) {
            p.v[1] = -15;
            f.no_chao = false;
        }
        p.v[1] += 1;
        p.y += p.v[1];

        if (p.y >= f.chao) {
            p.y = f.chao;
            p.v[1] = 0;
            f.no_chao = true;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(fundo, f.width, f.height, 0);
        for (int i = 0; i < p.vida; i++) {
            al_draw_bitmap(life, 20 + i * 60, 60, 0);
        }

        if (left) {
            al_draw_bitmap(movimentoleft, p.x, p.y, 0);
        }
        else {
            if (right) {
                al_draw_bitmap(movimentoright, p.x, p.y, 0);
            }
            else {
                al_draw_bitmap(personagem, p.x, p.y, 0);
            }

        }
        al_draw_scaled_bitmap(NPC, 0, 0, 612, 408, 420 + f.width, 770, 40, 40, 0);
        al_flip_display();
    }
    al_destroy_timer(timer);
    al_destroy_bitmap(personagem);
    al_destroy_bitmap(NPC);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
    return tela;
}
int Tela2(int tela) {
    int chao = 216; bool no_chao = false;
    struct Posicaopersonagem p;
    p.x = 0; p.y = chao; p.v[0] = 2; p.vida = 3;
    struct tiro t;
    int vida = 1;
    for (int i = 0; i < 3; i++) {
        t.x = 720;
        t.y = 140;
    }
    t.xfinal = p.x;
    t.yfinal = p.y;
    float gravidade = 0;
    int tempo = 0;
    int i;
    bool right = false, left = false, up = false; bool down = false, Z = false;
    ALLEGRO_DISPLAY* janela = al_create_display(1600, 900);
    ALLEGRO_BITMAP* fundo2 = al_load_bitmap("fase2.png");
    ALLEGRO_BITMAP* life = al_load_bitmap("life.png");
    ALLEGRO_BITMAP* personagem = al_load_bitmap("personagem.png");
    ALLEGRO_BITMAP* movimentoleft = al_load_bitmap("personagemleft.png");
    ALLEGRO_BITMAP* vilao = al_load_bitmap("VilaoFase2.png");
    ALLEGRO_BITMAP* tirovilao2 = al_load_bitmap("tirovilao2.png");
    ALLEGRO_BITMAP* GameOver = al_load_bitmap("GameOver.png");
    ALLEGRO_BITMAP* movimentoright = al_load_bitmap("personagemright.png");
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_keyboard_event_source());
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
    al_register_event_source(fila, al_get_mouse_event_source());
    al_register_event_source(fila, al_get_timer_event_source(timer));
    al_draw_bitmap(fundo2, 0, 0, 0);
    al_draw_bitmap(personagem, p.x, p.y, 0);
    al_start_timer(timer);
    while (tela == 3) {
        ALLEGRO_EVENT evento;

        al_wait_for_event(fila, &evento);
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            tela = 1;
        }
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (evento.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT: left = true; break;
            case ALLEGRO_KEY_RIGHT: right = true; break;
            case ALLEGRO_KEY_A: left = true; break;
            case ALLEGRO_KEY_D: right = true; break;
            case ALLEGRO_KEY_DOWN:down = true; break;
            case ALLEGRO_KEY_UP:up = true; break;
            case ALLEGRO_KEY_W:up = true; break;
            case ALLEGRO_KEY_Z:Z = true; break;
            case ALLEGRO_KEY_ESCAPE: tela = 1; break;
            case ALLEGRO_KEY_ENTER: if (p.x == 1456 && p.y == 557 )return tela = 4;

            }
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
            switch (evento.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT: left = false; break;
            case ALLEGRO_KEY_RIGHT: right = false; break;
            case ALLEGRO_KEY_UP:up = false; break;
            case ALLEGRO_KEY_W:up = false; break;
            case ALLEGRO_KEY_Z:Z = false; break;
            case ALLEGRO_KEY_DOWN:down = false; break;
            case ALLEGRO_KEY_A: left = false; break;
            case ALLEGRO_KEY_D: right = false; break;
            }
        }
        tempo++;
        if (vida > 0) {
                if (t.x> p.x) t.x--;
                if (t.x < p.x) t.x++; 
                if (t.y > p.y) t.y--; 
                if (t.y < p.y) t.y++;
                if (t.x  ==p.x && t.y == p.y && p.vida > 0)
                    p.vida--;
        }
        if (Z && p.x >= 700 && p.x <=740 && p.y >= 125) {
            vida --;
            printf("ok");
            printf("%d",vida);
        }
        if (left) {

            p.x = Colisao_Left(p.x, p.y, p.v[0], tela);
            chao = calcular_chao(p.x, tela, p.y);
        }
        if (right) {
            p.x = Colisao_Right(p.x, p.y, p.v[0], tela);
            chao = calcular_chao(p.x, tela, p.y);
        }
        if (up && no_chao) {
            gravidade = -12.0;
            no_chao = false;
        }
        gravidade += 0.5;
        p.y += gravidade;

        if (p.y >= chao) {
            p.y = chao;
            gravidade = 0.0;
            no_chao = true;
        }
        
        al_draw_scaled_bitmap(fundo2, 0, 0, 872, 606, 0, 0, 1600, 900, 0);
       
        if (p.vida == 0) {
            al_draw_bitmap(GameOver, 230, -50, 0);
        }if (vida>0)
             {
            if (t.x != t.xfinal || t.y != t.yfinal) al_draw_bitmap(tirovilao2, t.x, t.y, 0);
            al_draw_scaled_bitmap(vilao, 0, 0, 1024, 1024, 720, 140, 60, 60, 0);
        }
        
       
        for (int i = 0; i < p.vida; i++) {
            al_draw_bitmap(life, 20 + i * 60, 60, 0);
        }
        if (left) {
            al_draw_bitmap(movimentoleft, p.x, p.y, 0);
        }
        else {
            if (right) {
                al_draw_bitmap(movimentoright, p.x, p.y, 0);
            }
            else {
                al_draw_bitmap(personagem, p.x, p.y, 0);
            }

        }
        al_flip_display();
    }
    al_destroy_bitmap(fundo2);
    al_destroy_event_queue(fila);
    al_destroy_display(janela);
    return tela;
}
int Tela3(int tela) {
    ALLEGRO_DISPLAY* janela = al_create_display(1920, 1080);
    ALLEGRO_BITMAP* fundo_Inicial = al_load_bitmap("Fase 3.png");
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_mouse_event_source());
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_draw_bitmap(fundo_Inicial, 0, 0, 0);
    while (tela == 4) {
        ALLEGRO_EVENT evento;
        while (al_get_next_event(fila, &evento)) {

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {//se esc for apertado esse if fechará o jogo
                    tela = 1;
                }
            }
            if (tela == 4) {
                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    tela = 5;
                }
            }
        }
        al_flip_display();
    }
    al_destroy_bitmap(fundo_Inicial);
    al_destroy_event_queue(fila);
    al_destroy_display(janela);
    return tela;
}
int Tela4(int tela) {
    ALLEGRO_DISPLAY* janela = al_create_display(1920, 1080);
    ALLEGRO_BITMAP* fundo_Inicial = al_load_bitmap("Fase 4.png");
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_mouse_event_source());
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_draw_bitmap(fundo_Inicial, 0, 0, 0);
    while (tela == 5) {
        ALLEGRO_EVENT evento;
        while (al_get_next_event(fila, &evento)) {

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {//se esc for apertado esse if fechará o jogo
                    tela = 1;
                }
            }
            if (tela == 5) {
                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    tela = 2;
                }
            }
        }
        al_flip_display();
    }
    al_destroy_bitmap(fundo_Inicial);
    al_destroy_event_queue(fila);
    al_destroy_display(janela);
    return tela;
}

int main() {
    int tela = 0;
    while (tela != 1) {
        if (tela == 0) {
            tela = TelaInicial(tela);
        }
        if (tela == 2) {
            tela = Telaestomago(tela);
        }
        if (tela == 3) {
            tela = Tela2(tela);
        }
        if (tela == 4) {
            tela = Tela3(tela);
        }
        if (tela == 5) {
            tela = Tela4(tela);
        }
    }
}



