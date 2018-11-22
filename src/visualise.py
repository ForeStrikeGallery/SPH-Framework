import matplotlib.pyplot as plt


def visualise_system(filename):

	X_fluid = []
	Y_fluid = []

	X_bound = [] 
	Y_bound = []

	with open(filename) as f:
		for line in f:
			vals = [float(i) for i in line.split()]
			if vals[2] == 0.0:
				X_fluid.append(vals[0])
				Y_fluid.append(vals[1])
			elif vals[2] == 1.0:
				X_bound.append(vals[0])
				Y_bound.append(vals[1])


	plt.scatter(X_fluid, Y_fluid, color='blue')
	plt.scatter(X_bound, Y_bound, color='red') 
	plt.show()
	


if __name__ == '__main__':
	filename = 'test4.txt'
	visualise_system(filename)
