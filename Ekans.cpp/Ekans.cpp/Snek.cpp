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





int main() {
	int SCREEN_W = 800;
	int SCREEN_H = 800;
	int head_x = 1;
	int head_y = 1;
	int snak_x = 2;
	int snak_y = 2;
	int sneksize = 40;
	bool key[4]{ false, false, false, false };
	int snake_length = 2;
	bool Eatgoal = false;
	bool doexit = false;
	bool redraw = true;
	ALLEGRO_DISPLAY*display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_BITMAP*snake = NULL;
	ALLEGRO_FONT*font = NULL;
	ALLEGRO_SAMPLE*bite = NULL;
	ALLEGRO_SAMPLE*music = NULL;
	ALLEGRO_SAMPLE_INSTANCE*background = NULL;
	ALLEGRO_TIMER*timer = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;

	vector<int>nodes;
	vector<int>::const_iterator iter;







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

	grid[snak_x][snak_y] = 2;
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

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++) {
					//					if (grid[i][j] == 1)

				}
			for (int i = 0; i < snake_length; i = i + 2) {
				grid[nodes[i]][nodes[i + 1]] = 1;
			}

			if (grid[snak_x] == grid[head_x] && grid[snak_y] == grid[head_y]) {
				Eatgoal = true;
				snake_length += 2;
			}


			if (Eatgoal == true) {
				grid[snak_x][snak_y] = 0;
				snak_x = rand() % 20;
				snak_y = rand() % 20;
				grid[snak_x][snak_y] = 2;
				Eatgoal = false;
				cout << "Goal @ " << snak_x << ", " << snak_y << endl;
			}

			if (key[0])
				head_y -= 1;
			else if (key[1])
				head_y += 1;
			else if (key[2])
				head_x -= 1;
			else if (key[3])
				head_x += 1;




			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

				//"keycode" holds all the different keys on the keyboard
				switch (ev.keyboard.keycode) {

					//if the up key has been pressed
				case ALLEGRO_KEY_UP:
					key[0] = true;
					key[1] = false;
					key[2] = false;
					key[3] = false;
					break;

					//if the down key has been pressed
				case ALLEGRO_KEY_DOWN:
					key[1] = true;
					key[2] = false;
					key[3] = false;
					key[0] = false;
					break;

					//if the left key has been pressed
				case ALLEGRO_KEY_LEFT:
					key[2] = true;
					key[3] = false;
					key[0] = false;
					key[1] = false;
					break;

					//if the right key has been pressed
				case ALLEGRO_KEY_RIGHT:
					key[3] = true;
					key[0] = false;
					key[1] = false;
					key[2] = false;
					break;
				}

			}
			//has something been released on the keyboard?
			else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					key[0] = false;
					break;

				case ALLEGRO_KEY_DOWN:
					key[1] = false;
					break;

				case ALLEGRO_KEY_LEFT:
					key[2] = false;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[3] = false;
					break;

					//kill the program if someone presses escape
				case ALLEGRO_KEY_ESCAPE:
					doexit = true;
					break;
				}
			}

			if (head_x > 0 &&
				head_y > 0 &&
				head_x < 20 &&
				head_y < 20)
				grid[head_x][head_y] = 1;

			nodes.insert(nodes.begin(), head_y);
			nodes.insert(nodes.begin(), head_x);

			if (head_x < 0 || head_y < 0)
				cout << "MATRIX ERROR" << endl;

			if (head_x < 0 || head_x > 20 || head_y < 0 || head_y > 20) {
				cout << "Hit a wall, snek is ded" << endl;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_textf(font, al_map_rgb(255, 100, 100), 300, 300, NULL, "Snek done dedded dude");
				al_flip_display();
				al_rest(2);
				return 0;
			}

			for (iter = nodes.begin() + 2; iter < nodes.end(); iter += 2) {
				cout << "Head id " << head_x << ", " << head_y << endl;
				cout << "Node values are " << *iter << ", " << *(iter + 1) << endl;


				if ((head_x == *iter &&  head_y == *(iter + 1))) {
					cout << "Snek tail killed snek" << endl;
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_textf(font, al_map_rgb(255, 100, 100), 300, 300, NULL, "Sned done dedded dude");
					al_flip_display();
					al_rest(2);
					return 0;
				}
			}
			nodes.erase(nodes.begin() + snake_length, nodes.end());
			redraw = true;






		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			if (Eatgoal == false)
				grid[snak_x][snak_y] = 2;
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++) {
					if (grid[i][j] == 1)
						al_draw_filled_rectangle(i*sneksize, j*sneksize, i*sneksize + sneksize, j*sneksize + sneksize, al_map_rgb(50, 250, 50));
					if (grid[i][j] == 0)
						al_draw_rectangle(i*sneksize, j*sneksize, i*sneksize + sneksize, j*sneksize + sneksize, al_map_rgb(250, 250, 250), 4);
					if (grid[i][j] == 2)
						al_draw_filled_rectangle(i*sneksize, j*sneksize, i*sneksize + sneksize, j*sneksize + sneksize, al_map_rgb(100, 100, 150));
					if (Eatgoal = true)
						grid[snak_x][snak_y] = 0;
					al_flip_display();
				}
		}
	}
	al_destroy_bitmap(snake);
	al_destroy_timer(timer);
	al_destroy_display(display);
}

