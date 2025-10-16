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

    ALLEGRO_DISPLAY* janela = al_create_display(1920, 1080);
    ALLEGRO_BITMAP* fundo_Inicial = al_load_bitmap("Página_InicialNova.png");
    ALLEGRO_BITMAP* fundoInstr = al_load_bitmap("Página_Instruções.png");
    ALLEGRO_BITMAP* fundoCreditos = al_load_bitmap("Página_creditos.png");
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_mouse_event_source());
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_draw_bitmap(fundo_Inicial, 0, 0, 0);
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
                    if ((evento.mouse.x >= 768 && evento.mouse.x <= 1140) && evento.mouse.y >= 636 && evento.mouse.y <= 812) {
                        sair = true;
                        tela = 2;
                    }
                    if ((evento.mouse.x >= 770 && evento.mouse.x <= 1153) && evento.mouse.y >= 842 && evento.mouse.y <= 928) {
                        tela = 1;
                        al_rest(0.3);
                    }
                    if ((evento.mouse.x >= 1733 && evento.mouse.x <= 1864) && evento.mouse.y >= 893 && evento.mouse.y <= 1017) {
                        tela = 6;

                    }
                }
            }

        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        if (tela == 0)
            al_draw_bitmap(fundo_Inicial, 0, 0, 0);
        else if (tela == 1)
            al_draw_bitmap(fundoInstr, 0, 0, 0);
        else if (tela == 6)
            al_draw_bitmap(fundoCreditos, 0, 0, 0);
        if (tela == 1) {
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((evento.mouse.x >= 837 && evento.mouse.x <= 1060) && evento.mouse.y >= 841 && evento.mouse.y <= 951) {
                    tela = 0;
                    al_rest(0.3);
                }
            }
        }
        if (tela == 6) {
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((evento.mouse.x >= 837 && evento.mouse.x <= 1060) && evento.mouse.y >= 841 && evento.mouse.y <= 951) {
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
    if (tela == 2) {
        return 2;
    }
    else return 1;
}

int calcular_chao(int x) {
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
int Colisao_Left(int x, int y, int v) {
    int novo_x = x;
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

int Colisao_Right(int x, int y, int v) {
    int novo_x = x;
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


struct Posicaopersonagem
{
    int x , y , gravidade;
    int v[2];
};
struct Posicaofundo
{
    bool no_chao;
    int width , height, chao , movimento;
};
int Telaestomago(int tela) {
    struct Posicaopersonagem p;
    p.x = 20; p.y = 630; p.v[0] = 4; p.v[1] = 0; p.gravidade = 5;
    struct Posicaofundo f;
    f.width = 0;f.height = 0; f.no_chao = true; f.chao = 630; f.movimento = 0;
    bool right = false, left = false, up = false;
    int x_mapa = p.x;
    int sair = 1;
    bool desenhar = false;
    int camera = 4;
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_EVENT_QUEUE* fila_eventos = al_create_event_queue();
    ALLEGRO_DISPLAY* janela = al_create_display(1900, 1080);
    ALLEGRO_BITMAP* fundo = al_load_bitmap("tela1.png");
    ALLEGRO_BITMAP* personagem = al_load_bitmap("personagem.png");
    ALLEGRO_TIMER* timer = al_create_timer(2.0 / 60);

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    al_draw_bitmap(fundo, f.width, f.height, 0);
    al_draw_bitmap(personagem, p.x, p.y, 0);
    al_start_timer(timer);
    while ( tela == 2) {
        ALLEGRO_EVENT evento;

        al_wait_for_event(fila_eventos, &evento);
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            tela = 1;
         }
        else if (evento.type == ALLEGRO_EVENT_TIMER)
            desenhar = true;
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (evento.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT: left = true; break;
            case ALLEGRO_KEY_RIGHT: right = true; break;
            case ALLEGRO_KEY_UP:up = true; break;
            case ALLEGRO_KEY_ESCAPE: tela = 1; break;
            case ALLEGRO_KEY_ENTER:
                if (x_mapa >= 2350)tela = 3;
            }
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
            switch (evento.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT: left = false; break;
            case ALLEGRO_KEY_RIGHT: right = false; break;
            case ALLEGRO_KEY_UP:up = false; break;
            }
        }
        //eixo X
        if (left) {
            int colisao = Colisao_Left(x_mapa, p.y, p.v[0]);
            if (colisao != x_mapa) {
                x_mapa = colisao;
                if (x_mapa >= 960 && x_mapa <= 1460)
                    f.width += p.v[0];
                else
                    p.x -= p.v[0];
            }
        }

        if (right) {
            int colisao = Colisao_Right(x_mapa, p.y, p.v[0]);
            if (colisao != x_mapa) {
                x_mapa = colisao;
                if (x_mapa >= 960 && x_mapa <= 1460)
                    f.width -= p.v[0];
                else
                    p.x += p.v[0];
            }
        }



        // eixo Y
        f.chao = calcular_chao(x_mapa);
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
        al_draw_bitmap(personagem, p.x, p.y, 0);
        al_flip_display();
    }
    al_destroy_timer(timer);
    al_destroy_bitmap(personagem);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
    return tela;
}
int Tela2(int tela) {
    ALLEGRO_DISPLAY* janela = al_create_display(1920, 1080);
    ALLEGRO_BITMAP* fundo_Inicial = al_load_bitmap("Fase 2.png");
    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_register_event_source(fila, al_get_mouse_event_source());
    al_draw_bitmap(fundo_Inicial, 0, 0, 0);
    while (tela==3) {
        ALLEGRO_EVENT evento;
        while (al_get_next_event(fila, &evento)) {

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {//se esc for apertado esse if fechará o jogo
                    tela = 1;
                }
            }
            if (tela == 3) {
                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                        tela = 4; 
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
                    tela = 1;
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

int main(){
    int tela = 0;
    while (tela != 1) {
        if (tela == 0) {
            tela = TelaInicial(tela);
        }
        if (tela == 2) {
            tela = Telaestomago(tela);
        }
        if(tela == 3) {
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

