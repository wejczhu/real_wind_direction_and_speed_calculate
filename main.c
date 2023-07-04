#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Ship direction and speed
    double ship_direction = 170;
    double ship_speed = 7.2;

    // Relative wind direction and speed, usually get from sensor on ship
    double relative_wind_direction = 30.0;
    double relative_wind_speed = 10.0;

    double angle_ship_relative = abs(relative_wind_direction - ship_direction);

    if(angle_ship_relative > 180)
    {
      angle_ship_relative = 360 - angle_ship_relative;
    }

    // Calculate true wind speed
    double true_wind_speed = sqrt(pow(relative_wind_speed, 2) + pow(ship_speed, 2) - 2 * relative_wind_speed * ship_speed * cos(angle_ship_relative * M_PI / 180));

    // Calculate true wind direction
    double true_wind_angle = acos((pow(ship_speed, 2) + pow(true_wind_speed, 2) - pow(relative_wind_speed, 2)) / (2 * ship_speed * true_wind_speed)) * 180 / M_PI;
    double true_wind_direction = 0;

    double relative_angle = ship_direction - relative_wind_direction;

    if((relative_angle > 180) || relative_angle < 0)
    {
      true_wind_direction = ship_direction + 180 - true_wind_angle;
    }
    else
    {
      true_wind_direction = ship_direction + 180 + true_wind_angle;
    }

    if(true_wind_direction >= 360)
    {
      true_wind_direction -= 360;
    }

    printf("True wind direction:  %.2lf degrees\n", true_wind_direction);
    printf("True wind speed: %.2f knots\n", true_wind_speed);

    return 0;
}
