#pragma once
#include <string>
using namespace std;

class Link {
private:
  string material;

public:
  Link(string material) {
    this->material = material;
  }

  string get_material() {
    return this->material;
  }
};