/*!
 * \file CFEAMeshNumerics.hpp
 * \brief Declaration and inlines of the class to compute
 *        the stiffness matrix of a linear, pseudo-elastic mesh problem.
 * \author Ruben Sanchez
 * \version 7.0.0 "Blackbird"
 *
 * SU2 Project Website: https://su2code.github.io
 *
 * The SU2 Project is maintained by the SU2 Foundation 
 * (http://su2foundation.org)
 *
 * Copyright 2012-2019, SU2 Contributors (cf. AUTHORS.md)
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "../numerics_structure.hpp"

class CFEAMeshElasticity : public CFEALinearElasticity {

  bool element_based;
  bool stiffness_set;

public:

  /*!
   * \brief Constructor of the class.
   * \param[in] val_nDim - Number of dimensions of the problem.
   * \param[in] val_nVar - Number of variables of the problem.
   * \param[in] config - Definition of the particular problem.
   */
  CFEAMeshElasticity(unsigned short val_nDim, unsigned short val_nVar, unsigned long val_nElem, CConfig *config);

  /*!
   * \brief Destructor of the class.
   */
  ~CFEAMeshElasticity(void);

  inline void SetElement_Properties(CElement *element, CConfig *config){
    if(element_based){E = E_i[element->Get_iProp()];  Compute_Lame_Parameters();}
  }

  /*!
   * \brief Set the element-based local properties in mesh problems
   * \param[in] element_container - Element structure for the particular element integrated.
   */
  inline void SetMeshElasticProperties(unsigned long iElem, su2double val_E){
    if (element_based){ E_i[iElem]  = val_E;}
  }

};
