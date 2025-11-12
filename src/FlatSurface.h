#include "ISurface.h";

class FlatSurface : public ISurface {

	// Метод для получения пространственных координат точки, находящейся на поверхности
	Eigen::Vector3d get3Dpoint(double u, double v) const override;

	// Метрический тензор - матрица 2х2 в точке (u, v)
	Eigen::Matrix2d metricTensor(double u, double v) const override;

	// Матрица, обратная метрическому тензору, в точке (u, v)
	Eigen::Matrix2d inverseMetricTensor(double u, double v) const override;

	// Определитель матрицы метрического тензора det(metricTensor) в точке (u, v)
	double metricTensorDet(double u, double v) const override;

	// Символы Кристоффеля в точке (u, v)
	std::array<Eigen::Matrix2d, 2> cristoffelSymbols(double u, double v) const override;

	// Деструктор
	~FlatSurface() {}
};