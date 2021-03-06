#pragma once
#include "stdafx.h"
#include "Piso.h"

void Piso::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}


Piso::Piso() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	 rPiso = 0.32f;
	 gPiso = 0.32f;
	 bPiso = 0.32f;

	vertices.push_back({ vec4(-50.0f, -0.8f,  -100.0f, 1.0f),vec4(0.39607f, 0.54509f, 0.38431f, 0.3f) });
	vertices.push_back({ vec4(50.0f, -0.8f,  -100.0f, 1.0f),vec4(0.39607f, 0.54509f, 0.38431f, 0.25f) });
	vertices.push_back({ vec4(50.0f, -0.8f,  26.0f, 1.0f),vec4(0.39607f, 0.54509f, 0.38431f, 0.5f) });
	vertices.push_back({ vec4(-50.0f, -0.8f,  26.0f, 1.0f),vec4(0.39607f, 0.54509f, 0.38431f, 0.4f) });

	vertices.push_back({ vec4(-50.0f, 20.0f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(50.0f, -0.8f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(-50.0f, -0.8f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });

	vertices.push_back({ vec4(-50.0f, -0.8f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(-50.0f, -0.8f, 26.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, 26.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });

	vertices.push_back({ vec4(50.0f, -0.8f, 26.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(50.0f, -0.8f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, -100.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, 26.0f, 1.0f),vec4(rPiso, gPiso, bPiso, 0.2f) });
	actualizarMatrizModelo();
}

