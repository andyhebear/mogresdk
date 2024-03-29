/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2009 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef __SimpleRenderable_H__
#define __SimpleRenderable_H__

#include "OgrePrerequisites.h"

#include "OgreMovableObject.h"
#include "OgreRenderable.h"
#include "OgreAxisAlignedBox.h"
#include "OgreMaterial.h"

namespace Ogre {

	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Scene
	*  @{
	*/
	/** Simple implementation of MovableObject and Renderable for single-part custom objects. 
	@see ManualObject for a simpler interface with more flexibility
	*/
	class _OgreExport SimpleRenderable : public MovableObject, public Renderable
    {
	public:
		DECLARE_INIT_CLROBJECT_METHOD_OVERRIDE(SimpleRenderable);
		
    protected:
        RenderOperation mRenderOp;

        Matrix4 m_matWorldTransform;
        AxisAlignedBox mBox;

        String m_strMatName;
        MaterialPtr m_pMaterial;

        /// The scene manager for the current frame.
        SceneManager *m_pParentSceneManager;

        /// The camera for the current frame.
        Camera *m_pCamera;

        /// Static member used to automatically generate names for SimpleRendaerable objects.
        static uint ms_uGenNameCount;

    public:
        SimpleRenderable();

        void setMaterial( const String& matName );
        virtual const MaterialPtr& getMaterial(void) const;

        virtual void setRenderOperation( const RenderOperation& rend );
        virtual void getRenderOperation(RenderOperation& op);

        void setWorldTransform( const Matrix4& xform );
        virtual void getWorldTransforms( Matrix4* xform ) const;


        virtual void _notifyCurrentCamera(Camera* cam);

        void setBoundingBox( const AxisAlignedBox& box );
        virtual const AxisAlignedBox& getBoundingBox(void) const;

        virtual void _updateRenderQueue(RenderQueue* queue);
		/// @copydoc MovableObject::visitRenderables
		void visitRenderables(Renderable::Visitor* visitor, 
			bool debugRenderables = false);

        virtual ~SimpleRenderable();


        /** Overridden from MovableObject */
        virtual const String& getMovableType(void) const;

        /** @copydoc Renderable::getLights */
        const LightList& getLights(void) const;

    };
	/** @} */
	/** @} */
}

#endif

