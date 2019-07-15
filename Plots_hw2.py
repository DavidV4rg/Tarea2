import numpy as np
import matplotlib.pylab as plt

euler1 = np.genfromtxt("euler.dat", delimiter= ";")
LF1 = np.genfromtxt("LF.dat", delimiter = ";")
RK1 = np.genfromtxt("RK.dat", delimiter = ";")

tiempo_e1 = euler1[:,0]
x_e1 = euler1[:,1]
y_e1 = euler1[:,2]
vx_e1 = euler1[:,3]
vy_e1 = euler1[:,4]

tiempo_LF1 = LF1[:,0]
x_LF1 = LF1[:,1]
y_LF1 = LF1[:,2]
vx_LF1 = LF1[:,3]
vy_LF1 = LF1[:,4]

tiempo_RK1 = RK1[:,0]
x_RK1 = RK1[:,1]
y_RK1 = RK1[:,2]
vx_RK1 = RK1[:,3]
vy_RK1 = RK1[:,4]

