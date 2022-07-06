#pragma once

#include "constants.h"

#include "paddle.h"
#include "ball.h"

#include "raylib.h"

class Game
{
public:
	Game();
	~Game();

	void start(void);
	void update(void);
	void render(void);

	void resetKeepScore(void);
	void hardReset(void);

private:
	Paddle m_leftPaddle;
	Paddle m_rightPaddle;

	Ball m_ball;

	bool m_startUpdating;
};


