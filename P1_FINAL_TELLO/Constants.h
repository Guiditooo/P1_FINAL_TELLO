#ifndef CONSTANTS_H
#define CONSTANTS_H

// Creada para no modificar la librería.

struct Vector2
{
	int x, y;
};
struct Vector3
{
	int x, y, z;
};
struct Vector4
{
	int x, y, x2, y2;
};

const int TARGET_WIN_CONDITION = 15;

const int KEY_SPACE = 32;
const int KEY_A = 97;
const int KEY_D = 100;

const int FRAME_WIDTH = 80;
const int FRAME_HEIGHT = 50;

const int BULLET_COUNT = 10;

const int PLAYER_WIDTH = 5;
const int PLAYER_HEIGHT = 3;

const int ASTEROID_COUNT = 10;
const int ASTEROID_MAX_SPEED = 3;
const int ASTEROID_MIN_SPEED = 1;

const int HUD_WIDTH = 20;
const int HUD_HEIGHT = 20;
const int HUD_POS_X = FRAME_WIDTH + 2;
const int HUD_POS_Y = 2;
const int HUD_HEART_ID = 3;

#endif