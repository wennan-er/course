#pragma once

#include <string>

namespace potd {
  class Thing {
  public:
    Thing(int);
    Thing(const Thing &);
    Thing & operator=(const Thing &);
    ~Thing();

    int set_property(std::string prop,std::string val);
    std::string get_property(std::string prop);

  private:

    void _copy(const Thing &);
    void _destroy();

    std::string *properties_;
    std::string *values_;
    int props_ct_;
    int props_max_;

  };
}
