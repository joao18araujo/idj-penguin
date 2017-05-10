#include "Collision.h"

bool Collision::is_colliding(Rectangle& a, Rectangle& b, float angleOfA, float angleOfB) {
    Vector A[] = { Vector( a.get_x(), a.get_y() + a.get_height() ),
                  Vector( a.get_x() + a.get_width(), a.get_y() + a.get_height() ),
                  Vector( a.get_x() + a.get_width(), a.get_y() ),
                  Vector( a.get_x(), a.get_y() )
                };
    Vector B[] = { Vector( b.get_x(), b.get_y() + b.get_height() ),
                  Vector( b.get_x() + b.get_width(), b.get_y() + b.get_height() ),
                  Vector( b.get_x() + b.get_width(), b.get_y() ),
                  Vector( b.get_x(), b.get_y() )
                };

    for (auto& v : A) {
        v = rotate(v - a.get_center(), angleOfA) + a.get_center();
    }

    for (auto& v : B) {
        v = rotate(v - b.get_center(), angleOfB) + b.get_center();
    }

    Vector axes[] = { norm(A[0] - A[1]), norm(A[1] - A[2]), norm(B[0] - B[1]), norm(B[1] - B[2]) };

    for (auto& axis : axes) {
        float P[4];

        for (int i = 0; i < 4; ++i) P[i] = dot(A[i], axis);

        float minA = *std::min_element(P, P + 4);
        float maxA = *std::max_element(P, P + 4);

        for (int i = 0; i < 4; ++i) P[i] = dot(B[i], axis);

        float minB = *std::min_element(P, P + 4);
        float maxB = *std::max_element(P, P + 4);

        if (maxA < minB || minA > maxB)
            return false;
    }

    return true;
}


float Collision::mag(const Vector& p) {
    return std::sqrt(p.x * p.x + p.y * p.y);
}

Vector Collision::norm(const Vector& p) {
    return p * (1.f / mag(p));
}

float Collision::dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}

Vector Collision::rotate(const Vector& p, float angle) {
    float cs = std::cos(angle), sn = std::sin(angle);
    return Vector ( p.x * cs - p.y * sn, p.x * sn + p.y * cs );
}
