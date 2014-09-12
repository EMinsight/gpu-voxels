// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of the GPU Voxels Software Library.
//
// This program is free software licensed under the CDDL
// (COMMON DEVELOPMENT AND DISTRIBUTION LICENSE Version 1.0).
// You can find a copy of this license in LICENSE.txt in the top
// directory of the source code.
//
// © Copyright 2014 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Matthias Wagner
 * \date    2014-07-09
 *
 * \brief This class is for the management of the interprocess communication with the provider.
 *
 */
//----------------------------------------------------------------------
#ifndef GPU_VOXELS_VISUALIZATION_SHAREDMEMORYMANAGERVISUALIZER_H_INCLUDED
#define GPU_VOXELS_VISUALIZATION_SHAREDMEMORYMANAGERVISUALIZER_H_INCLUDED

#include <gpu_visualization/SharedMemoryManager.h>
#include <gpu_voxels/vis_interface/VisualizerInterface.h>
#include <boost/lexical_cast.hpp>
#include <glm/glm.hpp>

namespace gpu_voxels {
namespace visualization {
class SharedMemoryManagerVisualizer: public SharedMemoryManager
{
public:
  SharedMemoryManagerVisualizer() :
      SharedMemoryManager(shm_segment_name_visualizer, false)
  {
  }
  bool getCameraTargetPoint(glm::vec3& target);
  bool getPrimitivePositions(glm::vec3*& d_positions, uint32_t& size, PrimitiveTypes& type);
  bool hasPrimitiveBufferChanged();
  void setPrimitiveBufferChangedToFalse();
  DrawTypes getDrawTypes();

private:

}
;
} //end of namespace visualization
} //end of namespace gpu_voxels
#endif /* GPU_VOXELS_VISUALIZATION_SHAREDMEMORYMANAGERVISUALIZER_H_INCLUDED */
