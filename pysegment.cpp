/*
Copyright (C) 2006 Pedro Felzenszwalb

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
*/
#include "pysegment.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "image.h"
#include "misc.h"
#include "pnmfile.h"
#include "segment-image.h"
#include "filter.h"

void felzenszwalb(int* img, int h, int w, int d, int* seg, int h1, int w1, float sigma, float k, int min_size){
  image<rgb> *input = new image<rgb>(w, h);
  typedef unsigned char uchar;
  printf("height: %d\n width: %d\n depth %d\n ", h,w,d);
  for (int y = 0; y < h; y++) 
  {
      for (int x = 0; x < w; x++) 
      {
	  int index = x + w*y;

	  imRef(input, x, y).r = static_cast<uchar>( img[3*index] );
	  imRef(input, x, y).g = static_cast<uchar>( img[1 + 3*index] );
	  imRef(input, x, y).b = static_cast<uchar>( img[2 + 3*index] );
          if ((y==59)&&(x==100)){//&& (y==0)) {
               printf("x: %d y:%d r:%d g:%d b:%d\n", x,y,img[3*index],img[3*index+1],img[3*index+2]);
          }
          /*if ((x==19)&& (y==0)) {
               printf("index:%d\n",index);
               printf("x: %d y:%d r:%d g:%d b:%d\n", x+1,y+1,img[3*index],img[3*index+1],img[3*index+2]);
          } 
          if ((x==20)&& (y==0)) {
               printf("index:%d\n",index);
               printf("x: %d y:%d r:%d g:%d b:%d\n", x+1,y+1,img[3*index],img[3*index+1],img[3*index+2]);
          } 	
          if ((x==21)&& (y==0)) {
               printf("index:%d\n",index);
               printf("x: %d y:%d r:%d g:%d b:%d\n", x+1,y+1,img[3*index],img[3*index+1],img[3*index+2]);
          }
          if ((x==1)&& (y==1)) {
               printf("index:%d\n",index);
               printf("x: %d y:%d r:%d g:%d b:%d\n", x+1,y+1,img[3*index],img[3*index+1],img[3*index+2]);
          } */	             	            
      }
  }
	
  printf("processing\n");
  int num_ccs;
  
  segment_image(input, sigma, k, min_size, &num_ccs,seg); 
  delete input;

  printf("got %d components\n", num_ccs);
  printf("done! uff...thats hard work.\n");

}

