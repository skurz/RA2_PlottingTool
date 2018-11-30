#include <iostream>

#include "Config.h"
#include "DataSet.h"
#include "Selection.h"
#include "Style.h"


std::map<TString,int> Style::markers_;
std::map<TString,int> Style::colors_;
std::map<TString,TString> Style::dataSetLabels_;
std::map<TString,TString> Style::selectionLabels_;
bool Style::plotYields_ = true;


void Style::init(const Config &cfg, const TString &key) {
  std::cout << "  Setting style parameters...  " << std::flush;
  std::vector<Config::Attributes> attrList = cfg(key);
  for(std::vector<Config::Attributes>::const_iterator it = attrList.begin();
      it != attrList.end(); ++it) {

    // Style parameters related to datasets
    if( it->hasName("dataset") ) {
      TString dataSetLabel = it->value("dataset");
      if( it->hasName("marker") && it->isInteger("marker") ) {
	markers_[dataSetLabel] = it->valueInteger("marker");
      }
      if( it->hasName("color") ) {
	colors_[dataSetLabel] = cfg.color(it->value("color"));
      }
      if( it->hasName("plot label") ) {
	dataSetLabels_[dataSetLabel] = it->value("plot label");
      }
    }

    // Style parameters related to selections
    if( it->hasName("selection") ) {
      TString selectionLabel = it->value("selection");
      if( it->hasName("plot label") ) {
	selectionLabels_[selectionLabel] = it->value("plot label");
      }
    }

    // Plotting parameters
    if( it->hasName("plot yields") ) {
      if( it->isBoolean("plot yields") ) {
	plotYields_ = it->valueBoolean("plot yields");
      }
    }
  }

  std::cout << "ok" << std::endl;
}


TString Style::tlatexType(const DataSet* dataSet) {
  TString label = "";
  if( dataSet->type() == DataSet::Data )              label = "Data";
//  else if( dataSet->type() == DataSet::MC )           label = "Sim.";
  else if( dataSet->type() == DataSet::MC )           label = "MC";
  else if( dataSet->type() == DataSet::Prediction )   label = "Pred.";
  else if( dataSet->type() == DataSet::MCPrediction ) label = "Pred.";
  else if( dataSet->type() == DataSet::Signal )       label = "Signal";

  return label;
}





