import pylab
import numpy


time_interval = 3.0/10.0
n_points = 1000;

data = numpy.loadtxt(open("inicial1.dat", "r"))
u = data[:, 1]
x = data[:, 0]
	
pylab.plot(x, u)
pylab.xlabel('x')
pylab.ylabel('u(x)')
pylab.title('x-u_1')
pylab.savefig('x-u_1.png')
	
	
