%module felzenszwalb
%{
  #define SWIG_FILE_WITH_INIT
  #include "pysegment.h"
%}      
%include "numpy.i"
%init %{
import_array();
%}
%apply ( int* IN_ARRAY3, int DIM1, int DIM2, int DIM3 ) {(int* img, int h, int w, int d)};
%apply ( int* INPLACE_ARRAY2, int DIM1, int DIM2 ) {(int* seg, int h1, int w1)};
%include "pysegment.h"

