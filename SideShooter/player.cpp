#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	for (int i = 0; i < 6; i++) {
		if (images[i])
			al_destroy_bitmap(images[i]);
	}
}
player::player(int HEIGHT)
{

	images[0] = al_load_bitmap("kirby4.png");
	images[1] = al_load_bitmap("kirby3.png");
	images[2] = al_load_bitmap("kirby2.png");
	images[3] = al_load_bitmap("kirby1.png");
	images[4] = al_load_bitmap("kirby0.png");
	images[5] = al_load_bitmap("Kirby.png"); // original full-health Kirby

	imageIndex = 5;
	image = images[imageIndex];


	x = 20;
	y = HEIGHT / 2;
	lives = 5;
	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	score = 0;
}
void player::DrawPlayer()
{
	al_draw_bitmap(images[imageIndex], x, y, 0);
}
void player::MoveUp()
{
	y -= speed;
	if(y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if (y > HEIGHT - boundy)
		y = HEIGHT - boundy;
}
void player::MoveLeft()
{
	x -= speed;
	if(x < 0)
		x = 0;
}
void player::MoveRight()
{
	x += speed;
	if(x > 300)
		x = 300;
}



void player::removeLife() {
	if (lives > 0)
		lives--;

	if (imageIndex > 0)
		imageIndex--;

	image = images[imageIndex];
}

