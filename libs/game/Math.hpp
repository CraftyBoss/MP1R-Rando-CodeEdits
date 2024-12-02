#pragma once

struct CVector3f {
public:
    float x;
    float y;
    float z;

    inline CVector3f() : x(0), y(0), z(0) {};

    inline CVector3f(float x, float y, float z) : x(x), y(y), z(z) {};
};

struct CVector2i {
public:
    int x;
    int y;

    inline CVector2i() : x(0), y(0) {};

    inline CVector2i(int x, int y) : x(x), y(y) {};
};

struct CQuaternion {
public:
    float w;
    float x;
    float y;
    float z;

    inline CQuaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {};
};

struct CAxisAngle : CVector3f {
    inline CAxisAngle() : CVector3f() {}
    inline CAxisAngle(float x, float y, float z) : CVector3f(x, y, z) {}
};

struct CScale3f : CVector3f {
    inline CScale3f() : CVector3f() {}
    inline CScale3f(float x, float y, float z) : CVector3f(x, y, z) {}
};

class CRelAngle {
public:
    inline CRelAngle(float theta): theta(theta) {}
    float theta;
};

class CTransform4f {
public:
    union {
        float matrix[12];
        float mtx[3][4];
        struct {
            float row1[3];
            float x;
            float row2[3];
            float y;
            float row3[3];
            float z;
        };
    };

    static constexpr inline CTransform4f Identity() {
        CTransform4f res;
        float mat[16] = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        res.matrix[0] = mat[0];
        res.matrix[1] = mat[1];
        res.matrix[2] = mat[2];
        res.matrix[3] = mat[3];
        res.matrix[4] = mat[4];
        res.matrix[5] = mat[5];
        res.matrix[6] = mat[6];
        res.matrix[7] = mat[7];
        res.matrix[8] = mat[8];
        res.matrix[9] = mat[9];
        res.matrix[10] = mat[10];
        res.matrix[11] = mat[11];

        return res;
    }

    static CTransform4f Translate(float x, float y, float z);
    //  CTransform4f RotateX(float theta);
    //  CTransform4f RotateY(float theta);
    CTransform4f RotateLocalX(const CRelAngle &theta);
    CTransform4f RotateLocalY(const CRelAngle &theta);
    CTransform4f RotateLocalZ(const CRelAngle &theta);
    void MultiplyRotation(CTransform4f const&) const;
    void MultiplyIgnoreTranslation(const CTransform4f *param_1);

    CTransform4f operator*(const CTransform4f &rhs) const;
    CVector3f TransposeRotate(CVector3f const&) const;
    CVector3f Rotate(CVector3f const&) const;

    inline CVector3f origin() { return CVector3f(matrix[3], matrix[3 + 4], matrix[3 + 8]); };
};

class CAABox {
public:
    enum EBoxEdgeId {
        kE_Z0,
        kE_X0,
        kE_Z1,
        kE_X1,
        kE_Z2,
        kE_X2,
        kE_Z3,
        kE_X3,
        kE_Y0,
        kE_Y1,
        kE_Y2,
        kE_Y3,
    };
    enum EBoxFaceId {
        kF_YMin,
        kF_YMax,
        kF_XMin,
        kF_XMax,
        kF_ZMax,
        kF_ZMin,
    };

    CAABox(const CVector3f& min, const CVector3f& max);
    CAABox(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
        : min(minX, minY, minZ), max(maxX, maxY, maxZ) {}
//    CAABox(CInputStream& in);
    // CAABox(const CAABox& other)
    // : min(other.min)
    // , max(other.max) {}

    // CAABox& operator=(const CAABox& other) {
    //   min = other.min;
    //   max = other.max;
    //   return *this;
    // }

//    CLineSeg GetEdge(EBoxEdgeId edge) const;
//    CTri GetTri(EBoxFaceId face, int windOffset) const;
    CVector3f ClosestPointAlongVector(const CVector3f& vec) const;
    CVector3f FurthestPointAlongVector(const CVector3f& vec) const;
    CVector3f GetCenterPoint() const;
    CVector3f GetPoint(int) const;
    // Include__6CAABoxFRC9CVector3f weak
    // Include__6CAABoxFRC6CAABox weak
    void AccumulateBounds(const CVector3f&);
    bool Invalid() const;
    bool PointInside(const CVector3f& vec) const;
    bool DoBoundsOverlap(const CAABox&) const;
    float GetVolume() const;
    CAABox GetBooleanIntersection(const CAABox& other) const;
    bool Inside(const CAABox& other) const;
//    bool InsidePlane(const CPlane& plane) const;
    CVector3f ClampToBox(const CVector3f& vec) const;
    CAABox GetTransformedAABox(const CTransform4f& xf) const;

//    inline CVector3f GetHalfExtent() const {
//        // Name is a guess
//        return (max - min) * 0.5f;
//    }

    const CVector3f& GetMinPoint() const { return min; }
    const CVector3f& GetMaxPoint() const { return max; }

    static const CAABox& Identity() { return skZeroBox; }
    static const CAABox& MakeMaxInvertedBox() { return skInvertedBox; }
    // MakeNullBox__6CAABoxFv ??
    static float DistanceBetween(const CAABox& a, const CAABox& b);

private:
    CVector3f min;
    CVector3f max;

    static CAABox skInvertedBox;
    static CAABox skZeroBox;
};

class CAABox2i {
private:
    CVector2i min;
    CVector2i max;
};

struct CColor4f {
    float r;
    float g;
    float b;
    float a;

    inline CColor4f() : r(0), g(0), b(0), a(0) {};
    inline CColor4f(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {};
};

class CMath {
public:
    static float CeilingF(float);
};