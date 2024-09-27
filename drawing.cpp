#include "../include/vars.h"
#include "../include/enums.h"
#include "../include/natives.h"
#include "../include/drawing.h"
#include "../include/gameFunctions.h"

void SET_TEXT_JUSTIFICATON(int type) {
	setTextData->justification = type;
}

void SET_TEXT_FONT(int fontId) {
	setTextData->font = fontId;
}

void SET_TEXT_WRAP(float start, float end) {
	setTextData->wrap_start = start;
	setTextData->wrap_end = end;
}

void SET_TEXT_SCALE_s(float scale, float scale2) {
	setTextData->text_scale = scale;
	setTextData->text_scale2 = scale2;
}

void SET_TEXT_COLOR_s(int r, int g, int b, int a) {
	fcolor fontColor;
	fontColor.r = r;
	fontColor.g = g;
	fontColor.b = b;
	fontColor.a = a;
	setTextData->color = fontColor;
}

void DRAW_TEXT_OPTION(char* text, int Font, float x, float y, float scalex, float scaley, int a, bool center, bool UseEdge, int RD, int GD, int BD) {
	SET_TEXT_FONT(Font);
	if (SelectedItem) {
		SET_TEXT_SCALE_s(0.45, 0.45);
		SET_TEXT_COLOR_s(SelClrR, SelClrG, SelClrB, 255);
	} else {
		SET_TEXT_SCALE_s(scalex, scaley);
		SET_TEXT_COLOR_s(236, 240, 241, 255);
	}
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATON(!center);
	const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	#if GAME_VERSION != 129
	DRAW_TEXT(str, x, y);
	#else
	_BG_DISPLAY_TEXT(str, x, y);
	#endif
}

void DRAW_TEXT(const char* text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge, int RD, int GD, int BD) {
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE_s(scalex, scaley);
	SET_TEXT_COLOR_s(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATON(!center);
	const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	#if GAME_VERSION != 129
	DRAW_TEXT(str, x, y);
	#else
	_BG_DISPLAY_TEXT(str, x, y);
	#endif
}

void DRAW_TEXT2(char* text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center) {
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE_s(scalex, scaley);
	SET_TEXT_COLOR_s(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATON(!center);
	const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	#if GAME_VERSION != 129
	DRAW_TEXT(str, x, y);
	#else
	_BG_DISPLAY_TEXT(str, x, y);
	#endif
}
void drawFloat(float Val, bool center, float x, float y, float scalex, float scaley, int r, int b, int g, int a) {
	char buf[255];
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE_s(scalex, scaley);
	SET_TEXT_COLOR_s(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATON(!center);
	snprintf_hook(buf, sizeof(buf), "%.2f", Val);
	const char* str = CREATE_STRING(10, "LITERAL_STRING", buf);
	#if GAME_VERSION != 129
	DRAW_TEXT(str, x, y);
	#else
	_BG_DISPLAY_TEXT(str, x, y);
	#endif
}

void drawNumber(int Val, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, int center) {
	char buf[255];
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE_s(scalex, scaley);
	SET_TEXT_COLOR_s(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATON(!center);
	snprintf_hook(buf, sizeof(buf), "%i", Val);
	const char* str = CREATE_STRING(10, "LITERAL_STRING", buf);
	#if GAME_VERSION != 129
	DRAW_TEXT(str, x, y);
	#else
	_BG_DISPLAY_TEXT(str, x, y);
	#endif
}

void drawTextCounter(char* text, int Font, float x, float y, float scalex, float scaley, int r, int b, int g, int a) {
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE_s(scalex, scaley);
	SET_TEXT_COLOR_s(r, g, b, a);
	SET_TEXT_JUSTIFICATON(0);
	const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	#if GAME_VERSION != 129
	DRAW_TEXT(str, x, y);
	#else
	_BG_DISPLAY_TEXT(str, x, y);
	#endif
}

void DrawSprite(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a) {
	if (!HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) {
		REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, 0);
	} else {
		DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a, 0);
	}
}
