#include "GLQuadRenderer.h"

void Lava::OpenGL::GLQuadRenderer::Setup()
{
	glGenVertexArrays(1, &k_vao);
	glGenBuffers(1, &k_vbo);
	glBindVertexArray(k_vao);
	glBindBuffer(GL_ARRAY_BUFFER, k_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));


	//m_bank->AddVariable(1, "texCoord");
}

void Lava::OpenGL::GLQuadRenderer::Render(unsigned int& targetTextureId)
{
	glBindVertexArray(k_vao);
	glEnableVertexAttribArray(0);
	glDisable(GL_DEPTH_TEST); //No need to depth test for screen quad

	int targetId = targetTextureId;
	int i = 0;
	for (PostProcessingEffect* postFx : postProcessingEffects) {
		i++;
		postFx->Render(targetId, postProcessingEffects.size() == i);
		targetId = (postFx->colorTargetID);
	}

	//glBindFramebuffer(GL_FRAMEBUFFER, renderSceneFbo);
	//m_bank->Bind();
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, targetTextureId);
	//m_bank->GetShader(1)->SetInt1("hdrTexture", 3);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//m_bank->Unbind();
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);


	glEnable(GL_DEPTH_TEST);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

Lava::OpenGL::GLQuadRenderer::~GLQuadRenderer()
{
	//delete m_bank;
}
