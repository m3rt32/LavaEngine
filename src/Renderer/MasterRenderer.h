#pragma once
#include "../Core/Scene.h"
#include "BatchedRenderer.h"
#include "SkyboxRenderer.h"
namespace Lava
{
	class MasterRenderer {
	public:
		BatchedRenderer* batchedRenderer;
		SkyboxRenderer* skyboxRenderer;
		virtual void InternalUpdate() = 0;
		MasterRenderer(Scene* scene) : m_scene(scene),batchedRenderer(nullptr),skyboxRenderer(nullptr) {

		}
		void Update() {
			InternalUpdate();
			batchedRenderer->Update(m_scene);
			skyboxRenderer->Update(m_scene);
		}
	protected:
		Scene* m_scene;
	};
}