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
#ifndef __SubEntity_H__
#define __SubEntity_H__

#include "OgrePrerequisites.h"

#include "OgreString.h"
#include "OgreRenderable.h"
#include "OgreHardwareBufferManager.h"
#include "OgreResourceGroupManager.h"

namespace Ogre {

	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Scene
	*  @{
	*/
	/** Utility class which defines the sub-parts of an Entity.
        @remarks
            Just as meshes are split into submeshes, an Entity is made up of
            potentially multiple SubMeshes. These are mainly here to provide the
            link between the Material which the SubEntity uses (which may be the
            default Material for the SubMesh or may have been changed for this
            object) and the SubMesh data.
        @par
            The SubEntity also allows the application some flexibility in the
            material properties for this section of a particular instance of this
            Mesh, e.g. tinting the windows on a car model.
        @par
            SubEntity instances are never created manually. They are created at
            the same time as their parent Entity by the SceneManager method
            createEntity.
    */
    class _OgreExport SubEntity: public Renderable, public SubEntityAlloc, public CLRObject
    {
	public:
		DECLARE_INIT_CLROBJECT_METHOD_OVERRIDE(SubEntity);
		 
        // Note no virtual functions for efficiency
        friend class Entity;
        friend class SceneManager;
    protected:
        /** Private constructor - don't allow creation by anybody else.
        */
        SubEntity(Entity* parent, SubMesh* subMeshBasis);

        /** Private destructor.
        */
        virtual ~SubEntity();

        /// Pointer to parent.
        Entity* mParentEntity;

        /// Name of Material in use by this SubEntity.
        String mMaterialName;

        /// Cached pointer to material.
        MaterialPtr mpMaterial;

        // Pointer to the SubMesh defining geometry.
        SubMesh* mSubMesh;

        /// Is this SubEntity visible?
        bool mVisible;

		/// The LOD number of the material to use, calculated by Entity::_notifyCurrentCamera
		unsigned short mMaterialLodIndex;

        /// blend buffer details for dedicated geometry
        VertexData* mSkelAnimVertexData;
        /// Quick lookup of buffers
        TempBlendedBufferInfo mTempSkelAnimInfo;
		/// Temp buffer details for software Vertex anim geometry
		TempBlendedBufferInfo mTempVertexAnimInfo;
		/// Vertex data details for software Vertex anim of shared geometry
		VertexData* mSoftwareVertexAnimVertexData;
		/// Vertex data details for hardware Vertex anim of shared geometry
		/// - separate since we need to s/w anim for shadows whilst still altering
		///   the vertex data for hardware morphing (pos2 binding)
		VertexData* mHardwareVertexAnimVertexData;
		/// Have we applied any vertex animation to geometry?
		bool mVertexAnimationAppliedThisFrame;
		/// Number of hardware blended poses supported by material
		ushort mHardwarePoseCount;
		/// Cached distance to last camera for getSquaredViewDepth
		mutable Real mCachedCameraDist;
		/// The camera for which the cached distance is valid
		mutable const Camera *mCachedCamera;

        /** Internal method for preparing this Entity for use in animation. */
        void prepareTempBlendBuffers(void);

    public:
        /** Gets the name of the Material in use by this instance.
        */
        const String& getMaterialName() const;

        /** Sets the name of the Material to be used.
            @remarks
                By default a SubEntity uses the default Material that the SubMesh
                uses. This call can alter that so that the Material is different
                for this instance.
        */
        void setMaterialName( const String& name, const String& groupName = ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME );

		/** Sets a Material to be used.
			@remarks
				By default a SubEntity uses the default Material that the SubMesh
				uses. This call can alter that so that the Material is different
				for this instance.
		*/
		void setMaterial( const MaterialPtr& material );

        /** Tells this SubEntity whether to be visible or not. */
        virtual void setVisible(bool visible);

        /** Returns whether or not this SubEntity is supposed to be visible. */
        virtual bool isVisible(void) const;

        /** Accessor method to read mesh data.
        */
        SubMesh* getSubMesh(void);

		/** Accessor to get parent Entity */
		Entity* getParent(void) const { return mParentEntity; }

        /** Overridden - see Renderable.
        */
        const MaterialPtr& getMaterial(void) const;

        /** Overridden - see Renderable.
        */
        Technique* getTechnique(void) const;

        /** Overridden - see Renderable.
        */
        void getRenderOperation(RenderOperation& op);

        /** Overridden - see Renderable.
        */
        void getWorldTransforms(Matrix4* xform) const;
        /** Overridden - see Renderable.
        */
        unsigned short getNumWorldTransforms(void) const;
        /** Overridden, see Renderable */
        Real getSquaredViewDepth(const Camera* cam) const;
        /** @copydoc Renderable::getLights */
        const LightList& getLights(void) const;
        /** @copydoc Renderable::getCastsShadows */
        bool getCastsShadows(void) const;
		/** Advanced method to get the temporarily blended vertex information
		for entities which are software skinned. 
        @remarks
            Internal engine will eliminate software animation if possible, this
            information is unreliable unless added request for software animation
            via Entity::addSoftwareAnimationRequest.
        @note
            The positions/normals of the returned vertex data is in object space.
		*/
		VertexData* _getSkelAnimVertexData(void);
		/** Advanced method to get the temporarily blended software morph vertex information
        @remarks
            Internal engine will eliminate software animation if possible, this
            information is unreliable unless added request for software animation
            via Entity::addSoftwareAnimationRequest.
        @note
            The positions/normals of the returned vertex data is in object space.
		*/
		VertexData* _getSoftwareVertexAnimVertexData(void);
		/** Advanced method to get the hardware morph vertex information
        @note
            The positions/normals of the returned vertex data is in object space.
		*/
		VertexData* _getHardwareVertexAnimVertexData(void);
		/** Advanced method to get the temp buffer information for software 
		skeletal animation.
		*/
		TempBlendedBufferInfo* _getSkelAnimTempBufferInfo(void);
		/** Advanced method to get the temp buffer information for software 
		morph animation.
		*/
		TempBlendedBufferInfo* _getVertexAnimTempBufferInfo(void);
		/// Retrieve the VertexData which should be used for GPU binding
		VertexData* getVertexDataForBinding(void);

		/** Mark all vertex data as so far unanimated. 
		*/
		void _markBuffersUnusedForAnimation(void);
		/** Mark all vertex data as animated. 
		*/
		void _markBuffersUsedForAnimation(void);
		/** Are buffers already marked as vertex animated? */
		bool _getBuffersMarkedForAnimation(void) const { return mVertexAnimationAppliedThisFrame; }
		/** Internal method to copy original vertex data to the morph structures
		should there be no active animation in use.
		*/
		void _restoreBuffersForUnusedAnimation(bool hardwareAnimation);

		/** Overridden from Renderable to provide some custom behaviour. */
		void _updateCustomGpuParameter(
			const GpuProgramParameters::AutoConstantEntry& constantEntry,
			GpuProgramParameters* params) const;

		/** Invalidate the camera distance cache */
		void _invalidateCameraCache ()
		{ mCachedCamera = 0; }
    };
	/** @} */
	/** @} */

}


#endif
