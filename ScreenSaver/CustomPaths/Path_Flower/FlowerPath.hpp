# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_FLOWER_PATH
    /**
     * @file FlowerPath.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @def RK_GRAPHICS_PROJECT_SCREEN_SAVER_FLOWER_PATH
     * @brief Ramtin Kosari's Screen Saver Custom Paths - Flower Path Header File
     * @date 2024-10-14
     */
    # define RK_GRAPHICS_PROJECT_SCREEN_SAVER_FLOWER_PATH
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
     * @def FLOWER_PATH_SCALE
     * @brief Flower Path Scale
     */
    # define FLOWER_PATH_SCALE 300
    /**
     * @def FLOWER_PATH_CENTER_X
     * @brief Flower Path Center X-Axis
     */
    # define FLOWER_PATH_CENTER_X RK_SCREEN_SAVER_WINDOW_WIDTH / 2
    /**
     * @def FLOWER_PATH_CENTER_Y
     * @brief Flower Path Center Y-Axis
     */
    # define FLOWER_PATH_CENTER_Y RK_SCREEN_SAVER_WINDOW_HEIGHT / 2
    /**
     * @brief Class to Handle Flower Path
     * @class RKFlowerPath
     */
    class RKFlowerPath {
        public:
            /**
             * @brief Construct a New RKFlowerPath Object
             */
            RKFlowerPath();
            /**
             * @brief Destroy the RKFlowerPath Object
             */
            ~RKFlowerPath();
            /**
             * @brief Get Flower Path Position
             * @param time Time
             * @param k Number of Petals
             * @param scale Scale Factor to Make Curve Visible
             * @param centerX Center X
             * @param centerY Center Y
             * @return RKGPoint Position
             */
            // RKGPoint getPosition(
            //     double time,
            //     int k = 5,
            //     double scale = FLOWER_PATH_SCALE,
            //     double centerX = FLOWER_PATH_CENTER_X,
            //     double centerY = FLOWER_PATH_CENTER_Y
            // );
            RKGPoint getPosition(
                double time,
                int k = 5,
                double scale = FLOWER_PATH_SCALE,
                double centerX = FLOWER_PATH_CENTER_X,
                double centerY = FLOWER_PATH_CENTER_Y
            );
    };
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_FLOWER_PATH