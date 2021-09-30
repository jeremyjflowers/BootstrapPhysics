#include "Mesh.h"

Mesh::Mesh()
{
	m_transform = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	m_triCount = 0;
	m_vertexArrayObject = 0;
	m_vertexBufferObject = 0;
	m_indexBufferObject = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	glDeleteBuffers(1, &m_vertexBufferObject);
	glDeleteBuffers(1, &m_indexBufferObject);
}

void Mesh::start()
{
	assert(m_vertexArrayObject == 0);

	//Generate buffer and array
	glGenBuffers(1, &m_vertexBufferObject);
	glGenVertexArrays(1, &m_vertexArrayObject);

	//Bind vertex array and vertex buffers
	glBindVertexArray(m_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

	//Define the vertices for a quad
	Vertex vertices[6];
	//Triangle 0
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	//Triangle 1
	vertices[3].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[4].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[5].position = { 0.5f, 0.0f, 0.5f, 1.0f };

	//Fill vertex buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6, vertices, GL_STATIC_DRAW);

	//Enable vertex position as first attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	//Unbind buffer and array
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::draw()
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
