//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2008-2010, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

// This include needs to be the very first to prevent problems with warnings
// regarding redefinition of _POSIX_C_SOURCE
#include "boost/python.hpp"

#include "IECorePython/AngleConversionBinding.h"

#include "IECore/AngleConversion.h"
#include "IECore/Export.h"

IECORE_PUSH_DEFAULT_VISIBILITY
#include "OpenEXR/OpenEXRConfig.h"
#if OPENEXR_VERSION_MAJOR < 3
#include "OpenEXR/ImathVec.h"
#else
#include "Imath/ImathVec.h"
#endif
IECORE_POP_DEFAULT_VISIBILITY

using namespace boost::python;
using namespace Imath;
using namespace IECore;

namespace IECorePython
{

void bindAngleConversion()
{

	def( "degreesToRadians", &degreesToRadians<float> );
	def( "degreesToRadians", &degreesToRadians<double> );
	def( "degreesToRadians", &degreesToRadians<Imath::V2f> );
	def( "degreesToRadians", &degreesToRadians<Imath::V2d> );
	def( "degreesToRadians", &degreesToRadians<Imath::V3f> );
	def( "degreesToRadians", &degreesToRadians<Imath::V3d> );

	def( "radiansToDegrees", &radiansToDegrees<float> );
	def( "radiansToDegrees", &radiansToDegrees<double> );
	def( "radiansToDegrees", &radiansToDegrees<Imath::V2f> );
	def( "radiansToDegrees", &radiansToDegrees<Imath::V2d> );
	def( "radiansToDegrees", &radiansToDegrees<Imath::V3f> );
	def( "radiansToDegrees", &radiansToDegrees<Imath::V3d> );

}

}
