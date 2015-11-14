// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2015 Alec Jacobson <alecjacobson@gmail.com>
//                    Qingnan Zhou <qnzhou@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
//
#ifndef IGL_COPYLEFT_BOOLEAN_MESH_BOOLEAN_H
#define IGL_COPYLEFT_BOOLEAN_MESH_BOOLEAN_H

#include "../../igl_inline.h"
#include "MeshBooleanType.h"
#include <Eigen/Core>
#include <functional>

namespace igl
{
  namespace copyleft
  {
    namespace boolean
    {
      template <
        typename DerivedVA,
        typename DerivedFA,
        typename DerivedVB,
        typename DerivedFB,
        typename WindingNumberOp,
        typename KeepFunc,
        typename ResolveFunc,
        typename DerivedVC,
        typename DerivedFC,
        typename DerivedJ>
      IGL_INLINE void per_face_winding_number_binary_operation(
          const Eigen::PlainObjectBase<DerivedVA> & VA,
          const Eigen::PlainObjectBase<DerivedFA> & FA,
          const Eigen::PlainObjectBase<DerivedVB> & VB,
          const Eigen::PlainObjectBase<DerivedFB> & FB,
          const WindingNumberOp& wind_num_op,
          const KeepFunc& keep,
          const ResolveFunc& resolve_fun,
          Eigen::PlainObjectBase<DerivedVC > & VC,
          Eigen::PlainObjectBase<DerivedFC > & FC,
          Eigen::PlainObjectBase<DerivedJ > & J);

      template <
        typename DerivedVA,
        typename DerivedFA,
        typename DerivedVB,
        typename DerivedFB,
        typename DerivedVC,
        typename DerivedFC,
        typename DerivedJ>
      IGL_INLINE void mesh_boolean(
          const Eigen::PlainObjectBase<DerivedVA > & VA,
          const Eigen::PlainObjectBase<DerivedFA > & FA,
          const Eigen::PlainObjectBase<DerivedVB > & VB,
          const Eigen::PlainObjectBase<DerivedFB > & FB,
          const MeshBooleanType & type,
          Eigen::PlainObjectBase<DerivedVC > & VC,
          Eigen::PlainObjectBase<DerivedFC > & FC,
          Eigen::PlainObjectBase<DerivedJ > & J);

      template <
        typename DerivedVA,
        typename DerivedFA,
        typename DerivedVB,
        typename DerivedFB,
        typename DerivedVC,
        typename DerivedFC>
      IGL_INLINE void mesh_boolean(
          const Eigen::PlainObjectBase<DerivedVA > & VA,
          const Eigen::PlainObjectBase<DerivedFA > & FA,
          const Eigen::PlainObjectBase<DerivedVB > & VB,
          const Eigen::PlainObjectBase<DerivedFB > & FB,
          const MeshBooleanType & type,
          Eigen::PlainObjectBase<DerivedVC > & VC,
          Eigen::PlainObjectBase<DerivedFC > & FC);
    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#  include "mesh_boolean.cpp"
#endif

#endif
