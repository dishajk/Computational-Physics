    #convergence is exponential exp(-t/tau)
    #sites in 3x3 are labled 
    #|6|7|8|
    #|3|4|5|
    #|0|1|2|


import random
neighbor =  [[1, 3, 0, 0], [2, 4, 0, 1], [2, 5, 1, 2],
             [4, 6, 3, 0], [5, 7, 3, 1], [5, 8, 4, 2],
             [7, 6, 6, 3], [8, 7, 6, 4], [8, 8, 7, 5]]
t_max = 4
site = 8
t = 0
print(site)
while t < t_max:
    t += 1
    # [right, up, left, down] = [0,1,2,3]
    site = neighbor[site][random.randint(0, 3)]     #site is updated at each t increment
    print(site)
