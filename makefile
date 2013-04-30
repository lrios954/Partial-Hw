a.out: pde.c
	@cc pde.c -lm
	@ ./a.out
	@python graficador.py
	
all: a.out

clean: 
	@rm -f a.out
	@rm -f *.dat
	@rm -f *.jpg

