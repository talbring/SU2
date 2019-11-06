/*!
 * \file gauss_structure.inl
 * \brief In-Line subroutines of the <i>gauss_structure.hpp</i> file.
 * \author R. Sanchez
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

inline void CGaussVariable::SetGradNi_Xj(su2double val_GradNi_Xj, unsigned short val_iDim, unsigned short val_Ni) { GradNi_Xj[val_Ni][val_iDim] = val_GradNi_Xj; }

inline void CGaussVariable::SetGradNi_xj(su2double val_GradNi_xj, unsigned short val_iDim, unsigned short val_Ni) { GradNi_xj[val_Ni][val_iDim] = val_GradNi_xj; }

inline void CGaussVariable::SetNi(su2double val_ShapeNi, unsigned short val_Ni) { Ni[val_Ni] = val_ShapeNi; }

inline void CGaussVariable::SetJ_X(su2double valJ_X) { J_X = valJ_X; }

inline void CGaussVariable::SetJ_x(su2double valJ_x) { J_x = valJ_x; }

inline unsigned short CGaussVariable::Get_iGauss(void) { return iGaussPoint; }

inline su2double **CGaussVariable::GetGradNi_Xj(void) { return GradNi_Xj; }

inline su2double CGaussVariable::GetGradNi_Xj(unsigned short val_Ni, unsigned short val_iDim) { return GradNi_Xj[val_Ni][val_iDim]; }

inline su2double CGaussVariable::GetGradNi_xj(unsigned short val_Ni, unsigned short val_iDim) { return GradNi_xj[val_Ni][val_iDim]; }

inline su2double CGaussVariable::GetNi(unsigned short val_Ni) { return Ni[val_Ni]; }

inline su2double CGaussVariable::GetJ_X(void) { return J_X; }

inline su2double CGaussVariable::GetJ_x(void) { return J_x; }

inline unsigned long CProperty::GetMat_Mod(void) { return 0; }

inline unsigned long CProperty::GetMat_Prop(void) { return iMat_Prop; }

inline unsigned long CProperty::GetElectric_Prop(void) { return 0; }

inline unsigned long CProperty::GetDV(void) { return 0; }

inline void CProperty::SetDesignDensity(su2double valDensity) { }

inline su2double CProperty::GetDesignDensity(void) { return 0.0; }

inline void CProperty::SetPhysicalDensity(su2double valDensity) { }

inline su2double CProperty::GetPhysicalDensity(void) { return 0.0; }

inline su2double CProperty::GetAdjointDensity(void) { return 0.0; }

inline void CProperty::RegisterDensity(void) { }

inline unsigned long CElementProperty::GetMat_Mod(void) { return iMat_Mod; }

inline unsigned long CElementProperty::GetElectric_Prop(void) { return iElectric_Prop; }

inline unsigned long CElementProperty::GetDV(void) { return iDV; }

inline void CElementProperty::SetDesignDensity(su2double valDensity) { design_rho = valDensity; }

inline su2double CElementProperty::GetDesignDensity(void) { return design_rho; }

inline void CElementProperty::SetPhysicalDensity(su2double valDensity) { physical_rho = valDensity; }

inline su2double CElementProperty::GetPhysicalDensity(void) { return physical_rho; }

inline su2double CElementProperty::GetAdjointDensity(void) { return SU2_TYPE::GetDerivative(design_rho); }
  
inline void CElementProperty::RegisterDensity(void) { AD::RegisterInput(design_rho); }

