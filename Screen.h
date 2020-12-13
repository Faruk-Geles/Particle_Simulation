/*
 * Screen.h
 *
 *  Created on: 14.10.2020
 *      Author: faruk
 */



#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL.h>
using namespace std;


namespace fg {
class Screen {
private:

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

	/*Uint32 *m_frontBuffer;
	Uint32 *m_backBuffer;

	const static int short RED_SHIFT=24;
	const static int short GREEN_SHIFT=16;
	const static int short BLUE_SHIFT=8;*/

public:

	const static int SCREEN_WIDTH=800;
	const static int SCREEN_HEIGHT=600;


	Screen();
	virtual ~Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
	void clear();
	void boxBlur();

};


} //end namespace;
#endif /* SCREEN_H_ */


