#include "FlatSurface.h";

Eigen::Vector3d FlatSurface::get3Dpoint(double u, double v) const {
	return Eigen::Vector3d(u, v, 0.0);
}

// Метрический тензор - матрица 2х2 в точке (u, v)
Eigen::Matrix2d FlatSurface::metricTensor(double u, double v) const {
	// Единичная матрица 
	return Eigen::Matrix2d::Identity();
}

// Матрица, обратная метрическому тензору, в точке (u, v)
Eigen::Matrix2d FlatSurface::inverseMetricTensor(double u, double v) const {
	// Обратная к единичной - тоже единичная
	return Eigen::Matrix2d::Identity();
}

// Определитель матрицы метрического тензора det(metricTensor) в точке (u, v)
double FlatSurface::metricTensorDet(double u, double v) const {
	return 1;
}

// Символы Кристоффеля в точке (u, v)
std::array<Eigen::Matrix2d, 2> FlatSurface::cristoffelSymbols(double u, double v) const {
	return { Eigen::Matrix2d::Zero(), Eigen::Matrix2d::Zero() };
}