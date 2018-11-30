#ifndef VARIABLE_H
#define VARIABLE_H

#include <map>
#include <set>
#include <vector>

#include "TString.h"

#include "Config.h"

class Variable {
  friend class EventBuilder;
  
public:
  static void checkIfIsInit();
  static void init(const Config &cfg, const TString &key);
  static bool validType(const TString &type);
  static bool exists(const TString &name);

  static unsigned int nVars() { return names_.size(); }
  static std::vector<TString>::const_iterator begin() { return names_.begin(); }
  static std::vector<TString>::const_iterator end() {  return names_.end(); }
  static TString type(const TString& name);

  static TString label(const TString &name);
  static TString unit(const TString &name);


protected:
  static bool isArrayField(const TString &name) { return arrayNames_.find(name) != arrayNames_.end(); }
  static unsigned int arrayFieldIndex(const TString &name);
  static TString baseName(const TString &name);


private:
  static bool isInit_;
  static std::set<TString> validTypes_;
  static std::vector<TString> names_;
  static std::map<TString,TString> types_;
  static std::map<TString,TString> arrayNames_;
  static std::map<TString,unsigned int> arrayFieldIndices_;
  static std::map<TString,TString> labels_;
  static std::map<TString,TString> units_;
};
#endif
