# real_wind_direction_and_speed_calculate
Calculate the real wind speed and direction on the moving vehicle and ship

## Usage

1. Get ship direction and speed
2. Get relative wind direction and speed by sensor on the ship
3. Change variable value in main.c according to above value

e.g.
```cpp
    // Ship direction and speed
    double ship_direction = 170;
    double ship_speed = 7.2;

    // Relative wind direction and speed, usually get from sensor on ship
    double relative_wind_direction = 30.0;
    double relative_wind_speed = 10.0;
```
4. compile the code and run it.