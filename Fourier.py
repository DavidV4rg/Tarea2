import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, ifft2
from matplotlib.colors import LogNorm

datos1 = plt.imread("imagen1.png")
datos2 = plt.imread("imagen2.png")

trans1 = fft2(datos1)
trans2 = fft2(datos2)

plt.figure()
plt.imshow(np.abs(trans1), norm = LogNorm() )
plt.colorbar()
plt.savefig("FFT2D1.png")

plt.figure()
plt.imshow(np.abs(trans2), norm = LogNorm() )
plt.colorbar()
plt.savefig("FFT2D2.png")

freq1 = np.fft.fftshift(datos1)
variable1 = np.copy(trans1)

freq2 = np.fft.fftshift(datos2)
variable=np.copy(trans2)



