/*
 * Particle.cpp
 *
 *  Created on: 15.10.2020
 *      Author: faruk
 */

#include "Particle.h"
//#include <stdlib.h>
#include <iostream>
#include <math.h>

namespace fg {

Particle::Particle():m_x(0),m_y(0) {
	init();
	//m_direction=(2*M_PI*rand())/RAND_MAX;
	//m_speed = (0.0004*rand())/RAND_MAX;

	//m_x = ((2.0*rand())/RAND_MAX)-1;
	//m_y = ((2.0*rand())/RAND_MAX)-1;

	//m_xspeed=0.001*(((2.0*rand())/RAND_MAX)-1);
	//m_yspeed=0.001*(((2.0*rand())/RAND_MAX)-1);

}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}


void Particle::init() {
	m_x=0;
	m_y=0;
	m_direction=(2*M_PI*rand())/RAND_MAX;
	m_speed = (0.0004*rand())/RAND_MAX;

}



void Particle::update(int interval) {

	m_direction += interval*0.0004;


	double xspeed=m_speed*cos(m_direction);
	double yspeed=m_speed*sin(m_direction);

	m_x += xspeed*interval;
	m_y += yspeed*interval;

	if(m_x<=-1 || m_x>=1.0 || m_y<=-1 || m_y>=1.0 ) {
		//m_xspeed = -m_xspeed;
		init();
	}

	if(rand()<RAND_MAX/100) {
		init();
	}

}


/*
void Particle::update() {

	m_x += m_xspeed;
	m_y += m_yspeed;

	if(m_x<=-1 || m_x>=1.0) {
		m_xspeed = -m_xspeed;
	}

	if(m_y<=-1 || m_y>=1.0) {
		m_yspeed = -m_yspeed;
	}
}*/

} /* namespace fg */
