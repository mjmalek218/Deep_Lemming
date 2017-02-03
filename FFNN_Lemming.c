#include <time.h>
#include <stdlib.h>
#include <assert.h>

/* This file will essentially include the architecture for a feed-forward-
   neural network. This begs the question: what *exactly* does a neural network
   consist of? */




/* All major work, including intialization of the weights,
   will be performed by the user. After having 
   read the paper the program will be based upon, it seems as though
   this initialization procedure will have to become significantly
   more sophisticated upon further iterations of design, in order to 
   allow the SGD optimization to (specifically on the auto-encoder)
   converge to a reasonable solution. */

/* Not that num layers INCLUDES the output layer */
struct FFNN*  init_FFNN(size_t num_layers, size_t *widths, 
			matrix** weights,  fp (*hidden_act_func)(fp),  
			fp learning_rate, fp (*output_func)(fp))
{
  /* Allocate necessary memory for the struct */
  struct FFNN* ffnn = malloc(size(struct FNNN));

  int i = 0;

  /* Least we can do is assert all component matrices of the passed in
     array of pointers to weight matrices are valid. There should
     be one less weight matrix than the given number here, as the 
     weight matrices only correspond to the spaces between layers */
  for (i = 0; i < num_layers - 1; i++)
    {
      is_valid( (*weights)[i]);      
    }

  /* All the memory should be allocated already. We just need to set it equal.
     The major allocation work needs to be done by the user of this file,
     which is a bit tedious but we are working in C after all */
  ffnn->num_layers = num_layers;
  ffnn->widths = widths;
  ffnn->weights = weights;
  ffnn->hidden_act_func = hidden_act_func;
  ffnn->learning_rate = learning_rate;
  ffnn->output_func = output_func;
  
  return ffnn;
}

/* Tedious since each vector of weights in 
   the chain must be freed. */
void free_FFNN(FFNN* ffnn)
{
  int i;

  free(ffnn->widths);

  for (i = 0; i < num_layers; i++)
    {
      free_matrix(weights[i]);
    }

  /* Then free the weight array itself */
  free(ffnn->weights);
}


/* returns an output vector for the current iteration. don't need
   to pass in a pointer since we don't need to change the network 
   itself in this function. It also needs an input data vector */

/* This could be multi-threaded tbh. Probably not worth the
   synchronization overhead. Save multi-threading for the pure 
   matrix computations. */

/* We only need a struct here not a pointer to the struct. 
   NOTE: the length of the input needs to match up with
   the length of the first layer: otherwise there is some
   problem here. */
matrix* forward_prop(FFNN ffnn, matrix* inp, size_t inp_length)
{
  /* On each iteration, we allocate a matrix of outputs. Once the 
     computation of the next layer is complete, we free the 
     previous layer. It is then the job of the receiving function
     to free the final output, which is naturally the only exception 
     to the above chain. */
  
  /* First assert the input length is the same as the width of the
     first layer */
  assert(inp_length == ffnn->widths[0]);

  matrix* prev_layer, next_layer;

  prev_layer = inp;
  
  /* Now iterate through and feed in previous layer into next. Note 
     allocating and re-allocating and free-ing this memory is *quite*
     inefficient: the reset function *needs* to be made more efficient
     somehow: TODO: look into how matlab allocates and resizes matrices
     on a system level. */
  int i, j;
  for (i = 0; i < ffnn->num_layers; i++)
    {
      reset_matrix(curr_output, ffnn->widths[i+1], 1);

      for (j = 1; j <= ffnn->widths[i+1]; j++)
	{
	  /* Apply weight multiplication and
	     activation function simultaneously. */
	  set_elem(curr_layer, 
		   j, 1, 
		   ffnn->hidden_act_func(naive_mat_mult(ffnn->weights[i]), 
					                prev_layer,
					                next_layer));
	}

       deep_copy(next_layer, prev_layer);
    }

  /* Then on the final layer use the output function */
  for (j = 1; j <= ffnn->widths[ffnn->num_layers - 1]; j++)
    {
      set_elem(curr_layer, 
	       j, 1, 
	       ffnn->output_func(naive_mat_mult(ffnn->weights[i]), 
					        prev_layer,
					        next_layer));
      
    }

  free_matrix(prev_layer);

  return next_layer;
}

/* performs one pass of back-propagation through the input
   neural network. For this... it needs an input matrix (really composed of
   multiple inputs), the current output this input produces, and the 
   corresponding desired output. Weights are updated based upon the neural 
   network's learning rate. */
void back_prop(FFNN* inp_ffnn, )
{

}

/* Given an activation function, a matrix of input data which corresponds
   to a matrix of output data, a learning rate, a set of data */
void train_FFNN(


