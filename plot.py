import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


fig = plt.figure()

data = np.loadtxt("adveccion.dat")
print(np.shape(data))
x = np.shape(data)[0]
y = np.zeros(x)
i = 0
j = 0
im = []

for i in range(x):
    x1 = data[i]
    for j in range(x):
        y[j] = x1[j]
        t = np.arange(np.shape(data)[1])
        im = plt.plot((y,t), animated=True)
        ims.append([im])
        
ani = animation.ArtistAnimation(fig, ims, interval=50, blit=True,repeat_delay=1000)
ani.save('movie.gif')
plt.show()


