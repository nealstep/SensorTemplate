#include "s_mlx90615.h"
#ifdef S_MLX90615
#include <sensors.h>

#include <Wire.h>
#include <MLX90615.h>

#define MLX MLX90615_DefaultAddr

MLX90615 mlx90615(MLX, &Wire);

void s_mlx90615_init(void) {
    lg.debug("s_mlx90615 init");

    Wire.begin();
}

void s_mlx90615_check(void) {
    lg.debug("s_mlx90615 check");

    float obj_tempc, amb_tempc;

    obj_tempc = mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE);
    amb_tempc = mlx90615.getTemperature(MLX90615_AMBIENT_TEMPERATURE);

	lg.report("mlx90615.obj_temp", conv_float_uint32(obj_tempc));
	lg.report("mlx90615.amb_temp", conv_float_uint32(amb_tempc));
}

#endif // S_MLX90615
