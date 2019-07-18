import numpy as np
import matplotlib.pylab as plt

euler1 = np.genfromtxt("Euler1.dat", delimiter= "||")
LF1 = np.genfromtxt("LF1.dat", delimiter = "||")
RK1 = np.genfromtxt("RK1.dat", delimiter = "||")

tiempo_e1 = euler1[:,0]
x_e1 = euler1[:,1]
y_e1 = euler1[:,2]
vx_e1 = euler1[:,3]
vy_e1 = euler1[:,4]
ma_e1 = euler1[:,5]
ep_e1 = euler1[:,6]
el_e1 = euler1[:,7]
ener_e1 = ep_e1+el_e1

tiempo_LF1 = LF1[:,0]
x_LF1 = LF1[:,1]
y_LF1 = LF1[:,2]
vx_LF1 = LF1[:,3]
vy_LF1 = LF1[:,4]
ma_LF1 = LF1[:,5]
ep_LF1 = LF1[:,6]
el_LF1 = LF1[:,7]
ener_LF1 = ep_LF1+el_LF1

tiempo_RK1 = RK1[:,0]
x_RK1 = RK1[:,1]
y_RK1 = RK1[:,2]
vx_RK1 = RK1[:,3]
vy_RK1 = RK1[:,4]
ma_RK1 = RK1[:,5]
ep_RK1 = RK1[:,6]
el_RK1 = RK1[:,7]
ener_RK1 = ep_RK1+el_RK1

plt.figure(figsize=(18,14))
plt.subplot(3,4,1)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Euler)$")
plt.plot(x_e1, y_e1, color= "navy")

plt.subplot(3,4,2)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Euler)$")
plt.plot(vx_e1, vy_e1, color= "plum")

plt.subplot(3,4,3)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Euler)$")
plt.plot(tiempo_e1, ma_e1, color= "lightcoral")

plt.subplot(3,4,4)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Euler)$")
plt.plot(tiempo_e1, ener_e1, color= "darkseagreen")

plt.subplot(3,4,5)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Leap Frog)$")
plt.plot(x_LF1, y_LF1, color= "navy")

plt.subplot(3,4,6)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Leap Frog)$")
plt.plot(vx_LF1, vy_LF1, color= "plum")

plt.subplot(3,4,7)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Leap Frog)$")
plt.plot(tiempo_LF1, ma_LF1, color= "lightcoral")

plt.subplot(3,4,8)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Leap Frog)$")
plt.plot(tiempo_LF1, ener_LF1, color= "darkseagreen")

plt.subplot(3,4,9)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Runge Kutta)$")
plt.plot(x_RK1, y_RK1, color= "navy")

plt.subplot(3,4,10)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Runge Kutta$")
plt.plot(vx_RK1, vy_RK1, color= "plum")

plt.subplot(3,4,11)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Runge Kutta)$")
plt.plot(tiempo_RK1, ma_RK1, color= "lightcoral")

plt.subplot(3,4,12)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Runge Kutta)$")
plt.plot(tiempo_RK1, ener_RK1, color= "darkseagreen")

plt.savefig("Primer dt")

##Plots del segundo dt
euler2 = np.genfromtxt("Euler2.dat", delimiter= "||")
LF2 = np.genfromtxt("LF2.dat", delimiter = "||")
RK2 = np.genfromtxt("RK2.dat", delimiter = "||")

tiempo_e2 = euler2[:,0]
x_e2 = euler2[:,1]
y_e2 = euler2[:,2]
vx_e2 = euler2[:,3]
vy_e2 = euler2[:,4]
ma_e2 = euler2[:,5]
ep_e2 = euler2[:,6]
el_e2 = euler2[:,7]
ener_e1 = ep_e2+el_e2

tiempo_LF2 = LF2[:,0]
x_LF2 = LF2[:,1]
y_LF2 = LF2[:,2]
vx_LF2 = LF2[:,3]
vy_LF2 = LF2[:,4]
ma_LF2 = LF2[:,5]
ep_LF2 = LF2[:,6]
el_LF2 = LF2[:,7]
ener_LF2 = ep_LF2+el_LF2

tiempo_RK2 = RK2[:,0]
x_RK2 = RK2[:,1]
y_RK2 = RK2[:,2]
vx_RK2 = RK2[:,3]
vy_RK2 = RK2[:,4]
ma_RK2 = RK2[:,5]
ep_RK2 = RK2[:,6]
el_RK2 = RK2[:,7]
ener_RK2 = ep_RK2+el_RK2


plt.figure(figsize=(18,14))
plt.subplot(3,4,1)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Euler)$")
plt.plot(x_e2, y_e2, color= "navy")

plt.subplot(3,4,2)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Euler)$")
plt.plot(vx_e2, vy_e2, color= "plum")

plt.subplot(3,4,3)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Euler)$")
plt.plot(tiempo_e2, ma_e2, color= "lightcoral")

plt.subplot(3,4,4)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Ennergía$")
plt.title("$Energía$ $(Euler)$")
plt.plot(tiempo_e2, ener_e2, color= "darkseagreen")

plt.subplot(3,4,5)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Leap Frog)$")
plt.plot(x_LF2, y_LF2, color= "navy")

plt.subplot(3,4,6)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Leap Frog)$")
plt.plot(vx_LF2, vy_LF2, color= "plum")

plt.subplot(3,4,7)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Leap Frog)$")
plt.plot(tiempo_LF2, ma_LF2, color= "lightcoral")

plt.subplot(3,4,8)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Leap Frog)$")
plt.plot(tiempo_LF2, ener_LF2, color= "darkseagreen")

plt.subplot(3,4,9)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Runge Kutta)$")
plt.plot(x_RK2, y_RK2, color= "navy")

plt.subplot(3,4,10)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Runge Kutta$")
plt.plot(vx_RK2, vy_RK2, color= "plum")

plt.subplot(3,4,11)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Runge Kutta)$")
plt.plot(tiempo_RK2, ma_RK2, color= "lightcoral")

plt.subplot(3,4,12)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Runge Kutta)$")
plt.plot(tiempo_RK2, ener_RK2, color= "darkseagreen")
plt.savefig("Segundo dt")

euler3 = np.genfromtxt("Euler3.dat", delimiter= "||")
LF3 = np.genfromtxt("LF3.dat", delimiter = "||")
RK3 = np.genfromtxt("RK3.dat", delimiter = "||")

tiempo_e3 = euler3[:,0]
x_e3 = euler3[:,1]
y_e3 = euler3[:,2]
vx_e3 = euler3[:,3]
vy_e3 = euler3[:,4]
ma_e3 = euler3[:,5]
ep_e3 = euler3[:,6]
el_e3 = euler3[:,7]
ener_e3 = ep_e3+el_e3

tiempo_LF3 = LF3[:,0]
x_LF3 = LF3[:,1]
y_LF3 = LF3[:,2]
vx_LF3 = LF3[:,3]
vy_LF3 = LF3[:,4]
ma_LF3 = LF3[:,5]
ep_LF3 = LF3[:,6]
el_LF3 = LF3[:,7]
ener_LF3 = ep_LF3+el_LF3

tiempo_RK3 = RK3[:,0]
x_RK3 = RK3[:,1]
y_RK3 = RK3[:,2]
vx_RK3 = RK3[:,3]
vy_RK3 = RK3[:,4]
ma_RK3 = RK3[:,5]
ep_RK3 = RK3[:,6]
el_RK3 = RK3[:,7]
ener_RK3 = ep_RK3+el_RK3


plt.figure(figsize=(18,14))
plt.subplot(3,4,1)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Euler)$")
plt.plot(x_e3, y_e3, color= "navy")

plt.subplot(3,4,2)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Euler)$")
plt.plot(vx_e3, vy_e3, color= "plum")

plt.subplot(3,4,3)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Euler)$")
plt.plot(tiempo_e3, ma_e3, color= "lightcoral")

plt.subplot(3,4,4)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Euler)$")
plt.plot(tiempo_e3, ener_e3, color= "darkseagreen")

plt.subplot(3,4,5)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Leap Frog)$")
plt.plot(x_LF3, y_LF3, color= "navy")

plt.subplot(3,4,6)
plt.xlabel("$Vx$")
plt.ylabel("$Vy$")
plt.title("$Velocidad$ $(Leap Frog)$")
plt.plot(vx_LF3, vy_LF3, color= "plum")

plt.subplot(3,4,7)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Leap Frog)$")
plt.plot(tiempo_LF3, ma_LF3, color= "lightcoral")

plt.subplot(3,4,8)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Leap Frog)$")
plt.plot(tiempo_LF3, ener_LF3, color= "darkseagreen")

plt.subplot(3,4,9)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Posición$ $(Runge Kutta)$")
plt.plot(x_RK3, y_RK3, color= "navy")

plt.subplot(3,4,10)
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("$Velocidad$ $(Runge Kutta$")
plt.plot(vx_RK3, vy_RK3, color= "plum")

plt.subplot(3,4,11)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Momento$ $angular$")
plt.title("$Momento$ $(Runge Kutta)$")
plt.plot(tiempo_RK3, ma_RK3, color= "lightcoral")

plt.subplot(3,4,12)
plt.xlabel("$Tiempo$ $(yr)$")
plt.ylabel("$Energía$")
plt.title("$Energía$ $(Runge Kutta)$")
plt.plot(tiempo_RK3, ener_RK3, color= "darkseagreen")

plt.savefig("Tercer dt")





