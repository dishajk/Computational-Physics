import random

def markov_pi(N, delta): 
    x, y = 1.0, 1.0
    n_hits = 0
    for i in range(N):
        del_x, del_y = random.uniform(-delta, delta), random.uniform(-delta, delta)     #random displacement of (-0.1,0.1)
        if abs(x + del_x) < 1.0 and abs(y + del_y) < 1.0:
            x, y = x + del_x, y + del_y     #if displacement inside the square, update position
        if x**2 + y**2 < 1.0: n_hits += 1   #if inside circle, increase number of hits
    return n_hits

n_runs = 10
n_trials = 4000
delta = 0.1
for run in range(n_runs):
    print(4.0 * markov_pi(n_trials, delta) / float(n_trials))
