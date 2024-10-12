# ifndef RK_GRAPHICS_PROJECT_1_CONFIGS
    /**
     * @file Configs.hpp
     * @author RamtinKosari (ramtinkosari@gmail.com)
     * @brief Configuration File for Screen Saver
     * @def RK_GRAPHICS_PROJECT_1_CONFIGS
     * @date 2024-10-11
     */
    # define RK_GRAPHICS_PROJECT_1_CONFIGS
    //-- Include OpenGL
    # ifndef __GLEW_H__
        # include <GL/glew.h>
    # endif // __GLEW_H__
    //-- Include Free Glut
    # ifndef __FREEGLUT_H__
        # include <GL/freeglut.h>
    # endif // __FREEGLUT_H__
    /**
     * @brief Screen Saver Window Width
     * @def RK_SCREEN_SAVER_WINDOW_WIDTH
     */
    # define RK_SCREEN_SAVER_WINDOW_WIDTH 2200
    /**
     * @brief Screen Saver Window Height
     * @def RK_SCREEN_SAVER_WINDOW_HEIGHT
     */
    # define RK_SCREEN_SAVER_WINDOW_HEIGHT 1440
# endif // RK_GRAPHICS_PROJECT_1_CONFIGS