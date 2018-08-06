from particle import Particle
from integrator import Integrator
from utilities import euclidean_distance 
from operator import itemgetter

class ParticleSystem:

	def __init__(self, h, initial_particle_properties):
		'''
			Constructor that initialised the system
			with the initial properties for all the 
			particles in the system, and the kernel 
			width. 
		'''
		self.h = h
		self.count = len(initial_particle_properties)
		self.particles = []
		for particle_properties in initial_particle_properties:
			new_particle = Particle(particle_properties)
			self.particle.append(new_particle)


	def update_system_properties(self, steps=1):
		'''
			Updated the properties of all the particles in
			the system according to the integrator scheme provided
			in the integrator class
		'''
		updated_properties = {}
		integrator = Integrator()

		for particle in self.particles:
			neighbours = self.get_neighbours(particle)
			updated_properties = integrator.get_updated_properties\
					(particle, neighbours, self.h, \
						kernel='cubic-spline')
			particle.set_properties(udated_properties)
		
		
	def get_neighbours(self, particle):
		'''
			Gets the position of 'particle' and finds the closest
			particles near it that have euclidean distances between
			them less than the kernel width 'h'

			This algorithm is very slow, it runs in O(N). To find the
			neighbours for all the particles in the system, it will then
			take O(N^2). Hence, the number of particles used for the 
			simulation cannot go beyond a few thousands.

			Spatial hashing can be implemented to make it faster
		'''
		center_properties = particle.get_properties()
		center_x = center_properties['x']
		center_y = center_properties['y']
		

		all_particle_properties = [p.get_properties() for p in
						self.particles]
		distances_from_center = [euclidean_distance(center_x, center_y, p['x'], p['y'] \
					for p in all_particle_properties]
		particles_and_distance = zip(self.particles, distances_from_center)
		sorted_particles = sorted(particles_and_distance, key=itemgetter(1))
		neighbours = []
		for particle, distance in sorted_particles:
			if distance < self.h:
				neighbours.append(particle)
			else:
				break

		return neighbours	
		
					
			
	def collision_detection(self):

							
