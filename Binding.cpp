/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2016 INRIA, USTL, UJF, CNRS, MGH                    *
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
//#include "PythonCommon.h"
#include "PythonMacros.h"
#include "Binding.h"
#include "Binding_SofaModule.h"

#include "Binding_Data.h"
#include "Binding_DisplayFlagsData.h"
#include "Binding_OptionsGroupData.h"
#include "Binding_Link.h"
#include "Binding_Base.h"
#include "Binding_BaseObject.h"
#include "Binding_BaseState.h"
#include "Binding_BaseContext.h"
#include "Binding_Context.h"
#include "Binding_Node.h"
#include "Binding_Vector.h"
#include "Binding_BaseLoader.h"
#include "Binding_MeshLoader.h"
#include "Binding_Topology.h"
#include "Binding_BaseMeshTopology.h"
#include "Binding_MeshTopology.h"
#include "Binding_GridTopology.h"
#include "Binding_RegularGridTopology.h"
#include "Binding_BaseMechanicalState.h"
#include "Binding_MechanicalObject.h"
#include "Binding_PythonScriptController.h"
#include "Binding_LinearSpring.h"
#include "Binding_BaseMapping.h"
//#include "Binding_Mapping.h"
//#include "Binding_RigidMapping.h"
//#include "Binding_MultiMapping.h"
#include "Binding_SubsetMultiMapping.h"
#include "Binding_VisualModel.h"
#include "Binding_OBJExporter.h"
#include "Binding_DataEngine.h"
#include "PythonFactory.h"


using sofa::PythonFactory;


void bindSofaPythonModule()
{
    //PyImport_AppendInittab( (char*)"Sofa", &initSofa );

    PythonFactory::s_sofaPythonModule = SP_INIT_MODULE(Sofa)

    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,Data)
    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,DisplayFlagsData)
    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,OptionsGroupData)

    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,Link)

    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,Vector3)

    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,LinearSpring)


    SP_ADD_CLASS(PythonFactory::s_sofaPythonModule,Base)
    SP_ADD_CLASS_IN_FACTORY(BaseContext,sofa::core::objectmodel::BaseContext)
    SP_ADD_CLASS_IN_FACTORY(Context,sofa::core::objectmodel::Context)
    SP_ADD_CLASS_IN_FACTORY(Node,sofa::simulation::Node)
    SP_ADD_CLASS_IN_FACTORY(BaseObject,sofa::core::objectmodel::BaseObject)
    SP_ADD_CLASS_IN_FACTORY(BaseState,sofa::core::BaseState)
    SP_ADD_CLASS_IN_FACTORY(BaseMechanicalState,sofa::core::behavior::BaseMechanicalState)
//    SP_ADD_CLASS_IN_FACTORY(MechanicalObject,MechanicalObject3)
    SP_ADD_CLASS_IN_FACTORY(VisualModel,sofa::core::visual::VisualModel)
    SP_ADD_CLASS_IN_FACTORY(VisualModelImpl,sofa::component::visualmodel::VisualModelImpl)
    SP_ADD_CLASS_IN_FACTORY(BaseMapping,sofa::core::BaseMapping)
    SP_ADD_CLASS_IN_FACTORY(DataEngine,sofa::core::DataEngine)
    //SP_ADD_CLASS_IN_FACTORY(Mapping)
    //SP_ADD_CLASS_IN_FACTORY(RigidMapping)
    //SP_ADD_CLASS_IN_FACTORY(MultiMapping3_to_3)
//    SP_ADD_CLASS_IN_FACTORY(SubsetMultiMapping3_to_3,SubsetMultiMapping3_to_3)
    SP_ADD_CLASS_IN_FACTORY(BaseLoader,sofa::core::loader::BaseLoader)
    SP_ADD_CLASS_IN_FACTORY(MeshLoader,sofa::core::loader::MeshLoader)
    SP_ADD_CLASS_IN_FACTORY(Topology,sofa::core::topology::Topology)
    SP_ADD_CLASS_IN_FACTORY(BaseMeshTopology,sofa::core::topology::BaseMeshTopology)
    SP_ADD_CLASS_IN_FACTORY(MeshTopology,sofa::component::topology::MeshTopology)
    SP_ADD_CLASS_IN_FACTORY(GridTopology,sofa::component::topology::GridTopology)
    SP_ADD_CLASS_IN_FACTORY(RegularGridTopology,sofa::component::topology::RegularGridTopology)
    SP_ADD_CLASS_IN_FACTORY(OBJExporter,sofa::component::misc::OBJExporter)
    //SP_ADD_CLASS_IN_FACTORY(BaseController)
    //SP_ADD_CLASS_IN_FACTORY(Controller)
    //SP_ADD_CLASS_IN_FACTORY(ScriptController)
    SP_ADD_CLASS_IN_FACTORY(PythonScriptController,sofa::component::controller::PythonScriptController)
}




