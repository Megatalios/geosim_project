#include "Solver.h"

std::vector<Solver::State> Solver::solve(const ISurface& surface, const State& state, double step, int numOfSteps) {
	// 
	std::vector<State> trajectory;
	State curState = state;
	for (int i = 0; i < numOfSteps; ++i) {
		State k1 = computeDerivatives(surface, curState);
		State k2 = computeDerivatives(surface, curState + k1 * 0.5 * step);
		State k3 = computeDerivatives(surface, curState + k2 * 0.5 * step);
		State k4 = computeDerivatives(surface, curState + k3 * step);

		curState = curState + (k1 + k2 * 2.0 + k3 * 2.0 + k4) * (step / 6.0);

		trajectory.push_back(curState);
	}
	return trajectory;
}

Solver::State Solver::computeDerivatives(const ISurface& surface, const State& state) {
	// Вычисление символов Кристоффеля в текущей точке поверхности
	auto G = surface.cristoffelSymbols(state[0], state[1]);
	State dy;

	// d(u)/dt = u'
	dy[0] = state[2];
	// d(v)/dt = v'
	dy[1] = state[3];
	// u'' = - ( G_11*du^2 + 2*G_12*du*dv + G_22*dv^2 )
	dy[2] = - G[0](1, 1) * state[3] * state[3] - 2 * G[0](0, 1) * state[2] * state[3] - G[0](0, 0) * state[2] * state[2];
	// v''
	dy[3] = - G[1](1, 1) * state[3] * state[3] - 2 * G[1](0, 1) * state[2] * state[3] - G[1](0, 0) * state[2] * state[2];

	return dy;
}