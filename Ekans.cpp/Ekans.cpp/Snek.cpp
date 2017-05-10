#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <vector>
using namespace std;
int SCREEN_W = 800;
int SCREEN_H = 800;
int head_x;
int head_y;
int goal_x;
int goal_y;
bool key[4]{ false, false, false, false };
int snake_length;
bool Eatgoal = false;
bool doexit = false;

vector<int>nodes;
vector<int>::const_iterator iter;




int main() {
	ALLEGRO_DISPLAY*display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_BITMAP*snake = NULL;
	ALLEGRO_FONT*font = NULL;
	ALLEGRO_SAMPLE*bite = NULL;
	ALLEGRO_SAMPLE*music = NULL;
	ALLEGRO_SAMPLE_INSTANCE*background = NULL;
	ALLEGRO_TIMER*timer = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;








	al_init();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_reserve_samples(2);
//	music = al_load_sample("music.wav");
//  al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	font = al_create_builtin_font();
	timer = al_create_timer(0.02);
	display = al_create_display(SCREEN_W, SCREEN_H);

	int grid[20][20];
	for (int i = 0; i > 20; i++)
		for (int j = 0; j > 20; j++)
			grid[i][j] = 0;

	grid[goal_x][goal_y] = 2;
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

	while (doexit != false) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++)
				cout << grid[i][j] << endl;
		}
//		if (ev.type == ALLEGRO_EVENT_TIMER) {
//			for (int i = 0; i < 20; i++)
//				for (int j = 0; j < 20; j++) {
//					if (grid [i][j] == 1)

//				}
		for (int i = 0; i < snake_length; i = i+2){
			grid[nodes[i]][nodes[i + 1]] = 1;
	}
		if (Eatgoal == true) {
			grid[goal_x][goal_y] = 0;
			goal_x = rand() % 20;
			goal_y = rand() % 20;
			grid[goal_x][goal_y] = 2;
			Eatgoal = false;
			cout << "Goal @ " << goal_x << ", " << goal_y << endl;
		}

		















	}


}




