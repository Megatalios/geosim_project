#include "FlatSurface.h";

Eigen::Vector3d FlatSurface::get3Dpoint(double u, double v) const {
	// Плоская поверхность в плоскости XY
	return Eigen::Vector3d(u, v, 0.0);
}

Eigen::Matrix2d FlatSurface::metricTensor(double u, double v) const {
	// Единичная матрица 
	return Eigen::Matrix2d::Identity();
}

Eigen::Matrix2d FlatSurface::inverseMetricTensor(double u, double v) const {
	// Обратная к единичной - тоже единичная
	return Eigen::Matrix2d::Identity();
}

double FlatSurface::metricTensorDet(double u, double v) const {
	// Определитель единичной матрицы равен 1
	return 1;
}

std::array<Eigen::Matrix2d, 2> FlatSurface::cristoffelSymbols(double u, double v) const {
	// Все символы Кристоффеля равны нулю на плоской поверхности
	return { Eigen::Matrix2d::Zero(), Eigen::Matrix2d::Zero() };
}