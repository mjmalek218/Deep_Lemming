/* Header File for Deep Lemming Neural Net */

#include "fixed_point.h"
#include "activation_funcs.h"


/* A network is just an array of neurons, indexed in column-major order. 

   That is, first the depth
*/
struct neural_network
{


}


/* 

   A neuron should consist:


   1. an activation function


   2. location pair (i,j) where 

      i = which "row" it is in whatever level 

      j = the depth in the neural network

      These indices are 0-based, and match up what a matrix would look
      like if the network were visualized as percolating from left to right. 


   3. 
*/
struct neuron
{
  /* activation function. This machinery is defined in activation_funcs.h */
  fp (*act_func)(fp);

  size_t i,j;

}
