/*
 * Particle.h
 *
 *  Created on: 15.10.2020
 *      Author: faruk
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace fg {

struct Particle {

//public:
	double m_x;
	double m_y;

private:
	void init();
	double m_speed;
	double m_direction;
	//double m_xspeed;
	//double m_yspeed;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
	//void init();
};

} /* namespace fg */

#endif /* PARTICLE_H_ */
