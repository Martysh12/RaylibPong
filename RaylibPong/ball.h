#pragma once

#include "constants.h"

#include <iostream>

class Ball
{
public:
	Ball();
	~Ball();

	void update(void);
	void render(void);
	
	void reset(void);

	Rectangle getRec(void);

	void flipXVel(void);

	int getOutOfBounds(void);


private:
	int m_x;
	int m_y;

	int m_vx;
	int m_vy;

	Sound m_sndCollideWall;
};
