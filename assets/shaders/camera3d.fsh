#version 450 core

// Add textures for per-pixel effects.

// Interpolation of output from per-vertex stage.
layout (location = 0) in vec3 InterpolatedPosition;
layout (location = 1) in vec3 InterpolatedNormal;
layout (location = 2) in vec2 InterpolatedTextureCoordinate;

layout (location = 0) out vec3 PixelColor;
layout (location = 1) out vec3 PixelPosition;
layout (location = 2) out vec3 PixelNormal;

void main() {
	PixelColor = vec4(pColor.x, pColor.y, pColor.z, 1.0f);
	PixelPosition = InterpolatedPosition;
	PixelNormal = InterpolatedNormal;
}