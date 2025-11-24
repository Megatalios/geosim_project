#include "Solver.h"

void Solver::solve(const ISurface& surface, const State& state, double step, int numOfSteps) {

}

Solver::State Solver::computeDerivatives(const ISurface& surface, const State& state) {
	// Вычисление символов Кристоффеля в текущей точке поверхности
	auto G = surface.cristoffelSymbols(state[0], state[1]);

	double dy[4];

	dy[0] = state[2];
	dy[1] = state[3];

	dy[3] = -G[0](1, 1) * state[2] * state[2]
			- 2 * G[0](0, 1) * state[2] * state[3]
		- G[0](0, 0) * state[3] * state[3];
	dy[4] = -G[1](1, 1) * state[2] * state[2]
			- 2 * G[1](0, 1) * state[2] * state[3]
		- G[1](0, 0) * state[3] * state[3];

	return State(dy);
}