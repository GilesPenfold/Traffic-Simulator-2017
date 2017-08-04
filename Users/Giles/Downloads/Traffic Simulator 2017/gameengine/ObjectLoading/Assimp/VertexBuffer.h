#pragma once

//#include <gl/glew.h>
#include "../../include/gl/glew.h"
#include <vector>

/********************************

Class:		VertexBuffer

Purpose:	Wraps OpenGL vertex buffer
object.

********************************/
class VertexBuffer{
public:
	void CreateVBO(int a_iSize = 0);
	void DeleteVBO();

	void* MapBufferToMemory(int iUsageHint);
	void* MapSubBufferToMemory(int iUsageHint, GLuint uiOffset, GLuint uiLength);
	void UnmapBuffer();

	void BindVBO(int a_iBufferType = GL_ARRAY_BUFFER);
	void UploadDataToGPU(int iUsageHint);

	void AddData(void* ptrData, GLuint uiDataSize);

	void* GetDataPointer();
	GLuint GetBufferID();

	int GetCurrentSize();

	VertexBuffer();

private:
	GLuint uiBuffer;
	int iSize;
	int iCurrentSize;
	int iBufferType;
	std::vector<unsigned char> data;

	bool bDataUploaded;
};