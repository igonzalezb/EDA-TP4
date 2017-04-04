#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include "Graphics.h"


void intro (ALLEGRO_DISPLAY*display,int alto,int largo) {

	
	al_set_window_title(display, "SEGA GENESIS--WOMRS");
	ALLEGRO_BITMAP*image = al_load_bitmap("descarga.png");
	ALLEGRO_BITMAP*bmp = al_load_bitmap("mouse/wormPrecision-triangle.png");
	ALLEGRO_MOUSE_CURSOR *cursor=al_create_mouse_cursor(bmp,0, 0);
	al_set_mouse_cursor(display, cursor);
	al_set_display_icon(display, image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	ALLEGRO_SAMPLE *sample = NULL;
	sample = al_load_sample("Sega_-_1991.wav");
	
	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	al_rest(2.5);
	//al_draw_bitmap(image, largo / 5, alto / 3, 0);


	al_draw_scaled_bitmap(image,
		0, 0,                                // source origin
		al_get_bitmap_width(image),     // source width
		al_get_bitmap_height(image),    // source height
		largo/6, alto/4,                                // target origin
		al_get_bitmap_width(image)*2/3, al_get_bitmap_height(image)*0.5,                                // target dimensions
		0                                    // flags
	);


	al_flip_display();

	al_rest(2.5);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_destroy_sample(sample);
	ALLEGRO_SAMPLE *sample2 = al_load_sample("Worms Reloaded OST - Generic [HQ](1).wav");
	al_play_sample(sample2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	image = al_load_bitmap("worms.png");
	ALLEGRO_BITMAP *imagen2 = NULL;
	imagen2= al_load_bitmap("logo_gusano.png");

	for (int i = alto; i >= -500; i -= 10) {
		
		al_draw_bitmap(image, largo / 3, i, 0);
		al_draw_bitmap(imagen2, largo *0.5 , i+(alto/6)+500, 0);
	
		al_flip_display();
		al_rest(0.1);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
		
	}


	al_draw_bitmap(imagen2, largo *  0.5, alto/6, 0);
	al_flip_display();
	al_rest(2);
	for (float timer = 1; timer != 120; timer++) {

		al_draw_tinted_bitmap(imagen2,
			al_map_rgba_f(1 / timer, 1 / timer, 1 / timer, 1 / timer),
			largo *0.5, alto / 6, 0);
		al_flip_display();


		al_rest(0.08);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
	}
	srand(time(NULL));
	switch (rand() % 4)
	{
			case 3: {
				image = al_load_bitmap("fondo1.png");
				al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
				al_flip_display();
				break;
		}
		case 2: {
			image = al_load_bitmap("fondo2.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
		}
		case 1: {
			image = al_load_bitmap("fondo3.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
		}
		case 0: {
			image = al_load_bitmap("fondo4.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
				}
			
		}
	al_destroy_bitmap(imagen2);
	al_flip_display();
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_EVENT ev;

	ALLEGRO_TIMER *timer = NULL;
	timer = al_create_timer(0.5);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	al_start_timer(timer);


	ALLEGRO_FONT * font = NULL;
	font = al_load_font("ARCADE.TTF", 72, 0);
	while (1)
	{
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
		al_flip_display();
		

		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			al_draw_text(font, al_map_rgb(255, 255, 255), alto / 2, (largo * 5 / 6), ALLEGRO_ALIGN_CENTRE, "Press any key to continue");
			al_flip_display();
			al_rest(0.1);
		
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit(3);
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			break;
		}
		
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
		al_flip_display();
		
	}
	
	al_destroy_timer(timer);


	
}