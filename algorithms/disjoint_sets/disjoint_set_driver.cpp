#include <iostream>
#include <vector>

#include "disjoint_set.h"

using namespace std;

/* Demonstration for the Disjoint Set data structure
 * 
 * Graph:
 * V = [0, 1, 2, 3, 4, 5, 6]
 * E = [[0, 6], [1,4], [4,6], [6,1], [2,5]] (undirected edges)
 *
 * End result:
 * Set 1: [0, 1, 4, 6]
 * Set 2: [2, 5]
 * Set 3: [3]
 */

int main() {

  vector<int> vertices{0, 1, 2, 3, 4, 5, 6};
  vector<vector<int>> edges{{0, 6}, {1, 4}, {4, 6}, {6, 1}, {2, 5}};

  vector<DJS_Node*> forest;

  for(int v : vertices) {
    DJS_Node* nodePtr = new DJS_Node(v);
    forest.push_back(nodePtr);
  }

  for(vector<int> e : edges) {
    DJS_Union(forest[e[0]], forest[e[1]]);
  }
  
  DJS_Node* r0 = DJS_Find(forest[0]);
  DJS_Node* r1 = DJS_Find(forest[1]);
  DJS_Node* r2 = DJS_Find(forest[2]);
  DJS_Node* r3 = DJS_Find(forest[3]);
  DJS_Node* r4 = DJS_Find(forest[4]);
  DJS_Node* r5 = DJS_Find(forest[5]);
  DJS_Node* r6 = DJS_Find(forest[6]);

  cout << "Expect r0 == r1 == r4 == r6. Actual r0 = " << r0->getId() <<
                                            ", r1 = " << r1->getId() <<
                                            ", r4 = " << r4->getId() <<
                                            ", r6 = " << r6->getId() << "\n";

  cout << "Expect r2 == r5. Actual r2 = " << r2->getId() <<
                                ", r5 = " << r5->getId() << "\n";

  cout << "Expect r3 = 3. Actual r3 = " << r3->getId() << "\n";

  return 0;
}
