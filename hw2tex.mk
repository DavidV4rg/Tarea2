Resultados_hw2.pdf: Resultados_hw2.tex FtIm.pdf ImProceso.pdf ImHybrid.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf
	pdflatex Resultados_hw2.tex 
FFtIm.pdf ImProceso.pdf ImHybrid.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf: Fourier.py Plots_hw2.py Euler1.dat LF1.dat RK1.dat Euler2.dat LF2.dat RK2.dat Euler3.dat LF3.dat RK3.dat
	python Fourier.py
	python Plots_hw2.py    
%.dat: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp
    