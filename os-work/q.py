import matplotlib.pyplot as plt
import numpy as np

# Define the objective function coefficients (Z = cx + dy)
c = 8
d = 1

# Define the constraints
constraint1 = {'a': 1, 'b': 1, 'c': 40}  # x + y <= 40
constraint2 = {'a': 2, 'b': 1, 'c': 60}  # 2x + y <= 60

# Calculate the feasible region
x = np.linspace(0, 60, 400)  # Range of x values

# Constraint 1: x + y <= 40
y1 = (constraint1['c'] - constraint1['a']*x) / constraint1['b']

# Constraint 2: 2x + y <= 60
y2 = (constraint2['c'] - constraint2['a']*x) / constraint2['b']

# Plotting the constraints and feasible region
plt.figure(figsize=(8, 6))

plt.plot(x, y1, label=r'$1x + y \leq 40$')
plt.plot(x, y2, label=r'$2x + y \leq 60$')
plt.fill_between(x, 0, np.minimum(y1, y2), where=(y1 > 0) & (y2 > 0), color='gray', alpha=0.3, label='Feasible Region')
plt.xlim((0, 60))
plt.ylim((0, 60))
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.title('Graphical Representation of Linear Programming Problem')

# Plot the objective function Z = cx + dy for some values of x and corresponding y in the feasible region
Z = c*x + d*y1
optimal_x = 30
optimal_y = 0
plt.scatter(optimal_x, optimal_y, color='red', marker='o', s=100, label='Optimal Solution (30, 0)')

plt.legend()
plt.show()
            