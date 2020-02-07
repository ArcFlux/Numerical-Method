import numpy as np

def f(x):
    return x**6-x**4-x**3-1

x1=float(input("x1: "))
x2=float(input("x2: "))
d=float(input("Accuracy: "))
xm=float()
while abs(x2-x1)>=d and abs(f(xm))>=d:
    xm = x2 - (x2-x1) / (f(x2)-f(x1)) * f(x2)
    x1 = x2
    x2 = xm
    print("Root=","%.5f" % xm)
if f(xm)>d:
    print("Not convergent")
else:
    print("Final Solution=","%.5f" % xm)
