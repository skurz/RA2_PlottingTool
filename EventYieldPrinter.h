// $Id: EventYieldPrinter.h,v 1.5 2013/04/22 16:21:34 mschrode Exp $

#ifndef EVENT_YIELD_PRINTER_H
#define EVENT_YIELD_PRINTER_H

#include <vector>

#include "TString.h"

class EventYieldPrinter {
public:
  EventYieldPrinter();

private:
  const DataSets inputDataSets_;

  std::vector< std::vector<TString> > summaryTable_;
  std::vector< std::vector<TString> > summaryTableLatex_;
  std::vector<unsigned int> summaryTableColw_;
  std::vector<unsigned int> summaryTableLatexColw_;

  void prepareSummaryTable();
  void printToScreen() const;
  void printToLaTeX(const TString &outFileName) const;
  void printDataCard(const TString &outFileName) const;
};
#endif
