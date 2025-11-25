#include "ISurface.h";

/// <summary>
/// Класс плоской поверхности, реализующий интерфейс ISurface
/// </summary>
class FlatSurface : public ISurface {

	/// <summary>
	/// Метод для получения пространственных координат точки, находящейся на поверхности
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	Eigen::Vector3d get3Dpoint(double u, double v) const override;

	/// <summary>
	/// Метрический тензор - матрица 2х2 в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	Eigen::Matrix2d metricTensor(double u, double v) const override;

	/// <summary>
	/// Матрица, обратная метрическому тензору, в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	Eigen::Matrix2d inverseMetricTensor(double u, double v) const override;

	/// <summary>
	/// Определитель матрицы метрического тензора det(metricTensor) в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	double metricTensorDet(double u, double v) const override;

	/// <summary>
	/// Символы Кристоффеля в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	std::array<Eigen::Matrix2d, 2> cristoffelSymbols(double u, double v) const override;

	// Деструктор
	~FlatSurface() {}
};