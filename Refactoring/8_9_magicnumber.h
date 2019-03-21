#ifndef MAGICNUMBER_8_9_H
#define MAGICNUMBER_8_9_H

//// 原始版本
//double potentialEnergy(double mass, double height)
//{
//    return mass*9.81*height;
//}

// 新版本
static double GRAVITY_CONSTANT = 9.81;
double potentialEnergy(double mass, double height)
{
    return mass*GRAVITY_CONSTANT*height;
}

#endif // MAGICNUMBER_8_9_H
