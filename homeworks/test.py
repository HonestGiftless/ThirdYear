import numpy as np
import matplotlib.pyplot as plt
from skimage.measure import label
from skimage.morphology import binary_erosion, binary_dilation, binary_closing, binary_opening

image = np.load("C:\\Users\\nickm\\Desktop\\lesson\\wires2.npy.txt")
labeled = label(image)
mask = [[0,1,0],
        [0,1,0],
        [0,1,0]]

for i in range(labeled.max() + 1):
    one_wire = np.zeros_like(image)
    one_wire[labeled == i] = 1
    erosion = binary_erosion(one_wire, mask)
    erosion_label = label(erosion)
    print(np.unique(erosion_label))
    print(erosion_label.max())
plt.imshow(labeled)
plt.show()