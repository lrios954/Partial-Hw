a.out: pde.c
	@cc -lm pde.c
	@cc ./a.out
	@python graficador.py
	


clean: 
	@rm -f a.out
	@rm -f *.dat
	@rm -f *.jpg

