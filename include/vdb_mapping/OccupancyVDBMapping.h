// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// Copyright 2021 FZI Forschungszentrum Informatik
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Marvin Große Besselmann grosse@fzi.de
 * \author  Lennart Puck puck@fzi.de
 * \date    2021-04-29
 *
 */
//----------------------------------------------------------------------
#ifndef VDB_MAPPING_OCCUPANCY_VDB_MAPPING_H_INCLUDED
#define VDB_MAPPING_OCCUPANCY_VDB_MAPPING_H_INCLUDED

#include "vdb_mapping/VDBMapping.h"

class OccupancyVDBMapping : public VDBMapping<float>
{
public:
  /*!
   * \brief Accumulation of configuration parameters
   */
  struct Config : BaseConfig
  {
    double prob_hit;
    double prob_miss;
    double prob_thres_min;
    double prob_thres_max;
  };

  OccupancyVDBMapping(const double resolution)
    : VDBMapping<float>(resolution)
  {
  }

  /*!
   * \brief Handles changing the mapping config
   *
   * \param config Configuration structure
   */
  void setConfig(const Config confiig);

protected:
  bool updateNode(openvdb::FloatGrid::Ptr& temp_grid) override;

  /*!
   * \brief Probability update value for passing an obstacle
   */
  double m_logodds_hit;
  /*!
   * \brief Probability update value for passing free space
   */
  double m_logodds_miss;
  /*!
   * \brief Upper occupancy probability threshold
   */
  double m_logodds_thres_min;
  /*!
   * \brief Lower occupancy probability threshold
   */
  double m_logodds_thres_max;
};

#endif /* VDB_MAPPING_OCCUPANCY_VDB_MAPPING_H_INCLUDED */
