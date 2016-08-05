#include <iostream>
#include <string.h>
#include <sys/utsname.h>
using namespace std;

#define HPUX "HPUX"
#define SUNOS "SunOS"

class Product {
  public :
    virtual Product* Clone()=0;
};

class HPScanner : public Product {
  public :
    Product* Clone() { return new HPScanner(*this); }
};

class HPParser : public Product {
  public :
    Product* Clone() { return new HPParser(*this); }
};

class HPCodeGenerator : public Product {
  public :
    Product* Clone() { return new HPCodeGenerator(*this); }
};

class HPOptimizer : public Product {
  public :
    Product* Clone() { return new HPOptimizer(*this); }
};

class SunScanner : public Product {
  public :
    Product* Clone() { return new SunScanner(*this); }
};

class SunParser : public Product {
  public :
    Product* Clone() { return new SunParser(*this); }
};

class SunCodeGenerator : public Product {
  public :
    Product* Clone() { return new SunCodeGenerator(*this); }
};

class SunOptimizer : public Product {
  public :
    Product* Clone() { return new SunOptimizer(*this); }
};

// -- �߰� �ʿ� �κ� ����
class HPErrorHandler : public Product {
  public :
    Product* Clone() { return new HPErrorHandler(*this); }
};

class SunErrorHandler : public Product {
  public :
    Product* Clone() { return new SunErrorHandler(*this); }
};
// -- �߰� �ʿ� �κ� ��

class CompilerFactory {  
  public :    
    virtual Product* CreateProduct(Product *p) = 0;  
};

class HPCompilerFactory : public CompilerFactory {  
  public :    
    Product* CreateProduct(Product *p) { 
       return p->Clone();
    }
};

class SunCompilerFactory : public CompilerFactory {  
  public :    
    Product* CreateProduct(Product *p) { 
      return p->Clone();
    }
};

CompilerFactory *pFactory;  

int main() {  
  Product *pScanner, *pParser, *pCodeGenerator, *pOptimizer;
  Product *pErrorHandler; // -- �߰� �ʿ�
  struct utsname sysInfo;

  // -- OS ���� �� �ϵ���� Ÿ�� ���� ��� ���� �ý��� �Լ�  
  if (uname(&sysInfo) < 0) { 
    cout << "Error Occurred" << endl;
    return(-1);
  }

  if (strncasecmp(sysInfo.sysname, HPUX, strlen(HPUX)) == 0) {  
    // -- HP �� ��ü ���� �� ���
    pScanner = new HPScanner;
    pParser = new HPParser;
    pCodeGenerator = new HPCodeGenerator;
    pOptimizer = new HPOptimizer;
    pErrorHandler = new HPErrorHandler; // -- �߰� �ʿ�

    pFactory = new HPCompilerFactory;
  }
  else if (strncasecmp(sysInfo.sysname, SUNOS, strlen(SUNOS)) == 0) {  
    // -- Sun �� ��ü ���� �� ���
    pScanner = new SunScanner;
    pParser = new SunParser;
    pCodeGenerator = new SunCodeGenerator;
    pOptimizer = new SunOptimizer;
    pErrorHandler = new SunErrorHandler; // -- �߰� �ʿ�

    pFactory = new SunCompilerFactory;
  }
  else {  
    // -- ���� ���ϴ� �ý��� ȯ��  
    cout << sysInfo.sysname << endl;
    return(0);
  }

  Product *pNewScanner = pFactory->CreateProduct(pScanner);
  Product *pNewParser = pFactory->CreateProduct(pParser);
  Product *pNewCodeGenerator = pFactory->CreateProduct(pCodeGenerator);
  Product *pNewOptimizer = pFactory->CreateProduct(pOptimizer);
  // -- Product *pNewErrorHandler = pFactory->CreateProduct(pErrorHandler);
}