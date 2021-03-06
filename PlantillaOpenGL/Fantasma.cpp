#pragma once
#include "stdafx.h"
#include "Fantasma.h"
#include "Robot.h"

void Fantasma::actualizarMatrizModelo() {
	vec3 escalaFantasma = vec3(tamanoFantama);

	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadasFantasma);
	modelo = scale(modelo, escalaFantasma);
}



void Fantasma::flotar() {
	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;

	bajarFantasma();
	actualizarMatrizModelo();

}



void Fantasma::bajarFantasma() {
	if (definidor % 2 == 1){
		if (coordenadasFantasma.y <= 0.7 && coordenadasFantasma.y > 0.0) {
			definidor = 1;
			coordenadasFantasma.y -= 0.0008f * tiempoActual;
		}
		else
			definidor++;
	}
	if (definidor % 2 == 0) {
		if (coordenadasFantasma.y <= 0.1 && coordenadasFantasma.y > -1.0) {
			coordenadasFantasma.y += 0.0008f * tiempoActual;
		}
		else
			definidor++;
	}
}



Fantasma::Fantasma() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(0.5f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.5f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//OJOS
	//Ojo - Izquierdo
	vertices.push_back({ vec4(-0.35f, 0.2f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(-0.35f, 0.0f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(-0.1f, 0.0f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(-0.1f, 0.2f, 0.01f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.80f) });

	//Ojo - Derecho
	vertices.push_back({ vec4(0.35f, 0.2f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(0.35f, 0.0f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(0.1f, 0.0f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(0.1f, 0.2f, 0.01f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.80f) });

	//BOCA
	vertices.push_back({ vec4(-0.1f, -0.05f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(-0.1f, -0.5f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(0.1f, -0.5f,  0.01f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 0.80f) });
	vertices.push_back({ vec4(0.1f, -0.05f, 0.01f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 0.80f) });

	//LAGRIMAS
	//Lagrimas - Izquierda
	vertices.push_back({ vec4(-0.25f, 0.0f,  0.01f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.80f) });
	vertices.push_back({ vec4(-0.25f, -0.5f,  0.01f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.80f) });
	vertices.push_back({ vec4(-0.2f, -0.5f,  0.01f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.80f) });
	vertices.push_back({ vec4(-0.2f, 0.0f, 0.01f, 1.0f), vec4(0.0f, 0.2f, 0.5f, 0.08f) });

	//Lagrimas - Izquierda
	vertices.push_back({ vec4(0.25f, 0.0f,  0.01f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.80f) });
	vertices.push_back({ vec4(0.25f, -0.5f,  0.01f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.80f) });
	vertices.push_back({ vec4(0.2f, -0.5f,  0.01f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.80f) });
	vertices.push_back({ vec4(0.2f, 0.0f, 0.01f, 1.0f), vec4(0.0f, 0.2f, 0.5f, 0.80f) });

}

