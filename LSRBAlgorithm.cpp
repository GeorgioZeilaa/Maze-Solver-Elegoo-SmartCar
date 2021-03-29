#include "LSRBAlgorithm.h"

void LSRBAlgorithm::increment(char letter)
{
  //to add a direction to the path char array
  path[path_size] = letter;
  //making sure that the path_size integer is ready for the next char to be inserted into the array
  path_size++;

  //checking if the array has the B character before the recently inserted character
  //minus 2 since the path_size has 1 extra added to be ready for the next increment
  if (path[path_size - 2] == 'B')
  {
     arrange();//to arrange the path if there is a rule that is met
  }
}

int LSRBAlgorithm::arrange()
{
  //if the left and right of B character correspond to a correct rule then it will change it to the shorter direction
  if (path[path_size - 3] == 'L' && path[path_size-1] == 'R')
  {
    path_size -= 3;
    path[path_size] = 'B';
    path_size++;
    return 1;
  }
  if (path[path_size - 3] == 'L' && path[path_size - 1] == 'S')
  {
    path_size -= 3;
    path[path_size] = 'R';
    path_size++;
    return 1;
  }
  if (path[path_size - 3] == 'R' && path[path_size - 1] == 'L')
  {
    path_size -= 3;
    path[path_size] = 'B';
    path_size++;
    return 1;
  }
  if (path[path_size - 3] == 'S' && path[path_size - 1] == 'L')
  {
    path_size -= 3;
    path[path_size] = 'R';
    path_size++;
    return 1;
  }
  if (path[path_size - 3] == 'S' && path[path_size - 1] == 'S')
  {
    path_size -= 3;
    path[path_size] = 'B';
    path_size++;
    return 1;
  }
  if (path[path_size - 3] == 'L' && path[path_size - 1] == 'L')
  {
    path_size -= 3;
    path[path_size] = 'S';
    path_size++;
    return 1;
  }
}

char LSRBAlgorithm::receive()
{
  //to return all the path unless it is equal to the size of the path
  if (path_size != receive_index)
  {
    receive_index++;
  }
  return path[receive_index-1];//returns the letter of the direction
}
