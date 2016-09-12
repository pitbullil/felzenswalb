#This git repositroy implements a full Python wrapper of the code of the paper "Efficient Graph-Based Image Segmentation by P. Felzenszwalb, D. Huttenlocher ,International Journal of Computer Vision, Vol. 59, No. 2, September 2004"
#The basic C++ code is provided by provided by http://cs.brown.edu/~pff/segment/
#I have made changes to image-segment.h and added pysegment.cpp pysegment.h felzenswalb.i and setup.py in order to create a python interface

to compile you must have SWIG and python installed

#you should run:
#swig -c++ -python felzenszwalb.i
#python3 setup.py  build_ext -ifg

#to use in python use:
#import sys
#sys.path.insert(0,'<felzenswalb dir>')
#from felzenszwalb import felseg
#felseg(image,seg,sigma,k,min_size)

#image - should be uint8 RGB image
#seg - a place holder of size(height,width) which will changed in place to the final segmentation
#sigma - float
#k - int
#min_size - int

#you can try running test1.py to check it out

