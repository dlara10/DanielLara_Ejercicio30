movie.gif: adveccion.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: DanielLara_Ejercicio30.cpp
	g++ DanielLara_Ejercicio30.cpp

clean:
	rm -rf a.out adveccion.dat movie.gif *~