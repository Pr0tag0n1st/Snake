#include <vector>
#include <ctime>
#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
int main() {
	int SCREEN_W = 800;
	int SCREEN_H = 800;
	int snak_x;
	int snak_y;
	int snek_x;
	int snek_y;
	int clock;
	int sneksize = 40;
	int sneklength = 2;
	bool key[4]{ false, false, false, false };
	bool EatSnak = false;
	bool doexit = false;

	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_install_keyboard();
	vector<int>nodes;
	vector<int>::const_iterator iter;

	ALLEGRO_DISPLAY*display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_BITMAP*snake = NULL;
	ALLEGRO_BITMAP*snak = NULL;
	ALLEGRO_FONT*font = al_create_builtin_font();
	ALLEGRO_SAMPLE*bite = NULL;
	ALLEGRO_SAMPLE*music = NULL;
	ALLEGRO_SAMPLE_INSTANCE*background = NULL;
	ALLEGRO_TIMER*timer = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;

	al_reserve_samples(2);
//	music = al_load_sample
	timer = al_create_timer(clock);


	int grid[20][20];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			grid[i][j] = 0;

	grid[snak_x][snak_y = 2];
	srand(time(NULL));
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_reserve_samples(10);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);
	while (doexit == false) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++)
				cout << grid[i][j];
			cout << endl;
		}
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			for (int i = 0; i < 20; i ++)
				for (int j = 0; j < 20; j ++)
					if (grid[i][j] == 1)
						+
		}
	}
















}