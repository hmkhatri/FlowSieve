#include <algorithm>
#include <math.h>
#include "../functions.hpp"
#include "../constants.hpp"

#ifndef DEBUG
    #define DEBUG 0
#endif

void compute_vorticity_at_point(
        double & vort_r_tmp,      /**< [in] where to store vort_r */
        double & vort_lon_tmp,    /**< [in] where to store vort_lon */
        double & vort_lat_tmp,    /**< [in] where to store vort_lat */
        const double * u_r,       /**< [in] full u_r for calculation */
        const double * u_lon,     /**< [in] full u_lon for calculation */
        const double * u_lat,     /**< [in] full u_lat for calculation */
        const int Ntime,          /**< [in] Length of time dimension */
        const int Ndepth,         /**< [in] Length of depth dimension */
        const int Nlat,           /**< [in] Length of latitude dimension */
        const int Nlon,           /**< [in] Length of longitude dimension */
        const int Itime,          /**< [in] Current position in time dimension */
        const int Idepth,         /**< [in] Current position in depth dimension */
        const int Ilat,           /**< [in] Current position in latitude dimension */
        const int Ilon,           /**< [in] Current position in longitude dimension */
        const double * longitude, /**< [in] Longitude dimension (1D) */
        const double * latitude,  /**< [in] Latitude dimension (1D) */
        const double * mask       /**< [in] Mask array (2D) to distinguish land from water*/
        ) {


    vort_r_tmp   = 0.;
    vort_lon_tmp = 0.;
    vort_lat_tmp = 0.;

    int index = Index(Itime, Idepth, Ilat, Ilon,
                      Ntime, Ndepth, Nlat, Nlon);

    // For the moment, only compute vort_r

    // Longitudinal derivative component
    vort_r_tmp += constants::R_earth
                    * longitude_derivative_at_point(
                        u_lat, longitude,
                        Itime, Idepth, Ilat, Ilon,
                        Ntime, Ndepth, Nlat, Nlon,
                        mask);

    // Latitudinal derivative component
    //  - ddlat ( u_lon * cos(lat) ) = u_lon * sin(lat) - ddlat( u_lon ) * cos(lat)
    vort_r_tmp += constants::R_earth
                    * (   sin(latitude[Ilat]) * u_lon[index]
                        - cos(latitude[Ilat]) * latitude_derivative_at_point(
                                                    u_lon, latitude,
                                                    Itime, Idepth, Ilat, Ilon,
                                                    Ntime, Ndepth, Nlat, Nlon,
                                                    mask)
                      );

    // Scale
    vort_r_tmp *= 1. / ( pow(constants::R_earth, 2) * cos(latitude[Ilat]) );

}

