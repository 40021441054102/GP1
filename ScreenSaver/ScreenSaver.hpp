# ifndef RK_GRAPHICS_PROJECT_1
    /**
     * @file ScreenSaver.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Ramtin Kosari's Screen Saver - Term 7 Graphics Project 1
     * @def RK_GRAPHICS_PROJECT_1
     * @note This File is Remake of the Original File Developed During Class Time
     * @date 2024-10-11
     */
    # define RK_GRAPHICS_PROJECT_1
    /**
     * @brief Ramtin Kosari's Screen Saver
     * @def RK_GRAPHICS_PROJECT_SCREEN_SAVER
     * @note This is Part of Term 7 Graphics Project 1
     */
    # define RK_GRAPHICS_PROJECT_SCREEN_SAVER
    //-- Check if Project is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configuration File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Configuration File is Required for RK Graphics Project 1"
        # endif // RK_GRAPHICS_PROJECT_1_CONFIGS
        //-- Check if RKLogger is Configured
        # ifndef HAS_RKACPB_MODULE_RKLOGGER
            # error "RKLogger is Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_RKLOGGER
        //-- Check if RKOGLT is Configured
        # ifndef HAS_RKACPB_MODULE_RKOGLT
            # error "RKOGLT is Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_RKOGLT
        //-- Check if Window is Configured
        # ifndef HAS_RKACPB_MODULE_WINDOW
            # error "Window is Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_WINDOW
        //-- Check if Line is Configured
        # ifndef HAS_RKACPB_MODULE_LINE
            # error "Line is Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_LINE
        //-- Check if Custom Paths are Configured
        # ifndef HAS_RKACPB_MODULE_CUSTOMPATHS
            # error "Custom Paths are Required for RK Graphics Project 1"
        # endif // HAS_RKACPB_MODULE_CUSTOMPATHS
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef RK_GRAPHICS_PROJECT_1_CONFIGS
        # include "Configs.hpp"
    # endif // RK_GRAPHICS_PROJECT_1_CONFIGS
    //-- Include RKLogger
    # ifndef RKLOGGER
        # include "RKLogger.hpp"
    # endif // RKLOGGER
    //-- Include RKOGLT
    # ifndef RKOGLT
        # include "RKOGLT.hpp"
    # endif // RKOGLT
    //-- Include Window
    # ifndef SYNESTIA_GRAPHICS_WINDOW
        # include "Window.hpp"
    # endif // SYNESTIA_GRAPHICS_WINDOW
    //-- Include Line
    # ifndef RK_GRAPHICS_LINE
        # include "Line.hpp"
    # endif // RK_GRAPHICS_LINE
    //-- Include Custom Paths
    # ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
        # include "CustomPaths.hpp"
    # endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
    //-- Include Random Library
    # ifndef _GLIBCXX_RANDOM
        # include <random>
    # endif // _GLIBCXX_RANDOM
    //-- Include Thread Library
    # ifndef _GLIBCXX_THREAD
        # include <thread>
    # endif // _GLIBCXX_THREAD
    //-- Include Chrono Library
    # ifndef _GLIBCXX_CHRONO
        # include <chrono>
    # endif // _GLIBCXX_CHRONO
    //-- Include Deque Library
    # ifndef _GLIBCXX_DEQUE
        # include <deque>
    # endif // _GLIBCXX_DEQUE
    /**
     * @brief Screen Saver Types
     * @enum RKScreenSaverType
     * @note This Enum Defines Different Types of Screen Savers
     * @param RK_SCREEN_SAVER_SOUND_EQUALIZER_CIRCLE Circle Shape Sound Equalizer Screen Saver
     * @param RK_SCREEN_SAVER_SOUND_EQUALIZER_LINE Line Shape Sound Equalizer Screen Saver
     * @param RK_SCREEN_SAVER_WISH_FLOWER Wish Flower Screen Saver
     * @param RK_SCREEN_SAVER_INFINITE Infinite Screen Saver
     * @param RK_SCREEN_SAVER_RANDOM Random Screen Saver
     * @param RK_SCREEN_SAVER_CIRCLE Circle Screen Saver
     * @param RK_SCREEN_SAVER_CUSTOM Custom Screen Saver
     * @param RK_SCREEN_SAVER_HEART Heart Screen Saver
     */
    enum RKScreenSaverType {
        RK_SCREEN_SAVER_SOUND_EQUALIZER_CIRCLE,
        RK_SCREEN_SAVER_SOUND_EQUALIZER_LINE,
        RK_SCREEN_SAVER_WISH_FLOWER,
        RK_SCREEN_SAVER_INFINITE,
        RK_SCREEN_SAVER_RANDOM,
        RK_SCREEN_SAVER_CIRCLE,
        RK_SCREEN_SAVER_CUSTOM,
        RK_SCREEN_SAVER_HEART
    };
    /**
     * @brief Class to Handle Screen Saver
     * @class RKScreenSaver
     */
    class RKScreenSaver {
        public:
            /**
             * @brief Synestia Graphics Window
             */
            synwin::SynWindow window = synwin::SynWindow(
                "Synestia Graphics",
                RK_SCREEN_SAVER_WINDOW_HEIGHT,
                RK_SCREEN_SAVER_WINDOW_WIDTH
            );
            /**
             * @brief Define RK Line Object
             */
            RKLine line;
            /**
             * @brief Method to Construct a New RKScreenSaver Object
             */
            RKScreenSaver();
            /**
             * @brief Method to Construct a New RKScreenSaver Object
             * @param type Screen Saver Type
             */
            RKScreenSaver(int type);
    };
# endif // RK_GRAPHICS_PROJECT_1