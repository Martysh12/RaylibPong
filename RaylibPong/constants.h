#pragma once

#include "raylib.h"

constexpr int screenWidth = 800;
constexpr int screenHeight = 450;

constexpr char const* gameTitle = "Pong";

constexpr int keyStartGame = KEY_SPACE;
constexpr int keyResetGame = KEY_R;

constexpr int leftPaddleKeyUp = KEY_W;
constexpr int leftPaddleKeyDown = KEY_S;

constexpr int rightPaddleKeyUp = KEY_UP;
constexpr int rightPaddleKeyDown = KEY_DOWN;

constexpr int paddleSize = 50;
constexpr int paddleWidth = 20;
constexpr int paddlePadding = 20;

constexpr int paddleSpeed = 7;

constexpr int ballRadius = 7;
constexpr int ballSpeed = 4;

constexpr Color mainColor = RAYWHITE;
constexpr Color backColor = BLACK;
