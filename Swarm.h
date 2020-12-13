/*
 * Swarm.h
 *
 *  Created on: 15.10.2020
 *      Author: faruk
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace fg {

class Swarm {
private:
	Particle * m_pParticles;
	int lastTime;
public:
	const static int NPARTICLES=5000;
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const Particle *const getParticles() {return m_pParticles;};
};

} /* namespace fg */

#endif /* SWARM_H_ */
