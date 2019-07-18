FFT2D1-2.pdf: cara_03_grisesMF.png cara_02_grisesMF.png Fourier.py
	python Fourier.py
    
frecuencias.pdf: cara_03_grisesMF.png cara_02_grisesMF.png Fourier.py
	python Fourier.py
    
filtros.pdf: cara_03_grisesMF.png cara_02_grisesMF.png Fourier.py
	python Fourier.py

filtradas.pdf: cara_03_grisesMF.png cara_02_grisesMF.png Fourier.py
	python Fourier.py

Primer_dt.pdf: Euler1.dat LF1.dat RK1.dat Plots_hw2.py ODEs.cpp 
	python Plots_hw2.py
%.dat: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    
Segundo_dt.pdf: Euler2.dat LF2.dat RK2.dat Plots_hw2.py ODEs.cpp 
	python Plots_hw2.py
%.dat: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    
Tercer_dt.pdf: Euler3.dat LF3.dat RK3.dat Plots_hw2.py ODEs.cpp
	python Plots_hw2.py
%.dat: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    
