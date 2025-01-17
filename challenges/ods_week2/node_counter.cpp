#include <iostream>
/**
 * Your job is to implement the function "int count(Node *n)" that computes and returns the number of nodes in the binary tree that has n as its root.
 * When you write your code below, assume that a class type called "Node" has already been defined for you; you cannot change the class definition.
 * This class type has two child pointers ("left" , "right").
 * There is also a constructor Node() that initializes the children to nullptr and a destructor that deallocates the subtree's memory recursively.
 */

/********************************************************
You may assume that the following Node class has already
been defined for you previously:

class Node {
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

You may also assume that iostream has already been included.

Implement the function "int count(Node *n)" below to return
an integer representing the number of nodes in the subtree
of Node n (including Node n itself).

*********************************************************/
class Node
{
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node()
  {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

int count(Node *n)
{
  int nodeSum = 1;
  if (n != nullptr)
  {
    nodeSum = count(n->left) + count(n->right);
    nodeSum += 1;
    return nodeSum;
  }
  else
  {
    return 0;
  }
  return nodeSum;
}

int main()
{
  Node *n = new Node();
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();

  // This should print a count of six nodes
  std::cout << count(n) << std::endl;

  // Deleting n is sufficient to delete the entire tree
  // because this will trigger the recursively-defined
  // destructor of the Node class.
  delete n;
  n = nullptr;

  return 0;
}