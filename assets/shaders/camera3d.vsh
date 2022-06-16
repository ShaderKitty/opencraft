#version 450 core

layout (binding = 0) uniform Object3DTransform {
	mat4 Translation;	// Transforms vertices to world space.
	mat4 Transform; 	// Transforms vertices to object space.
} Object3D;

// TODO: determine how sets will be organized.
layout (binding = 1) uniform Camera3DTransform {
    mat4 Translation; 	// Transforms world space vertices into camera space.
    mat4 Rotation;		// Will rotate into view of camera3d.
    mat4 Projection;	// Will perform final projection either pespective or orthographic.
} Camera3D;

// Actual Mesh Infomation.
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;

// Texture Coordinate Section.
layout (location = 2) in vec2 VertexTextureCoordinate;

// Interpolation of output variables.
layout (location = 0) out vec3 InterpolatedPosition;				// Contains World Space Interpolated pixel position.
layout (location = 1) out vec3 InterpolatedNormal;					// Contains interpolated normal vectors.
layout (location = 2) out vec2 InterpolatedTextureCoordinate;		// 

void main() {
	// Will interpolate position and normal info in next shader stage.
	InterpolatedPosition = Object3D.Translation * VertexPosition;
	InterpolatedNormal = VertexNormal;
	InterpolatedTextureCoordinate = VertexTextureCoordinate;

	// Calculate vertex transforms.
	gl_Position = Camera3D.Projection * Camera3D.Rotation * Camera3D.Translation * Object3D.Translation * Object3D.Transform * vec4(VertexPosition, 1.0f);
}