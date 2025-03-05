import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv("Simulation_Results (Three Main Pumps).csv")

# --- 1. Average Service Times for Car Category ---
plt.figure(figsize=(8, 6))
plt.hist(data['Avg Service Time Category A'], bins=10, alpha=0.7, label='Category A')
plt.hist(data['Avg Service Time Category B'], bins=10, alpha=0.7, label='Category B')
plt.hist(data['Avg Service Time Category C'], bins=10, alpha=0.7, label='Category C')
plt.title("Histogram of Average Service Times by Car Category", fontsize=14)
plt.xlabel("Time (minutes)")
plt.ylabel("Frequency")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()

# --- 2. Average Service Times for Each Pump ---
plt.figure(figsize=(8, 6))
plt.hist(data['Avg Service Time 95'], bins=10, alpha=0.7, label='95 Octane')
plt.hist(data['Avg Service Time 90'], bins=10, alpha=0.7, label='90 Octane')
plt.hist(data['Avg Service Time Gas'], bins=10, alpha=0.7, label='Gas')
plt.title("Histogram of Average Service Times by Pump", fontsize=14)
plt.xlabel("Time (minutes)")
plt.ylabel("Frequency")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()

# --- 3. Average Waiting Times for Each Pump ---
plt.figure(figsize=(8, 6))
plt.hist(data['Avg Wait Time 95'], bins=10, alpha=0.7, label='95 Octane')
plt.hist(data['Avg Wait Time 90'], bins=10, alpha=0.7, label='90 Octane')
plt.hist(data['Avg Wait Time Gas'], bins=10, alpha=0.7, label='Gas')
plt.hist(data['Avg Wait Time All Cars'], bins=10, alpha=0.7, label='All Cars', linestyle='--')
plt.title("Histogram of Average Waiting Times by Pump", fontsize=14)
plt.xlabel("Time (minutes)")
plt.ylabel("Frequency")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()

# --- 4. Maximum Queue Lengths for Each Pump ---
plt.figure(figsize=(8, 6))
plt.hist(data['Avg Max Queue Length 95'], bins=10, alpha=0.7, label='95 Octane')
plt.hist(data['Avg Max Queue Length 90'], bins=10, alpha=0.7, label='90 Octane')
plt.hist(data['Avg Max Queue Length Gas'], bins=10, alpha=0.7, label='Gas')
plt.title("Histogram of the Average Maximum Queue Length per Pump", fontsize=14)
plt.xlabel("Number of Cars")
plt.ylabel("Frequency")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()

# --- 5. Average Probability That a Car Waits on Each Pump ---
plt.figure(figsize=(8, 6))
plt.hist(data['Avg prob. wait 95'], bins=10, alpha=0.7, label='95 Octane')
plt.hist(data['Avg prob. wait 90'], bins=10, alpha=0.7, label='90 Octane')
plt.hist(data['Avg prob. wait Gas'], bins=10, alpha=0.7, label='Gas')
plt.title("Histogram of the Average Probability That a Car Waits on Each Pump", fontsize=14)
plt.xlabel("Average Probability")
plt.ylabel("Frequency")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()

# --- 6. Average Probability of idle time for each pump ---
plt.figure(figsize=(8, 6))
plt.hist(data['Avg prob. idle 95'], bins=10, alpha=0.7, label='95 Octane')
plt.hist(data['Avg prob. idle 90'], bins=10, alpha=0.7, label='90 Octane')
plt.hist(data['Avg prob. idle Gas'], bins=10, alpha=0.7, label='Gas')
plt.title("Histogram of the Average Probability of idle time for each pump", fontsize=14)
plt.xlabel("Average Probability")
plt.ylabel("Frequency")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()
