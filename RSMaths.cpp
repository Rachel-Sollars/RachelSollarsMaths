#include "RSMaths.h"

const float RSMaths::PI = 3.141593f;
const float RSMaths::TAU = 6.283185f;

float RSMaths::Lerp(float pointA, float pointB, float by)
{
    return pointA + (pointB - pointA) * by;
}

float RSMaths::LerpClamped(float pointA, float pointB, float by)
{
    if (by > 1)
        by = 1;
    else if (by < 0)
        by = 0;
    return pointA + (pointB - pointA) * by;
}

float RSMaths::InverseLerp(float pointA, float pointB, float value)
{
    return (value - pointA) / (pointB - pointA);
}

float RSMaths::InverseLerpClamped(float pointA, float pointB, float value)
{
    if (pointA > pointB)
    {
        if (value > pointA)
            value = pointA;
        else if (value < pointB)
            value = pointB;
    }

    else
    {
        if (value > pointB)
            value = pointB;
        else if (value < pointA)
            value = pointA;
    }
    return (value - pointA) / (pointB - pointA);
}

float RSMaths::Remap(float inMin, float inMax, float outMin, float outMax, float value)
{
    float newValue = InverseLerp(inMin, inMax, value);
    return Lerp(outMin, outMax, newValue);
}

float RSMaths::RemapClamped(float inMin, float inMax, float outMin, float outMax, float value) {
    float newVaue = InverseLerp(inMin, inMax, value);
    return LerpClamped(outMin, outMax, newVaue);
}

bool RSMaths::CloserThanOrEqualTo(float positionA[], float positionB[], float Distance)
{
    if (sizeof(positionA) != sizeof(positionB)) {
        return NULL;
    }
    else {
        float distVal = 0;

        for (int i = 0; i < sizeof(positionA); i++) {
            distVal += ((positionA[i] - positionB[i]) * (positionA[i] - positionB[i]));
        }
        return distVal <= Distance;
    }
}

float RSMaths::Quantize(float value, float increment)
{
    float diff = std::fmod(value, increment);
    float half = increment * 0.5f;

    if (diff == 0)
        return value;

    else if (diff < half)
        return value - diff;

    else
        return value + (increment - diff);
}