//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2014, Image Engine Design Inc. All rights reserved.
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

#include "IECore/Export.h"

IECORE_PUSH_DEFAULT_VISIBILITY
#include "OpenEXR/OpenEXRConfig.h"
#if OPENEXR_VERSION_MAJOR < 3
#include "OpenEXR/ImathColor.h"
#else
#include "Imath/ImathColor.h"
#endif
IECORE_POP_DEFAULT_VISIBILITY

#include <iostream>

#define BOOST_TEST_DYN_LINK

#include "KDTreeTest.h"
#include "TypedDataTest.h"
#include "InterpolatorTest.h"
#include "IndexedIOTest.h"
#include "BoostUnitTestTest.h"
#include "DataConversionTest.h"
#include "DataConvertTest.h"
#include "DespatchTypedDataTest.h"
#include "CompilerTest.h"
#include "RadixSortTest.h"
#include "SweepAndPruneTest.h"
#include "InternedStringTest.h"
#include "LevenbergMarquardtTest.h"
#include "SpaceTransformTest.h"
#include "LookupTest.h"
#include "ParameterThreadingTest.h"
#include "InternedStringTest.h"
#include "RefCountedThreadingTest.h"
#include "LRUCacheThreadingTest.h"
#include "CompoundDataTest.h"
#include "CompoundObjectTest.h"
#include "ComputationCacheTest.h"
#include "MurmurHashTest.h"

using namespace boost::unit_test;

using namespace IECore;

bool init()
{

	test_suite *test = &framework::master_test_suite();

	try
	{
		addBoostUnitTestTest(test);
		addKDTreeTest(test);
		addTypedDataTest(test);
		addInterpolatorTest(test);
		addIndexedIOTest(test);
		addDataConversionTest(test);
		addDataConvertTest(test);
		addDespatchTypedDataTest(test);
		addCompilerTest(test);
		addRadixSortTest(test);
		addSweepAndPruneTest(test);
		addLevenbergMarquardtTest(test);
		addSpaceTransformTest(test);
		addLookupTest(test);
		addParameterThreadingTest(test);
		addInternedStringTest(test);
		addRefCountedThreadingTest(test);
		addLRUCacheThreadingTest(test);
		addCompoundDataTest(test);
		addCompoundObjectTest(test);
		addComputationCacheTest(test);
		addMurmurHashTest(test);
	}
	catch (std::exception &ex)
	{
		std::cerr << "Failed to create test suite: " << ex.what() << std::endl;
		throw;
	}

	return true;
}

int main( int argc, char *argv[] )
{
	return boost::unit_test::unit_test_main( &init, argc, argv );
}
