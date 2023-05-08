import matplotlib
import matplotlib.pyplot as plt
import numpy as np
f = open("demo.txt", "r")

areaval = []
netval = []

values = []
values2 = []
temp =[]
temp2 = []
xval1 =[]
yval1 = []


check = []
data = f.readlines()
for line in data:
    if line[-1] == '\n':
        values.append(line[:-1])
        
    else:
        values.append(line)
        




for string in values:
    substrings = string.split(" ")
    temp.extend(substrings)
    



for line in data:
    
    substrings = line.split()
    xval1.append(int(substrings[1]))
    yval1.append(int(substrings[0]))
    areaval.append(int(substrings[2]))


fig = plt.figure()
ax = fig.add_subplot(111)
colors = np.random.rand(len(xval1), 3)


for x in range(len(xval1)):
    rectangle_color = colors[x]
    rect1 = matplotlib.patches.Rectangle((xval1[x],yval1[x]),areaval[x],1, linewidth = 1, edgecolor = rectangle_color, facecolor ='none')
    #plt.plot([xval1[x], yval1[x]], [xval2[x], yval2[x]])
    ax.add_patch(rect1)

plt.xlim([0, 700000])
plt.ylim([0, 7])


plt.show()








