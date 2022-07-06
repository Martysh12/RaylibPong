#include "paddle.h"

Paddle::Paddle(bool side) :
	m_side(side),
	m_y((screenHeight - paddleSize) / 2),
	m_score(0)
{
}

Paddle::~Paddle()
{
}

void Paddle::update(void)
{
	if (m_side ? IsKeyDown(rightPaddleKeyUp) : IsKeyDown(leftPaddleKeyUp))
		m_y -= paddleSpeed;
	
	if (m_side ? IsKeyDown(rightPaddleKeyDown) : IsKeyDown(leftPaddleKeyDown))
		m_y += paddleSpeed;

	// clamp time

	m_y = m_y < 0 ? 0 : m_y;
	m_y = m_y > (screenHeight - paddleSize) ? screenHeight - paddleSize : m_y;
}

void Paddle::render(void)
{
	int x = calculateX();

	Color color1 = m_side ? mainColor : backColor;
	Color color2 = m_side ? backColor : mainColor;

	DrawRectangleGradientH(x, m_y, paddleWidth, paddleSize, color1, color2);
	DrawText(std::to_string(m_score).c_str(), x + ((paddleWidth - 10) / 2), m_y + (paddleSize / 2) - 8, 20, backColor);
}

void Paddle::resetKeepScore(void)
{
	m_y = (screenHeight - paddleSize) / 2;
}

void Paddle::hardReset(void)
{
	resetKeepScore();
	m_score = 0;
}

void Paddle::increaseScore(void)
{
	m_score++;
}

int Paddle::calculateX(void)
{
	return m_side ? (screenWidth - paddlePadding - paddleWidth) : paddlePadding;
}

bool Paddle::collideRec(Rectangle rec)
{
	Rectangle paddleRec;
	paddleRec.x = calculateX();
	paddleRec.y = m_y;
	paddleRec.width = paddleWidth;
	paddleRec.height = paddleSize;

	return CheckCollisionRecs(paddleRec, rec);
}
