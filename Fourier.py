import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, ifft2
from matplotlib.colors import LogNorm

#Se guardan los datos de las imagenes en archivos numpy
datos1 = plt.imread("imagen1.png")
datos2 = plt.imread("imagen2.png")

#Se calcula la transformada de Fourier de ambas imagenes
trans1 = fft2(datos1)
trans2 = fft2(datos2)

#Se grafica el espectro de Fourier de cada una de las imágenes
plt.figure()
plt.imshow(np.abs(trans1), norm = LogNorm() )
plt.colorbar()
plt.savefig("FFT2D1.png")

plt.figure()
plt.imshow(np.abs(trans2), norm = LogNorm() )
plt.colorbar()
plt.savefig("FFT2D2.png")

#Se crean los filtros de la imagen
filtro1 = 100
index1 = np.where(trans1 > filtro1)
trans1[index1] = 0

plt.figure()
plt.imshow(np.abs(trans1), norm = LogNorm())
plt.colorbar()
plt.savefig("flitro_imagen_1")

filtro2 = 0
index2 = np.where(trans2 < filtro2)
trans2[index2] = 0

plt.figure()
plt.imshow(np.abs(trans2), norm = LogNorm())
plt.colorbar()
plt.savefig("filtro_imagen_2")

filt1 = ifft2(trans1)
plt.figure()
plt.imshow(np.real(filt1), plt.cm.gray)
plt.savefig("im1_flitrada")

filt2 = ifft2(trans2)
plt.figure()
plt.imshow(np.real(filt2), plt.cm.gray)
plt.savefig("im2_filtrada")

suma = np.real(filt2)+np.real(filt1)

plt.figure()
plt.imshow(suma, plt.cm.gray)
plt.savefig("hibrida")


freq1 = np.fft.fftshift(datos1)
variable1 = np.copy(trans1)

freq2 = np.fft.fftshift(datos2)
variable=np.copy(trans2)



