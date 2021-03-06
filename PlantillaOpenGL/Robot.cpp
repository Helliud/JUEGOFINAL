#pragma once
#include "stdafx.h"
#include "Robot.h"

void Robot::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadasRobot);

	if (darVueltaRobotDerecha) {
		modelo = rotate(modelo, -90.0f * 3.14159f / 180.0f , vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotIzquierda)
	{
		modelo = rotate(modelo, 90.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAtras)
	{
		modelo = rotate(modelo, -180.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAdelante) {
		modelo = rotate(modelo, 0.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));

	}

	if (darVueltaRobotAdelante && darVueltaRobotDerecha) {
		modelo = rotate(modelo, 45.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAdelante && darVueltaRobotIzquierda) {
		modelo = rotate(modelo, -45.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAtras && darVueltaRobotIzquierda) {
		modelo = rotate(modelo, -135.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAtras && darVueltaRobotDerecha) {
		modelo = rotate(modelo, 135.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

}

vec3 Robot::getCoordenadas() {
	return coordenadasRobot;
}

void Robot::robotTiempoDiferencial() {

	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;

}

void Robot::avanzar() {
	darVueltaRobotAdelante = true;
	coordenadasRobot.z -= velocidad * (tiempoDiferencial * bonusVelocidad);
	actualizarMatrizModelo();
}

void Robot::rotarIzq() {
	darVueltaRobotIzquierda = true;
	coordenadasRobot.x -= velocidad * (tiempoDiferencial * bonusVelocidad);
		actualizarMatrizModelo();
}

void Robot::rotarDer() {
	darVueltaRobotDerecha = true;
	coordenadasRobot.x += velocidad * (tiempoDiferencial * bonusVelocidad);
	actualizarMatrizModelo();
}

void Robot::regresar() {
	darVueltaRobotAtras = true;
	coordenadasRobot.z += velocidad * (tiempoDiferencial * bonusVelocidad);
	actualizarMatrizModelo();
}



Robot::Robot() {	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, - 0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });


	//OJOS
	//Ojos - Parte arriba
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	
	//Ojos - Parte abajo
	vertices.push_back({ vec4(-0.4f, 0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f, 0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });

	//Ojos - Parte delantera
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });

	//Ojos - Parte izquierda
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f,  0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });

	//Ojos - Parte derecha
	vertices.push_back({ vec4(0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f, 0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });


	//CUERPO
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	vertices.push_back({ vec4(0.1f, -0.4f,  0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	vertices.push_back({ vec4(0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	vertices.push_back({ vec4(0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Derecha
	vertices.push_back({ vec4(0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });


	//Izquierda
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
}

