#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 *
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  stacktmp.push(start);

  toler = tolerance;
  image = png;
  Pixelstart=png.getPixel(start.x,start.y);
  visited.resize(image.width());
 for (unsigned i = 0; i < visited.size(); i++) {
   visited[i].resize(image.height());
     for (unsigned j = 0; j < visited[i].size(); j++) {
       visited[i][j] = false;
     }
 }
  visited[start.x][start.y] = true;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */

      if (canbeadded(point)){
        if (!isinvisited(point)){
         stacktmp.push(point);
       }
    }
  }


/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  if (stacktmp.empty()){
    return Point(-1,-1);
  }
  Point curr = stacktmp.top();
  if (!isinvisited(curr)){
      visited[curr.x][curr.y] = true;
  }
  stacktmp.pop();

  return curr;
}



/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  if (empty()){
    return Point(-1, -1);
  }
  return stacktmp.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if (stacktmp.empty()){
    return true;
  }
  return false;
}
