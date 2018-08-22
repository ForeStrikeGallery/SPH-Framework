#include "particle.h"
#include<iostream>
#include<vector>

//Constructor
Particle :: Particle(float m, int type=0) {
	this->m = m;
	this->ptype=type;
}

// Getters

float Particle :: getPressure() {
	return this->pressure;
}

int Particle :: getType() {
	return ptype;
}

float Particle :: getDensity() {
        return rho;
}

pair<float, float> Particle :: getPosition() {
        return position;
}

pair<float, float> Particle :: getVelocity() {
        return velocity;
}

pair<float, float> Particle :: getForce() {
        return force;
}

float Particle :: getKernelLength() {
	return h;
}

float Particle :: getMass() {
	return m;
}

//Setters
void Particle :: setPressure(float pressure) {
	this->pressure = pressure;
}

void Particle :: setDensity(float rho) {
        this->rho = rho;
}

void Particle :: setKernelLength(float h) {
	this->h = h;
}

void Particle :: setPosition(pair<float, float> position) {
        this->position = position;
}

void Particle :: setVelocity(pair<float, float> velocity) {
        this->velocity = velocity;
}

void Particle :: setForce(pair<float, float> force) {
        this->force = force;
}


