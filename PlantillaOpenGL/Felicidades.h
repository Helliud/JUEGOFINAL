#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Felicidades : public Modelo
{
public:
	Felicidades();


	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 50.0f, 0.0f);


};
