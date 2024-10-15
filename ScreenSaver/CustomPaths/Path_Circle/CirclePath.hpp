# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
    /**
     * @file CirclePath.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @def RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
     * @brief Ramtin Kosari's Screen Saver Custom Paths - Circle Path Header File
     * @date 2024-10-11
     */
    # define RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
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
     * @def CIRCLE_PATH_RADIUS
     * @brief Circle Path Radius
     */
    # define CIRCLE_PATH_RADIUS RK_SCREEN_SAVER_WINDOW_HEIGHT * 3 / 8
    /**
     * @def CIRCLE_PATH_SPEED
     * @brief Circle Path Speed
     * @note Speed is in Milliseconds
     */
    # define CIRCLE_PATH_SPEED 0.02
    /**
     * @def CIRCLE_PATH_CENTER_X
     * @brief Circle Path Center X-Axis
     */
    # define CIRCLE_PATH_CENTER_X RK_SCREEN_SAVER_WINDOW_WIDTH / 2
    /**
     * @def CIRCLE_PATH_CENTER_Y
     * @brief Circle Path Center Y-Axis
     */
    # define CIRCLE_PATH_CENTER_Y RK_SCREEN_SAVER_WINDOW_HEIGHT / 2
    /**
     * @def CIRCLE_PATH_CENTER_Z
     * @brief Circle Path Center Z-Axis
     */
    # define CIRCLE_PATH_CENTER_Z 0.0
    /**
     * @brief Class to Handle Circle Path
     * @class RKCirclePath
     */
    class RKCirclePath {
        public:
            /**
             * @brief Construct a New RKCirclePath Object
             */
            RKCirclePath();
            /**
             * @brief Destroy the RKCirclePath Object
             */
            ~RKCirclePath();
            /**
             * @brief Method to Get Position of Circle Path According to Time
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
                double radius = CIRCLE_PATH_RADIUS,
                double centerX = CIRCLE_PATH_CENTER_X,
                double centerY = CIRCLE_PATH_CENTER_Y,
                double centerZ = CIRCLE_PATH_CENTER_Z
            );
    };
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH