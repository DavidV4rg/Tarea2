import numpy as np
import matplotlib.pylab as plt

euler1 = np.genfromtxt("euler1.dat", delimiter= "||")
LF1 = np.genfromtxt("LF1.dat", delimiter = "||")
RK1 = np.genfromtxt("RK1.dat", delimiter = "||")

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

euler2 = np.genfromtxt("euler2.dat", delimiter= "||")
LF2 = np.genfromtxt("LF2.dat", delimiter = "||")
RK2 = np.genfromtxt("RK2.dat", delimiter = "||")

tiempo_e1 = euler2[:,0]
x_e2 = euler2[:,1]
y_e2 = euler2[:,2]
vx_e2 = euler2[:,3]
vy_e2 = euler2[:,4]

tiempo_LF2 = LF2[:,0]
x_LF2 = LF2[:,1]
y_LF2 = LF2[:,2]
vx_LF2 = LF2[:,3]
vy_LF2 = LF2[:,4]

tiempo_RK2 = RK2[:,0]
x_RK2 = RK2[:,1]
y_RK2 = RK1[:,2]
vx_RK2 = RK2[:,3]
vy_RK2 = RK2[:,4]

euler3 = np.genfromtxt("euler3.dat", delimiter= "||")
LF3 = np.genfromtxt("LF3.dat", delimiter = "||")
RK3 = np.genfromtxt("RK3.dat", delimiter = "||")

tiempo_e3 = euler3[:,0]
x_e3 = euler3[:,1]
y_e3 = euler3[:,2]
vx_e3 = euler3[:,3]
vy_e3 = euler3[:,4]

tiempo_LF3 = LF3[:,0]
x_LF3 = LF3[:,1]
y_LF3 = LF3[:,2]
vx_LF3 = LF3[:,3]
vy_LF3 = LF3[:,4]

tiempo_RK3 = RK3[:,0]
x_RK3 = RK3[:,1]
y_RK3 = RK3[:,2]
vx_RK3 = RK3[:,3]
vy_RK3 = RK3[:,4]