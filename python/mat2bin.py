"""
Converting matlab velocity files to raw binary files.
"""
import numpy as np
from scipy.io import matlab

matfile = matlab.loadmat('../datasultan/snapshot.mat')
dx = matfile['DeltaX']
dy = matfile['DeltaY']
zc = matfile['ZC']

u = matfile['UCenter']
v = matfile['VCenter']
w = matfile['WCenter']

charac = np.where(np.isnan(u), -1.0, 1.0)

print(dx, dy)
print(zc.T)
i = 487
j = 67
k = 19
print(u[i, j, k], v[i, j, k], w[i, j, k])
print(u.shape)

u.tofile('tmp/u.bin')
v.tofile('tmp/v.bin')
w.tofile('tmp/w.bin')
zc.tofile('tmp/z.bin')
charac.tofile('tmp/charac.bin')
