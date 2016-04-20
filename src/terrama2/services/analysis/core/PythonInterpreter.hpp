/*
  Copyright (C) 2007 National Institute For Space Research (INPE) - Brazil.

  This file is part of TerraMA2 - a free and open source computational
  platform for analysis, monitoring, and alert of geo-environmental extremes.

  TerraMA2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License,
  or (at your option) any later version.

  TerraMA2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with TerraMA2. See LICENSE. If not, write to
  TerraMA2 Team at <terrama2-team@dpi.inpe.br>.
*/

/*!
  \file terrama2/services/analysis/core/PythonInterpreter.hpp

  \brief Manages the communication of Python and C.

  \author Paulo R. M. Oliveira
*/


#ifndef __TERRAMA2_ANALYSIS_CORE_PYTHONINTERPRETER_HPP__
#define __TERRAMA2_ANALYSIS_CORE_PYTHONINTERPRETER_HPP__

#include "Analysis.hpp"

#include <boost/python.hpp>

namespace terrama2
{
  namespace services
  {
    namespace analysis
    {
      namespace core
      {
        enum StatisticOperation
        {
          MIN = 1,
          MAX = 2,
          SUM = 3,
          MEAN = 4,
          MEDIAN = 5,
          STANDARD_DEVIATION = 6,
          COUNT = 7
        };

        enum Buffer
        {
          NONE = 0,
          EXTERN = 1,
          INTERN = 2,
          INTERN_PLUS_EXTERN = 3,
          OBJECT_PLUS_EXTERN = 4,
          OBJECT_WITHOUT_INTERN = 5
        };

        void addValue(const std::string& attribute, double value);


        double dcpOperator(StatisticOperation statisticOperation, const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());
        int dcpCount(const std::string& dataSeriesName, double radius, Buffer bufferType);
        double dcpMin(const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());
        double dcpMax(const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());
        double dcpMean(const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());
        double dcpMedian(const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());
        double dcpSum(const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());
        double dcpStandardDeviation(const std::string& dataSeriesName, const std::string& attribute, double radius, Buffer bufferType, boost::python::list ids = boost::python::list());

        double dcpHistoryOperator(StatisticOperation statisticOperation, const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);
        double dcpHistorySum(const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);
        double dcpHistoryMean(const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);
        double dcpHistoryMin(const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);
        double dcpHistoryMax(const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);
        double dcpHistoryMedian(const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);
        double dcpHistoryStandardDeviation(const std::string& dataSeriesName, const std::string& attribute, uint64_t dcpId, const std::string& dateFilter);


        int occurrenceCount(const std::string& dataSeriesName, double radius, Buffer bufferType, std::string dateFilter, std::string restriction);

        void exportDCP();
        void exportOccurrence();

        void initInterpreter();
        void finalizeInterpreter();

        void runPythonScript(std::string script, boost::python::dict dictMain);
        void runScriptMonitoredObjectAnalysis(PyThreadState* state, uint64_t analysisId, std::vector<uint64_t> indexes);
        void runScriptDCPAnalysis(PyThreadState* state, uint64_t analysisId);

      } // end namespace core
    }   // end namespace analysis
  }     // end namespace services
}       // end namespace terrama2

#endif //__TERRAMA2_ANALYSIS_CORE_PYTHONINTERPRETER_HPP__