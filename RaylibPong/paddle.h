#pragma once

#include "constants.h"

#include "raylib.h"

#include <string>

class Paddle
{
public:
	Paddle(bool side);
	~Paddle();

	void update(void);
	void render(void);

	void resetKeepScore(void);
	void hardReset(void);

	void increaseScore(void);

	int calculateX(void);

	bool collideRec(Rectangle rec);

private:
	bool m_side;
	int m_y;
	int m_score;
};
