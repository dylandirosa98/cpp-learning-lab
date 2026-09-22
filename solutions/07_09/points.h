#ifndef CPP_LEARNING_LAB_POINTS_H
#define CPP_LEARNING_LAB_POINTS_H

inline constexpr int pointsPerBadge{ 4 };

inline int badgePoints(int badges)
{
    return badges * pointsPerBadge;
}

#endif
