#ifndef DISJOINT_SET
#define DISJOINT_SET

// your code goes here

class DJS_Node
{
private:
  int m_id;
  int m_rank;
  DJS_Node* m_parent;

public:
  DJS_Node(int id);

  DJS_Node* getParent() const { return m_parent; }
  void setParent(DJS_Node* parent) { m_parent = parent; }

  int getId() const { return m_id; }
  void setId(int id) {m_id = id; }

  int getRank() const { return m_rank; }
  void setRank(int rank) { m_rank = rank; }
  void incRank() { m_rank++; }
};


DJS_Node* DJS_Find(DJS_Node* x);
  
void DJS_Union(DJS_Node* x, DJS_Node* y);

#endif
