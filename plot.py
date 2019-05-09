import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import imageio
import os

fig = plt.figure()
data = np.loadtxt("adveccion.dat")
x = np.linspace(0.0,1.0,len(data[1]))
fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = plt.plot([], [], 'ro')
plt.plot(x, data[0])

def init():
    ax.set(xlabel='Posicion[metros]', ylabel = 'U')
    ax.set_xlim(0.0, 1.0)
    ax.set_ylim(-0.04, 0.04)
    return ln,

def update():
    for i in range(len(data[1])):
        ln.set_ydata(np.shape(data[i]))
    return ln,

ani = FuncAnimation(fig, update, frames=np.shape(data)[0],
                    init_func=init, blit=True)
ani.save("movie.gif")
plt.show()










