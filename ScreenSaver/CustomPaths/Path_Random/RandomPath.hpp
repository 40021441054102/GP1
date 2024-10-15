# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_RANDOM_PATH
    /**
     * @file RandomPath.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Ramtin Kosari's Screen Saver Custom Paths - Random Path Header File
     * @date 2024-10-15
     */
    # define RK_GRAPHICS_PROJECT_SCREEN_SAVER_RANDOM_PATH
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
    //-- Include Random Library
    # ifndef _GLIBCXX_RANDOM
        # include <random>
    # endif // _GLIBCXX_RANDOM
    /**
     * @def RANDOM_PATH_SCALE
     * @brief Random Path Scale
     */
    # define RANDOM_PATH_SCALE 300
    /**
     * @def RANDOM_PATH_CENTER_X
     * @brief Random Path Center X-Axis
     */
    # define RANDOM_PATH_CENTER_X RK_SCREEN_SAVER_WINDOW_WIDTH / 2
    /**
     * @def RANDOM_PATH_CENTER_Y
     * @brief Random Path Center Y-Axis
     */
    # define RANDOM_PATH_CENTER_Y RK_SCREEN_SAVER_WINDOW_HEIGHT / 2
    /**
     * @brief Class to Handle Random Path
     * @class RKRandomPath
     */
    class RKRandomPath {
        public:
            /**
             * @brief Construct a New RKRandomPath Object
             */
            RKRandomPath();
            /**
             * @brief Destroy the RKRandomPath Object
             */
            ~RKRandomPath();
            /**
             * @brief Get Random Path Position
             * @param time Time
             * @param scale Scale Factor to Make Curve Visible
             * @param centerX Center X
             * @param centerY Center Y
             * @return RKGPoint Position
             */
            RKGPoint getPosition(
                double time,
                double k = 5,
                double scale = RANDOM_PATH_SCALE,
                double centerX = RANDOM_PATH_CENTER_X,
                double centerY = RANDOM_PATH_CENTER_Y
            );
    };
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_RANDOM_PATH