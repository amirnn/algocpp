
#pragma once

#include "Types.hpp"

class UF
{

public:
  
  UF(u64 n);
  
  ~UF();
  
  void unite(u64 id);

  bool connected(u64 id);
  
  static bool connected(u64 id1, u64 id2);

  u64 find();
  
  u64 count();

private:
  const u64 _id;

};
