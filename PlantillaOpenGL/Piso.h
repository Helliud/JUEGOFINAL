#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Piso : public Modelo
{
public:
	Piso();
	float rPiso;
	float gPiso;
	float bPiso;

	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);


};

