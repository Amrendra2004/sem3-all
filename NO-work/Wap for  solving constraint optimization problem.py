from scipy.optimize import minimize

# Define the objective function to minimize
def objective_function(variables):
    x, y = variables
    return x**2 + y**2

# Define the inequality constraints
def inequality_constraints(variables):
    x, y = variables
    return [
        5 - 3*x - y,  # 3x + y >= 5 becomes 3x + y - 5 >= 0
        6 - x - 4*y   # x + 3y >= 6 becomes x + 4y - 6 >= 0
    ]

# Define initial guess for variables
initial_guess = [0.6, 0.6]

bounds = [(0, None), (0, None)]

# Define constraints using dictionary format
constraints = {'type': 'ineq', 'fun': inequality_constraints}

# Use minimize function to solve the optimization problem
result = minimize(objective_function, initial_guess, bounds=bounds, constraints=constraints)

# Print the optimal solution and minimum value of the objective function
print("Optimal Solution (x, y):", result.x)
print("Minimum Value of f(x, y):", result.fun)
