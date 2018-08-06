

class Particle:

	def __init__(self, x, y, u=0, v=0, a_x=0, a_y=0, rho=0, m=1, ptype='fluid'):
		self.properties = {
			'x': x,
			'y': y,
			'u': u,
			'v': v,
			'a_x':a_x,
			'a_y':a_y,
			'rho':rho,
			'm':m
			'ptype':ptype
		}
		
	
	def set_properties(self, updated_properties):
		''' sets the properties of the particle '''
		if self.properties['type'] == 'boundary':
			return 

		for key in updated_properties:
				
			self.properties[key] = updated_properties[key]

	def get_properties(self):
		''' gets the properties of the particle '''
		return self.properties




	
