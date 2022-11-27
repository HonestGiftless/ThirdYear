import numpy as np
import matplotlib.pyplot as plt
from skimage import color
from skimage.measure import label, regionprops

def type_of_object(region):
    a = region.area / (region.image.shape[0] * region.image.shape[1])
    return a

def group_hue(sorted):
    groups = [[sorted[0]],]
    delta = np.max(np.diff(sorted)) / 2
    for i in range(1, len(sorted)):
        previous = sorted[i-1]
        current = sorted[i]
        if current - previous > delta:
            groups.append([])
        groups[-1].append (current)
    return groups

def colors_writter(groups):
    res = dict()
    for grp in groups:
        res[np.mean(grp)] = len(grp)
    return res

image = plt.imread("balls_and_rects.png")
hsv = color.rgb2hsv(image)
binary = hsv[:, :, 0].copy()
binary[binary > 0] = 1
labeled = label(binary)
regions = regionprops(labeled)

rects_colors = []
balls_colors = []

square_counter = 0
circle_counter = 0

for reg in regions:
    cy, cx = reg.centroid
    if type_of_object(reg) == 1:
        rct = rects_colors.append(hsv[int(cy), int(cx), 0])
        square_counter += 1
    else:
        bls = balls_colors.append(hsv[int(cy), int(cx), 0])
        circle_counter += 1

rects_colors = sorted(rects_colors)
rects_groups = group_hue(rects_colors)
rects_result = colors_writter(rects_groups)

balls_colors = sorted(balls_colors)
balls_groups = group_hue(balls_colors)
balls_result= colors_writter(balls_groups)

print("Всего объектов: ", len(regions))
print("Квадратов:", square_counter, "Их оттенки:", rects_result)
print("Шаров:", circle_counter, "Их оттенки:", balls_result)