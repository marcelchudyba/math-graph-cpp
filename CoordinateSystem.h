#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H
#include <raylib.h>
#include <StoneMath.h>
#include <string>
#include <vector>

#include "Point.h"


class CoordinateSystem {
public:
    std::vector<Point> points;
    Vector2 origin;
    int screen_width,screen_height;
    double gridStep;
    double scale;
    float length_of_step;
    double pixel_step;
    double start_cart_x, end_cart_x,start_cart_y, end_cart_y;
    CoordinateSystem(int screen_width, int screen_height,float scale,int gridStep);
    void DrawGrid();
    void DrawCoordinateSystem();
    void DrawStep(int x, int y,float text_x, float text_y, double value,bool direction);
    void AddPoint(int x, int y);
    void DrawPoint(Point point,Color color);
    void DrawPoints();
    void UpdateScale(double new_value);
    void GetCenter();
    void ChangePixelStep();
    void DrawSequence(const std::string& expr,Color color);
    std::string CutPrefix(const std::string& expr);
    void DrawFunction(const std::string& expr,Color color);
    Vector2 ConvertXY(double x, double y);

};


#endif //COORDINATESYSTEM_H
