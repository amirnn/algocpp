
#pragma once

#include "types.hpp"

class UF
{

public:
  
  UF(u64 node_count);
  
  ~UF();
  
  void unite(u64 id);

  bool connected(u64 id);
  
  static bool connected(u64 id1, u64 id2);

  u64 find();
  
  u64 count();

private:
  const u64 m_node_count;

};
