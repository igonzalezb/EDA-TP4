#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include "Graphics.h"


void intro (ALLEGRO_DISPLAY*display,int alto,int largo) {

	ALLEGRO_BITMAP *sega = NULL;
	ALLEGRO_BITMAP* mouse = NULL;
	ALLEGRO_BITMAP* logo = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP *imagen2 = NULL;
	ALLEGRO_MOUSE_CURSOR *cursor = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE *sample2 = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue1 = NULL;
	ALLEGRO_EVENT evIntro;
	ALLEGRO_TIMER *timer1 = NULL;
	ALLEGRO_FONT * font = NULL;

	sega = al_load_bitmap("resources/sega.png");
	if (!sega)
	{
		fprintf(stderr, "failed to create sega bitmap!\n");
	}

	logo = al_load_bitmap("resources/worms.png");
	if (!logo)
	{
		fprintf(stderr, "failed to create logo bitmap!\n");
	}
	
	imagen2 = al_load_bitmap("resources/logo_gusano.png");
	if (!imagen2)
	{
		fprintf(stderr, "failed to create imagen2 bitmap!\n");
	}

	mouse = al_load_bitmap("resources/mouse/mouse.png");
	if (!mouse)
	{
		fprintf(stderr, "failed to create mouse bitmap!\n");
	}
	
	cursor=al_create_mouse_cursor(mouse,0, 0);
	if (!cursor)
	{
		fprintf(stderr, "failed to create cursor bitmap!\n");
	}

	sample = al_load_sample("resources/Sega1991.wav");
	if (!sample)
	{
		fprintf(stderr, "failed to create sample!\n");
	}

	sample2 = al_load_sample("resources/WormsReloadedOST.wav");
	if (!sample2)
	{
		fprintf(stderr, "failed to create sample2!\n");
	}

	font = al_load_font("resources/ARCADE.TTF", 72, 0);
	if (!font)
	{
		fprintf(stderr, "failed to create sega bitmap!\n");
	}

	timer1 = al_create_timer(0.5);
	if (!timer1)
	{
		fprintf(stderr, "failed to create timer1!\n");
	}
	event_queue1 = al_create_event_queue();
	if (!event_queue1)
	{
		fprintf(stderr, "failed to create eventqueue1!\n");
	}

	al_set_mouse_cursor(display, cursor);
	al_set_display_icon(display, sega);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	al_rest(2.5);
	
	al_draw_scaled_bitmap(sega,
		0, 0,                                // source origin
		al_get_bitmap_width(sega),     // source width
		al_get_bitmap_height(sega),    // source height
		largo/6, alto/4,                                // target origin
		al_get_bitmap_width(sega)*2/3, al_get_bitmap_height(sega)*0.5,                                // target dimensions
		0                                    // flags
	);

	al_flip_display();

	al_rest(2.5);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_stop_samples();
	al_destroy_sample(sample);
//=========================================================================================================================	
	al_play_sample(sample2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	
	for (int i = alto; i >= -500; i -= 10) {
		
		al_draw_bitmap(logo, largo / 3, i, 0);
		al_draw_bitmap(imagen2, largo *0.5 , i+(alto/6)+500, 0);
	
		al_flip_display();
		al_rest(0.1);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
		
	}


	al_draw_bitmap(imagen2, largo *  0.5, alto/6, 0);
	al_flip_display();
	al_rest(2);
	for (float timer = 1; timer != 100; timer++) {

		al_draw_tinted_bitmap(imagen2,
			al_map_rgba_f(1 / timer, 1 / timer, 1 / timer, 1 / timer),
			largo *0.5, alto / 6, 0);
		al_flip_display();


		al_rest(0.08);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
	}
	
	switch (rand() % 5)
	{
		case 4: {
			image = al_load_bitmap("resources/fondo0.jpg");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
		}
		case 3: {
			image = al_load_bitmap("resources/fondo1.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
		}
		case 2: {
			image = al_load_bitmap("resources/fondo2.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
		}
		case 1: {
			image = al_load_bitmap("resources/fondo3.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
		}
		case 0: {
			image = al_load_bitmap("resources/fondo4.png");
			al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
			al_flip_display();
			break;
				}
			
		}
	al_destroy_bitmap(imagen2);
	al_flip_display();
	
	
	al_register_event_source(event_queue1, al_get_display_event_source(display));
	al_register_event_source(event_queue1, al_get_timer_event_source(timer1));
	al_register_event_source(event_queue1, al_get_keyboard_event_source());
	
	al_start_timer(timer1);

	while (1)
	{
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
		al_flip_display();
		

		al_wait_for_event(event_queue1, &evIntro);

		if (evIntro.type == ALLEGRO_EVENT_TIMER) {
			al_draw_text(font, al_map_rgb(255, 255, 255), alto / 2, (largo * 5 / 6), ALLEGRO_ALIGN_CENTRE, "Press any key to continue");
			al_flip_display();
			al_rest(0.1);
		
		}
		else if (evIntro.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit(3);
		}
		else if (evIntro.type == ALLEGRO_EVENT_KEY_DOWN) {
			break;
		}
		
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, alto, largo, 0);
		al_flip_display();
		
	}
	
	al_destroy_timer(timer1);
	al_destroy_event_queue(event_queue1);
	
}