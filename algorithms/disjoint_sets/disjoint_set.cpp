#include <cstddef>

#include "disjoint_set.h"

DJS_Node::DJS_Node(int id) {
  this->m_id = id;
  this->m_rank = 0;
  this->m_parent = this;
}

DJS_Node* DJS_Find(DJS_Node* x) {
  DJS_Node* root = x;

  while(root->getParent() != root) {
    root = root->getParent();
  }

  while(x->getParent() != root) {
    DJS_Node* tmp = x->getParent();
    x->setParent(root);
    x = tmp;
  }

  return root;
}

void DJS_Union(DJS_Node* x, DJS_Node* y) {

  DJS_Node* x_root = DJS_Find(x);
  DJS_Node* y_root = DJS_Find(y);
  
  if (x_root == y_root) {
    return;
  }

  // Swap x and y if rank(x) < rank(y) to ensure a balanced tree asymptotically
  if (x_root->getRank() < y_root->getRank()) {
    DJS_Node* tmp = x_root;
    x_root = y_root;
    y_root = tmp;
  }

  y_root->setParent(x_root);

  // Update rank if necessary
  if (x_root->getRank() == y_root->getRank()) {
    x_root->incRank();
  }
  
}




