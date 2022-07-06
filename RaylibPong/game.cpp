#include "game.h"

Game::Game() :
    m_leftPaddle(false),
    m_rightPaddle(true),
    m_startUpdating(false)
{
	InitWindow(screenWidth, screenHeight, gameTitle);

    InitAudioDevice();

    if (!IsAudioDeviceReady())
    {
        std::cerr << "There was an error while initializing the audio device!" << std::endl;
        exit(1);
    }

	SetTargetFPS(60);
}

Game::~Game()
{
}

void Game::start(void)
{
    while (!WindowShouldClose())
    {
        update();
        render();
    }

    CloseWindow();
}

void Game::update(void)
{
    if (m_startUpdating)
    {
        // Check if player pressed the reset key
        if (IsKeyPressed(keyResetGame))
            hardReset();

        // Update objects
        m_leftPaddle.update();
        m_rightPaddle.update();

        m_ball.update();

        // Perform collision checks
        if (m_leftPaddle.collideRec(m_ball.getRec()) || m_rightPaddle.collideRec(m_ball.getRec()))
        {
            m_ball.flipXVel();
            m_ball.update();
        }

        // Check if ball is out of bounds and increase scores
        int ballOutOfBoundsState = m_ball.getOutOfBounds();

        switch (ballOutOfBoundsState)
        {
            case 1:
                m_rightPaddle.increaseScore();
                resetKeepScore();
                break;
            case 2:
                m_leftPaddle.increaseScore();
                resetKeepScore();
                break;
        }
    }
    else
    {
        // Check if player has pressed the start key
        if (IsKeyPressed(keyStartGame))
            m_startUpdating = true;
    }
}

void Game::render(void)
{
    BeginDrawing();
    {
        // Hide all traces of previous render
        ClearBackground(backColor);

        // Render paddles
        m_leftPaddle.render();
        m_rightPaddle.render();

        // Render text if game hasn't started yet or render the ball if it has
        if (!m_startUpdating)
            DrawText("Press SPACE to start!", (screenWidth - (22 * 10)) / 2, (screenHeight - 18) / 2, 20, mainColor);
        else
            m_ball.render();

#ifdef _DEBUG

        // Draw FPS
        DrawFPS(10, 10);

#endif // _DEBUG
    }
    EndDrawing();
}

void Game::resetKeepScore(void)
{
    m_leftPaddle.resetKeepScore();
    m_rightPaddle.resetKeepScore();

    m_ball.reset();
}

void Game::hardReset(void)
{
    m_startUpdating = false;

    m_leftPaddle.hardReset();
    m_rightPaddle.hardReset();

    m_ball.reset();
}
