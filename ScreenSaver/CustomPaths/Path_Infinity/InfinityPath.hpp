# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_INFINITY_PATH
    /**
     * @file InfinityPath.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @def RK_GRAPHICS_PROJECT_SCREEN_SAVER_INFINITY_PATH
     * @brief Ramtin Kosari's Screen Saver Custom Paths - Infinity Path Header File
     * @date 2024-10-13
     */
    # define RK_GRAPHICS_PROJECT_SCREEN_SAVER_INFINITY_PATH
    //-- Check if Project is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Screen Saver Configuration File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Screen Saver Configuration File is Required for RK Graphics Project 1"
        # endif // RK_GRAPHICS_PROJECT_1_CONFIGS
        //-- Check if RKOGLT is Configured
        # ifndef HAS_RKACPB_MODULE_RKOGLT
            # error "RKOGLT is Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_RKOGLT
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef RK_GRAPHICS_PROJECT_1_CONFIGS
        # include "Configs.hpp"
    # endif // RK_GRAPHICS_PROJECT_1_CONFIGS
    //-- Include RKOGLT
    # ifndef RKOGLT
        # include "RKOGLT.hpp"
    # endif // RKOGLT
    //-- Include Math Library
    # ifndef _GLIBCXX_CMATH
        # include <cmath>
    # endif // _GLIBCXX_CMATH
    /**
     * @def INFINITY_PATH_RADIUS
     * @brief Infinity Path Radius
     */
    # define INFINITY_PATH_RADIUS RK_SCREEN_SAVER_WINDOW_HEIGHT * 3 / 8
    /**
     * @def INFINITY_PATH_SPEED
     * @brief Infinity Path Speed
     * @note Speed is in Milliseconds
     */
    # define INFINITY_PATH_SPEED 0.01
    /**
     * @def INFINITY_PATH_CENTER_X
     * @brief Infinity Path Center X-Axis
     */
    # define INFINITY_PATH_CENTER_X RK_SCREEN_SAVER_WINDOW_WIDTH / 2
    /**
     * @def INFINITY_PATH_CENTER_Y
     * @brief Infinity Path Center Y-Axis
     */
    # define INFINITY_PATH_CENTER_Y RK_SCREEN_SAVER_WINDOW_HEIGHT / 2
    /**
     * @def INFINITY_PATH_CENTER_Z
     * @brief Infinity Path Center Z-Axis
     */
    # define INFINITY_PATH_CENTER_Z 0.0
    /**
     * @brief Class to Handle Infinity Path
     * @class RKInfinityPath
     */
    class RKInfinityPath {
        public:
        /**
         * @brief Construct a New RKInfinityPath Object
         */
        RKInfinityPath();
        /**
         * @brief Destroy the RKInfinityPath Object
         */
        ~RKInfinityPath();
        /**
         * @brief Method to Get Position of Infinity Path According to Time
         * @param time Time
         * @param radius Radius
         * @param centerX Center X
         * @param centerY Center Y
         * @param centerZ Center Z
         * @note Default Values are Defined in Header File
         * @return RKGPoint Position
         */
        RKGPoint getPosition(
            double time,
            double radius = INFINITY_PATH_RADIUS,
            double centerX = INFINITY_PATH_CENTER_X,
            double centerY = INFINITY_PATH_CENTER_Y,
            double centerZ = INFINITY_PATH_CENTER_Z
        );
    };
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_INFINITY_PATH