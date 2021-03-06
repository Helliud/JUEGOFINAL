#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
#include <time.h>

class Fantasma : public Modelo
{
public:
	Fantasma();
	bool flotarLimite;
	void flotar();
	double tiempoAnterior = 0.0f;
	double tiempoActual = 0.0f;
	double tiempoDiferencial = 0.0f;
	void bajarFantasma();
	double lastTime = glfwGetTime();
	double seconds;
	double deltaTime = 0.0f;
	int definidor = 1;

	int bonusFantasma = 1;
	float tamanoFantama = 1.0;

	void actualizarMatrizModelo();
	vec3 coordenadasFantasma = vec3(45.0f, 0.2f, -95.0f);


}; 
