#ifndef GLEWMOCK_H
#define GLEWMOCK_H
#include "gl/glew.h"
#include "gmock/gmock.h"
#include "glewmock2.hpp"

// The mock methods had to be split into 2 classes as when it was just one class it created
// objects with too many sections for the COFF format on compilers which use COMDAT sections
class GlewMock : public GlewMock2 {
public:
	GlewMock();
	virtual ~GlewMock();
	static GlewMock* getMock();

	MOCK_METHOD9(gl_CopyTexSubImage3D, void (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height));
	MOCK_METHOD6(gl_DrawRangeElements, void (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices));
	MOCK_METHOD10(gl_TexImage3D, void (GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels));
	MOCK_METHOD1(gl_ActiveTexture, void (GLenum texture));
	MOCK_METHOD1(gl_ClientActiveTexture, void (GLenum texture));
	MOCK_METHOD7(gl_CompressedTexImage1D, void (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data));
	MOCK_METHOD8(gl_CompressedTexImage2D, void (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data));
	MOCK_METHOD9(gl_CompressedTexImage3D, void (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data));
	MOCK_METHOD7(gl_CompressedTexSubImage1D, void (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data));
	MOCK_METHOD9(gl_CompressedTexSubImage2D, void (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data));
	MOCK_METHOD3(gl_GetCompressedTexImage, void (GLenum target, GLint lod, void* img));
	MOCK_METHOD1(gl_LoadTransposeMatrixd, void (const GLdouble* m));
	MOCK_METHOD1(gl_LoadTransposeMatrixf, void (const GLfloat* m));
	MOCK_METHOD1(gl_MultTransposeMatrixd, void (const GLdouble* m));
	MOCK_METHOD1(gl_MultTransposeMatrixf, void (const GLfloat* m));
	MOCK_METHOD2(gl_MultiTexCoord1d, void (GLenum target, GLdouble s));
	MOCK_METHOD2(gl_MultiTexCoord1dv, void (GLenum target, const GLdouble* v));
	MOCK_METHOD2(gl_MultiTexCoord1f, void (GLenum target, GLfloat s));
	MOCK_METHOD2(gl_MultiTexCoord1fv, void (GLenum target, const GLfloat* v));
	MOCK_METHOD2(gl_MultiTexCoord1i, void (GLenum target, GLint s));
	MOCK_METHOD2(gl_MultiTexCoord1iv, void (GLenum target, const GLint* v));
	MOCK_METHOD2(gl_MultiTexCoord1s, void (GLenum target, GLshort s));
	MOCK_METHOD2(gl_MultiTexCoord1sv, void (GLenum target, const GLshort* v));
	MOCK_METHOD3(gl_MultiTexCoord2d, void (GLenum target, GLdouble s, GLdouble t));
	MOCK_METHOD2(gl_MultiTexCoord2dv, void (GLenum target, const GLdouble* v));
	MOCK_METHOD3(gl_MultiTexCoord2f, void (GLenum target, GLfloat s, GLfloat t));
	MOCK_METHOD2(gl_MultiTexCoord2fv, void (GLenum target, const GLfloat* v));
	MOCK_METHOD3(gl_MultiTexCoord2i, void (GLenum target, GLint s, GLint t));
	MOCK_METHOD2(gl_MultiTexCoord2iv, void (GLenum target, const GLint* v));
	MOCK_METHOD3(gl_MultiTexCoord2s, void (GLenum target, GLshort s, GLshort t));
	MOCK_METHOD2(gl_MultiTexCoord2sv, void (GLenum target, const GLshort* v));
	MOCK_METHOD4(gl_MultiTexCoord3d, void (GLenum target, GLdouble s, GLdouble t, GLdouble r));
	MOCK_METHOD2(gl_MultiTexCoord3dv, void (GLenum target, const GLdouble* v));
	MOCK_METHOD4(gl_MultiTexCoord3f, void (GLenum target, GLfloat s, GLfloat t, GLfloat r));
	MOCK_METHOD2(gl_MultiTexCoord3fv, void (GLenum target, const GLfloat* v));
	MOCK_METHOD4(gl_MultiTexCoord3i, void (GLenum target, GLint s, GLint t, GLint r));
	MOCK_METHOD2(gl_MultiTexCoord3iv, void (GLenum target, const GLint* v));
	MOCK_METHOD4(gl_MultiTexCoord3s, void (GLenum target, GLshort s, GLshort t, GLshort r));
	MOCK_METHOD2(gl_MultiTexCoord3sv, void (GLenum target, const GLshort* v));
	MOCK_METHOD5(gl_MultiTexCoord4d, void (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q));
	MOCK_METHOD2(gl_MultiTexCoord4dv, void (GLenum target, const GLdouble* v));
	MOCK_METHOD5(gl_MultiTexCoord4f, void (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q));
	MOCK_METHOD2(gl_MultiTexCoord4fv, void (GLenum target, const GLfloat* v));
	MOCK_METHOD5(gl_MultiTexCoord4i, void (GLenum target, GLint s, GLint t, GLint r, GLint q));
	MOCK_METHOD2(gl_MultiTexCoord4iv, void (GLenum target, const GLint* v));
	MOCK_METHOD5(gl_MultiTexCoord4s, void (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q));
	MOCK_METHOD2(gl_MultiTexCoord4sv, void (GLenum target, const GLshort* v));
	MOCK_METHOD2(gl_SampleCoverage, void (GLclampf value, GLboolean invert));
	MOCK_METHOD4(gl_BlendColor, void (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha));
	MOCK_METHOD1(gl_BlendEquation, void (GLenum mode));
	MOCK_METHOD4(gl_BlendFuncSeparate, void (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha));
	MOCK_METHOD3(gl_FogCoordPointer, void (GLenum type, GLsizei stride, const void* pointer));
	MOCK_METHOD1(gl_FogCoordd, void (GLdouble coord));
	MOCK_METHOD1(gl_FogCoorddv, void (const GLdouble* coord));
	MOCK_METHOD1(gl_FogCoordf, void (GLfloat coord));
	MOCK_METHOD1(gl_FogCoordfv, void (const GLfloat* coord));
	MOCK_METHOD4(gl_MultiDrawArrays, void (GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount));
	MOCK_METHOD5(gl_MultiDrawElements, void (GLenum mode, const GLsizei* count, GLenum type, const void*const * indices, GLsizei drawcount));
	MOCK_METHOD2(gl_PointParameterf, void (GLenum pname, GLfloat param));
	MOCK_METHOD2(gl_PointParameterfv, void (GLenum pname, const GLfloat* params));
	MOCK_METHOD2(gl_PointParameteri, void (GLenum pname, GLint param));
	MOCK_METHOD2(gl_PointParameteriv, void (GLenum pname, const GLint* params));
	MOCK_METHOD3(gl_SecondaryColor3b, void (GLbyte red, GLbyte green, GLbyte blue));
	MOCK_METHOD1(gl_SecondaryColor3bv, void (const GLbyte* v));
	MOCK_METHOD3(gl_SecondaryColor3d, void (GLdouble red, GLdouble green, GLdouble blue));
	MOCK_METHOD1(gl_SecondaryColor3dv, void (const GLdouble* v));
	MOCK_METHOD3(gl_SecondaryColor3f, void (GLfloat red, GLfloat green, GLfloat blue));
	MOCK_METHOD1(gl_SecondaryColor3fv, void (const GLfloat* v));
	MOCK_METHOD3(gl_SecondaryColor3i, void (GLint red, GLint green, GLint blue));
	MOCK_METHOD1(gl_SecondaryColor3iv, void (const GLint* v));
	MOCK_METHOD3(gl_SecondaryColor3s, void (GLshort red, GLshort green, GLshort blue));
	MOCK_METHOD1(gl_SecondaryColor3sv, void (const GLshort* v));
	MOCK_METHOD3(gl_SecondaryColor3ub, void (GLubyte red, GLubyte green, GLubyte blue));
	MOCK_METHOD1(gl_SecondaryColor3ubv, void (const GLubyte* v));
	MOCK_METHOD3(gl_SecondaryColor3ui, void (GLuint red, GLuint green, GLuint blue));
	MOCK_METHOD1(gl_SecondaryColor3uiv, void (const GLuint* v));
	MOCK_METHOD3(gl_SecondaryColor3us, void (GLushort red, GLushort green, GLushort blue));
	MOCK_METHOD1(gl_SecondaryColor3usv, void (const GLushort* v));
	MOCK_METHOD4(gl_SecondaryColorPointer, void (GLint size, GLenum type, GLsizei stride, const void* pointer));
	MOCK_METHOD2(gl_WindowPos2d, void (GLdouble x, GLdouble y));
	MOCK_METHOD1(gl_WindowPos2dv, void (const GLdouble* p));
	MOCK_METHOD2(gl_WindowPos2f, void (GLfloat x, GLfloat y));
	MOCK_METHOD1(gl_WindowPos2fv, void (const GLfloat* p));
	MOCK_METHOD2(gl_WindowPos2i, void (GLint x, GLint y));
	MOCK_METHOD1(gl_WindowPos2iv, void (const GLint* p));
	MOCK_METHOD2(gl_WindowPos2s, void (GLshort x, GLshort y));
	MOCK_METHOD1(gl_WindowPos2sv, void (const GLshort* p));
	MOCK_METHOD3(gl_WindowPos3d, void (GLdouble x, GLdouble y, GLdouble z));
	MOCK_METHOD1(gl_WindowPos3dv, void (const GLdouble* p));
	MOCK_METHOD3(gl_WindowPos3f, void (GLfloat x, GLfloat y, GLfloat z));
	MOCK_METHOD1(gl_WindowPos3fv, void (const GLfloat* p));
	MOCK_METHOD3(gl_WindowPos3i, void (GLint x, GLint y, GLint z));
	MOCK_METHOD1(gl_WindowPos3iv, void (const GLint* p));
	MOCK_METHOD3(gl_WindowPos3s, void (GLshort x, GLshort y, GLshort z));
	MOCK_METHOD1(gl_WindowPos3sv, void (const GLshort* p));
	MOCK_METHOD2(gl_BeginQuery, void (GLenum target, GLuint id));
	MOCK_METHOD2(gl_BindBuffer, void (GLenum target, GLuint buffer));
	MOCK_METHOD4(gl_BufferData, void (GLenum target, GLsizeiptr size, const void* data, GLenum usage));
	MOCK_METHOD4(gl_BufferSubData, void (GLenum target, GLintptr offset, GLsizeiptr size, const void* data));
	MOCK_METHOD2(gl_DeleteBuffers, void (GLsizei n, const GLuint* buffers));
	MOCK_METHOD2(gl_DeleteQueries, void (GLsizei n, const GLuint* ids));
	MOCK_METHOD1(gl_EndQuery, void (GLenum target));
	MOCK_METHOD2(gl_GenBuffers, void (GLsizei n, GLuint* buffers));
	MOCK_METHOD2(gl_GenQueries, void (GLsizei n, GLuint* ids));
	MOCK_METHOD3(gl_GetBufferParameteriv, void (GLenum target, GLenum pname, GLint* params));
	MOCK_METHOD3(gl_GetBufferPointerv, void (GLenum target, GLenum pname, void** params));
	MOCK_METHOD4(gl_GetBufferSubData, void (GLenum target, GLintptr offset, GLsizeiptr size, void* data));
	MOCK_METHOD3(gl_GetQueryObjectiv, void (GLuint id, GLenum pname, GLint* params));
	MOCK_METHOD3(gl_GetQueryObjectuiv, void (GLuint id, GLenum pname, GLuint* params));
	MOCK_METHOD3(gl_GetQueryiv, void (GLenum target, GLenum pname, GLint* params));
	MOCK_METHOD1(gl_IsBuffer, unsigned char (GLuint buffer));
	MOCK_METHOD1(gl_IsQuery, unsigned char (GLuint id));
	MOCK_METHOD2(gl_MapBuffer, void*(GLenum target, GLenum access));
	MOCK_METHOD1(gl_UnmapBuffer, unsigned char (GLenum target));
	MOCK_METHOD2(gl_AttachShader, void (GLuint program, GLuint shader));
	MOCK_METHOD3(gl_BindAttribLocation, void (GLuint program, GLuint index, const GLchar* name));
	MOCK_METHOD2(gl_BlendEquationSeparate, void (GLenum modeRGB, GLenum modeAlpha));
	MOCK_METHOD1(gl_CompileShader, void (GLuint shader));
	MOCK_METHOD0(gl_CreateProgram, unsigned int ());
	MOCK_METHOD1(gl_CreateShader, unsigned int (GLenum type));
	MOCK_METHOD1(gl_DeleteProgram, void (GLuint program));
	MOCK_METHOD1(gl_DeleteShader, void (GLuint shader));
	MOCK_METHOD2(gl_DetachShader, void (GLuint program, GLuint shader));
	MOCK_METHOD1(gl_DisableVertexAttribArray, void (GLuint index));
	MOCK_METHOD2(gl_DrawBuffers, void (GLsizei n, const GLenum* bufs));
	MOCK_METHOD1(gl_EnableVertexAttribArray, void (GLuint index));
	MOCK_METHOD7(gl_GetActiveAttrib, void (GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name));
	MOCK_METHOD7(gl_GetActiveUniform, void (GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name));
	MOCK_METHOD4(gl_GetAttachedShaders, void (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders));
	MOCK_METHOD2(gl_GetAttribLocation, int (GLuint program, const GLchar* name));
};

#endif
