/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_SPHERICALPROJECTIONSURFACE_H_
#define _CARTO_SPHERICALPROJECTIONSURFACE_H_

#include "projections/ProjectionSurface.h"

#include <cglib/vec.h>
#include <cglib/mat.h>
#include <cglib/ray.h>

namespace carto {
    
    class SphericalProjectionSurface : public ProjectionSurface {
    public:
        SphericalProjectionSurface();
        
        virtual MapPos calculateMapPos(const cglib::vec3<double>& pos) const;
        virtual MapVec calculateMapVec(const cglib::vec3<double>& pos, const cglib::vec3<double>& vec) const;

        virtual cglib::vec3<double> calculatePosition(const MapPos& mapPos) const;
        virtual cglib::vec3<double> calculateNormal(const MapPos& mapPos) const;
        virtual cglib::vec3<double> calculateVector(const MapPos& mapPos, const MapVec& mapVec) const;

        virtual void tesselateSegment(const MapPos& mapPos0, const MapPos& mapPos1, std::vector<MapPos>& mapPoses) const;
        virtual void tesselateTriangle(unsigned int i0, unsigned int i1, unsigned int i2, std::vector<unsigned int>& indices, std::vector<MapPos>& mapPoses) const;

        virtual double calculateDistance(const cglib::vec3<double> pos0, const cglib::vec3<double>& pos1) const;
        virtual cglib::vec3<double> calculateNearestPoint(const cglib::vec3<double>& pos, double height) const;
        virtual cglib::vec3<double> calculateNearestPoint(const cglib::ray3<double>& ray, double height, double& t) const;
        virtual bool calculateHitPoint(const cglib::ray3<double>& ray, double height, double& t) const;

        virtual cglib::mat4x4<double> calculateLocalFrameMatrix(const cglib::vec3<double>& pos) const;
        virtual cglib::mat4x4<double> calculateTranslateMatrix(const cglib::vec3<double>& pos0, const cglib::vec3<double>& pos1, double t) const;

    private:
        static bool SplitSegment(const MapPos& mapPos0, const MapPos& mapPos1, MapPos& mapPosM);
        static MapPos SphericalToInternal(const cglib::vec3<double>& pos);
        static cglib::vec3<double> InternalToSpherical(const MapPos& mapPos);
        static cglib::mat3x3<double> LocalFrame(const cglib::vec3<double>& pos);

        static const double SPHERE_SIZE;
        static const double PLANAR_APPROX_ANGLE;
        static const double SEGMENT_SPLIT_THRESHOLD;
    };
    
}

#endif
