from scipy.ndimage import morphology
from skimage.measure import label
import matplotlib.pyplot as plt
import numpy as np

quantity = 0
masks = np.array([[[1,1,1,1],
                    [1,1,1,1],
                    [1,1,0,0],
                    [1,1,0,0],
                    [1,1,1,1],
                    [1,1,1,1]],

                    [[1,1,1,1],
                    [1,1,1,1],
                    [0,0,1,1],
                    [0,0,1,1],
                    [1,1,1,1],
                    [1,1,1,1]],

                    [[1,1,1,1],
                    [1,1,1,1],
                    [1,1,1,1],
                    [1,1,1,1],
                    [1,1,1,1],
                    [1,1,1,1]],
                    
                    [[1,1,0,0,1,1],
                    [1,1,0,0,1,1],
                    [1,1,1,1,1,1],
                    [1,1,1,1,1,1]],
                    
                    [[1,1,1,1,1,1],
                    [1,1,1,1,1,1],
                    [1,1,0,0,1,1],
                    [1,1,0,0,1,1]],
                    
                    [[1,1,1,1,1,1],
                    [1,1,1,1,1,1],
                    [1,1,1,1,1,1],
                    [1,1,1,1,1,1]]], dtype=object)

def counter(image, mask):
    dilation = morphology.binary_dilation(morphology.binary_erosion(image, mask), mask)
    image -= dilation
    count = label(dilation).max()
    return count

image = np.load("ps.npy.txt")

def masks_types(x):
    strings = ''
    for n in x[::2]:
        strings += str(n[::2]).replace('[', '').replace(']', '').replace(', ', '')
        strings += '\n'
    return strings

for mask in masks:
    cts = counter(image, mask)
    print('Объекты типа: \n', masks_types(mask), 'Их количество = ', cts, sep = '', end = '\n\n')
    quantity += cts
print("Количество объектов на изображении: ", quantity)
    
plt.figure()
plt.imshow(image, cmap="gray")
plt.show()