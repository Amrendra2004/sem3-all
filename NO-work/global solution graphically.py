import numpy as np
import matplotlib.pyplot as plt

# Given function
def f(x):
    return -10 * np.cos(np.pi * x - 2.2) + (x + 1.5) * x

# Generate value of x.
x = np.linspace(-5, 5, 1000)

# Calculate values of y.
y = f(x)

# Find the value of x that corresponds to the minimum value of y.
optimal_x = x[np.argmin(y)]
optimal_y = np.min(y)

# Ploting the function
plt.figure(figsize=(10, 8))
plt.plot(x, y, label=r'$f(x)=-10\cos(\pi x - 2.2)+(x+1.5)x$')
plt.scatter(optimal_x, optimal_y, color='black', label='Global Optimal Solution')

plt.title('Graph of f(x)')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.show()

print("Global Optimal Solution = ", optimal_x)
print("Minimum Value of f(x) = ", optimal_y)
