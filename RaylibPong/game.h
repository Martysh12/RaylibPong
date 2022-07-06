#pragma once

#include "constants.h"

#include "paddle.h"
#include "ball.h"

#include <iostream>

#include "raylib.h"

class Game
{
public:
	Game();
	~Game();

	void initSound(void);

	void start(void);
	void update(void);
	void render(void);

	void resetKeepScore(void);
	void hardReset(void);

private:
	Paddle m_leftPaddle;
	Paddle m_rightPaddle;

	Ball m_ball;

	int m_ballIFrames;

	bool m_startUpdating;

	Sound m_sndCollidePaddle;
	Sound m_sndStart;
	Sound m_sndLose;
};


