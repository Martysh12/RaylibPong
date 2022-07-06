#include "ball.h"

Ball::Ball() :
	m_x(screenWidth / 2),
	m_y(screenHeight / 2),
	m_vx(ballSpeed),
	m_vy(ballSpeed)
{
}

Ball::~Ball()
{
}

void Ball::loadSounds(void)
{
	m_sndCollideWall = LoadSound("sounds\\collide_wall.wav");
}

void Ball::update(void)
{
	m_x += m_vx;
	m_y += m_vy;

	if ((m_y - ballRadius) < 0)
	{
		m_y = -m_y;
		m_vy = -m_vy;

		PlaySound(m_sndCollideWall);
	}
	else if ((m_y + ballRadius) > screenHeight)
	{
		m_y = screenHeight * 2 - ballRadius * 2 - m_y;
		m_vy = -m_vy;

		PlaySound(m_sndCollideWall);
	}
}

void Ball::render(void)
{
	DrawCircle(m_x, m_y, ballRadius, mainColor);
}

void Ball::reset(void)
{
	m_x = screenWidth / 2;
	m_y = screenHeight / 2;

	m_vx = ballSpeed;
	m_vy = ballSpeed;
}

Rectangle Ball::getRec(void)
{
	Rectangle ballRec;
	ballRec.x = m_x - ballRadius;
	ballRec.y = m_y - ballRadius;
	ballRec.width = ballRadius * 2;
	ballRec.height = ballRadius * 2;

	return ballRec;
}

void Ball::flipXVel(void)
{
	m_vx = -m_vx;
}

int Ball::getOutOfBounds(void)
{
	if ((m_x + ballRadius) < 0)
		return 1;
	else if ((m_x - ballRadius) > screenWidth)
		return 2;
	else
		return 0;
}
