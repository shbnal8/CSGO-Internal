/*****************************************************************//**
 * \file   Interfaces.cpp
 * \brief  
 * 
 * \author ALPEREN
 * \date   May 2020
 * 
 *  <br>
 *  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *********************************************************************/
#include "Interfaces.hpp"
#include <Windows.h>

 /**
 * Calls cs:go CreateInterface function
 * 
 * \param dllName Name of dll (client or engine)
 * \param interfaceName Name of the interface \sa Strings.hpp
 * \returns Created interface or nullptr 
 */
void* 
GetInterface(const char* dllName, const char* interfaceName)
{
    
    if (nullptr == dllName || interfaceName == nullptr)
        return nullptr;

    tCreateInterface pCreateInterface;
    
    pCreateInterface = reinterpret_cast<tCreateInterface>(GetProcAddress(GetModuleHandleA(dllName), "CreateInterface"));
    if (nullptr == pCreateInterface)
        return nullptr;
    
    void* addy = pCreateInterface(interfaceName, nullptr);

    return addy;
}
