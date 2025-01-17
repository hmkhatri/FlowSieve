# Small Tutorial for Working on a Sphere {#tutorials4}
[TOC]

This tutorial walks through analysing a velocity field using Helmholtz decomposition with coarse-graining.

---

The generated data here is very low resolution (2-degree grid spacing), but runs in ~5 minutes on a single processor.

1. First, compile `Helmholtz_projection.x` and `coarse_grain_helmholtz.x` and copy them into this directory
2. Run the `run_all_steps.sh` script (`./run_all_steps.sh`)
3. Afterwards, you can run the jupyter notebook to analyse the results.

---

There is a known issue where the python scripts that run after calling `coarse_grain_helmholtz.x` in the `run_all_steps.sh` script fail to run withour printing an error. 
If the coarse-graining successfully runs (i.e. directory `outputs` is created and populated with `postprocessing_*.nc` files) but the `RESULTS_*.nc` files are not created, then you will need to manually call the three python scripts listed at the end of `run_all_steps.sh` script.


### Notes when compiling

When compiling the executables, set the `constants.hpp` variables as follows:
- `CARTESIAN = false`
- `PERIODIC_X = true`
- `PERIODIC_Y = false`
- `DEFORM_AROUND_LAND = false`
- `FILTER_OVER_LAND = true`
- `UNIFORM_LON_GRID = true`
- `UNIFORM_LAT_GRID = true`
- `EXTEND_DOMAIN_TO_POLES = false`
- `FULL_LON_SPAN = true`
- `MINIMAL_OUTPUT = true`
- `NO_FULL_OUTPUTS = true`
- `CAST_TO_SINGLE = true`
- `CAST_TO_INT = false`
- `APPLY_POSTPROCESS = true`
- `POSTPROCESS_DO_ZONAL_MEANS = true`
- `POSTPROCESS_DO_TIME_MEANS = false`
- `DO_OKUBOWEISS_ANALYSIS = false`
