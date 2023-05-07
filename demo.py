#import matplotlib.pyplot as plt 
#plt.plot ([1,2,3,4], [1,4,9,16])
#plt.ylabel('y numbers')
#plt.xlabel('x numbers')
#plt.show()

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
f = open("demo.txt", "r")
net = open("ibm01.net", "r")
area = open("ibm01.are","r")
areaval = []
netval = []

values = []
values2 = []
temp =[]
temp2 = []
xval1 =[]
yval1 = []
xval2 =[]
yval2 = []
weightval = []
check = []
data = f.readlines()
for line in data:
    if line[-1] == '\n':
        values.append(line[:-1])
        
    else:
        values.append(line)
        
data3 = area.readlines()
for line in data3:
    if line[-1] == '\n':
        values2.append(line[:-1])
        
    else:
        values2.append(line)
        


for string in values2:
    substrings = string.split(" ")
    temp2.extend(substrings)
    
for string in values:
    substrings = string.split(" ")
    temp.extend(substrings)
    

print("this is xval")

for line in data:
    
    substrings = line.split()
    xval1.append(int(substrings[1]))
    yval1.append(int(substrings[0]))
    weightval.append(int(substrings[2]))
    #xval2.append(int(substrings[4]))
    #yval2.append(int(substrings[5]))

for line in data3:
    substring = line.split()
    areaval.append(int(substring[1]))


#print(xval1)
#print(yval1)
#print(xval2)
#print(yval2)
#print(weightval)
#print(areaval)

#for plot get x1 y1 and x2 y2 in their own array then we can plot just gotaa gigure out how 

#col and row are lit pos of the table
fig = plt.figure()
ax = fig.add_subplot(111)
colors = np.random.rand(len(xval1), 3)


for x in range(len(xval1)):
    rectangle_color = colors[x]
    rect1 = matplotlib.patches.Rectangle((xval1[x],yval1[x]),areaval[x],1, linewidth = 1, edgecolor = rectangle_color, facecolor ='none')
    #plt.plot([xval1[x], yval1[x]], [xval2[x], yval2[x]])
    ax.add_patch(rect1)

plt.xlim([0, 700000])
plt.ylim([0, 1])

#plt.show()



#add rectangle to plot
#(start pt) width height
#width should be area
#height all same so one
#as for starting point row for x but need to figure out what y will be 
#ax.add_patch(Rectangle((1, 1), 2, 6))

#display plot
plt.show()
#had to change setting so that it wouldnt only read C drive and would read the folder that the code was in 








