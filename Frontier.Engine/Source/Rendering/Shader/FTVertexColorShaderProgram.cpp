#include "FTVertexColorShaderProgram.h"

const char* FTVertexColorShaderProgram::fragment_shader_source_ = {
	"#version 330 core\n\
	\n\
	in vec3 fragmentColor;\n\
	\n\
	// Ouput data\n\
	out vec3 color;\n\
	\n\
	void main(){\n\
		\n\
		color = fragmentColor;\n\
		\n\
	}"
};

const char* FTVertexColorShaderProgram::vertex_shader_source_ = {
	"#version 330 core\n\
	\n\
	layout(location = 0) in vec3 vertexPosition_modelspace;\n\
	layout(location = 1) in vec3 vertexColor;\n\
	\n\
	out vec3 fragmentColor;\n\
	uniform mat4 MVP;\n\
	\n\
	void main(){\n\
		\n\
		gl_Position = MVP * vec4(vertexPosition_modelspace, 1);\n\
		\n\
		fragmentColor = vertexColor;\n\
	}"
};

FTVertexColorShaderProgram::FTVertexColorShaderProgram() : FTVertexShaderProgram(vertex_shader_source_,fragment_shader_source_){
	
}


FTVertexColorShaderProgram::~FTVertexColorShaderProgram() {
}
