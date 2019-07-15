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

#Calculo del momento angular, para ello se halla la velocidad angular y el momento de inercia (que es constante)
#Inercia = Masa tierra en Masas solares(MT)*Radio tierra en Unidades astronómicas(RT)*2/5
#Velocidad angular = velocidad tangencial/distancia; la distancia es una unidad astronómica
#Momento angular(L) = Inercia*Momento angular

MT = (3.0025)*10**-6
RT = (4.258)*10**-5
inercia = (2/5)*MT*(RT**2)

wx_e1 = vx_e1/1 
wy_e1 = vy_e1/1 
wx_e2 = vx_e2/1
wy_e2 = vy_e2/1
wx_e3 = vx_e3/1
wy_e3 = vy_e3/1

Lx_e1 = inercia*wx_e1
Ly_e1 = inercia*wy_e1
Lx_e2 = inercia*wx_e2
Ly_e2 = inercia*wy_e2
Lx_e3 = inercia*wx_e3
Ly_e3 = inercia*wy_e3

wx_LF1 = vx_LF1/1
wy_LF1 = vy_LF1/1
wx_LF2 = vx_LF2/1
wy_LF2 = vy_LF2/1
wx_LF3 = vx_LF3/1
wy_LF3 = vy_LF3/1

Lx_LF1 = inercia*wx_LF1
Ly_LF1 = inercia*wy_LF1
Lx_LF2 = inercia*wx_LF2
Ly_LF2 = inercia*wy_LF2
Lx_LF3 = inercia*wx_LF3
Ly_LF3 = inercia*wy_LF3

wx_RK1 = vx_RK1/1
wy_RK1 = vy_RK1/1
wx_RK2 = vx_RK2/1
wy_RK2 = vy_RK2/1
wx_RK3 = vx_RK3/1
wy_RK3 = vy_RK3/1

Lx_RK1 = inercia*wx_RK1
Ly_RK1 = inercia*wy_RK1
Lx_RK2 = inercia*wx_RK2
Ly_RK2 = inercia*wy_RK2
Lx_RK3 = inercia*wx_RK3
Ly_RK3 = inercia*wy_RK3



