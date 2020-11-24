#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

class Import {
    public:
      virtual string doOperation(string type) = 0;
};

class ImportTXT:public Import {
    public:
      string doOperation(string type) {
        return "This is a .TXT file.";
      }
};
class ImportJSON:public Import {
    public:
      string doOperation(string type) {
        return "This is a .JSON file.";
      }
};
class ImportXML:public Import {
   public:
      string doOperation(string type) {
        return "This is a .XML file.";
      }
};
class ImportCSV:public Import {
   public:
      string doOperation(string type) {
        return "This is a .CSV file.";
      }
};

class Context {
  private:
    Import *ImportStrategy;

  public:
    Context(Import *new_strategy){
      ImportStrategy = new_strategy;
    }
   
    void changeStrategy(Import *new_strategy){
      ImportStrategy = new_strategy;
    }

    string executeStrategy(string type){
      return ImportStrategy->doOperation(type);
   }
};

int main() {

  cout << "Give me a file path. (This is a command)" << endl;
  string input;
  vector<string> deliver;
  cin >> input;
  split(deliver, input, boost::is_any_of("."));
  cout << "You entered: " + deliver[1] << endl;

  if (deliver.size() > 2) {  
    return 0;

  } else if (deliver[1].compare("TXT") == 0 || 
      deliver[1].compare("txt") == 0) {
    ImportTXT imp;
    Context context(&imp);
    cout << context.executeStrategy(deliver[1]);
    return 0;

  } else if (deliver[1].compare("JSON") == 0 || 
      deliver[1].compare("json")== 0) {
    ImportJSON imp;
    Context context(&imp);
    cout << context.executeStrategy(deliver[1]);
    return 0;

  } else if (deliver[1].compare("XML") == 0 ||
      deliver[1].compare("xml") == 0) {
    ImportXML imp;
    Context context(&imp);
    cout << context.executeStrategy(deliver[1]);
    return 0;

  } else if (deliver[1].compare("CSV") == 0 || 
      deliver[1].compare("csv") == 0) {
    ImportCSV imp;
    Context context(&imp);
    cout << context.executeStrategy(deliver[1]);
    return 0;

  } else {
    cout << "You entered an unsupported file type.";
    return 0; 
    
  }
  return 0; 
}
