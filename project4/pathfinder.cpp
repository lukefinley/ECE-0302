#include <iostream>
#include "image.h"
#include "deque.hpp"

int x = -1, y = -1;

void initial(Image<Pixel>& img);
bool goal(Image<Pixel>& img);
void breadth_first_search(Image<Pixel>& img);
bool present(Deque<int> d, int x_val, int y_val);
Deque<int> actions(Image<Pixel>& img, int x_val, int y_val);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cout << "Usage: compare"
              << "<first_input_filename> <secont_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  Image<Pixel> img = readFromFile(argv[1]); // Read input file
  breadth_first_search(img);  // Preform search

  // Error Check
  if (x == -1 && y == -1)
    return EXIT_FAILURE;

  writeToFile(img, argv[2]);  // Write to output file
}

void breadth_first_search(Image<Pixel>& img)
{
  // Get initial point, and check to see if at goal
  initial(img);
  if (goal(img) || (x == -1 && y == -1))
    return;

  // Creat new deques for frontier and explored
  Deque<int> frontier;
  Deque<int> explored;

  // Put the initial array in the frontier
  frontier.pushBack(x); 
  frontier.pushBack(y);

  while (true)
  {
    // Return failure if frontier is empty
    if (frontier.isEmpty())
    {
      x = -1;
      y = -1;
      return;
    }

    // Pop next state from frontier
    x = frontier.front();
    frontier.popFront();
    y = frontier.front();
    frontier.popFront();

    // Add location to explored
    explored.pushBack(x);
    explored.pushBack(y);

    Deque<int> next = actions(img, x, y); // Create next deque from actions

    // Loop through next actions
    for (int i = 0; i < next.size(); i += 2)
    {
      // Get coordinates from next array
      x = next.front();
      next.popFront();
      y = next.front();
      next.popFront();

      // If next coordinates are not in explored or frontier
      if (present(explored, x, y) == false || present(frontier, x, y) == false)
      {
        // Return if the coordinates are a goal
        if (goal(img))
          return;
        
        // Insert next location into frontier
        frontier.pushBack(x);
        frontier.pushBack(y);
      }
    }
  }
}

// Function that sets the initial state
void initial(Image<Pixel>& img)
{
  // Loop through all of the pixels
  for (int i = 0; i < img.height(); i++)
  {
    for (int j = 0; j < img.width(); j++)
    {
      // If red pixel found, set coordinates to initial positions
      if (img(i, j) == RED && x == -1 && y == -1)
      {
        x = i;
        y = j;
      }
      // Error check
      else if ((img(i, j) == RED && x != -1 && y != -1) || (img(i, j) != WHITE && img(i, j) != RED && img(i, j) != BLACK))
      {
        x = -1;
        y = -1;
        return;
      }
    }
  }
}

// Function that returns if the current position is the goal state
bool goal(Image<Pixel>& img)
{
  // If on boundary, set to green and return true
  if (x == 0 || y == 0 || x == img.height() - 1 || y == img.width() - 1)
  {
    img(x, y) = GREEN;
    return true;
  }
  else
    return false;
}

// Function that returns possible moves
Deque<int> actions(Image<Pixel>& img, int x_val, int y_val)
{
  Deque<int> next;

  if (img(x + 1, y) == WHITE)
  {
    next.pushBack(x + 1);
    next.pushBack(y);
  }
  if (img(x - 1, y) == WHITE)
  {
    next.pushBack(x - 1);
    next.pushBack(y);
  }
  if (img(x, y + 1) == WHITE)
  {
    next.pushBack(x);
    next.pushBack(y + 1);
  }
  if (img(x, y - 1) == WHITE)
  {
    next.pushBack(x);
    next.pushBack(y - 1);
  }

  return next;
}

// Function that checks if the coordinates match
bool present(Deque<int> d, int x_val, int y_val)
{
  // Loop through all values in deque
  for (int i = 0; i < d.size(); i += 2)
  {
    if (d.front() == x_val)
    {
      d.popFront();
      if (d.front() == y_val)
        return true;
      d.popFront();
    }
    else
    {
      d.popFront();
      d.popFront();
    }
  }
  return false;
}
