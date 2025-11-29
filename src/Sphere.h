#include "ISurface.h"

class Sphere : public ISurface {
public:
    ///<summary>
    ///
    ///</summary>
    Eigen::Vector3d get3Dpoint(double u, double v) const override;
    Eigen::Matrix2d metricTensor(double u, double v) const override;
    Eigen::Matrix2d inverseMetricTensor(double u, double v) const override;
    double metricTensorDet(double u, double v) const override;
    std::array<Eigen::Matrix2d, 2> cristoffelSymbols(double u, double v) const override;
};
