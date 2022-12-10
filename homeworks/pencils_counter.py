from skimage.measure import label,regionprops
from skimage.filters.thresholding import (threshold_li)
from skimage import filters
from scipy import ndimage
import os, re, numpy as np, math
import matplotlib.pyplot as plt
from natsort import natsorted #Для сортировки файлов по порядку, нагуглил

path_list = natsorted(os.listdir())
pencil_counter = 0

def get_euclid(reg):
    y0, x0 = reg.centroid
    orientation = reg.orientation
    x1 = x0 + math.cos(orientation) * 0.5 * reg.minor_axis_length
    y1 = y0 - math.sin(orientation) * 0.5 * reg.minor_axis_length
    x2 = x0 - math.sin(orientation) * 0.5 * reg.major_axis_length
    y2 = y0 - math.cos(orientation) * 0.5 * reg.major_axis_length
    return  math.sqrt((x1-x0)**2+(y1-y0)**2),math.sqrt((x2-x0)**2+(y2-y0)**2)

def take_area(e):
    return e.area

for i in path_list:
    if re.match(r".+.jpg", i):
        counter = 0
        image = plt.imread(i)
        image = np.mean(image, 2)
        sobel = filters.sobel(image)
        th = filters.threshold_li(sobel)
        sobel[sobel < th] = 0
        sobel[sobel > 0] = 1
        fillings = ndimage.binary_fill_holes(sobel)
        for j in range(5):
            fillings = ndimage.binary_erosion(fillings)
        labeled = label(fillings)
        regions = regionprops(labeled)
        regions = sorted(regions, key = take_area, reverse = True)
        for region in regions:
            if region.area < 10000:
                continue
            a,b = get_euclid(region)
            if a/b > 10 or b/a > 10:
                counter += 1
            else:
                counter
        print("На изображении", i, "количество карандашей =", counter, sep=" ")
        pencil_counter += counter

print("Total pencils:", pencil_counter)

        
