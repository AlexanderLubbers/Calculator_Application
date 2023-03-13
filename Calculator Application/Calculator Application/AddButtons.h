#pragma once
#include "Windows.h"
#include "resource.h"

//HMENU constants for the buttons
#define LEFT_PARENTHESES_PRESSED 301
#define RIGHT_PARENTHESES_PRESSED 302
#define DECIMAL_PRESSED 303
#define NEGATIVE_PRESSED 304
#define HISTORY_PRESSED 305
#define CLEAR_PRESSED 306
#define SQROOT_PRESSED 307
#define SEVEN_PRESSED 308
#define EIGHT_PRESSED 309
#define NINE_PRESSED 310
#define DIVIDE_PRESSED 311
#define PI_PRESSED 312
#define EXPONENT_PRESSED 313
#define FOUR_PRESSED 314
#define FIVE_PRESSED 315
#define SIX_PRESSESD 316
#define MULTIPLY_PRESSED 317
#define SINE_PRESSED 318
#define E_PRESSED 319
#define ONE_PRESSED 320
#define TWO_PRESSED 321
#define THREE_PRESSED 322
#define SUBTRACT_PRESSED 323
#define COSINE_PRESSED 324
#define LOG_PRESSED 325
#define LOGBASE_PRESSED 326
#define ZERO_PRESSED 327
#define COMMA_PRESSED 328
#define ADD_PRESSED 329
#define TANGENT_PRESSED 330
#define INVERSE_SINE_PRESSED 331
#define INVERSE_COSINE_PRESSED 332
#define INVERSE_TANGENT_PRESSED 333
#define DELETE_PRESSED 334

class AddButtons {
public:
	void button(HWND hWnd);
};

