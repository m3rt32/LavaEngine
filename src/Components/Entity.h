#pragma once
#include "Transform.h"
#include "MeshRenderer.h"
#include "../Renderer/Mesh.h"
#include "../Renderer/RenderObject.h"
#include "../Renderer/Shader.h"
#include "../Renderer/ShaderBank.h"
namespace Lava {
	class Entity {
	public:
		Transform* transform;
		MeshRenderer* meshRenderer;
		Mesh* mesh;
		Material* material;
		Entity()
		{
			transform = new Transform();
			mesh = new Mesh();
			material = new Material();
		}

		Entity(glm::vec3 position)
		{
			transform = new Transform(position);
			mesh = new Mesh();
			material = new Material();
		}

		void SetMeshData(std::vector<float>& vertices, std::vector<int>& indices,
			std::vector<VertexBufferElement>& bufferElements) {
			mesh->m_positions = &vertices[0];
			mesh->m_posCount = vertices.size();
			mesh->m_indices = &indices[0];
			mesh->m_indiceCount = indices.size();
			mesh->m_bufferLayoutElement = &bufferElements[0];
			mesh->m_bufferLayoutCount = bufferElements.size();
		}

		MeshRenderer* GetMeshRenderer(Platform platform) {
			if (meshRenderer) return meshRenderer;
			meshRenderer = new MeshRenderer(mesh, material, platform);
			return meshRenderer;
		}
	};
}