#pragma once
#include "stdafx.h"
#include "Felicidades.h"

void Felicidades::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}


Felicidades::Felicidades() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	vertices.push_back({ vec4(-50.0f, -0.8f,  -100.0f, 1.0f),vec4(0.1176f, 0.51764f, 0.28627f, 1.0f) });
	vertices.push_back({ vec4(50.0f, -0.8f,  -100.0f, 1.0f),vec4(0.1176f, 0.51764f, 0.28627f, 1.0f) });
	vertices.push_back({ vec4(50.0f, -0.8f,  20.0f, 1.0f),vec4(0.1176f, 0.51764f, 0.28627f, 1.0f) });
	vertices.push_back({ vec4(-50.0f, -0.8f,  20.0f, 1.0f),vec4(0.1176f, 0.51764f, 0.28627f, 1.0f) });

	vertices.push_back({ vec4(-50.0f, 20.0f, -100.0f, 1.0f),vec4(0.68235f, 0.83921f, 0.94509f, 1.0f) });
	vertices.push_back({ vec4(50.0f, 20.0f, -100.0f, 1.0f),vec4(0.68235f, 0.83921f, 0.94509f, 1.0f) });
	vertices.push_back({ vec4(50.0f, -0.8f, -100.0f, 1.0f),vec4(0.20392f, 0.59607f, 0.85882f, 1.0f) });
	vertices.push_back({ vec4(-50.0f, -0.8f, -100.0f, 1.0f),vec4(0.20392f, 0.59607f, 0.85882f, 1.0f) });

	vertices.push_back({ vec4(-50.0f, -0.8f, -100.0f, 1.0f),vec4(0.20392f, 0.59607f, 0.85882f, 1.0f) });
	vertices.push_back({ vec4(-50.0f, -0.8f, 20.0f, 1.0f),vec4(0.20392f, 0.59607f, 0.85882f, 1.0f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, 20.0f, 1.0f),vec4(0.68235f, 0.83921f, 0.94509f, 1.0f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, -100.0f, 1.0f),vec4(0.68235f, 0.83921f, 0.94509f, 1.0f) });

	vertices.push_back({ vec4(50.0f, -0.8f, 20.0f, 1.0f),vec4(0.20392f, 0.59607f, 0.85882f, 1.0f) });
	vertices.push_back({ vec4(50.0f, -0.8f, -100.0f, 1.0f),vec4(0.20392f, 0.59607f, 0.85882f, 1.0f) });
	vertices.push_back({ vec4(50.0f, 20.0f, -100.0f, 1.0f),vec4(0.68235f, 0.83921f, 0.94509f, 1.0f) });
	vertices.push_back({ vec4(50.0f, 20.0f, 20.0, 1.0f),vec4(0.68235f, 0.83921f, 0.94509f, 1.0f) });

	//F
	vertices.push_back({ vec4(-0.5f, 0.0f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.0f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.5f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.5f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.4f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.4f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.3f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.3f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.2f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.2f, -99.33, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });




	actualizarMatrizModelo();
}

