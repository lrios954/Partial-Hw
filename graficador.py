import pylab
import numpy
import matplotlib.pyplot as plt

time_interval = 3.0/10.0
n_points = 1000;

fig1 = plt.figure()

for i in range(0, 10):

	data = numpy.loadtxt(open(str(i) + ".dat", "r"))
	u = data[:, 1]
	x = data[:, 0]
			
	plt.plot(x, u)

plt.show()
fig1.savefig("u_x1.png")
plt.close()

fig2 = plt.figure()
for i in range(11, 20):

	data = numpy.loadtxt(open(str(i) + ".dat", "r"))
	u = data[:, 1]
	x = data[:, 0]
			
	plt.plot(x, u)

plt.show()
fig2.savefig("u_x2.png")
plt.close()
	
	
