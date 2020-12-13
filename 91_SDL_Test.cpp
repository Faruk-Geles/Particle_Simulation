//============================================================================
// Name        : 91_SDL_Test.cpp
// Author      : Faruk Geles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <math.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace fg;

int main() {

	srand(time(NULL));  //seed of random number generator

	Screen screen;

	if(screen.init()==false) {
		cout << "Error initializing SDL " << endl;
	}

	//GAME LOOP
	//int max=0;

	Swarm swarm;

	while(true) {
		//Update particles


		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);


		unsigned char green = (unsigned char)((1+sin(elapsed*0.0001))*128);
		unsigned char red = (unsigned char)((1+sin(elapsed*0.0002))*128);
		unsigned char blue = (unsigned char)((1+sin(elapsed*0.0003))*128);
		//if (green>max) max=green;

		//cout <<green<<endl;

		const Particle * const pParticles = swarm.getParticles();
		for(int i=0; i<Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			//int x=(particle.m_x+1)*Screen::SCREEN_WIDTH/2;
			//int y=(particle.m_y+1)*Screen::SCREEN_HEIGHT/2;

			int x=(particle.m_x+1)*Screen::SCREEN_WIDTH/2;
			int y=particle.m_y*Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x,y,red,green,blue);

		}


		/*
		for (int y=0; y<Screen::SCREEN_HEIGHT; y++ ) {
			for(int x=0; x<Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x,y,red,green,blue);
			}
		}

		//screen.setPixel(400,300,255,255,255);
		 */
		screen.boxBlur();


		//Draw Particles
		screen.update();

		//Check for messages/even
		if(screen.processEvents()==false) {
			break;
		}

	}

	//cout << "Max" << max << endl;

	screen.close();


	return 0;
}
