import sys
sys.path.insert(0,'./felzenszwalb')
import numpy as np
from skimage import io as sio
from felzenszwalb import felseg
image = sio.imread("./0010.jpg")
seg = np.zeros(image.shape[0:2],dtype=np.int32)
felseg(image,seg,0.8,100,150)
sio.imshow(seg)
sio.show()
