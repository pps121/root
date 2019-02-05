/// \file ROOT/RTreeEntry.hxx
/// \ingroup Forest ROOT7
/// \author Jakob Blomer <jblomer@cern.ch>
/// \date 2018-07-19
/// \warning This is part of the ROOT 7 prototype! It will change without notice. It might trigger earthquakes. Feedback
/// is welcome!

/*************************************************************************
 * Copyright (C) 1995-2015, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT7_RTreeEntry
#define ROOT7_RTreeEntry

#include <ROOT/RTreeField.hxx>
#include <ROOT/RTreeValue.hxx>

#include <memory>
#include <utility>
#include <vector>

namespace ROOT {
namespace Experimental {

// clang-format off
/**
\class ROOT::Experimental::RTreeEntry
\ingroup Forest
\brief The RTreeEntry is a collection of tree values corresponding to a complete row in the data set

*/
// clang-format on
class RTreeEntry {
   std::vector<std::unique_ptr<Detail::RTreeValueBase>> fTreeValues;

public:
   RTreeEntry() = default;

   /// While building the entry, adds a new value to the list and return the value's shared pointer
   void TakeValue(Detail::RTreeValueBase* value) {
      fTreeValues.emplace_back(value);
   }

   decltype(fTreeValues)::iterator begin() { return fTreeValues.begin(); }
   decltype(fTreeValues)::iterator end() { return fTreeValues.end(); }
};

} // namespace Experimental
} // namespace ROOT

#endif
