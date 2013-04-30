a.out: condicionesIniciales.o pde.o
	@cc condicionesIniciales.o pde.o
	@cc ./a.out
	
condicionesIniciales.o: condicionesIniciales.c
	@cc -lm condicionesIniciales.c

pde.o: pde.c
	@cc -lm pde.c

clean: 
	@rm -f a.out
	@rm -f *.dat
	@rm -f *.jpg

