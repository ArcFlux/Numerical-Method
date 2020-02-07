import numpy as np

def f(x):
    return 20*x**1.5+np.exp(-x/5)

n=int(input("Number of panels: "))
sum = float()
if n%2!=0:
    print("Error.")
    quit()
else:
    x1=float(input("xmin: "))
    x2=float(input("xmax: "))
    h = (x2 - x1) / n
    for i in range(0,n):
        if i==0:
            x = x1
            y = f(x)
            sum = y
            print("x:","%.5f" % x); print("y:","%.5f" % y); print()
        else:
            x = x1 + h*i
            y = f(x)
            if i%2==0:
                sum = sum + 2*y
            else:
                sum = sum + 4*y
            print("x:","%.5f" % x); print("y:","%.5f" % y); print()
    x = x2
    y = f(x)
    sum = sum + y
    print("x:","%.5f" % x); print("y:","%.5f" % y); print()
    sum = h * sum/3
    print("SUM=","%.5f" % sum)
