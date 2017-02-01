#include <time.h>
#include <stdlib.h>


/* This file will essentially include the architecture for a feed-forward-
   neural network. This begs the question: what *exactly* does a neural network
   consist of? */




/* This not only initializes the size of matrices, but also the 
   weight vectors themselves to "small" random values. After having 
   read the paper the program will be based upon, it seems as though
   this initialization procedure will have to become significantly
   more sophisticated upon further iterations of design, in order to 
   allow the SGD optimization to (specifically on the auto-encoder)
   converge to a reasonable solution. */
struct FFNN*  init_FFNN(size_t num_layers, size_t *widths, 
			matrix* weights,  fp (*hidden_act_func)(fp),  
			fp learning_rate, fp (*output_func)(fp))
{
  /* Allocate necessary memory for the struct */
  struct FFNN* FFNN = malloc(size(struct FNNN));

  /* Also need to allocate for the arrays/matrices */
  FFNN->widths = malloc(sizeof(fp) * num_layers);

  FFNN->widths = 

}



/* returns an output vector for the current iteration. don't need
   to pass in a pointer since we don't need to change the network 
   itself in this function. It also needs an input data vector */
matrix* forward_prop(FFNN curr_ffnn)
{

}

/* performs one pass of back-propagation through the input-ed
   neural network. For this... it needs a input vector and
   the corresponding desired output. 
   Updates the weights accordingly
   */
void back_prop(FFNN* inp_ffnn, )
{

}

/* Given an activation function, a matrix of input data which corresponds
   to a matrix of output data, a learning rate, a set of data */
void train_FFNN(
