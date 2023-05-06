#import matplotlib.pyplot as plt 
#plt.plot ([1,2,3,4], [1,4,9,16])
#plt.ylabel('y numbers')
#plt.xlabel('x numbers')
#plt.show()

import matplotlib
import matplotlib.pyplot as plt
f = open("demo.txt", "r")
values = []
temp =[]
xval =[]
yval = []
weightval = []
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
    

print("this is xval")

for line in data:
    
    substrings = line.split()
    xval.append(int(substrings[0]))
    yval.append(int(substrings[1]))
    weightval.append(int(substrings[2]))

    


print(xval)
print(yval)
print(weightval)



#col and row are lit pos of the table
fig = plt.figure()
ax = fig.add_subplot(111)

for x in range(len(xval)):
    
    rect1 = matplotlib.patches.Rectangle((xval[x],yval[x]),weightval[x],1, linewidth = 1, edgecolor = 'b', facecolor ='none')
    plt.plot([1,3], [2,4])
    ax.add_patch(rect1)
    

#
#x y 
#rect works with (x,y) cord so x will be row y will increment to act as col third param is width so its area
#4th param will remain as a constant of 1 since all height is the same 

plt.xlim([0, 6])
plt.ylim([0, 6])

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




