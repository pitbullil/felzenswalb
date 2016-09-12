%module adjmat
%{
  #define SWIG_FILE_WITH_INIT
  #include "adjmat.h"
%}      
%include "numpy.i"
%init %{
import_array();
%}
%apply ( int* IN_ARRAY2, int DIM1, int DIM2 ) {(int* segmap, int h,int w)};
%apply ( int* INPLACE_ARRAY2, int DIM1, int DIM2 ) {(int* adj_mat, int h1, int w1)};
%include "adjmat.h"

