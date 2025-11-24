#include "ISurface.h"

/// <summary>
/// Решатель задачи геодезических линий. Используется метод Рунге-Кутта 4-го порядка.
/// </summary>
class Solver {
public:

	// (u, v, du/ds, dv/ds)
	using State = Eigen::Vector4d; 

	/// <summary>
	/// Метод Рунге-Кутта. Принимает на вход поверхность, поддерживающую интерфейс ISurface.
	/// </summary>
	/// <param name="surface">Поверхность, для которой решается уравнение геодезических</param>
	/// <param name="state">Начальное состояние (u0, v0, du/ds0, dv/ds0)</param>
	/// <param name="step">Шаг по параметру s</param>
	/// <param name="numOfSteps">Количество шагов</param>
	void solve(const ISurface& surface, const State& state, double step, int numOfSteps);

	State computeDerivatives(const ISurface& surface, const State& state);
};