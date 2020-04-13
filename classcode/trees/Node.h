#pragma once

class Node {
 private:
  int data;
  Node *left;
  Node *right;
 public:
  Node();
  Node(int data);
  Node(int d, Node *left, Node *right);
  int getData();
  Node *getLeft();
  Node *getRight();

  void setData(int d);
  void setLeft(Node *l);
  void setRight(Node *r);

};
