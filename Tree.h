#include <string>
using namespace std;

class Tree {
public:
  virtual void Insert(string key, string value) = 0;
  virtual string Search(string key) = 0;
};
