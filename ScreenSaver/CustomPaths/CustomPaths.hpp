# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_CUSTOM_PATHS
    /**
     * @file CustomPaths.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @def RK_GRAPHICS_PROJECT_SCREEN_SAVER_CUSTOM_PATHS
     * @brief Ramtin Kosari's Screen Saver Custom Paths - Term 7 Graphics Project 1
     * @date 2024-10-11
     */
    # define RK_GRAPHICS_PROJECT_SCREEN_SAVER_CUSTOM_PATHS
    //-- Check if Project is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Circle Path File is Configured
        # ifndef HAS_RKACPB_MODULE_CIRCLEPATH
            # error "Configuration File is Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_CIRCLEPATH
    # endif // RKACPB
    //-- Include Circle Path File
    # ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
        # include "CirclePath.hpp"
    # endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
    /**
     * @brief Class to Handle Custom Paths
     * @class RKCustomPaths
     */
    class RKCustomPaths {
        public:
            /**
             * @brief Circle Path Object
             */
            RKCirclePath circlePath;
            /**
             * @brief Construct a New RKCustomPaths Object
             */
            RKCustomPaths();
            /**
             * @brief Destroy the RKCustomPaths Object
             */
            ~RKCustomPaths();
    };
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_CUSTOM_PATHS