/*
 * Swarm.cpp
 *
 *  Created on: 15.10.2020
 *      Author: faruk
 */

#include "Swarm.h"

namespace fg {

Swarm::Swarm():lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];  //allocate memory

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval=elapsed-lastTime;
	for(int i=0; i<Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
	lastTime=elapsed;

}


} /* namespace fg */
