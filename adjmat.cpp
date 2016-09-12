#include "adjmat.h"
void adjmat(int* segmap, int h, int w, int* adj_mat, int h1, int w1){
    for (int y = 0; y < h; y++) 
    {
      for (int x = 0; x < w; x++) 
      {
	int index = x + w*y;
        int sp = segmap[index];
        int l = x-1 + w*y;
        int lu = x-1 + w*(y-1);
        int ld = x-1 + w*(y+1);
        int u = x + w*(y-1);
        int d = x + w*(y+1);
        int r = x+1 + w*y;
        int ru = x+1 + w*(y-1);
        int rd = x+1 + w*(y+1);
        if (x > 0)
        {
          adj_mat[sp+(segmap[l])*w1]=1;
          if (y > 0){
            adj_mat[sp+(segmap[u])*w1]=1;
            adj_mat[sp+(segmap[lu])*w1]=1;
          }
          if (y < h-1)
          {
            adj_mat[sp+(segmap[d])*w1]=1;  
            adj_mat[sp+(segmap[ld])*w1]=1;
          }
        }
        if (x < w-1)
        {
          adj_mat[sp+(segmap[r])*w1]=1;
          if (y>0){
            adj_mat[sp+(segmap[ru])*w1]=1;
          }
          if (y<h-1)
          {
            adj_mat[sp+(segmap[rd])*w1]=1;
          }
        }
    }
  }
}
