/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 RC 1        *
*                (c) 2006-2011 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Plugins                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/

#include "Binding_SubsetMultiMapping.h"
#include "Binding_BaseMapping.h"
#include <SofaMiscMapping/SubsetMultiMapping.h>


typedef sofa::component::mapping::SubsetMultiMapping< sofa::defaulttype::Vec3Types, sofa::defaulttype::Vec3Types > SubsetMultiMapping3_to_3;
#ifndef SOFA_FLOAT
typedef sofa::component::mapping::SubsetMultiMapping< sofa::defaulttype::Vec3dTypes, sofa::defaulttype::Vec3dTypes > SubsetMultiMapping3d_to_3d;
#endif
#ifndef SOFA_DOUBLE
typedef sofa::component::mapping::SubsetMultiMapping< sofa::defaulttype::Vec3fTypes, sofa::defaulttype::Vec3fTypes > SubsetMultiMapping3f_to_3f;
#endif

#include <sofa/core/BaseState.h>
using namespace sofa::component::mapping;
using namespace sofa::core::objectmodel;

extern "C" PyObject * SubsetMultiMapping3_to_3_addPoint(PyObject *self, PyObject * args)
{
    SubsetMultiMapping3_to_3* obj=dynamic_cast<SubsetMultiMapping3_to_3*>(((PySPtr<Base>*)self)->object.get());
    PyObject* pyState;
    int index;
    if (!PyArg_ParseTuple(args, "Oi",&pyState,&index))
    {
        PyErr_BadArgument();
        Py_RETURN_NONE;
    }
    sofa::core::BaseState* state=dynamic_cast<sofa::core::BaseState*>(((PySPtr<Base>*)pyState)->object.get());

    obj->addPoint(state,index);
    Py_RETURN_NONE;
}

SP_CLASS_METHODS_BEGIN(SubsetMultiMapping3_to_3)
SP_CLASS_METHOD(SubsetMultiMapping3_to_3,addPoint)
SP_CLASS_METHODS_END


#ifndef SOFA_FLOAT
SP_CLASS_TYPE_SPTR(SubsetMultiMapping3_to_3,SubsetMultiMapping3d_to_3d,BaseMapping) // temp: MultiMapping3_to_3
#else
SP_CLASS_TYPE_SPTR(SubsetMultiMapping3_to_3,SubsetMultiMapping3f_to_3f,BaseMapping) // temp: MultiMapping3_to_3
#endif


