#include <Eigen/Dense>
#include <array>

/// <summary>
/// Интерфейс поверхности
/// </summary>
class ISurface {

public:
	// Метод для получения пространственных координат точки, находящейся на поверхности
	virtual Eigen::Vector3d get3Dpoint(double u, double v) const = 0;

	// Метрический тензор - матрица 2х2 в точке (u, v)
	virtual Eigen::Matrix2d metricTensor(double u, double v) const = 0;

	// Матрица, обратная метрическому тензору, в точке (u, v)
	virtual Eigen::Matrix2d inverseMetricTensor(double u, double v) const = 0;

	// Определитель матрицы метрического тензора det(metricTensor) в точке (u, v)
	virtual double metricTensorDet(double u, double v) const = 0;

	// Символы Кристоффеля в точке (u, v)
	virtual std::array<Eigen::Matrix2d, 2> cristoffelSymbols(double u, double v) const = 0;

	// Виртуальный деструктор
	virtual ~ISurface() {}
};
