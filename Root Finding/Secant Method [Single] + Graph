import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import fsolve

def f(x):
    return x**3 + 2*x**2 - 4*x -3

start = int(input("x start= "))
end = int(input("x end= "))
x = np.arange(start, end, 0.01)
for i in range(start, end):
    y = fsolve(f, i)
    if i == start and f(y) <= 0.01:
        print("Root=","%.5f" % y)
        a=y
    elif abs(a-y)>=0.001 and f(y) <= 0.01:
        print("Root=","%.5f" % y)
        a=y
    i =+ 1

plt.plot(x, f(x))
plt.grid(True)
plt.ylim(-10, 10)
plt.plot(x, np.zeros(len(x)))
plt.show()
