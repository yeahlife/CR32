#ifndef NAMESPACEINT_H
#define NAMESPACEINT_H
namespace Int {
  enum sign { positive, negative };
  struct Integer {
    int i;
    sign s;
    sign getSign() const {
      return s; 
    }
    void setSign(sign sgn) { 
      s = sgn; 
    }
    // ...
  };
}
#endif // NAMESPACEINT_H ///:~