import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, ifft2, fftshift
from matplotlib.colors import LogNorm

#Se guardan los datos de las imagenes en archivos numpy
datos1 = plt.imread("cara_03_grisesMF.png")
datos2 = plt.imread("cara_02_grisesMF.png")

#Se calcula la transformada de Fourier de ambas imagenes
trans1 = fft2(datos1)
trans2 = fft2(datos2)

#Se grafica el espectro de Fourier de cada una de las imágenes
plt.figure(figsize=(10,8))
plt.subplot(1,2,1)
plt.imshow(np.abs(trans1), norm = LogNorm() )
plt.colorbar()
plt.title("Espectro de Fourier para imagen feliz")
plt.subplot(1,2,2)
plt.imshow(np.abs(trans2), norm = LogNorm() )
plt.title("Espectro de Fourier para imagen seria")
plt.colorbar()
plt.savefig("FFT2D1-2.pdf")

#Se calculan las frecuencias de cada imagen
fr1 = fftshift(trans1)
fr2 = fftshift(trans2)

plt.figure(figsize=(10,8))
plt.subplot(1,2,1)
plt.imshow(np.abs(fr1), norm=LogNorm())
plt.title("Frecuencias imagen feliz")
plt.colorbar()
plt.subplot(1,2,2)
plt.imshow(np.abs(fr2), norm=LogNorm())
plt.title("Frecuencias imagen feliz")
plt.colorbar()
plt.savefig("frecuencias.pdf")

#Se crean los filtros de la imagen
filtro1 = 0
index1 = np.where(trans1 < filtro1)
trans1[index1] = 0

filtro2 = 45
index2 = np.where(trans2 > filtro2)
trans2[index2] = 0

plt.figure(figsize=(11,8))
plt.subplot(1,2,1)
plt.imshow(np.abs(trans1), norm = LogNorm())
plt.colorbar()
plt.title("flitro imagen 1")
plt.subplot(1,2,2)
plt.imshow(np.abs(trans2), norm = LogNorm())
plt.colorbar()
plt.title("filtro imagen 2")
plt.savefig("fitros.pdf")

filt1 = ifft2(trans1)
filt2 = ifft2(trans2)
suma = np.real(filt2)+np.real(filt1)

plt.figure(figsize=(12,8))
plt.subplot(1,3,1)
plt.imshow(np.real(filt1), plt.cm.gray)
plt.title("im1_flitrada")
plt.subplot(1,3,2)
plt.imshow(np.real(filt2), plt.cm.gray)
plt.title("im2_filtrada")
plt.subplot(1,3,3)
plt.imshow(suma, plt.cm.gray)
plt.title("hibrida")
plt.savefig("filtradas.pdf")


