#include <Eigen/Dense>
#include <array>

/// <summary>
/// Интерфейс поверхности
/// </summary>
class ISurface {

public:
	/// <summary>
	/// Метод для получения пространственных координат точки, находящейся на поверхности
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	virtual Eigen::Vector3d get3Dpoint(double u, double v) const = 0;

	/// <summary>
	/// Метрический тензор - матрица 2х2 в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	virtual Eigen::Matrix2d metricTensor(double u, double v) const = 0;

	/// <summary>
	/// Матрица, обратная метрическому тензору, в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	virtual Eigen::Matrix2d inverseMetricTensor(double u, double v) const = 0;

	/// <summary>
	/// Определитель матрицы метрического тензора det(metricTensor) в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	virtual double metricTensorDet(double u, double v) const = 0;

	/// <summary>
	/// Символы Кристоффеля в точке (u, v)
	/// </summary>
	/// <param name="u">Первая координата точки на поверхности</param>
	/// <param name="v">Вторая координата точки на поверхности</param>
	virtual std::array<Eigen::Matrix2d, 2> cristoffelSymbols(double u, double v) const = 0;

	// Виртуальный деструктор
	virtual ~ISurface() {}
};
