#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <math.h>
#include "Status.h"
#include "Animate.h"


// screen size
#define winx 500
#define winy 500

//coord dir
enum { UP, DOWN, LEFT, RIGHT, UPRIGHT, DOWNRIGHT, UPLEFT, DOWNLEFT };

//kinds of weapon
enum {PRIME, SECONDARY};

//animation for laser
enum { BLUE, YELLOW, RED };

enum {X, Y};

//enemies
enum {
	BLOBBY, ASTERIX, EPOLICE, JUPIBALL,
	KAMEKOSET, MPOLICE, SATUSPHERE, SPYDER,
	SPACESHIP, VOLCANON, WYRM, XYBTOFY
};

//miniboss
enum { E, M };

//bosses
enum {SPARTAK, MARTIANB, KAMETKHAN, XORGANA};

//weapon
enum{ICET=1, INFERRED, ZIGGONET, HAYCH, HAYCHBA, SONICWAVE, LAZER};

//ammo and tools
enum {HEALTH, DISFIG, ICE=5, FIRE=7, ZIG=9, H=11, HBAR=13, WAVE = 15};

//status
enum {FROZEN = 11, BURNED, STUNNED};

//choice for boss
enum {ATTACK, MOVE};

//boss's attack moves
enum {BALL, DIAMONDS, S_LAZER, CHARGE, EGG, TURBULENCE, B_LAZER, MOLTEN, KAMET, HEAT, SINGTW, V};

