/* Header File for Deep Lemming Neural Net */

#include "fixed_point.h"
#include "activation_funcs.h"
#include "matrix.c"


/* To make this as fast as possible, we will use arrays of numbers
   as opposed to structs of neural networks/weights that work
   via pointers. While the latter will make the code cleaner, it will
   come at the expense of speed, and the architectural consideration
   is too fundamental to be worth iterating over in an improved version.  */


/* FIX FIX FIX: FOR NOw, we only update based upon one individual training 
   input/output at a time. However, this is only for debugging purposes. As
   soon as we know this single-update progran is functional we will update
   for it to update based upon the gradients of GROUPS of input */
struct FFNN
{
  /* inclusive of input/output layers */
  size_t num_layers;

  /* Based upon the number of layers, (as in, the length of the array
     will be the number of layers)  
     this array will consist of the widths of the layers in the network  */
  size_t *widths;

  /* The weights will be arranged as an array of vectors, which will just
     be one-column matrices. Optimally, this would just be 
     one long vector of weights, and we would keep track of weights internally, 
     but this configuration should be more organized. If the pointers become
     too much of a bottleneck, we will change this design. */
  matrix* weights;

  /* For right now, we will use a single *hidden* activation function across the entire
     network. Also since back propagation is specific to the activation
     function used (different derivative) we are going to have to 
     fix the activation function ahead of time, and essentially re-write parts
     of the back-propagation code if we change the activation function. In the 
     future we might provide configuration options  */

  /* UPDATE: according to chapter 6 really the best hidden activation function is
     the rectified linear unit, and so this shouldn't be too much of an issue in
     the long run tbh  */
  fp (*hidden_act_func)(fp);
  
  /* The learning rate for the back-propagation updating algorithm. */
  fp learning_rate;

  /* Finally, we need an output function which, note, is generally *different* 
     than the hidden activaiton function, since its output needs to be in the 
     same "format", so to speak, as the output we train against.  */
  fp (*output_func)(fp);
}


/* Quick sum function for array allocation purposes. Sums up the total 
   number of fixed-point integers over the  array. */
  fp sum_array(fp* , size_t)
  {
    fp sum = 0;

  }
