//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2014, Image Engine Design Inc. All rights reserved.
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

#ifndef IECORESCENE_TRANSFORMSTACK_H
#define IECORESCENE_TRANSFORMSTACK_H

#include "IECoreScene/Export.h"

#include "IECore/Export.h"

IECORE_PUSH_DEFAULT_VISIBILITY
#include "OpenEXR/OpenEXRConfig.h"
#if OPENEXR_VERSION_MAJOR < 3
#include "OpenEXR/ImathMatrix.h"
#else
#include "Imath/ImathMatrix.h"
#endif
IECORE_POP_DEFAULT_VISIBILITY

#include <stack>
#include <vector>

namespace IECoreScene
{

class IECORESCENE_API TransformStack
{

	public :

		TransformStack();
		TransformStack( const TransformStack &other, bool flatten = false );

		void push();
		void pop();
		size_t size() const;

		void motionBegin( const std::vector<float> &times );
		void motionEnd();
		bool inMotion() const;

		void set( const Imath::M44f &matrix );
		void concatenate( const Imath::M44f &matrix );

		Imath::M44f get() const;
		Imath::M44f get( float time ) const;

		size_t numSamples() const;
		Imath::M44f sample( size_t sampleIndex ) const;
		float sampleTime( size_t sampleIndex ) const;

	private :

		struct Sample
		{
			Sample( float t, const Imath::M44f &m )
				:	time( t ), matrix( m )
			{
			}

			bool operator < ( float t ) const
			{
				return time < t;
			}

			float time;
			Imath::M44f matrix;
		};
		typedef std::vector<Sample> Samples;

		typedef std::stack<Samples> Stack;
		Stack m_stack;
		int m_motionIndex;

};

} // namespace IECoreScene

#endif // IECORESCENE_TRANSFORMSTACK_H
